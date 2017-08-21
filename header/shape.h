#ifndef SHAPE_H
#define SHAPE_H

#include <QObject>
#include <QPainter>
#include "sqrtfourier.h"
#include "game.h"
class Game;

class Shape
{
public:

    // Constructor 
    
    // Create a new Shape from a Square Rooted Fourier Series
    explicit Shape(Game*,SqrtFourier&,size_t);
    
    // Create a new Shape with const Radius
    explicit Shape(Game*,qreal,size_t);

    // Create a new Shape from Point Array
    explicit Shape(Game*,QPointF*,size_t);

    // Default Constructor
    explicit Shape();

    // Returns the Offset (Position) of the Shape
    inline QPointF& off(){return _off;}

    // Returns the Speed of the Shape
    inline QPointF& speed(){return _speed;}

    // Returns the Orientation of the Shape
    inline qreal& alpha(){return _alpha;}

    inline qreal mass()const{return _mass;}

    // Returns the size of the Point Array
    inline size_t size()const{return _size;}

    // Returns the Pointer of the Point Array
    inline operator QPointF*()const{return _points;}

    // Updates the Forces on the Shape
    void updateForce();

    // Updates the Position of the Shape
    void updatePos();

    // Draws the shape on a Canvas
    void paint(QPainter&);

private:

    // A Pointer to the Game Object
    // This has the same life cycle than the Program
    Game* _game;

    // The Pointer of the Point Array 
    QPointF* _points;

    // The size of the Point Array
    size_t _size;

    // The Mass of the Shape
    qreal _mass;

    // The Offset of the Shape
    QPointF _off;

    // The Speed of the Shape
    QPointF _speed;

    // The Forces on the Shape
    QPointF _force;

    // The Orientation of the Shape
    qreal _alpha;
};

#endif // SHAPE_H
