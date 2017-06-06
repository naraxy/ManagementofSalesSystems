#include "mainwidget.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QFont>
#include <QFile>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
//    初始化
    this->setFixedSize(560,380);
    QFile f("./core.db");
    if(!f.exists())
    {
        init->createDb();
    }else {
        init->openDb();
    }
//    页面部件
    mainTitle = new QLabel(tr("商品销售系统"));
//    页面布局
    QStackedLayout *stackedLayout = new QStackedLayout();
//    局部布局
    selectWgt = new selectWidget(this);
    buyWgt = new buyCommodityWidget(this);
    sellWgt = new sellCommodityWidget(this);
    addWgt = new addNewArrivalWidget(this);
    infoWgt = new commodityInfoWidget(this);
    buyRecordWgt = new buyRecordWidget(this);
    sellRecordWgt = new sellRecordWidget(this);

    stackedLayout->addWidget(selectWgt);
    stackedLayout->addWidget(buyWgt);
    stackedLayout->addWidget(sellWgt);
    stackedLayout->addWidget(addWgt);
    stackedLayout->addWidget(infoWgt);
    stackedLayout->addWidget(buyRecordWgt);
    stackedLayout->addWidget(sellRecordWgt);
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
    stackedLayout->setCurrentIndex(0);
    mainLayout->addLayout(stackedLayout);
    this->setLayout(mainLayout);
//    信号与槽
    connect(selectWgt,SIGNAL(SelectChanged(int)),stackedLayout,SLOT(setCurrentIndex(int)));
    connect(buyWgt,SIGNAL(backBuySignal(int)),stackedLayout,SLOT(setCurrentIndex(int)));
    connect(sellWgt,SIGNAL(backSellSignal(int)),stackedLayout,SLOT(setCurrentIndex(int)));
    connect(addWgt,SIGNAL(backAddSignal(int)),stackedLayout,SLOT(setCurrentIndex(int)));
    connect(infoWgt,SIGNAL(backInfoSignal(int)),stackedLayout,SLOT(setCurrentIndex(int)));
    connect(buyRecordWgt,SIGNAL(backBuyRecordSignal(int)),stackedLayout,SLOT(setCurrentIndex(int)));
    connect(sellRecordWgt,SIGNAL(backSellRecordSignal(int)),stackedLayout,SLOT(setCurrentIndex(int)));
}

MainWidget::~MainWidget()
{

}
