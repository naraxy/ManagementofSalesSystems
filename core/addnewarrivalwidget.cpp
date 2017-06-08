#include "addnewarrivalwidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

addNewArrivalWidget::addNewArrivalWidget(QWidget *parent) : QWidget(parent)
{
    this->resize(560,330);
    mainTitle = new QLabel(tr("录入新品信息"));
    backBtn = new QPushButton(tr("返回"));
    mainLayout = new QVBoxLayout();
    mainLayout->addWidget(mainTitle);
    mainLayout->addWidget(backBtn);
    this->setLayout(mainLayout);
    connect(backBtn,SIGNAL(clicked()),this,SLOT(backSlot()));
}

void addNewArrivalWidget::backSlot()
{
    emit backAddSignal(0);
}
