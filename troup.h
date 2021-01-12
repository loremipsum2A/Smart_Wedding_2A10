#ifndef TROUP_H
#define TROUP_H

#include <QString>
#include <QSqlQueryModel>


class troup
{
public:
    troup();
    troup(int,QString,int,QString);
    QString getnom();
    int getrate();
    QString getgenre();
    void setnom(QString);
    void setrate(int);
    void setgenre(QString);
    QSqlQueryModel*  afficher();
    bool supprimer(int);
    bool recherchenom(QString);
    bool ajouter();
    QSqlQueryModel* tri1(QString,QString);
    QSqlQueryModel* rechercher(QString,QString);
    int max();



private:
    QString nom_troop,genre;
    int id_troup,rating;
};

#endif // TROUP_H
