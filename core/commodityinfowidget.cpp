#include "commodityinfowidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QSqlTableModel>
#include <QGroupBox>
#include <QTableView>

commodityInfoWidget::commodityInfoWidget(QWidget *parent) : QWidget(parent)
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
    connect(this,SIGNAL(backInfoFresh()),this,SLOT(freshTable()));
}

void commodityInfoWidget::backSlot()
{
    emit backInfoSignal(0);
}

void commodityInfoWidget::createTable()
{
    sqlModel = new QSqlTableModel();
    sqlModel->setTable("commondity");
    sqlModel->select();
    sqlModel->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    sqlModel->setHeaderData(1,Qt::Horizontal,QObject::tr("商品"));
    sqlModel->setHeaderData(2,Qt::Horizontal,QObject::tr("采购价"));
    sqlModel->setHeaderData(3,Qt::Horizontal,QObject::tr("销售价"));
    sqlModel->setHeaderData(4,Qt::Horizontal,QObject::tr("库存"));
}

void commodityInfoWidget::freshTable()
{
    sqlModel->clear();
    this->createTable();
    tableView->setModel(sqlModel);
    //    禁止编辑表格
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
