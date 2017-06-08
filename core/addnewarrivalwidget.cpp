#include "addnewarrivalwidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>
#include <QSpacerItem>
#include <QLineEdit>
#include <QFont>
#include <QLineEdit>
#include <QSqlQuery>
#include <QDateTime>
#include <QMessageBox>

addNewArrivalWidget::addNewArrivalWidget(QWidget *parent) : QWidget(parent)
{
    //    初始化
    this->resize(560,330);
    //    页面部件
    nameTitle = new QLabel(tr("商  品："));
    buyPriceTitle = new QLabel(tr("采购价："));
    sellPriceTitle = new QLabel(tr("销售价："));
    numberTitle = new QLabel(tr("库存量："));
    nameEdit = new QLineEdit();
    buyPrice = new QLineEdit();
    sellPrice = new QLineEdit();
    number = new QLineEdit();

    backBtn = new QPushButton(tr("返回"));
    okBtn = new QPushButton(tr("确定"));
    Vspacer = new QSpacerItem(20,190);
    Hspacer = new QSpacerItem(420,20);
    OHspacer = new QSpacerItem(220,30);

    mainLayout = new QVBoxLayout();
    optionBox =new QGroupBox(tr("录入采新品信息"));
    optionLayout = new QVBoxLayout();
    optionName = new QHBoxLayout();
    optionBuyPrice = new QHBoxLayout();
    optionSellPrice = new QHBoxLayout();
    optionNum = new QHBoxLayout();
    btnLayout = new QHBoxLayout();
    //    局部布局
    okBtn->resize(70,20);
    //    字体布局
    QFont labelFont;
    labelFont.setPointSize(13);
    QRegularExpression val("^[\u4e00-\u9fa5]{0,20}$");
    nameVal = new QRegularExpressionValidator(val, this);
    nameEdit->setValidator(nameVal);
    priceVal = new QDoubleValidator;
    priceVal->setRange(0,1000,2);
    priceVal->setNotation(QDoubleValidator::StandardNotation);
    buyPrice->setValidator(priceVal);
    sellPrice->setValidator(priceVal);
    numberVal = new QIntValidator;
    numberVal->setRange(0,1000);
    number->setValidator(numberVal);
    //    选项栏布局
    optionBox->setAlignment(Qt::AlignCenter);
    nameTitle->setFont(labelFont);
    nameEdit->setFont(labelFont);
    optionName->addWidget(nameTitle);
    optionName->addWidget(nameEdit);
    optionName->addSpacerItem(OHspacer);

    buyPriceTitle->setFont(labelFont);
    buyPrice->setFont(labelFont);
    optionBuyPrice->addWidget(buyPriceTitle);
    optionBuyPrice->addWidget(buyPrice);
    optionBuyPrice->addSpacerItem(OHspacer);

    sellPriceTitle->setFont(labelFont);
    sellPrice->setFont(labelFont);
    optionSellPrice->addWidget(sellPriceTitle);
    optionSellPrice->addWidget(sellPrice);
    optionSellPrice->addSpacerItem(OHspacer);

    numberTitle->setFont(labelFont);
    number->setFont(labelFont);
    optionNum->addWidget(numberTitle);
    optionNum->addWidget(number);
    optionNum->addSpacerItem(OHspacer);

    optionLayout->addLayout(optionName);
    optionLayout->addLayout(optionBuyPrice);
    optionLayout->addLayout(optionSellPrice);
    optionLayout->addLayout(optionNum);
    optionBox->setLayout(optionLayout);
    //    按钮布局
    btnLayout->addWidget(okBtn);
    btnLayout->addSpacerItem(Hspacer);
    btnLayout->addWidget(backBtn);
    //    总体布局
    mainLayout->addWidget(optionBox);
    mainLayout->addSpacerItem(Vspacer);
    mainLayout->addLayout(btnLayout);
    this->setLayout(mainLayout);

    //    信号与槽
    connect(backBtn,SIGNAL(clicked()),this,SLOT(backSlot()));
    connect(okBtn,SIGNAL(clicked()),this,SLOT(insertDb()));
}

addNewArrivalWidget::~addNewArrivalWidget()
{
}

void addNewArrivalWidget::backSlot()
{
    nameEdit->clear();
    buyPrice->clear();
    sellPrice->clear();
    number->clear();
    emit backAddSignal(0);
}

void addNewArrivalWidget::insertDb()
{
    if(nameEdit->text().isEmpty() or sellPrice->text().isEmpty() or buyPrice->text().isEmpty() or number->text().isEmpty())
    {
        QMessageBox::warning(NULL,tr("错误"),tr("请将数据填写完整！"), QMessageBox::Yes);
    }else{
        //    插入数据
        QSqlQuery qInsert;
        qInsert.prepare("INSERT INTO commondity (name,buyprice,sellprice,store)"
                        "VALUES (:name,:buyprice,:sellprice,:store)");
        qInsert.bindValue(":name",nameEdit->text());
        qInsert.bindValue(":buyprice",buyPrice->text().toDouble());
        qInsert.bindValue(":sellprice",sellPrice->text().toDouble());
        qInsert.bindValue(":store",number->text().toInt());
        qInsert.exec();
        //    确认写入数据
        QMessageBox::information(NULL,tr("有效数据"),tr("数据已上传！"), QMessageBox::Yes);
    }
}
