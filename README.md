# Management of Sales Systems

---

> 创建于Desktop Qt5.9.0 MinGW 32bit 

> 在window 10 x64上编译
---
#### 系统功能结构
- 购进商品
- 卖出商品
- 添加商品
- 查看商品信息
- 查看采购记录
- 查看销售记录

---
```cpp
private:
    buyCommodityWidget  *buyWgt; //购进商品页面
    sellCommodityWidget *sellWgt; //卖出商品页面
    addNewArrivalWidget *addWgt; //添加商品页面
    commodityInfoWidget *infoWgt; //查看商品信息页面
    buyRecordWidget     *buyRecordWgt; //查看采购记录页面
    sellRecordWidget    *sellRecordWgt; //查看销售记录页面
    initDb              *init; //初始化数据库
    connectDb           *connectSqlite; //连接数据库及使用

    //建立各信号槽
private slots:
    void showBuyWidget();
    void showSellWidget();
    void showAddWidget();
    void showInfoWidget();
    void showBuyRecordWidget();
    void showSellRecordWidget();
```
> 修改于2017/6/4 11:39 
