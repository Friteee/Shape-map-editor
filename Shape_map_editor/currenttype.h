#ifndef CURRENTTYPE_H
#define CURRENTTYPE_H

#include <QRect>
#include <QGraphicsView>
#include <memory>
#include <utility>
#include "objecttype.h"

typedef std::pair<QString , QRect> Picture;

class CurrentType
{
public:
    CurrentType();
    void init_view(QGraphicsView * view);
    void init_picture(Picture init);
    void change_invincibility(bool invincible);
    void change_type(int type);
    void change_size(const QString size);
    inline std::shared_ptr<ObjectType> get_current_type()
    {
        return current_type;
    }

private:
    std::shared_ptr<ObjectType> current_type;
    QGraphicsView * picture_of_object;
    QGraphicsScene * image;


};

#endif // CURRENTTYPE_H
