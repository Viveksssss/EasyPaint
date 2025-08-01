#include "rectangle.h"

Rectangle::Rectangle():m_StartX(0)
,m_StartY(0)
,m_Height(0)
,m_Width(0)

{

}

Rectangle::Rectangle(const double &x, const double &y, const double &w, const double &h)
{
    this->m_StartX = x;
    this->m_StartY = y;
    this->m_Height = h;
    this->m_Width = w;
}

