#ifndef TOOLBAR_H
#define TOOLBAR_H


#include "map.h"
#include <QAction>

class Map;

class ToolBar
{
public:
    ToolBar();
    ToolBar(Map * init_map , QAction * draw, QAction * move, QAction * erase, CurrentType *type);
    void init(Map * init_map , QAction * draw, QAction * move, QAction * erase, CurrentType *type);
    void actionTriggered(QAction * action);
    void mapPressed(QGraphicsSceneMouseEvent * mouseEvent);
    void mapMoved(QGraphicsSceneMouseEvent * mouseEvent);
    void mapReleased(QGraphicsSceneMouseEvent * mouseEvent);

private:
    void drawPressed(QGraphicsSceneMouseEvent * mouseEvent);
    void movePressed(QGraphicsSceneMouseEvent * mouseEvent);
    void erasePressed(QGraphicsSceneMouseEvent * mouseEvent);
    Map         *map_;
    CurrentType *current_type_;
    QAction     *current_action_;
    QAction     *draw_;
    QAction     *move_;
    QAction     *erase_;
};

#endif // TOOLBAR_H
