#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "./core/buycommoditywidget.h"
#include "./core/sellcommoditywidget.h"
#include "./core/addnewarrivalwidget.h"
#include "./core/commodityinfowidget.h"
#include "./core/buyrecordwidget.h"
#include "./core/sellrecordwidget.h"
#include "./db/initdb.h"
#include "./db/connectdb.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
/*
 * #### 系统功能结构
 * - 购进商品
 * - 卖出商品
 * - 添加新品
 * - 查看商品信息
 * - 查看采购记录
 * - 查看销售记录
 */
private:
    buyCommodityWidget  *buyWgt;
    sellCommodityWidget *sellWgt;
    addNewArrivalWidget *addWgt;
    commodityInfoWidget *infoWgt;
    buyRecordWidget     *buyRecordWgt;
    sellRecordWidget    *sellRecordWgt;
    initDb              *init; //初始化数据库
    connectDb           *connectSqlite; //连接数据库及使用

private slots:
    void showBuyWidget();
    void showSellWidget();
    void showAddWidget();
    void showInfoWidget();
    void showBuyRecordWidget();
    void showSellRecordWidget();


};

#endif // MAINWIDGET_H
