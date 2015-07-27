#include "tileset.h"
#include <QMessageBox>
#include <QString>

TileSet::TileSet(QWidget * parent):
    QGraphicsView(parent)
{
    tileset_image_scene = new QGraphicsScene(this);
    rectangle = 0;
    this->setScene(tileset_image_scene);
    margin = 0;
    size = 32;
}

void TileSet::draw_grid()
{
    unsigned int buffer = margin + size;
    //draw vertical lines
    for(unsigned a = 0 ; a <= tileset_image->width() / buffer ; a++ )
    {
        tileset_image_scene->addLine(buffer * a, 0, buffer * a, tileset_image->height(), QPen(QBrush(Qt::black),margin));
    }
    //draw horizontal lines
    for(unsigned a = 0 ; a <= tileset_image->height() / buffer ; a++ )
    {
        tileset_image_scene->addLine(0, buffer * a, tileset_image->width(), buffer * a, QPen(QBrush(Qt::black),margin));
    }
}

void TileSet::init(QString filename , int init_margin , int init_size)
{
    tileset_image = new QPixmap(filename);
    if(tileset_image->isNull())
    {
        QMessageBox::critical(this, QObject::tr("Warning"), QObject::tr("Image is empty from this location: ") );
        return;
    }
    margin = init_margin;
    size = init_size;
    tileset_image_scene->addPixmap(*tileset_image);
    draw_grid();
}

void TileSet::mousePressEvent(QMouseEvent * e)
{
    if(rectangle != 0)
    {
        tileset_image_scene->removeItem(rectangle);
    }
    QPointF point_f = mapToScene(e->pos());
    QPoint point;
    point.setX(static_cast<int>(point_f.x()));
    point.setY(static_cast<int>(point_f.y()));
    point.setX(point.x() - point.x() % (margin + size) + margin / 2 - 1);
    point.setY(point.y() - point.y() % (margin + size) + margin / 2 - 1);
    rectangle = tileset_image_scene->addRect(point.x() , point.y() , qreal(size) + 1 , qreal(size) + 1, QPen(), QBrush(QColor(255, 255, 255, 128)));

}
