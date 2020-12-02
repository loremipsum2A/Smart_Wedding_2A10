#ifndef OFFRE_H
#define OFFRE_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
class Offre
{
public:
    Offre();
    Offre(int,QString,QString,int);
    int getnum_offre();
    QString getperiode();
    QString gettype();
    int getprix_offre();
    void setnum_offre(int);
    void setperiode(QString);
    void settype(QString);
    void setprix_offre(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    QSqlQueryModel* rechercher(QString,QString);

private:
int num_offre,prix_offre;
QString periode,type;

};

#endif // OFFRE_H
