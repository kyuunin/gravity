#include "header/canvas.h"
#include "header/game.h"

#include <iostream>
#include <QKeyEvent>

#define SPEED 10
#define ROT 1
#define ZOOM_IN 1.1
#define ZOOM_OUT 1/ZOOM_IN

bool w=0,a=0,s=0,d=0,q=0,e=0,p=0,m=0;
QTransform transform;

Canvas::Canvas(Game* game,QWidget *parent) : QWidget(parent)
{
    _game = game;
    transform = QTransform();
}

void Canvas::paintEvent(QPaintEvent* event){
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.fillRect(0,0,width(),height(),QColor(0,0,0));
    painter.setBrush(QBrush(Qt::yellow));
    painter.setPen(QPen(Qt::yellow));

    if(w) painter.translate(QPointF(0,SPEED));
    if(a) painter.translate(QPointF(SPEED,0));
    if(s) painter.translate(QPointF(0,-SPEED));
    if(d) painter.translate(QPointF(-SPEED,0));

    painter.translate(QPointF(width()/2,height()/2));

    if(m) painter.scale(ZOOM_OUT,ZOOM_OUT);
    if(p) painter.scale(ZOOM_IN,ZOOM_IN);
    if(q) painter.rotate(-ROT);
    if(e) painter.rotate(ROT);

    painter.translate(QPointF(-width()/2,-height()/2));

    painter.setTransform(transform,true);
    transform=painter.transform();


    for(size_t i =0; i<_game->n();i++){
        _game->shapes()[i].paint(painter);
    }
}

void setAction(int key, bool on = 1){

    switch (key) {
    case Qt::Key_W:
    case Qt::Key_Up:
        w=on;
        break;
    case Qt::Key_A:
    case Qt::Key_Left:
        a=on;
        break;
    case Qt::Key_S:
    case Qt::Key_Down:
        s=on;
        break;
    case Qt::Key_D:
    case Qt::Key_Right:
        d=on;
        break;
    case Qt::Key_Q:
        q=on;
        break;
    case Qt::Key_E:
        e=on;
        break;
    case Qt::Key_Plus:
        p=on;
        break;
    case Qt::Key_Minus:
        m=on;
        break;

    }
}

void Canvas::keyPressEvent(QKeyEvent * event){
    setAction(event->key(),1);
}
void Canvas::keyReleaseEvent(QKeyEvent * event){
    setAction(event->key(),0);
}
