#ifndef COMMODITYINFOWIDGET_H
#define COMMODITYINFOWIDGET_H

#include <QWidget>
class QPushButton;
class QLabel;

class commodityInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit commodityInfoWidget(QWidget *parent = nullptr);

signals:
    void backInfoSignal(int Id);


private:
    QPushButton *backBtn;
    QLabel *mainTitle;

private slots:
    void backSlot();
};

#endif // COMMODITYINFOWIDGET_H
