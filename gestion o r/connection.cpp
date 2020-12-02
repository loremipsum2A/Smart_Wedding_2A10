#include "connection.h"
#include <QDebug>
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("db_smart_2A10");
db.setUserName("ROPOROS");//inserer nom de l'utilisateur
db.setPassword("r1a2e3d4");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

qDebug()<<db.lastError().text();



    return  test;
}
