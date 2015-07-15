#ifndef TILESET_H
#define TILESET_H

#include <QGraphicsScene>
#include <QGraphicsView>

class TileSet
{
public:
    TileSet(QGraphicsView * init_view);
    void init(QString filename , int margin, int size);
private:
    QGraphicsScene* tileset_image_scene;
    QPixmap* tileset_image;
    QGraphicsView * view;
    int margin;
    int size;
};

#endif // TILESET_H
