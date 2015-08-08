#ifndef TILETYPE_H
#define TILETYPE_H

#include <utility>
#include <QString>
#include <QRect>

enum Object_kind
{
    TILE, PROP, FOREGROUND
};

typedef std::pair<QString , QRect> Picture;

class ObjectType
{
public:
    ObjectType(Object_kind init_kind, QSize init_size , bool init_invincible);
    ObjectType();
    void init(Object_kind init_kind, QSize init_size , bool init_invincible);
    void init_picture(Picture init_picture);
    bool operator==(const ObjectType & arg);
    inline Object_kind get_kind()
    {
        return kind;
    }
    inline QSize get_size()
    {
        return size;
    }
    inline bool get_invincibility()
    {
        return invincible;
    }
    inline unsigned int get_id()
    {
        return id;
    }
    inline const Picture& get_picture()
    {
        return image;
    }
    inline void set_id(unsigned int init_id)
    {
        id = init_id;
    }


private:

    //
    unsigned int id;
    // file and cropping rectangle of this tile type
    Picture image;
    //what kind of object is this
    Object_kind kind;
    //size x*x of the object
    QSize size;
    // if player can go through
    bool invincible;
};

#endif // TILETYPE_H
