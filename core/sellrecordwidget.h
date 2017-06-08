#ifndef SELLRECORDWIDGET_H
#define SELLRECORDWIDGET_H

#include <QWidget>
class QPushButton;
class QLabel;
class QVBoxLayout;

class sellRecordWidget : public QWidget
{
    Q_OBJECT
public:
    explicit sellRecordWidget(QWidget *parent = nullptr);

signals:
    void backSellRecordSignal(int Id);


private:
    QPushButton *backBtn;
    QLabel *mainTitle;
    QVBoxLayout *mainLayout;

private slots:
    void backSlot();
};

#endif // SELLRECORDWIDGET_H
