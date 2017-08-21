#include "header/sqrtfourier.h"
#include <math.h>
#include <random>
#include <chrono>

SqrtFourier::SqrtFourier(qreal r,QPointF* coeff,size_t n)
{
    _r=r;
    _coeff = coeff;
    _n = n;
}

SqrtFourier::SqrtFourier(qreal r, size_t n, unsigned seed)
{
    _r=r;
    _n=n;
    _coeff = new QPointF[n];

    if(seed == 0)
        seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::uniform_real_distribution<double> uniform (0, 2 * M_PI);
    std::normal_distribution<double> normal (0,r/2);
    for (size_t i = 0; i < n; ++i) {
        _coeff[i] = QPointF(normal(generator)/(i+1),uniform(generator));
    }

}

qreal SqrtFourier::operator()(qreal alpha) const{
    qreal res = _r*sqrt(_r);
    for(size_t i = 0; i<_n;i++){
        res += _coeff[i].x()*sin((i+1)*(alpha+_coeff[i].y()));
    }
    if(res < 0){
        return 0.0;
    }
    return sqrt(sqrt(_r)*res);
}
