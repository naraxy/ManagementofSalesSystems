#ifndef BUYCOMMODITYWIDGET_H
#define BUYCOMMODITYWIDGET_H

#include <QWidget>

class QPushButton;
class QLabel;
class QSpacerItem;
class QComboBox;
class QLineEdit;

class buyCommodityWidget : public QWidget
{
    Q_OBJECT
public:
    explicit buyCommodityWidget(QWidget *parent = nullptr);

signals:
    void backBuySignal(int Id);


private:
    QPushButton *backBtn,*okBtn;
    QSpacerItem *Vspacer,*Hspacer,*OHspacer;
    QLabel *nameTitle,*buyPriceTitle,*numberTitle;
    QLineEdit *buyPrice,*number;
    QComboBox *name;

private slots:
    void backSlot();
    void insertDb();
    void refreshName();
};

#endif // BUYCOMMODITYWIDGET_H
