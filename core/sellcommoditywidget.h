#ifndef SELLCOMMODITYWIDGET_H
#define SELLCOMMODITYWIDGET_H

#include <QWidget>
#include <QValidator>
class QPushButton;
class QLabel;
class QSpacerItem;
class QComboBox;
class QLineEdit;
class QVBoxLayout;
class QHBoxLayout;
class QGroupBox;

class sellCommodityWidget : public QWidget
{
    Q_OBJECT
public:
    explicit sellCommodityWidget(QWidget *parent = nullptr);
    ~sellCommodityWidget();

signals:
    void backSellSignal(int Id);
    void backSellFresh();


private:
    QPushButton *backBtn,*okBtn;
    QSpacerItem *Vspacer,*Hspacer,*OHspacer;
    QLabel *nameTitle,*sellPriceTitle,*numberTitle;
    QLineEdit *sellPrice,*number;
    QComboBox *name;
    QVBoxLayout *mainLayout,*optionLayout;
    QHBoxLayout *optionName,*optionSellPrice,*optionNum,*btnLayout;
    QGroupBox *optionBox;
    QDoubleValidator *sellPriceVal;
    QIntValidator *numberVal;

private slots:
    void backSlot();
    void insertDb();
    void createName();
    void freshName();
};

#endif // SELLCOMMODITYWIDGET_H
