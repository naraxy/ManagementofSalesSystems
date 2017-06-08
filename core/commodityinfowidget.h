#ifndef COMMODITYINFOWIDGET_H
#define COMMODITYINFOWIDGET_H

#include <QWidget>
class QPushButton;
class QLabel;
class QSqlTableModel;
class QTableView;
class QSpacerItem;
class QVBoxLayout;
class QGroupBox;
class QHBoxLayout;

class commodityInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit commodityInfoWidget(QWidget *parent = nullptr);
    ~commodityInfoWidget();

signals:
    void backInfoSignal(int Id);
    void backInfoFresh();

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

#endif // COMMODITYINFOWIDGET_H
