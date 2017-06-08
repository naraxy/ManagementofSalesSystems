#ifndef ADDNEWARRIVALWIDGET_H
#define ADDNEWARRIVALWIDGET_H

#include <QWidget>
class QPushButton;
class QLabel;
class QVBoxLayout;

class addNewArrivalWidget : public QWidget
{
    Q_OBJECT
public:
    explicit addNewArrivalWidget(QWidget *parent = nullptr);

signals:
    void backAddSignal(int Id);


private:
    QPushButton *backBtn;
    QLabel *mainTitle;
    QVBoxLayout *mainLayout;

private slots:
    void backSlot();
};

#endif // ADDNEWARRIVALWIDGET_H
