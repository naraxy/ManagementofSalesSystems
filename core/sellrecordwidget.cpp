#include "sellrecordwidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

sellRecordWidget::sellRecordWidget(QWidget *parent) : QWidget(parent)
{
    this->resize(560,330);
    mainTitle = new QLabel(tr("查看销售商品信息"));
    backBtn = new QPushButton(tr("返回"));
    mainLayout = new QVBoxLayout();
    mainLayout->addWidget(mainTitle);
    mainLayout->addWidget(backBtn);
    this->setLayout(mainLayout);
    connect(backBtn,SIGNAL(clicked()),this,SLOT(backSlot()));
}

void sellRecordWidget::backSlot()
{
    emit backSellRecordSignal(0);
}
