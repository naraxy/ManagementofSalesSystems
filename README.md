# Management of Sales Systems

---

> 创建于Desktop Qt5.9.0 MinGW 32bit 

> 在windows 10 x64上编译
---
#### 系统功能结构
- 采购商品
- 销售商品
- 添加新品
- 查看商品信息
- 查看采购记录
- 查看销售记录

---
```cpp
private:
    buyCommodityWidget  *buyWgt; //采购商品页面
    sellCommodityWidget *sellWgt; //销售商品页面
    addNewArrivalWidget *addWgt; //添加新品页面
    commodityInfoWidget *infoWgt; //查看商品信息页面
    buyRecordWidget     *buyRecordWgt; //查看采购记录页面
    sellRecordWidget    *sellRecordWgt; //查看销售记录页面
    initDb              *init; //初始化数据库
    connectDb           *connectSqlite; //连接数据库及使用

```
> 修改于2017/6/4 11:39 

---
- 完成主页面设计
- 做好了跳转传值测试
> 修改于2017/6/5 01:00
---
```cpp
// 跳转页面
selectWgt = new selectWidget(this);
buyWgt = new buyCommodityWidget(this);
sellWgt = new sellCommodityWidget(this);
addWgt = new addNewArrivalWidget(this);
infoWgt = new commodityInfoWidget(this);
buyRecordWgt = new buyRecordWidget(this);
sellRecordWgt = new sellRecordWidget(this);
//页面排序
stackedLayout->addWidget(selectWgt);
stackedLayout->addWidget(buyWgt);
stackedLayout->addWidget(sellWgt);
stackedLayout->addWidget(addWgt);
stackedLayout->addWidget(infoWgt);
stackedLayout->addWidget(buyRecordWgt);
stackedLayout->addWidget(sellRecordWgt);
// 信号与槽
connect(selectWgt,SIGNAL(SelectChanged(int)),stackedLayout,SLOT(setCurrentIndex(int)));
connect(buyWgt,SIGNAL(backBuySignal(int)),stackedLayout,SLOT(setCurrentIndex(int)));
connect(sellWgt,SIGNAL(backSellSignal(int)),stackedLayout,SLOT(setCurrentIndex(int)));
connect(addWgt,SIGNAL(backAddSignal(int)),stackedLayout,SLOT(setCurrentIndex(int)));
connect(infoWgt,SIGNAL(backInfoSignal(int)),stackedLayout,SLOT(setCurrentIndex(int)));
connect(buyRecordWgt,SIGNAL(backBuyRecordSignal(int)),stackedLayout,SLOT(setCurrentIndex(int)));
connect(sellRecordWgt,SIGNAL(backSellRecordSignal(int)),stackedLayout,SLOT(setCurrentIndex(int)));
```

- 完成了所有页面跳转
- 初始化各页面
> 修改于2017/6/5 11:48
---
#### 数据库功能及结构
core.db 数据库名
name商品 buyprice 采购价格 sellprice 销售价格 store 库存 pirce 价格 record 进出库记录 time 时间记录

table|commondity
---|---
id |int primary key
name | varchar(30)
buyprice| real
sellprice|real
store|int

table|countin
---|---
name|varchar(30)
price|real
record|int
time|varchar(20)

table|countout
---|---
name|varchar(30)
price|real
record|int
time|varchar(20)

- 创建了数据库
- 采购界面及功能已完成！
> 修改于2017/6/7 01:34
---
- 销售、商品信息界面已完成!
- 已知问题，无法自动刷新商品信息变更，故暂时设置刷新键，待后期解决问题弃用
>修改于2017/6/8 13:27
---
- 已知问题修复，刷新键取消
- 解决子窗口退出程序问题
>修改于2017/6/8 18:17
---
- 添加新品、销售记录、采购记录界面完整！
- 完整只能输入产品中文的正则规则
- 修改了切换页面表格未清空的错误
- 暂时保留上传后表格不清空状态
- 未解决问题，正常退出后会出现错误提示
> 完成于2017/6/8 23:59
---
- 精简及美化了程序
- 修正了退出后出现错误的问题
>2017/6/9
---
