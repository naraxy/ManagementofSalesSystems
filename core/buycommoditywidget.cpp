#include "buycommoditywidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>
#include <QSpacerItem>
#include <QComboBox>
#include <QLineEdit>
#include <QFont>
#include <QLineEdit>
#include <QSqlQuery>
#include <QDateTime>
#include <QMessageBox>
//#include <QDebug>

buyCommodityWidget::buyCommodityWidget(QWidget *parent) : QWidget(parent)
{
    //    初始化
    this->resize(560,330);
    //    页面部件
    nameTitle = new QLabel(tr("商  品："));
    buyPriceTitle = new QLabel(tr("采购价："));
    numberTitle = new QLabel(tr("采购量："));
    name = new QComboBox();
    this->createName();
    buyPrice = new QLineEdit();
    number = new QLineEdit();

    backBtn = new QPushButton(tr("返回"));
    okBtn = new QPushButton(tr("确定"));
    Vspacer = new QSpacerItem(20,220);
    Hspacer = new QSpacerItem(420,20);
    OHspacer = new QSpacerItem(220,30);

    mainLayout = new QVBoxLayout();
    optionBox =new QGroupBox(tr("录入采购商品信息"));
    optionLayout = new QVBoxLayout();
    optionName = new QHBoxLayout();
    optionBuyPrice = new QHBoxLayout();
    optionNum = new QHBoxLayout();
    btnLayout = new QHBoxLayout();
    //    局部布局
    okBtn->resize(70,20);
    //    字体布局
    QFont labelFont;
    labelFont.setPointSize(13);
    //    填表规范
    buyPriceVal = new QDoubleValidator;
    buyPriceVal->setRange(0,1000,2);
    buyPriceVal->setNotation(QDoubleValidator::StandardNotation);
    buyPrice->setValidator(buyPriceVal);
    numberVal = new QIntValidator;
    numberVal->setRange(0,1000);
    number->setValidator(numberVal);
    //    选项栏布局
    optionBox->setAlignment(Qt::AlignCenter);
    nameTitle->setFont(labelFont);
    name->setFont(labelFont);
    optionName->addWidget(nameTitle);
    optionName->addWidget(name);
    optionName->setAlignment(Qt::AlignLeft);

    buyPriceTitle->setFont(labelFont);
    buyPrice->setFont(labelFont);
    optionBuyPrice->addWidget(buyPriceTitle);
    optionBuyPrice->addWidget(buyPrice);
    optionBuyPrice->addSpacerItem(OHspacer);

    numberTitle->setFont(labelFont);
    number->setFont(labelFont);
    optionNum->addWidget(numberTitle);
    optionNum->addWidget(number);
    optionNum->addSpacerItem(OHspacer);

    optionLayout->addLayout(optionName);
    optionLayout->addLayout(optionBuyPrice);
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
    connect(this,SIGNAL(backBuyFresh()),this,SLOT(freshName()));
}

buyCommodityWidget::~buyCommodityWidget()
{
}

void buyCommodityWidget::createName()
{
    QSqlQuery qName;
    qName.exec("SELECT name FROM commondity");
    while (qName.next()) {
       name->addItem(qName.value("name").toString());
    }
}

void buyCommodityWidget::freshName()
{
    name->clear();
    this->createName();
}

void buyCommodityWidget::backSlot()
{
    buyPrice->clear();
    number->clear();
    emit backBuySignal(0);
}

void buyCommodityWidget::insertDb()
{
    if(buyPrice->text().isEmpty() or number->text().isEmpty())
    {
        QMessageBox::warning(NULL,tr("错误"),tr("请将数据填写完整！"), QMessageBox::Yes);
    }else{
        //    寻找选中哪个商品
        QSqlQuery qInsert;
        qInsert.prepare("select store from commondity where name = :name");
        qInsert.bindValue(":name",name->currentText());
        qInsert.exec();
        qInsert.next();
        int newStore = qInsert.value(0).toInt() + number->text().toInt();
        //    更新商品表的价格及库存
        qInsert.prepare("UPDATE commondity SET buyprice = :buyprice,store = :store WHERE name = :name");
        qInsert.bindValue(":buyprice",buyPrice->text().toDouble());
        qInsert.bindValue(":store",newStore);
        qInsert.bindValue(":name",name->currentText());
        qInsert.exec();
        //    更新采购记录表
        QDateTime time = QDateTime::currentDateTime();
        QString curTime = time.toString("yyyy-MM-dd hh:mm");
        qInsert.prepare("insert into countin (name,price,record,time)"
                        " values (:name,:price,:record,:time)");
        qInsert.bindValue(":name",name->currentText());
        qInsert.bindValue(":price",buyPrice->text().toDouble());
        qInsert.bindValue(":record",number->text().toInt());
        qInsert.bindValue(":time",curTime);
        qInsert.exec();
        //    确认写入数据
        QMessageBox::information(NULL,tr("有效数据"),tr("数据已上传！"), QMessageBox::Yes);
    }
}
