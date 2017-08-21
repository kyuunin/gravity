#include "header/game.h"
#include "header/canvas.h"
#include "header/shape.h"
#include <QTimer>
#include <QApplication>
#include <QPointF>

#include <iostream>

#define N 3
#define M 20
#define K 360
#define S 200.

#define X (5000*(i+1))
#define Y 0

Game::~Game(){
    std::cout<<"bye"<<std::endl;
}

Game::Game(QObject *parent) : QObject(parent)
{
    std::cout<<"init Shape Array"<<std::endl;
    _n=N;
    _shapes = new Shape[N];

    SqrtFourier f(1000,4*M);
    _shapes[0]=Shape(this,f,2*K);
    _shapes[0].off()=QPointF(0,0);
    _shapes[0].speed()=QPointF(0,0);
    auto mass = _shapes[0].mass();

    for(size_t i = 1; i<N ; i++){
        SqrtFourier f(S,M);
        _shapes[i]=Shape(this,f,K);
        QPointF pos = QPointF(X,Y);
        _shapes[i].off()=pos;
        auto tmp = QPointF::dotProduct(pos,pos);
        std::cout<<mass/sqrt(tmp)<<std::endl;

        _shapes[i].speed()=sqrt(mass/sqrt(tmp))*QPointF(0,1);
    }

    std::cout<<"init Canvas"<<std::endl;
    Canvas* c = new Canvas(this);

    std::cout<<"init Timer"<<std::endl;
    QTimer* t = new QTimer(c);
    t->setInterval(5);

    std::cout<<"connect Event"<<std::endl;
    std::cout<<Q_FUNC_INFO<<std::endl;
    std::cout<<QTimer::staticMetaObject.className()<<std::endl;
    QObject::connect(t,SIGNAL(timeout()),c,SLOT(update()));

    QObject::connect(t,SIGNAL(timeout()),this,SLOT(update()));


    std::cout<<"start Timer"<<std::endl;
    t->start();

    std::cout<<"start Game"<<std::endl;
    c->show();
}

int main(int argc,char **argv){
    std::cout<<"init App"<<std::endl;
    QApplication app(argc,argv);
    std::cout<<"create Game"<<std::endl;
    new Game();
    std::cout<<"starting App"<<std::endl;
    return app.exec();
}

void Game::update(){

    for (size_t i = 0; i<_n; ++i){
        _shapes[i].updateForce();
    }

    for (size_t i = 0; i<_n; ++i){
        _shapes[i].updatePos();
    }

    //Collision Check
}
