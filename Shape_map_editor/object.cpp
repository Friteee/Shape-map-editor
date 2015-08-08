#include "object.h"

Object::Object()
{
    type = nullptr;
    coordinates.setX(0);
    coordinates.setY(0);
    coordinates.setWidth(0);
    coordinates.setHeight(0);
}

QRect Object::get_rect()
{
    return coordinates;
}

ObjectType * Object::get_type()
{
    return type;
}

void Object::change_rect(QRect init_rectangle)
{
    coordinates = init_rectangle;
}

void Object::change_type(ObjectType * init_type)
{
    type = init_type;
}
