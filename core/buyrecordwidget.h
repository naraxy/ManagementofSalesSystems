#ifndef BUYRECORDWIDGET_H
#define BUYRECORDWIDGET_H

#include <QWidget>
class QPushButton;
class QLabel;
class QSqlTableModel;
class QTableView;
class QSpacerItem;
class QVBoxLayout;
class QGroupBox;
class QHBoxLayout;

class buyRecordWidget : public QWidget
{
    Q_OBJECT
public:
    explicit buyRecordWidget(QWidget *parent = nullptr);
    ~buyRecordWidget();

signals:
    void backBuyRecordSignal(int Id);
    void backBuyRecordFresh();


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

#endif // BUYRECORDWIDGET_H
