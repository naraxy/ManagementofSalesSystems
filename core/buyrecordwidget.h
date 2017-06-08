#ifndef BUYRECORDWIDGET_H
#define BUYRECORDWIDGET_H

#include <QWidget>
class QPushButton;
class QLabel;
class QVBoxLayout;

class buyRecordWidget : public QWidget
{
    Q_OBJECT
public:
    explicit buyRecordWidget(QWidget *parent = nullptr);

signals:
    void backBuyRecordSignal(int Id);


private:
    QPushButton *backBtn;
    QLabel *mainTitle;
    QVBoxLayout *mainLayout;

private slots:
    void backSlot();
};

#endif // BUYRECORDWIDGET_H
