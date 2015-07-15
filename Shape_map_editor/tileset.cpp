#include "tileset.h"
#include <QMessageBox>
#include <QString>

TileSet::TileSet(QGraphicsView * init_view)
{
    view = init_view;
    view->setScene(tileset_image_scene);
    margin = 0;
    size = 32;
}

void TileSet::init(QString filename , int init_margin , int init_size)
{
    tileset_image = new QPixmap(filename);
    if(tileset_image->isNull())
    {
        QMessageBox::critical(view, QObject::tr("Warning"), QObject::tr("Image is empty from this location: ") );
        return;
    }
    margin = init_margin;
    size = init_size;
}

