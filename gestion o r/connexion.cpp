#include "connexion.h"
#include <QDebug>
connexion::connexion()
{

}

bool connexion::ouvrirconnecxion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test-bd");
db.setUserName("ROPOROS");//inserer nom de l'utilisateur
db.setPassword("r1a2e3d4");//inserer mot de passe de cet utilisateur
if (db.open())
    test=true;
return test;
}

void connexion::fermerconnexion()
{db.close();}

