#ifndef SELLCOMMODITYWIDGET_H
#define SELLCOMMODITYWIDGET_H

#include <QWidget>
class QPushButton;
class QLabel;
class QSpacerItem;
class QComboBox;
class QLineEdit;

class sellCommodityWidget : public QWidget
{
    Q_OBJECT
public:
    explicit sellCommodityWidget(QWidget *parent = nullptr);

signals:
    void backSellSignal(int Id);


private:
    QPushButton *backBtn,*okBtn;
    QSpacerItem *Vspacer,*Hspacer,*OHspacer;
    QLabel *nameTitle,*sellPriceTitle,*numberTitle;
    QLineEdit *sellPrice,*number;
    QComboBox *name;

private slots:
    void backSlot();
    void insertDb();
    void refreshName();
};

#endif // SELLCOMMODITYWIDGET_H
