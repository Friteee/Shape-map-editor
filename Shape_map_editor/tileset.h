#ifndef TILESET_H
#define TILESET_H

#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

class TileSet : public QGraphicsView
{
public:

    TileSet(QWidget * parent = 0);
    void init(QString filename , int margin, int size);

signals:
public slots:
    void mousePressEvent(QMouseEvent * e);
private:
    void draw_grid();
    QGraphicsScene* tileset_image_scene;
    QPixmap* tileset_image;
    QGraphicsRectItem* rectangle;
    int margin;
    int size;
};

#endif // TILESET_H
