#ifndef BUYRECORDWIDGET_H
#define BUYRECORDWIDGET_H

#include <QWidget>
class QPushButton;
class QLabel;

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

private slots:
    void backSlot();
};

#endif // BUYRECORDWIDGET_H
