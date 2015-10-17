#ifndef MAP_H
#define MAP_H

#include <vector>
#include <memory>
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include "currenttype.h"
#include "objecttype.h"
#include "mapsettings.h"
#include "object.h"
#include "toolbar.h"

enum MapChunkId
{
    OBJECT , OBJECT_TYPE , BACKGROUND , SIZE
};

class ToolBar;

class MapSettings;

class Map : public QGraphicsScene
{
public:
    Map(QObject * parent = 0);
    Map( QGraphicsView * view , QObject * parent = 0);
    void init(QGraphicsView * view, ToolBar * toolbar);
    void open(QString filename);
    void save();
    void save(QString filename);
    void createNew(QString filename);
    void changeSize();
    void changeBackground(QString backgrounds);
    void setCurrentType(CurrentType * init_type);
    void drawGrid();
    void drawBackground(QPainter * painter, const QRectF & rect)override;
    inline std::vector<std::shared_ptr<ObjectType>> & getTypes()
    {
        return types_;
    }
    inline std::vector<std::shared_ptr<Object>> & getObjects()
    {
        return tiles_;
    }
    inline QSize getSize()
    {
        return size_;
    }
    inline QSize getTileSize()
    {
        return tile_size_;
    }

protected:

    void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);

private:
    CurrentType *                            current_type_;
    std::vector<std::shared_ptr<Object>>     tiles_;
    std::vector<std::shared_ptr<ObjectType>> types_;
    QGraphicsView *                          view_;
    MapSettings *                            settings_;
    QSize                                    size_;
    QSize                                    tile_size_;
    QPixmap                                  grid_image_;
    QString                                  background_;
    QPixmap                                  background_image_;
    QString                                  directory_;
    ToolBar *                                toolbar_;

    friend class MapSettings;
};

#endif // MAP_H
