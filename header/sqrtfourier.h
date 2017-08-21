#ifndef SQRTFOURIER_H
#define SQRTFOURIER_H

#include <QObject>
#include <QPointF>

class SqrtFourier{
public:

    // Constructor 

    // Create a new Square Rooted Fourier Series from given Coefficients
    explicit SqrtFourier(qreal,QPointF*,size_t);

    // Create a random Square Rooted Fourier Series with given Seed
    explicit SqrtFourier(qreal,size_t,unsigned seed=0);

    // Returns the Value at given point
    qreal operator()(qreal) const;

    // Returns the number of Coefficients
    inline size_t n()const{return _n;}

    // Returns the Coefficients
    inline QPointF* coeff() const{return _coeff;}

    // Returns the Radius
    inline qreal r() const{return _r;}

private:
    qreal _r;
    QPointF* _coeff;
    size_t _n ;

};

#endif // SQRTFOURIER_H
