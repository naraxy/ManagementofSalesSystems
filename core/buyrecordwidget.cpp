#include "buyrecordwidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

buyRecordWidget::buyRecordWidget(QWidget *parent) : QWidget(parent)
{
    this->resize(560,330);
    mainTitle = new QLabel(tr("查看采购商品信息"));
    backBtn = new QPushButton(tr("返回"));
    mainLayout = new QVBoxLayout();
    mainLayout->addWidget(mainTitle);
    mainLayout->addWidget(backBtn);
    this->setLayout(mainLayout);
    connect(backBtn,SIGNAL(clicked()),this,SLOT(backSlot()));
}

void buyRecordWidget::backSlot()
{
    emit backBuyRecordSignal(0);
}

