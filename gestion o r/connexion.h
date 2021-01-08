#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class connexion
{
public:
    connexion();
    bool ouvrirconnecxion();
    void fermerconnexion();

private :
    QSqlDatabase db;
};

#endif // CONNEXION_H
