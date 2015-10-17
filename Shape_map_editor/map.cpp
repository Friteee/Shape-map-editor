#include "map.h"
#include <iostream>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QTextStream>
#include <QGraphicsSceneDragDropEvent>
#include <QMessageBox>

Map::Map(QObject * parent):
    QGraphicsScene(parent),
    size_(5000,5000),
    tile_size_(32,32),
    grid_image_(size_)
{
    directory_ = "";
    if(!background_image_.load(QString(".\\images\\changeme.bmp")))
    {
        QMessageBox::critical(0,tr("Warning"),tr("No object found"));
    }
    this->setSceneRect(0, 0, size_.width(), size_.height());
}

Map::Map(QGraphicsView * init_view , QObject * parent)
    :QGraphicsScene(parent)
{
    directory_ = "";
    if(!background_image_.load(QString(".\\images\\changeme.bmp")))
    {
        QMessageBox::critical(0,tr("Warning"),tr("No object found"));
    }
    size_.setHeight(5000);
    size_.setWidth(5000);
    tile_size_.setHeight(32);
    tile_size_.setWidth(32);
    view_ = init_view;
    view_->setScene(this);
    this->setSceneRect(0, 0, size_.width(), size_.height());
    drawGrid();
}

void Map::init(QGraphicsView * init_view , ToolBar * toolbar)
{
    toolbar_ = toolbar;
    view_ = init_view;
    view_->setScene(this);
    this->setSceneRect(0,0,size_.width(),size_.height());
    drawGrid();
}

void Map::drawBackground(QPainter * painter, const QRectF & rect)
{
    QRectF buffer = rect;
    buffer = view_->mapToScene(QRect(view_->rect()) ).boundingRect();
    painter->drawPixmap( buffer, background_image_ , background_image_.rect());
    painter->drawPixmap( grid_image_.rect(), grid_image_ , this->sceneRect());
}

void Map::mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    toolbar_->mapMoved(mouseEvent);
    QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void Map::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    toolbar_->mapPressed(mouseEvent);
    QGraphicsScene::mousePressEvent(mouseEvent);
}

void Map::mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    toolbar_->mapReleased(mouseEvent);
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

void Map::open(QString filename)
{
    directory_ = filename;
    QFile file(directory_ + "/" + QDir(directory_).dirName() + ".shm");
    if(!file.exists())
    {
        QMessageBox::critical(view_,tr("Warning"), tr("No map in specified folder") + directory_ + "/" + QDir(directory_).dirName() + ".shm");
        return;
    }
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    unsigned int chunk_id;
    while(!in.atEnd())
    {
        in>>chunk_id;
        std::cout<<chunk_id<<" ";
        if(in.atEnd())
        {
            break;
        }
        MapChunkId id_buffer = static_cast<MapChunkId>(chunk_id);
        if(id_buffer == OBJECT_TYPE)
        {
            ObjectType type_buffer;
            Picture image_buffer;
            int x,y,w,h;
            unsigned int invincible,kind_buffer,id;
            in>>id;
            in>>image_buffer.first;
            in>>x>>y>>w>>h;
            image_buffer.second.setX(x);
            image_buffer.second.setY(y);
            image_buffer.second.setWidth(w);
            image_buffer.second.setHeight(h);
            in>>invincible;
            in>>w>>h;
            in>>kind_buffer;
            type_buffer.set_id(id);
            type_buffer.init(static_cast<Object_kind>(kind_buffer),QSize(w,h),static_cast<bool>(invincible));
            type_buffer.init_picture(image_buffer);
            std::shared_ptr<ObjectType> pointer_type = std::make_shared<ObjectType>(type_buffer);
            std::cout<<id<<" "<<invincible<<" "<<w<<" "<<h<<" "<<kind_buffer<<std::endl;
            types_.push_back(pointer_type);

        }
        else if (id_buffer == OBJECT)
        {
            std::shared_ptr<Object> buffer = std::make_shared<Object>();
            int x,y;
            unsigned int id;
            in>>id;
            in>>x>>y;
            buffer->change_rect(QPoint(x,y));
            for(auto a : types_)
            {
                if(a->get_id() == id)
                {
                    buffer->change_type(a);
                    QPixmap pixmap_buffer(a->get_picture().first);
                    pixmap_buffer = pixmap_buffer.copy(a->get_picture().second);
                    buffer->setPixmap(pixmap_buffer);
                    buffer->setOffset(x,y);
                    break;
                }
            }
            std::cout<<x<<" "<<y<<" "<<id<<" "<<std::endl;
            tiles_.push_back(buffer);
            this->addItem(buffer.get());

        }
        else if (id_buffer == BACKGROUND)
        {
            QString background;
            in >> background;
            changeBackground(background);
        }
        else if (id_buffer == SIZE)
        {
            int h,w;
            in>> w >> h;
            size_.setHeight(h);
            size_.setWidth(w);
            this->setSceneRect(0,0,w,h);
            drawGrid();
        }
    }
}

void Map::save()
{
    if(directory_ == "")
    {
        return;
    }
    QFile file(directory_ + "/" + QDir(directory_).dirName() + ".shm");
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    out<<static_cast<unsigned int>(SIZE)<<" "<<size_.width() <<" "<<size_.height()<<endl;
    out<<static_cast<unsigned int>(BACKGROUND)<<" "<<background_<<endl;
    for(unsigned int a = 0; a< types_.size() ; a++)
    {
        types_[a]->set_id(a);
    }
    for(unsigned int a = 0; a< types_.size() ; a++)
    {
        out<<static_cast<unsigned int>(OBJECT_TYPE)<<" "<<types_[a]->get_id()<<" "<<types_[a]->get_picture().first<<" ";
        out<<types_[a]->get_picture().second.x()<<" "<<types_[a]->get_picture().second.y()<<" "<<types_[a]->get_picture().second.width()<<" "<<types_[a]->get_picture().second.height()<<" ";
        out<<types_[a]->get_invincibility()<<" "<<types_[a]->get_size().width()<<" ";
        out<<types_[a]->get_size().height()<<" ";
        out<<static_cast<unsigned int>(types_[a]->get_kind())<<endl;
    }
    for(unsigned int a = 0; a < tiles_.size() ; a++)
    {
        out<<static_cast<unsigned int>(OBJECT)<<" ";
        out<<tiles_[a]->get_type()->get_id()<<" ";
        out<<tiles_[a]->get_rect().x()<<" "<<tiles_[a]->get_rect().y();
        out<<endl;
    }
}

void Map::save(QString filename)
{
    directory_ = filename;
    save();
}

void Map::createNew(QString filename)
{
    directory_ = filename;
    QFile file(directory_ + "/" + QDir(directory_).dirName() + ".shm");
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    out<<static_cast<unsigned int>(SIZE)<<" "<<size_.width() <<" "<<size_.height()<<endl;
    this->clear();
    types_.clear();
    types_.clear();
    background_ = QString(".\\images\\changeme.bmp");
    if(!background_image_.load(QString(".\\images\\changeme.bmp")))
    {
        QMessageBox::critical(0,tr("Warning"),tr("No object found"));
    }
}

void Map::changeBackground(QString background)
{
    QFile file(background);
    QFileInfo info(file);
    if (!info == directory_)
    {

    }
    if(!background_image_.load(background))
    {
        background_image_.load(background_);
    }
    else
    {
        background_ = background;

    }
}

void Map::changeSize()
{
    settings_ = new MapSettings(this , view_);
    settings_->show();
}

void Map::setCurrentType(CurrentType * init_type)
{
    current_type_ = init_type;
}

void Map::drawGrid()
{
    grid_image_ = grid_image_.scaled(size_);
    grid_image_.fill(Qt::transparent);
    QPainter painter (&grid_image_);
    painter.setPen(QPen(QBrush(Qt::gray,Qt::Dense5Pattern),1));
    //draw vertical lines
    for(int a = 0 ; a <= size_.width() / tile_size_.width() ; a++ )
    {
        painter.drawLine(tile_size_.width() * a, 0, tile_size_.width() * a, size_.height());
    }
    painter.setPen(QPen(QBrush(Qt::gray,Qt::Dense6Pattern),1));
    //draw horizontal lines
    for(int a = 0 ; a <= size_.height() / tile_size_.height() ; a++ )
    {
        painter.drawLine(0, tile_size_.height() * a, size_.width(), tile_size_.height() * a);
    }
}
