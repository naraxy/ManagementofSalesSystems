#include "sellrecordwidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QSqlTableModel>
#include <QGroupBox>
#include <QTableView>

sellRecordWidget::sellRecordWidget(QWidget *parent) : QWidget(parent)
{
    //    初始化
    this->resize(560,330);
    //    页面部件
    backBtn = new QPushButton(tr("返回"),this);
    Hspacer = new QSpacerItem(490,20);
    tableView = new QTableView(this);

    mainLayout = new QVBoxLayout();
    optionBox =new QGroupBox(tr("查看商品信息"),this);
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
    connect(this,SIGNAL(backSellRecordFresh()),this,SLOT(freshTable()));
}

sellRecordWidget::~sellRecordWidget()
{
}

void sellRecordWidget::backSlot()
{
    emit backSellRecordSignal(0);
}

void sellRecordWidget::createTable()
{
    sqlModel = new QSqlTableModel();
    sqlModel->setTable("countout");
    sqlModel->select();
    sqlModel->setHeaderData(0,Qt::Horizontal,QObject::tr("商品"));
    sqlModel->setHeaderData(1,Qt::Horizontal,QObject::tr("销售价"));
    sqlModel->setHeaderData(2,Qt::Horizontal,QObject::tr("销售量"));
    sqlModel->setHeaderData(3,Qt::Horizontal,QObject::tr("销售时间"));
}

void sellRecordWidget::freshTable()
{
    sqlModel->clear();
    this->createTable();
    tableView->setModel(sqlModel);
    //    禁止编辑表格
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
