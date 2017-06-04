#ifndef SELECTWIDGET_H
#define SELECTWIDGET_H

#include <QWidget>

class QRadioButton;
class QPushButton;
class QSpacerItem;

class selectWidget : public QWidget
{
    Q_OBJECT
public:
    explicit selectWidget(QWidget *parent = nullptr);

private:
    QRadioButton *buyBtn,*sellBtn,*addBtn,*infoBtn,*buyRecordBtn,*sellRecordBtn;
    QPushButton *nextBtn;

    QSpacerItem *Vspacer,*Hspacer;


signals:

public slots:
};

#endif // SELECTWIDGET_H
