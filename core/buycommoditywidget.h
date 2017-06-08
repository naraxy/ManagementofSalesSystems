#ifndef BUYCOMMODITYWIDGET_H
#define BUYCOMMODITYWIDGET_H

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

class buyCommodityWidget : public QWidget
{
    Q_OBJECT
public:
    explicit buyCommodityWidget(QWidget *parent = nullptr);
    ~buyCommodityWidget();

signals:
    void backBuySignal(int Id);
    void backBuyFresh();


private:
    QPushButton *backBtn,*okBtn;
    QSpacerItem *Vspacer,*Hspacer,*OHspacer;
    QLabel *nameTitle,*buyPriceTitle,*numberTitle;
    QLineEdit *buyPrice,*number;
    QComboBox *name;
    QVBoxLayout *mainLayout,*optionLayout;
    QHBoxLayout *optionName,*optionBuyPrice,*optionNum,*btnLayout;
    QGroupBox *optionBox;
    QDoubleValidator *buyPriceVal;
    QIntValidator *numberVal;

private slots:
    void backSlot();
    void insertDb();
    void createName();
    void freshName();
};

#endif // BUYCOMMODITYWIDGET_H
