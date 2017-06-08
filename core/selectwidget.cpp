#include "selectwidget.h"
#include <QRadioButton>
#include <QPushButton>
#include <QSpacerItem>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <QFont>
#include <QApplication>
//#include <QDebug>

selectWidget::selectWidget(QWidget *parent) : QWidget(parent)
{
//    初始化
    this->resize(560,330);
    this->setAttribute(Qt::WA_QuitOnClose,true);
//    页面部件
    buyBtn = new QRadioButton(tr("采购商品信息"));
    sellBtn = new QRadioButton(tr("销售商品信息"));
    addBtn = new QRadioButton(tr("添加新品信息"));
    infoBtn = new QRadioButton(tr("查看商品信息"));
    buyRecordBtn = new QRadioButton(tr("查看采购记录"));
    sellRecordBtn = new QRadioButton(tr("查看销售记录"));
    Vspacer = new QSpacerItem(20,110);
    Hspacer = new QSpacerItem(420,20);
    nextBtn = new QPushButton(tr("下一步"));
    exitBtn = new QPushButton(tr("退出"));
//    页面布局
    radioBtnGroup = new QButtonGroup();
    QVBoxLayout *radioBtnLayout = new QVBoxLayout();
    QHBoxLayout *pushbtnLayout = new QHBoxLayout();
//    局部布局
    radioBtnLayout->setAlignment(Qt::AlignCenter);
    radioBtnLayout->addWidget(buyBtn);
    radioBtnLayout->addWidget(sellBtn);
    radioBtnLayout->addWidget(addBtn);
    radioBtnLayout->addWidget(infoBtn);
    radioBtnLayout->addWidget(buyRecordBtn);
    radioBtnLayout->addWidget(sellRecordBtn);
    radioBtnLayout->addSpacerItem(Vspacer);

    pushbtnLayout->addWidget(exitBtn);
    pushbtnLayout->addSpacerItem(Hspacer);
    pushbtnLayout->addWidget(nextBtn);
//    总体布局
    QVBoxLayout *mainLayout = new QVBoxLayout();
//    部件设置
    QFont btnFont;
    btnFont.setPointSize(13);
    buyBtn->setFixedHeight(30);
    buyBtn->setFont(btnFont);
    sellBtn->setFixedHeight(30);
    sellBtn->setFont(btnFont);
    addBtn->setFixedHeight(30);
    addBtn->setFont(btnFont);
    infoBtn->setFixedHeight(30);
    infoBtn->setFont(btnFont);
    buyRecordBtn->setFixedHeight(30);
    buyRecordBtn->setFont(btnFont);
    sellRecordBtn->setFixedHeight(30);
    sellRecordBtn->setFont(btnFont);

    radioBtnGroup->addButton(buyBtn,1);
    radioBtnGroup->addButton(sellBtn,2);
    radioBtnGroup->addButton(addBtn,3);
    radioBtnGroup->addButton(infoBtn,4);
    radioBtnGroup->addButton(buyRecordBtn,5);
    radioBtnGroup->addButton(sellRecordBtn,6);
//    运行布局
    mainLayout->addLayout(radioBtnLayout);
    mainLayout->addLayout(pushbtnLayout);
    this->setLayout(mainLayout);
//    信号与槽
    connect(nextBtn,SIGNAL(clicked()),this,SLOT(showSelected()));
    connect(exitBtn,SIGNAL(clicked()),qApp,SLOT(quit()));
}

void selectWidget::showSelected()
{
//    qDebug() << radioBtnGroup->checkedId();
    emit SelectChanged(radioBtnGroup->checkedId());
}
