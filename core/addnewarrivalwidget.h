#ifndef ADDNEWARRIVALWIDGET_H
#define ADDNEWARRIVALWIDGET_H

#include <QWidget>
#include <QValidator>
class QPushButton;
class QLabel;
class QSpacerItem;
class QLineEdit;
class QVBoxLayout;
class QHBoxLayout;
class QGroupBox;

class addNewArrivalWidget : public QWidget
{
    Q_OBJECT
public:
    explicit addNewArrivalWidget(QWidget *parent = nullptr);
    ~addNewArrivalWidget();

signals:
    void backAddSignal(int Id);


private:
    QPushButton *backBtn,*okBtn;
    QSpacerItem *Vspacer,*Hspacer,*OHspacer;
    QLabel *nameTitle,*buyPriceTitle,*sellPriceTitle,*numberTitle;
    QLineEdit *nameEdit,*buyPrice,*sellPrice,*number;
    QVBoxLayout *mainLayout,*optionLayout;
    QHBoxLayout *optionName,*optionBuyPrice,*optionSellPrice,*optionNum,*btnLayout;
    QGroupBox *optionBox;
    QValidator *nameVal;
    QDoubleValidator *priceVal;
    QIntValidator *numberVal;

private slots:
    void backSlot();
    void insertDb();
};

#endif // ADDNEWARRIVALWIDGET_H
