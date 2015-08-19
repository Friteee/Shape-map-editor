#include "toolbar.h"
#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>
#include <iostream>

ToolBar::ToolBar()
{
    map_ = 0;
    draw_ = 0;
    erase_ = 0;
    move_ = 0;
}

ToolBar::ToolBar(Map * init_map , QAction * draw, QAction * move, QAction * erase, CurrentType *type)
{
    current_type_ = type;
    map_ = init_map;
    draw_ = draw;
    erase_ = erase;
    move_ = move;
    draw_->setChecked(true);
    current_action_ = draw_;
}

void ToolBar::init(Map * init_map , QAction * draw, QAction * move, QAction * erase, CurrentType *type)
{
    current_type_ = type;
    map_ = init_map;
    draw_ = draw;
    erase_ = erase;
    move_ = move;
    draw_->setChecked(true);
    current_action_ = draw_;
}

void ToolBar::actionTriggered(QAction * action)
{
    draw_->setChecked(false);
    move_->setChecked(false);
    erase_->setChecked(false);
    action->setChecked(true);
    current_action_ = action;
}

void ToolBar::mapPressed(QGraphicsSceneMouseEvent * mouseEvent)
{
    if(current_action_ == draw_)
    {
        this->drawPressed(mouseEvent);
    }
    else if(current_action_ == move_)
    {
        this->movePressed(mouseEvent);
    }
    else if(current_action_ == erase_)
    {
        this->erasePressed(mouseEvent);
    }
}

void ToolBar::mapReleased(QGraphicsSceneMouseEvent * mouseEvent)
{
    if(current_action_ == move_)
    {
        for(auto a : map_->getObjects())
        {
            a->setFlag(QGraphicsItem::ItemIsMovable,false);
        }
    }
}

void ToolBar::mapMoved(QGraphicsSceneMouseEvent * mouseEvent)
{
    if(current_action_ == draw_)
    {
        this->drawPressed(mouseEvent);
    }
}

void ToolBar::drawPressed(QGraphicsSceneMouseEvent * mouseEvent)
{
    if(current_type_->get_current_type()->get_picture().first.isNull())
    {
        return;
    }
    Qt::MouseButtons buttons = mouseEvent->buttons();
    if(!buttons.testFlag(Qt::LeftButton))
    {
        return;
    }
    std::shared_ptr<ObjectType> current_object_type = current_type_->get_current_type();
    bool unique = true;
    for(auto a : map_->getTypes())
    {
        if(a.unique())
            continue;
        if(*a == *current_object_type)
        {
            current_object_type = a;
            unique = false;
            break;
        }
    }
    if(unique)
    {
        map_->getTypes().push_back(current_object_type);
    }
    std::cout<< map_->getTypes().size() << " " << map_->getObjects().size()<<std::endl;
    std::shared_ptr<Object> buffer = std::make_shared<Object>();
    QPixmap pixmap_buffer(current_object_type->get_picture().first);
    pixmap_buffer = pixmap_buffer.copy(current_object_type->get_picture().second);
    buffer->setPixmap(pixmap_buffer);
    QRect buffer_rect;
    QPointF object_point = mouseEvent->scenePos();
    if(current_object_type->get_kind() == PROP)
    {
        object_point = mouseEvent->buttonDownScenePos(Qt::LeftButton);
        buffer_rect.setX(object_point.x());
        buffer_rect.setY(object_point.y());
        buffer_rect.setSize(current_object_type->get_size());
    }
    else if(current_object_type->get_kind() == TILE)
    {
        object_point = mouseEvent->scenePos();
        int x = static_cast<int>(object_point.x());
        int y = static_cast<int>(object_point.y());
        buffer_rect.setX(x - x % map_->getTileSize().width());
        buffer_rect.setY(y - y % map_->getTileSize().height());
        buffer_rect.setSize(current_object_type->get_size());
        for(unsigned int a = 0; a < map_->getObjects().size(); a++)
        {
            QPointF coordinates = map_->getObjects()[a]->get_rect();
            if(coordinates.x() == buffer_rect.x() && coordinates.y() == buffer_rect.y())
            {
                map_->removeItem(map_->getObjects()[a].get());
                map_->getObjects().erase(map_->getObjects().begin() + a);
            }
        }
    }
    buffer->setOffset(QPoint(buffer_rect.x(),buffer_rect.y()));
    buffer->change_type(current_object_type);
    buffer->change_rect(QPoint(buffer_rect.x(),buffer_rect.y()));
    map_->getObjects().push_back(buffer);
    map_->addItem(buffer.get());
}

void ToolBar::movePressed(QGraphicsSceneMouseEvent * mouseEvent)
{
    for(auto a : map_->getObjects())
    {
        a->setFlags(QGraphicsItem::ItemIsMovable);
    }
}

void ToolBar::erasePressed(QGraphicsSceneMouseEvent * mouseEvent)
{

}
