#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "shape.h"
#include "canvas.h"
#include <QTimer>
class Shape;
class Canvas;

// This Object has all important Information of the Game
class Game : public QObject
{
    Q_OBJECT
public:

    // Constructor
    explicit Game(QObject *parent = 0);

    // Destructor
    ~Game() override;

    // Returns the pointer of the Shape Array
    inline Shape* shapes() const{return _shapes;}

    // Returns the size of the Shape Array 
    inline size_t n() const{return _n;}

private:

    // The pointer of the Shape Array
    Shape* _shapes;

    // The size of the Shape Array
    size_t _n;

signals:

public slots:
    // This slot tells the Game to Update
    void update();
};

#endif // GAME_H
