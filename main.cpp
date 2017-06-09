#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget *mainWidget = new MainWidget;
    mainWidget->showWidget();

    return a.exec();
}
