#include "header/shape.h"

#include <iostream>
#include <chrono>

Shape::Shape(Game* game,SqrtFourier& radius,size_t size)
{
    _game = game;
    _points = new QPointF[size];
    _size=size;
    _mass = radius.r()*radius.r();

/*
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::normal_distribution<double> normal (0,1);
    _speed = QPointF(normal(generator),normal(generator));
*/
    qreal step = 2*M_PI/size;
    qreal r;
    for(size_t i=0;i<size;i++){
        r=radius(step*i);
        _points[i]= QPointF(r*cos(step*i),r*sin(step*i));
    }
}

Shape::Shape(Game* game,qreal radius,size_t size)
{
    _game = game;
    _points = new QPointF[size];
    _size=size;
    _mass = radius*radius;

    qreal step = 2*M_PI/size;

    for(size_t i=0;i<size;i++){
        _points[i]= QPointF(radius*sin(step*i),radius*cos(step*i));
    }
}

Shape::Shape(Game* game,QPointF* points,size_t size)
{
    _game = game;
    _points = points;
    _size = size;
}
Shape::Shape()
{
}


void Shape::updateForce(){
   _force=QPointF(0,0);
    for(size_t i  = 0; i<_game->n();i++){
        if(this!=_game->shapes()+i){
            QPointF dif =_game->shapes()[i].off()-_off;
            qreal length_sq = QPointF::dotProduct(dif,dif);
            _force+=_game->shapes()[i].mass()/length_sq * dif/sqrt(length_sq);
        }
    }
}

void Shape::updatePos(){

    _speed+=_force;
    _off+=_speed;
}
 void Shape::paint(QPainter & painter){


     painter.save();
     painter.translate(_off);
     painter.rotate(_alpha);
     painter.drawPolygon(_points,_size);
     painter.restore();
 }

 void genCircle(QPointF a, QPointF b, QPointF c, QPointF& center, qreal& radius){
     QPointF delta_b = b-a;
     QPointF delta_c = c-a;
     QPointF delta_len(QPointF::dotProduct(b,b)-QPointF::dotProduct(a,a),QPointF::dotProduct(c,c)-QPointF::dotProduct(a,a));
     qreal idet=1/(delta_b.x()*delta_c.y()-delta_c.x()*delta_b.y())/2;
     center=QPointF(
                 idet*(delta_c.y()*delta_len.x()-delta_b.y()*delta_len.y()),
                 idet*(delta_b.x()*delta_len.y()-delta_c.x()*delta_len.x())

                 );
     auto tmp = center-a;
     radius = QPointF::dotProduct(tmp,tmp);

 }
/*
 int main(){
     QPointF center;
     qreal radius;
     genCircle(QPointF(1,1),QPointF(-1,1),QPointF(0,2),center,radius);
     std::cout<<radius<<":"<<center.x()<<"_"<<center.y()<<std::endl;
 }
*/
