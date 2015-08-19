#include <QGraphicsScene>
#include <QMessageBox>
#include <QGraphicsItem>
#include "currenttype.h"
#include <iostream>

CurrentType::CurrentType()
{
    current_type = std::make_shared<ObjectType>();
    current_type->init(TILE,QSize(32,32),false);
}

void CurrentType::init_view(QGraphicsView * init_view)
{
    picture_of_object = init_view;
    image = new QGraphicsScene(picture_of_object);
    picture_of_object->setScene(image);
}

void CurrentType::init_picture(Picture init)
{
    std::shared_ptr<ObjectType> buffer_type = std::make_shared<ObjectType>(ObjectType());
    *buffer_type = *current_type;
    if(init.first.isNull())
    {
        return;
    }
    QPixmap buffer(init.first);
    buffer = buffer.copy(init.second);
    buffer = buffer.scaled(QSize(64,64));
    buffer_type->init_picture(init);
    current_type = buffer_type;
    image->addPixmap(buffer);
}

void CurrentType::change_invincibility(bool invincible)
{
    std::shared_ptr<ObjectType> buffer = std::make_shared<ObjectType>(ObjectType());
    *buffer = *current_type;
    buffer->init(buffer->get_kind(), buffer->get_size(), invincible);
    current_type = buffer;
}

void CurrentType::change_type(int type)
{
    std::shared_ptr<ObjectType> buffer = std::make_shared<ObjectType>(ObjectType());
    *buffer = *current_type;
    Object_kind kind;
    if(type == 1)
    {
        kind = PROP;
    }
    else if(type == 0)
    {
        kind = TILE;
    }
    buffer->init(kind, buffer->get_size(), buffer->get_invincibility());
    current_type = buffer;
}

void CurrentType::change_size(const QString size)
{
    std::shared_ptr<ObjectType> buffer = std::make_shared<ObjectType>(ObjectType());
    *buffer = *current_type;
    int size_int = size.toInt();
    buffer->init(buffer->get_kind(), QSize(size_int,size_int), buffer->get_invincibility());
    current_type = buffer;
}
