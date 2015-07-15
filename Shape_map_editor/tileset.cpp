#include "tileset.h"

TileSet::TileSet(QGraphicsView * view)
{
    view->setScene(tileset_image_scene);
}

void TileSet::init_image(QString filename)
{
    tileset_image = new QPixmap(filename);
}

