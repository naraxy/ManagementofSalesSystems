#include "mainwidget.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QFont>
#include <QFile>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QApplication>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
//    初始化
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);
    this->setFixedSize(560,380);
    QFile f("./core.db");
    if(!f.exists()){
        db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
        db->setDatabaseName("./core.db");
        db->open();
        QSqlQuery q;
        q.exec("create table commondity("
               "ID integer primary key autoincrement,"
               "name varchar(30),"
               "buyprice real,"
               "sellprice real,"
               "store integer)");
        q.exec("create table countin("
               "name varchar(30),"
               "price real,"
               "record integer,"
               "time varchar(20))");
        q.exec("create table countout("
               "name varchar(30),"
               "price real,"
               "record integer,"
               "time varchar(20))");
    }
    else {
        db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
        db->setDatabaseName("./core.db");
        db->open();
    }
//    页面部件
    mainTitle = new QLabel(tr("商品销售系统"),this);
//    页面布局
    stackedLayout = new QStackedLayout;
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
    mainLayout = new QVBoxLayout(this);
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
    connect(selectWgt,SIGNAL(SelectChanged(int)),stackedLayout,SLOT(setCurrentIndex(int)));
    connect(selectWgt,SIGNAL(SelectChanged(int)),infoWgt,SIGNAL(backInfoFresh()));
    connect(selectWgt,SIGNAL(SelectChanged(int)),buyWgt,SIGNAL(backBuyFresh()));
    connect(selectWgt,SIGNAL(SelectChanged(int)),sellWgt,SIGNAL(backSellFresh()));
    connect(selectWgt,SIGNAL(SelectChanged(int)),buyRecordWgt,SIGNAL(backBuyRecordFresh()));
    connect(selectWgt,SIGNAL(SelectChanged(int)),sellRecordWgt,SIGNAL(backSellRecordFresh()));
//    返回选择页
    connect(buyWgt,SIGNAL(backBuySignal(int)),stackedLayout,SLOT(setCurrentIndex(int)));
    connect(sellWgt,SIGNAL(backSellSignal(int)),stackedLayout,SLOT(setCurrentIndex(int)));
    connect(addWgt,SIGNAL(backAddSignal(int)),stackedLayout,SLOT(setCurrentIndex(int)));
    connect(infoWgt,SIGNAL(backInfoSignal(int)),stackedLayout,SLOT(setCurrentIndex(int)));
    connect(buyRecordWgt,SIGNAL(backBuyRecordSignal(int)),stackedLayout,SLOT(setCurrentIndex(int)));
    connect(sellRecordWgt,SIGNAL(backSellRecordSignal(int)),stackedLayout,SLOT(setCurrentIndex(int)));

    connect(selectWgt,SIGNAL(exitBtnClicked()),qApp,SLOT(closeAllWindows()));
}

MainWidget::~MainWidget()
{

}

void MainWidget::showWidget()
{
    this->setStyleSheet("color:rgb(135, 206, 235);background-color: gray");
    this->showNormal();
    this->raise();
    this->activateWindow();
}

