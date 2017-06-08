#ifndef SELLRECORDWIDGET_H
#define SELLRECORDWIDGET_H

#include <QWidget>
class QPushButton;
class QLabel;
class QVBoxLayout;
class QPushButton;
class QLabel;
class QSqlTableModel;
class QTableView;
class QSpacerItem;
class QVBoxLayout;
class QGroupBox;
class QHBoxLayout;

class sellRecordWidget : public QWidget
{
    Q_OBJECT
public:
    explicit sellRecordWidget(QWidget *parent = nullptr);
    ~sellRecordWidget();

signals:
    void backSellRecordSignal(int Id);
    void backSellRecordFresh();


private:
    QPushButton *backBtn;
    QTableView *tableView;
    QSqlTableModel *sqlModel;
    QSpacerItem *Hspacer;
    QGroupBox *optionBox;
    QVBoxLayout *mainLayout,*optionLayout;
    QHBoxLayout *btnLayout;

private slots:
    void backSlot();
    void createTable();
    void freshTable();
};

#endif // SELLRECORDWIDGET_H
