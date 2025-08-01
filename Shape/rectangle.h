#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include <QColor>
#include "Micro.h"

class Rectangle : public Shape
{
public:
    Rectangle(const double&x,const double&y,const double&w,const double&h);
    Rectangle();
    ~Rectangle() = default;
public:
    inline void setStartX(const double&x);
    inline void setStartY(const double&y);
    inline void setWidth(const double&w);
    inline void setHeight(const double&w);
    inline const double& getStartX(){return m_StartX;}
    inline const double& getStartY(){return m_StartY;}
    inline const double& getWidth(){return m_Width;}
    inline const double& getHeight(){return m_Height;}
private:
    double m_StartX;
    double m_StartY;
    double m_Width;
    double m_Height;
    QColor m_Color;
};

#endif // RECTANGLE_H
