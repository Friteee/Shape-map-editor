#include "map.h"
#include <QFile>
#include <QTextStream>
#include <QGraphicsSceneDragDropEvent>
#include <QMessageBox>

Map::Map(QObject * parent):
    QGraphicsScene(parent)
{
    filename_ = "";
    if(!background_image_.load(QString(".\\images\\changeme.bmp")))
    {
        QMessageBox::critical(0,tr("Warning"),tr("No object found"));
    }
    size_.setHeight(5000);
    size_.setWidth(5000);
    this->setSceneRect(0, 0, size_.width(), size_.height());
}

Map::Map(QGraphicsView * init_view , QObject * parent)
    :QGraphicsScene(parent)
{
    view_ = init_view;
    view_->setScene(this);
    background_image_.load("images\\changeme.bmp");
    this->setSceneRect(0, 0, size_.width(), size_.height());
}

void Map::init(QGraphicsView * init_view)
{
    view_ = init_view;
    view_->setScene(this);
    this->setSceneRect(0,0,view_->width(),view_->height());
}

void Map::drawBackground(QPainter * painter, const QRectF & rect)
{
    painter->drawPixmap(static_cast<int>(rect.x()), static_cast<int>(rect.y()), view_->width(), view_->height(), background_image_ );
}

void Map::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    std::shared_ptr<ObjectType> current_object_type = current_type_->get_current_type();
    bool unique = true;
    for(auto a : types_)
    {
        if(*a == *current_object_type)
        {
            current_object_type = a;
            unique = false;
            break;
        }
    }
    if(unique)
    {
        types_.push_back(current_object_type);
    }
    Qt::MouseButtons buttons = mouseEvent->buttons();
    if(!buttons.testFlag(Qt::LeftButton) || current_object_type->get_picture().first.isNull())
    {
        QMessageBox::critical(view_,tr("Warning"),tr("Lol"));
        return;
    }
    std::shared_ptr<Object> buffer;
    QPixmap pixmap_buffer(current_object_type->get_picture().first);
    pixmap_buffer = pixmap_buffer.copy(current_object_type->get_picture().second);
    buffer->setPixmap(pixmap_buffer);
    QRect buffer_rect;
    QPointF object_point = mouseEvent->buttonDownScenePos(Qt::LeftButton);
    buffer_rect.setX(object_point.x());
    buffer_rect.setY(object_point.y());
    buffer_rect.setSize(current_object_type->get_size());
    buffer->change_rect(buffer_rect);
    buffer->change_type(current_object_type);
    tiles_.push_back(buffer);
    this->addItem(buffer.get());
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

void Map::setCurrentType(CurrentType * init_type)
{
    current_type_ = init_type;
}
