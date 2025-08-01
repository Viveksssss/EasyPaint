#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QPen>
#include <QFont>
#include <QBrush>
#include <QOpenGLWidget>
#include <QWidget>
#include <QMouseEvent>
#include "staticdata.h"
#include "shape.h"


class DrawWidget : public QOpenGLWidget
{
public:
    DrawWidget(QWidget*parent = nullptr);
    ~DrawWidget();
private:
    StaticData*m_pStaticData;

    QFont m_Font;
    QPen m_Pen;
    QBrush m_Brush;

    bool m_BtnClicked;
    ShapeType m_ShapeType;

    QPoint m_MovePoint;
    QPoint m_ClickPoint;

public:
    inline void setShapeType(const ShapeType&shape){m_ShapeType = shape;}

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent*event)override;
    void resizeEvent(QResizeEvent*event)override;
    void mouseMoveEvent(QMouseEvent*event)override;
};

#endif // DRAWWIDGET_H
