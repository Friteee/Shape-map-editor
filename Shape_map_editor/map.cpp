#include "map.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

Map::Map(QObject * parent):
    QGraphicsScene(parent)
{
    filename_ = "";
    if(!background_image_.load(QString(".\\images\\changeme.bmp")))
    {
        QMessageBox::critical(0,tr("Warning"),tr("No object found"));
    }
    size_.setHeight(1800);
    size_.setWidth(1800);
}

Map::Map(QGraphicsView * init_view , QObject * parent)
    :QGraphicsScene(parent)
{
    view_ = init_view;
    view_->setScene(this);
    this->setSceneRect(0,0,view_->width(),view_->height());
    background_image_.load("images\\changeme.bmp");
}

void Map::init(QGraphicsView * init_view)
{
    view_ = init_view;
    view_->setScene(this);
    this->setSceneRect(0,0,view_->width(),view_->height());
}

void Map::drawBackground(QPainter * painter, const QRectF & rect)
{
    painter->drawPixmap(0, 0, view_->width(), view_->height(), background_image_ );
}

void Map::open(QString filename)
{
    filename_ = filename;
    QFile file(filename_);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    unsigned int chunk_id;
    while(!in.atEnd())
    {
        in>>chunk_id;
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
            types_.push_back(pointer_type);

        }
        else if (id_buffer == OBJECT)
        {

        }
        else if (id_buffer == BACKGROUND)
        {
            QString background;
            in >> background;
            changeBackground(background);
        }
    }
}

void Map::save()
{
    QFile file(filename_);
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    out<<static_cast<unsigned int>(SIZE)<<" "<<size_.width() <<" "<<size_.height()<<endl;
    out<<static_cast<unsigned int>(BACKGROUND)<<" "<<background_<<endl;
}

void Map::save(QString filename)
{
    filename_ = filename;
    save();
}

void Map::createNew(QString filename)
{
    filename_ = filename;
    QFile file(filename_);
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    out<<static_cast<unsigned int>(SIZE)<<" "<<size_.width() <<" "<<size_.height()<<endl;
}

void Map::changeBackground(QString background)
{
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
