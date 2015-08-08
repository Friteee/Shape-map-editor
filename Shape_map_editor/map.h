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

enum MapChunkId
{
    OBJECT , OBJECT_TYPE , BACKGROUND , SIZE
};

class MapSettings;

class Map : public QGraphicsScene
{
public:
    Map(QObject * parent = 0);
    Map( QGraphicsView * view , QObject * parent = 0);
    void init(QGraphicsView * view);
    void open(QString filename);
    void save();
    void save(QString filename);
    void createNew(QString filename);
    void changeSize();
    void changeBackground(QString backgrounds);
    void setCurrentType(CurrentType * init_type);
    void drawBackground(QPainter * painter, const QRectF & rect)override;
    inline std::vector<std::shared_ptr<ObjectType>> & get_types()
    {
        return types_;
    }
public slots:

    void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);

private:
    CurrentType *                            current_type_;
    std::vector<std::shared_ptr<Object>>     tiles_;
    std::vector<std::shared_ptr<ObjectType>> types_;
    QGraphicsView *                          view_;
    MapSettings *                            settings_;
    QSize                                    size_;
    QString                                  background_;
    QPixmap                                  background_image_;
    QString                                  filename_;
};

#endif // MAP_H
