#include "objecttype.h"

ObjectType::ObjectType(Object_kind init_kind, QSize init_size , bool is_invincible)
{
    kind = init_kind;
    size = init_size;
    invincible = is_invincible;
}

ObjectType::ObjectType()
{
    kind = PROP;
    size.setHeight(32);
    size.setWidth(32);
    invincible = false;
}

void ObjectType::init(Object_kind init_kind, QSize init_size , bool is_invincible)
{
    kind = init_kind;
    size = init_size;
    invincible = is_invincible;
}

bool ObjectType::operator==(const ObjectType & arg)
{
    bool returned = true;
    if(this->invincible != arg.invincible &&
            this->kind != arg.kind &&
            this->size != arg.size &&
            this->image.first != arg.image.first &&
            this->image.second == arg.image.second)
    {
        returned = false;
    }
    return returned;
}

void ObjectType::init_picture(Picture init_picture)
{
    image = init_picture;
}
