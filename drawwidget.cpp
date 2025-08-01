#include "drawwidget.h"
#include <QPainter>
#include <QDebug>
DrawWidget::DrawWidget(QWidget *parent)
:QOpenGLWidget(parent)
{

    setMouseTracking(true);

    m_pStaticData = StaticData::GetStaticData();

    m_Pen.setColor(QColor(DEFAULT_SHAPE_COLOR));
    m_Font.setFamily(QStringLiteral("楷体"));
    // m_Brush.setStyle(Qt::BrushStyle::SolidPattern);
    m_Brush.setStyle(Qt::BrushStyle::NoBrush);

    m_BtnClicked = false;
    m_ShapeType = ShapeType::SHAPE_UNKNOW;

    m_MovePoint = {0,0};
    m_ClickPoint = {0,0};
}

DrawWidget::~DrawWidget()
{

}

void DrawWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        m_BtnClicked = true;
        m_ClickPoint = event->pos();
    }
    QOpenGLWidget::mousePressEvent(event);
}

void DrawWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        m_BtnClicked = false;
        m_MovePoint = event->pos();
        switch(m_ShapeType){
            case ShapeType::SHAPE_RECTANGLE:{
                int x1 = std::min( m_ClickPoint.x() , m_MovePoint.x() );
                int y1 = std::min( m_ClickPoint.y() , m_MovePoint.y() );
                QPoint dis = m_MovePoint - m_ClickPoint;
                Rectangle *rec= new Rectangle(double(x1),double(y1),qAbs(double(dis.x())),qAbs(double(dis.y())));
                rec->setShapeType(ShapeType::SHAPE_RECTANGLE);
                m_pStaticData->m_ShapeVec.push_back(rec);
                update();
                break;
            }
            case ShapeType::SHAPE_ELLIPSE:{

            }
            case ShapeType::SHAPE_TRIANGLE:{

            }
            case ShapeType::SHAPE_LINE:{

            }
            case ShapeType::SHAPE_TEXT:{

            }
            default:{

                break;
            }
        }
    }
    QOpenGLWidget::mouseReleaseEvent(event);
}

void DrawWidget::paintEvent(QPaintEvent *event)
{
    QOpenGLWidget::paintEvent(event);
    glClearColor(255,255,255,0);

    QPainter painter(this);
    painter.setFont(m_Font);
    painter.setBrush(m_Brush);
    painter.setPen(m_Pen);

    // int dataSize = m_pStaticData->m_ShapeVec.size();
    // for(int i = 0;i<dataSize;++i){
    //     Shape*m_Shape = m_pStaticData->m_ShapeVec.at(i);
    //     switch(m_Shape->getShapeType()){
    //         case ShapeType::SHAPE_RECTANGLE:{
    //             Rectangle*rec = static_cast<Rectangle*>(m_Shape);
    //             painter.drawRect(QRectF(rec->getStartX(),rec->getStartY(),rec->getWidth(),rec->getHeight()));
    //             break;
    //         }
    //         case ShapeType::SHAPE_ELLIPSE:{

    //         }
    //         case ShapeType::SHAPE_TRIANGLE:{

    //         }
    //         case ShapeType::SHAPE_LINE:{

    //         }
    //         case ShapeType::SHAPE_TEXT:{

    //         }
    //         default:{
    //             break;
    //         }
    //     }
    // }
    qDebug() << m_pStaticData->m_ShapeVec.size();
    for (auto* shape : m_pStaticData->m_ShapeVec) {
        // 先做安全类型检查
        if (!shape) continue;

        switch(shape->getShapeType()) {
            case ShapeType::SHAPE_RECTANGLE: {
                if (auto* rect = dynamic_cast<Rectangle*>(shape)) {
                    painter.drawRect(QRectF(
                        rect->getStartX(),
                        rect->getStartY(),
                        rect->getWidth(),
                        rect->getHeight()
                    ));
                }
                break;
            }
            // 其他case...
            default:
                qWarning() << "Unhandled shape type or type mismatch";
                break;
        }
    }
        switch(m_ShapeType){
            case ShapeType::SHAPE_RECTANGLE:{
                painter.drawRect(QRect(m_ClickPoint,m_MovePoint));
                break;
            }
            case ShapeType::SHAPE_ELLIPSE:{

            }
            case ShapeType::SHAPE_TRIANGLE:{

            }
            case ShapeType::SHAPE_LINE:{

            }
            case ShapeType::SHAPE_TEXT:{

            }
            default:{
                break;
            }
        }
}

void DrawWidget::resizeEvent(QResizeEvent *event)
{
    QOpenGLWidget::resizeEvent(event);
}


void DrawWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(m_BtnClicked == true){
        m_MovePoint = event->pos();
        update();
    }
    QOpenGLWidget::mouseMoveEvent(event);
}
