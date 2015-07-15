#ifndef TILESET_H
#define TILESET_H

#include <QGraphicsScene>
#include <QGraphicsView>

class TileSet
{
public:
    TileSet(QGraphicsView * view);
    void init_image(QString filename);
private:
    QGraphicsScene* tileset_image_scene;
    QPixmap* tileset_image;
};

#endif // TILESET_H
