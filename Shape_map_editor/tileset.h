#ifndef TILESET_H
#define TILESET_H

#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include "currenttype.h"
#include <utility>

class TileSet : public QGraphicsView
{
public:

    TileSet(QWidget * parent = 0);
    void init(QString init_filename , int init_margin, int init_size);
    void registerMousePress(CurrentType * init_type);

signals:
public slots:
    void mousePressEvent(QMouseEvent * e);
private:
    void draw_grid();
    QGraphicsScene* tileset_image_scene;
    QPixmap* tileset_image;
    QGraphicsRectItem* rectangle;
    QString filename;
    CurrentType * type;
    int margin;
    int size;
};

#endif // TILESET_H
