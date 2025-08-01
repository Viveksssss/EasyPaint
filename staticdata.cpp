#include "staticdata.h"
#include "drawwidget.h"


StaticData *StaticData::GetStaticData()
{
    static StaticData s_StaticData;
    return &s_StaticData;
}

StaticData::StaticData()
{

}

StaticData::~StaticData()
{
    qDeleteAll<QVector<Shape*>>(m_ShapeVec);
    m_ShapeVec.clear();
    m_ShapeVec.shrink_to_fit();
}
