#ifndef TILETYPE_H
#define TILETYPE_H


enum Object
{
    TILE, PROP
};

class ObjectType
{
public:
    ObjectType();
private:
    Object type;
    int size;
    bool invincible;
    bool fixed;

};

#endif // TILETYPE_H
