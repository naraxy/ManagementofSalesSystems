#include "buycommoditywidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

buyCommodityWidget::buyCommodityWidget(QWidget *parent) : QWidget(parent)
{
    this->resize(560,330);
    mainTitle = new QLabel(tr("录入采购商品信息"));
    backBtn = new QPushButton(tr("返回"));
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(mainTitle);
    mainLayout->addWidget(backBtn);
    this->setLayout(mainLayout);
    connect(backBtn,SIGNAL(clicked()),this,SLOT(backSlot()));
}

void buyCommodityWidget::backSlot()
{
    emit backBuySignal(0);
}
