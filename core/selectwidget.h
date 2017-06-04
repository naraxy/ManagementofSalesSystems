#ifndef SELECTWIDGET_H
#define SELECTWIDGET_H

#include <QWidget>

class QRadioButton;
class QPushButton;
class QSpacerItem;
class QButtonGroup;

class selectWidget : public QWidget
{
    Q_OBJECT
public:
    explicit selectWidget(QWidget *parent = nullptr);

private:
    QRadioButton *buyBtn,*sellBtn,*addBtn,*infoBtn,*buyRecordBtn,*sellRecordBtn;
    QPushButton *nextBtn;
    QButtonGroup *radioBtnGroup;

    QSpacerItem *Vspacer,*Hspacer;

public slots:
    void showSelected();
};

#endif // SELECTWIDGET_H
