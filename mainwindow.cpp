#include "mainwindow.h"
#include "drawwidget.h"
#include <QVBoxLayout>
#include <QPropertyAnimation>
#include <QDebug>
#include <QLabel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_MouseInArea(false)
    , m_LeftIsVisible(false)
    , m_IsDrawing(false)

{
    this->setMouseTracking(true);
    this->setAutoFillBackground(true);
    this->setStyleSheet("background-color:rgb(255, 182, 193);");
    init();
}

MainWindow::~MainWindow()
{

}

void MainWindow::init()
{
    initResource();
    initButton();
}

void MainWindow::initResource()
{
    m_ArrowLabel = new QLabel(this);
    m_LeftWidget = new QWidget(this);
    m_LeftWidget->setMouseTracking(true);
    m_LeftLayout = new QVBoxLayout(m_LeftWidget);
    m_RectangleBtn = new QToolButton(this);
    m_EllipserBtn= new QToolButton(this);
    m_TriangleBtn= new QToolButton(this);
    m_LineBtn= new QToolButton(this);
    m_TextBtn= new QToolButton(this);


    m_ResetBtn= new QToolButton(this);
    m_RotateLeftBtn= new QToolButton(this);
    m_RotateRightBtn= new QToolButton(this);
    m_ZoomInBtn= new QToolButton(this);
    m_ZoomOutBtn= new QToolButton(this);
    m_FrontBtn= new QToolButton(this);
    m_BackBtn= new QToolButton(this);

    m_DeleteBtn= new QToolButton(this);
    m_CloseBtn= new QToolButton(this);

    m_DrawWidget = new DrawWidget(this);
    animation = new QPropertyAnimation(this);

}

void MainWindow::initButton()
{
    m_ArrowLabel->setPixmap(QPixmap(":/icon/resources/arrow.png").scaled(30,30,Qt::KeepAspectRatio));
    m_ArrowLabel->setStyleSheet("background-color:transparent;");
    m_ArrowLabel->raise();


    // 形状工具组
    m_LeftLayout->setAlignment(Qt::AlignCenter);
    m_LeftLayout->setContentsMargins(3, 0, 0, 0);
    m_LeftWidget->setLayout(m_LeftLayout);
    m_LeftWidget->setTabletTracking(true);
    m_LeftLayout->addWidget(m_RectangleBtn);
    m_LeftLayout->addWidget(m_EllipserBtn);
    m_LeftLayout->addWidget(m_TriangleBtn);
    m_LeftLayout->addWidget(m_LineBtn);
    m_LeftLayout->addWidget(m_TextBtn);
    m_LeftWidget->setStyleSheet(R"(border-radius:5px;)");
    // 形状工具组
    m_RectangleBtn->setText(QStringLiteral("矩形"));
    m_RectangleBtn->setIcon(QIcon(":/icon/resources/rectangleBtn.png"));
    m_RectangleBtn->setIconSize(QSize(ICON_SIZE, ICON_SIZE));
    m_RectangleBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    m_RectangleBtn->setFixedSize(BTN_SIZE,BTN_SIZE);
    m_RectangleBtn->setStyleSheet(
                                  "QToolButton:hover{"
                                  "background-color:red;"
                                  "border-bottom: 2px solid #FF5722;"
                                  "}");

    m_EllipserBtn->setText(QStringLiteral("椭圆"));
    m_EllipserBtn->setIcon(QIcon(":/icon/resources/ellipseBtn.png"));
    m_EllipserBtn->setIconSize(QSize(ICON_SIZE, ICON_SIZE));
    m_EllipserBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    m_EllipserBtn->setFixedSize(BTN_SIZE,BTN_SIZE);

    m_TriangleBtn->setText(QStringLiteral("三角形"));
    m_TriangleBtn->setIcon(QIcon(":/icon/resources/triangleBtn.png"));
    m_TriangleBtn->setIconSize(QSize(ICON_SIZE, ICON_SIZE));
    m_TriangleBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    m_TriangleBtn->setFixedSize(BTN_SIZE,BTN_SIZE);

    m_LineBtn->setText(QStringLiteral("直线"));
    m_LineBtn->setIcon(QIcon(":/icon/resources/lineBtn.png"));
    m_LineBtn->setIconSize(QSize(ICON_SIZE, ICON_SIZE));
    m_LineBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    m_LineBtn->setFixedSize(BTN_SIZE,BTN_SIZE);

    m_TextBtn->setText(QStringLiteral("文本"));
    m_TextBtn->setIcon(QIcon(":/icon/resources/textBtn.png"));
    m_TextBtn->setIconSize(QSize(ICON_SIZE, ICON_SIZE));
    m_TextBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    m_TextBtn->setFixedSize(BTN_SIZE,BTN_SIZE);

    // 操作工具组
    m_ResetBtn->setText(QStringLiteral("重置"));
    m_ResetBtn->setIcon(QIcon(":/icon/resources/resetBtn.png"));
    m_ResetBtn->setIconSize(QSize(ICON_SIZE, ICON_SIZE));
    m_ResetBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    m_RotateLeftBtn->setText(QStringLiteral("左旋转"));
    m_RotateLeftBtn->setIcon(QIcon(":/icon/resources/rotateLeftBtn.png"));
    m_RotateLeftBtn->setIconSize(QSize(ICON_SIZE, ICON_SIZE));
    m_RotateLeftBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    m_RotateRightBtn->setText(QStringLiteral("右旋转"));
    m_RotateRightBtn->setIcon(QIcon(":/icon/resources/rotateRightBtn.png"));
    m_RotateRightBtn->setIconSize(QSize(ICON_SIZE, ICON_SIZE));
    m_RotateRightBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    m_ZoomInBtn->setText(QStringLiteral("放大"));
    m_ZoomInBtn->setIcon(QIcon(":/icon/resources/zoomInBtn.png"));
    m_ZoomInBtn->setIconSize(QSize(ICON_SIZE, ICON_SIZE));
    m_ZoomInBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    m_ZoomOutBtn->setText(QStringLiteral("缩小"));
    m_ZoomOutBtn->setIcon(QIcon(":/icon/resources/zoomOutBtn.png"));
    m_ZoomOutBtn->setIconSize(QSize(ICON_SIZE, ICON_SIZE));
    m_ZoomOutBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    // 层级工具组
    m_FrontBtn->setText(QStringLiteral("前置"));
    m_FrontBtn->setIcon(QIcon(":/icon/resources/frontBtn.png"));
    m_FrontBtn->setIconSize(QSize(ICON_SIZE, ICON_SIZE));
    m_FrontBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    m_BackBtn->setText(QStringLiteral("后置"));
    m_BackBtn->setIcon(QIcon(":/icon/resources/backBtn.png"));
    m_BackBtn->setIconSize(QSize(ICON_SIZE, ICON_SIZE));
    m_BackBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    // 删除按钮
    m_DeleteBtn->setText(QStringLiteral("删除"));
    m_DeleteBtn->setIcon(QIcon(":/icon/resources/deleteBtn.png"));
    m_DeleteBtn->setIconSize(QSize(ICON_SIZE, ICON_SIZE));
    m_DeleteBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    m_CloseBtn->setIcon(QIcon(":/icon/resources/closeBtn.png"));
    m_CloseBtn->setIconSize(QSize(20, 20));


    QFont font = m_RotateLeftBtn->font();
    font.setPointSize(8);  // 设置字体大小为 8 磅
    m_RotateLeftBtn->setFont(font);
    m_RotateRightBtn->setFont(font);
    m_TriangleBtn->setFont(font);

    int i = 1;
    for(QToolButton*p :m_LeftWidget->findChildren<QToolButton*>()){
        connect(p,&QToolButton::clicked,this,[this,i](){
            m_DrawWidget->setShapeType(static_cast<ShapeType>(i));
        });
        i++;
    }


    connect(m_CloseBtn,&QToolButton::clicked,[this](){
        close();
    });
}

void MainWindow::resizeEvent(QResizeEvent *event)
{

    /*
        m_RectangleBtn->setGeometry(0, BTN_SIZE * 1, BTN_SIZE, BTN_SIZE);
        m_EllipserBtn->setGeometry(0, BTN_SIZE * 2, BTN_SIZE, BTN_SIZE);
        m_TriangleBtn->setGeometry(0, BTN_SIZE * 3, BTN_SIZE, BTN_SIZE);
        m_LineBtn->setGeometry(0, BTN_SIZE * 4, BTN_SIZE, BTN_SIZE);
        m_TextBtn->setGeometry(0, BTN_SIZE * 5, BTN_SIZE, BTN_SIZE);
    */
    m_ArrowLabel->setGeometry(0,BTN_SIZE+20,m_ArrowLabel->sizeHint().width(),m_ArrowLabel->sizeHint().height());
    m_LeftWidget->setGeometry(0 - BTN_SIZE ,BTN_SIZE + 2,m_LeftWidget->sizeHint().width(),m_LeftWidget->sizeHint().height());
    m_LeftWidget->raise();
    // 操作工具按钮
    m_ResetBtn->setGeometry(0, 0, BTN_SIZE, BTN_SIZE);
    m_RotateLeftBtn->setGeometry(BTN_SIZE*1, 0, BTN_SIZE, BTN_SIZE);
    m_RotateRightBtn->setGeometry(BTN_SIZE*2,  0, BTN_SIZE, BTN_SIZE);
    m_ZoomInBtn->setGeometry(BTN_SIZE*3,  0, BTN_SIZE, BTN_SIZE);
    m_ZoomOutBtn->setGeometry(BTN_SIZE*4,  0, BTN_SIZE, BTN_SIZE);
    m_FrontBtn->setGeometry(BTN_SIZE*5,  0, BTN_SIZE, BTN_SIZE);
    m_BackBtn->setGeometry(BTN_SIZE*6,  0, BTN_SIZE, BTN_SIZE);

    // 删除按钮
    m_DeleteBtn->setGeometry(BTN_SIZE*7, 0, BTN_SIZE, BTN_SIZE);
    m_CloseBtn->setGeometry(this->width()-BTN_SIZE,0,BTN_SIZE,BTN_SIZE);

    m_DrawWidget->setGeometry(5,BTN_SIZE+5,width()-10,height()-10-BTN_SIZE);    
    QWidget::resizeEvent(event);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    // if(!m_IsDrawing){
    //     m_DrawWidget->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    // }else setAttribute(Qt::WA_TransparentForMouseEvents, false);

    m_MouseInArea =  event->pos().x()<=50 && event->pos().y()>=m_ArrowLabel->pos().y()&&event->pos().y() <= m_ArrowLabel->pos().y()+30;
    if(m_MouseInArea == true && m_LeftIsVisible == true){
        QWidget::mouseMoveEvent(event);
        return;
    }else if(m_MouseInArea == false && m_LeftIsVisible == false){
        QWidget::mouseMoveEvent(event);;
        return;
    }

    if(m_MouseInArea == true && m_LeftIsVisible == false){
        animation->stop();
        animation->setTargetObject(m_LeftWidget);
        animation->setPropertyName("pos");
        animation->setDuration(300);
        animation->setStartValue(QPoint(0-BTN_SIZE,BTN_SIZE + 2));
        animation->setEndValue(QPoint(0,BTN_SIZE + 2));
        animation->start();
        m_LeftIsVisible = true;
        qDebug() << m_LeftWidget->pos().x()<< "\t" << m_LeftWidget->pos().y();
        m_ArrowLabel->move(QPoint(0-30,BTN_SIZE+20));
    }else if(m_MouseInArea == false && m_LeftIsVisible == true&&!m_LeftWidget->geometry().contains(event->x(),event->y())){
        animation->stop();
        animation->setTargetObject(m_LeftWidget);
        animation->setPropertyName("pos");
        animation->setDuration(300);
        animation->setStartValue(QPoint(0,BTN_SIZE + 2));
        animation->setEndValue(QPoint(0-BTN_SIZE,BTN_SIZE + 2));
        animation->start();
        m_LeftIsVisible = false;
        qDebug() << m_LeftWidget->pos().x()<< "\t" << m_LeftWidget->pos().y();
        m_ArrowLabel->move(QPoint(0,BTN_SIZE+20));
    }

    QWidget::mouseMoveEvent(event);
}

