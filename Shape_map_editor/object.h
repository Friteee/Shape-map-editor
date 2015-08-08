#ifndef OBJECT_H
#define OBJECT_H

#include "objecttype.h"
#include <QRect>

class Object
{
public:
    Object();

    QRect get_rect();
    ObjectType * get_type();
    void change_rect(QRect init_rectangle);
    void change_type(ObjectType * init_type);

private:
    //type of this object
    ObjectType * type;
    // coordinates and size of the object
    QRect coordinates;
};

#endif // OBJECT_H
