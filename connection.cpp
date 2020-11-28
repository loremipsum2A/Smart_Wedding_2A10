#include "connection.h"
#include "QSqlDatabase"
#include <QDebug>
#include <QSqlError>
connection::connection()
{

}

bool connection::createConnection()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test_db");
    db.setUserName("cyrine");
    db.setPassword("cyrine");
    if(db.open())
        test=true;
    qDebug() <<db.lastError().text();
    return test;
}
