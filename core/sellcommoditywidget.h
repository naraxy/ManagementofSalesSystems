#ifndef SELLCOMMODITYWIDGET_H
#define SELLCOMMODITYWIDGET_H

#include <QWidget>
class QPushButton;
class QLabel;

class sellCommodityWidget : public QWidget
{
    Q_OBJECT
public:
    explicit sellCommodityWidget(QWidget *parent = nullptr);

signals:
    void backSellSignal(int Id);


private:
    QPushButton *backBtn;
    QLabel *mainTitle;

private slots:
    void backSlot();
};

#endif // SELLCOMMODITYWIDGET_H
