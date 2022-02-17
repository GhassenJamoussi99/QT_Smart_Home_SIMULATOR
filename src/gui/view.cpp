#include "view.h"
#include <QMouseEvent>
#include <QDebug>

view::view(QWidget *parent) : QGraphicsView(parent)
{}

void view::mousePressEvent(QMouseEvent *event)
{
    //qDebug() << "Mouse pressed in view at position (View Coord) : " << event->pos();

    QPointF scenePosition = mapToScene(event->pos());

    qDebug() << "Mouse pressed in view at position (Scene Coord) : " << scenePosition;

}
