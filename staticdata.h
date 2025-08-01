#ifndef STATICDATA_H
#define STATICDATA_H

#include "Micro.h"
#include "shape.h"
#include "rectangle.h"
#include <QVector>

class DrawWidget;

class StaticData
{
    friend DrawWidget;
public:
    static StaticData*GetStaticData();

private:
    StaticData();
    ~StaticData();

private:
    // static StaticData s_StaticData;
    QVector<Shape*>m_ShapeVec;

};

#endif // STATICDATA_H
