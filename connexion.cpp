#include "connexion.h"
#include <QDebug>

// test tutoriel git
connexion::connexion()
{

}

bool connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase ::addDatabase("QODBC");

db.setDatabaseName("system");
db.setUserName("mayssa");//inserer nom de l'utilisateur
db.setPassword("mayssa300599");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
qDebug()<<db.lastError().text();

    return  test;
}
