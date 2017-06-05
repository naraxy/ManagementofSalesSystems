#ifndef BUYCOMMODITYWIDGET_H
#define BUYCOMMODITYWIDGET_H

#include <QWidget>
class QPushButton;
class QLabel;

class buyCommodityWidget : public QWidget
{
    Q_OBJECT
public:
    explicit buyCommodityWidget(QWidget *parent = nullptr);

signals:
    void backBuySignal(int Id);


private:
    QPushButton *backBtn;
    QLabel *mainTitle;

private slots:
    void backSlot();
};

#endif // BUYCOMMODITYWIDGET_H
