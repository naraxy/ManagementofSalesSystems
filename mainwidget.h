#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "./core/selectwidget.h"
#include "./core/buycommoditywidget.h"
#include "./core/sellcommoditywidget.h"
#include "./core/addnewarrivalwidget.h"
#include "./core/commodityinfowidget.h"
#include "./core/buyrecordwidget.h"
#include "./core/sellrecordwidget.h"
//#include "./db/initdb.h"
//#include "./db/connectdb.h"

class QLabel;

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
/*
 * #### 系统功能结构
 * - 采购商品
 * - 销售商品
 * - 添加新品
 * - 查看商品信息
 * - 查看采购记录
 * - 查看销售记录
 */
private:
    selectWidget        *selectWgt; //选择界面
    buyCommodityWidget  *buyWgt;
    sellCommodityWidget *sellWgt;
    addNewArrivalWidget *addWgt;
    commodityInfoWidget *infoWgt;
    buyRecordWidget     *buyRecordWgt;
    sellRecordWidget    *sellRecordWgt;
//    initDb              *init; //初始化数据库
//    connectDb           *connectSqlite; //连接数据库及使用
//主界面部件
    QLabel *mainTitle;

};

#endif // MAINWIDGET_H
