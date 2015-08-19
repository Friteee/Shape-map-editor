#include "object.h"

Object::Object(QGraphicsItem * parent ):
    QGraphicsPixmapItem (parent)
{
    type = nullptr;
    coordinates.setX(0);
    coordinates.setY(0);
}

QPoint Object::get_rect()
{
    return coordinates;
}

std::shared_ptr<ObjectType> Object::get_type()
{
    return type;
}

void Object::change_rect(QPoint init_point)
{
    coordinates = init_point;
}

void Object::change_type(std::shared_ptr<ObjectType> init_type)
{
    type = init_type;
}
