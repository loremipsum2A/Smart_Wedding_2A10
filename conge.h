#ifndef CONGE_H
#define CONGE_H
#include <QString>
#include <QSqlQueryModel>

class Conge
{
    int ref,CIN;
    QString date_deb,date_fin,motif,etat_c;
public:
    Conge();
    Conge(int,int,QString,QString,QString);
    int getRef();
    QString getDate_deb();
    QString getDate_fin();
    QString getMotif();
    QString getEtat_c();
    void setRef(int);
    void setDate_deb(QString);
    void setDate_fin(QString);
    void setMotif(QString);
    void setEtat_c(QString);
    bool ajouter();
    QSqlQueryModel* afficher_mesconges(int);
    bool rechercher(int);
    bool rechercher_admin(int);
    QSqlQueryModel* afficher_admin(QString);
    bool rechercher_ref(int,QString);

};

#endif // CONGE_H
