#include "initdb.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

void initDb::createDb()
{
    QSqlDatabase createdb = QSqlDatabase::addDatabase("QSQLITE");
    createdb.setDatabaseName("./core.db");
    if(!createdb.open())
    {
        qDebug() << createdb.lastError();
    }
    else {
        QSqlQuery q;
        q.exec("create table commondity("
               "ID integer primary key autoincrement,"
               "name varchar(30),"
               "buyprice real,"
               "sellprice real,"
               "store integer)");
        q.exec("create table countin("
               "name varchar(30),"
               "price real,"
               "record integer,"
               "time varchar(20))");
        q.exec("create table countout("
               "name varchar(30),"
               "price real,"
               "record integer,"
               "time varchar(20))");
    }
}

void initDb::openDb()
{
    QSqlDatabase openDb = QSqlDatabase::addDatabase("QSQLITE");
    openDb.setDatabaseName("./core.db");
    openDb.open();
}
