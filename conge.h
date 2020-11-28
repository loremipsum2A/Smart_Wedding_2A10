#ifndef CONGE_H
#define CONGE_H
#include <QString>
#include <QSqlQueryModel>

class Conge
{
    int ref,duree_c;
    QString date_c,motif,etat_c;
public:
    Conge();
    Conge(int,QString,int,QString);
    int getRef();
    int getDuree_c();
    QString getDate_c();
    QString getMotif();
    QString getEtat_c();
    void setRef(int);
    void setDuree_c(int);
    void setDate_c(QString);
    void setMotif(QString);
    void setEtat_c(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel* rechercher();

};

#endif // CONGE_H
