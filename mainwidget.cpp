#include "mainwidget.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QFont>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
//    初始化
    this->setFixedSize(560,380);
//    页面部件
    mainTitle = new QLabel(tr("商品销售系统"));
//    页面布局
    QStackedLayout *stackedLayout = new QStackedLayout();
//    局部布局
    selectWgt = new selectWidget(this);
    stackedLayout->addWidget(selectWgt);
//    总体布局
    QVBoxLayout *mainLayout = new QVBoxLayout();
//    部件设置
    mainTitle->setAlignment(Qt::AlignCenter);
    mainTitle->setFixedSize(560,50);
    QFont titleFont;
    titleFont.setPointSize(28);
    mainTitle->setFont(titleFont);
//    运行布局
    mainLayout->addWidget(mainTitle);
    mainLayout->addLayout(stackedLayout);
    this->setLayout(mainLayout);
//    信号与槽
}

MainWidget::~MainWidget()
{

}
