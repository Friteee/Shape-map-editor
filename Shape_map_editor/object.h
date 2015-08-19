#ifndef OBJECT_H
#define OBJECT_H

#include "objecttype.h"
#include <memory>
#include <QRect>
#include <QGraphicsPixmapItem>

class Object : public QGraphicsPixmapItem
{
public:
    Object(QGraphicsItem * parent = 0);

    QPoint get_rect();
    std::shared_ptr<ObjectType> get_type();
    void change_rect(QPoint init_point);
    void change_type(std::shared_ptr<ObjectType> init_type);

private:
    // type of this object
    std::shared_ptr<ObjectType> type;
    // coordinates and size of the object
    QPoint coordinates;
};

#endif // OBJECT_H
