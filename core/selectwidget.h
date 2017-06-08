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
    ~selectWidget();

signals:
    void SelectChanged(int id);

private:
    QRadioButton *buyBtn,*sellBtn,*addBtn,*infoBtn,*buyRecordBtn,*sellRecordBtn;
    QPushButton *nextBtn,*exitBtn;
    QButtonGroup *radioBtnGroup;

    QSpacerItem *Vspacer,*Hspacer;

private slots:
    void showSelected();
};

#endif // SELECTWIDGET_H
