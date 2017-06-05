#include "commodityinfowidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

commodityInfoWidget::commodityInfoWidget(QWidget *parent) : QWidget(parent)
{
    this->resize(560,330);
    mainTitle = new QLabel(tr("查看商品信息"));
    backBtn = new QPushButton(tr("返回"));
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(mainTitle);
    mainLayout->addWidget(backBtn);
    this->setLayout(mainLayout);
    connect(backBtn,SIGNAL(clicked()),this,SLOT(backSlot()));
}

void commodityInfoWidget::backSlot()
{
    emit backInfoSignal(0);
}
