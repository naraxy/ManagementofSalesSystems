#include "buyrecordwidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QSqlTableModel>
#include <QGroupBox>
#include <QTableView>

buyRecordWidget::buyRecordWidget(QWidget *parent) : QWidget(parent)
{
    //    初始化
    this->resize(560,330);
    //    页面部件
    backBtn = new QPushButton(tr("返回"));
    Hspacer = new QSpacerItem(490,20);
    tableView = new QTableView();

    mainLayout = new QVBoxLayout();
    optionBox =new QGroupBox(tr("查看商品信息"));
    optionLayout = new QVBoxLayout();
    btnLayout = new QHBoxLayout();
    //    局部布局
    tableView->resize(550,290);
    this->createTable();
    tableView->setModel(sqlModel);
    //    禁止编辑表格
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    optionBox->setAlignment(Qt::AlignCenter);
    optionLayout->addWidget(tableView);
    optionBox->setLayout(optionLayout);

    btnLayout->addSpacerItem(Hspacer);
    btnLayout->addWidget(backBtn);
    //    总体布局
    mainLayout->addWidget(optionBox);
    mainLayout->addLayout(btnLayout);
    this->setLayout(mainLayout);
    connect(backBtn,SIGNAL(clicked()),this,SLOT(backSlot()));
    connect(this,SIGNAL(backBuyRecordFresh()),this,SLOT(freshTable()));
}

buyRecordWidget::~buyRecordWidget()
{
}

void buyRecordWidget::backSlot()
{
    emit backBuyRecordSignal(0);
}

void buyRecordWidget::createTable()
{
    sqlModel = new QSqlTableModel();
    sqlModel->setTable("countin");
    sqlModel->select();
    sqlModel->setHeaderData(0,Qt::Horizontal,QObject::tr("商品"));
    sqlModel->setHeaderData(1,Qt::Horizontal,QObject::tr("采购价"));
    sqlModel->setHeaderData(2,Qt::Horizontal,QObject::tr("采购量"));
    sqlModel->setHeaderData(3,Qt::Horizontal,QObject::tr("采购时间"));
}

void buyRecordWidget::freshTable()
{
    sqlModel->clear();
    this->createTable();
    tableView->setModel(sqlModel);
    //    禁止编辑表格
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
