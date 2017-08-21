#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include "shape.h"
#include "game.h"
class Game;

// The Game will be drawn on the Canvas

class Canvas : public QWidget
{
    Q_OBJECT
public:

    // Constructor
    explicit Canvas(Game*,QWidget *parent = 0);

protected:

    // Listen for Events
    void paintEvent(QPaintEvent*) override;
    void keyPressEvent(QKeyEvent *)override;
    void keyReleaseEvent(QKeyEvent *)override;

private:

    // A Pointer to the Game Object
    // This has the same life cycle than the Program
    Game* _game;

signals:

public slots:

};

#endif // CANVAS_H
