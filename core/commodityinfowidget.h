#ifndef COMMODITYINFOWIDGET_H
#define COMMODITYINFOWIDGET_H

#include <QWidget>
class QPushButton;
class QLabel;
class QSqlTableModel;
class QTableView;
class QSpacerItem;

class commodityInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit commodityInfoWidget(QWidget *parent = nullptr);

signals:
    void backInfoSignal(int Id);

private:
    QPushButton *backBtn,*freshBtn;
    QTableView *tableView;
    QSqlTableModel *sqlModel;
    QSpacerItem *Hspacer;

private slots:
    void backSlot();
    void createTable();
    void freshTable();
};

#endif // COMMODITYINFOWIDGET_H
