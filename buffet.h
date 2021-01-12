#ifndef BUFFET_H
#define BUFFET_H


#include <QString>
#include <QSqlQueryModel>


class buffet
{
public:
    buffet();
    buffet(int,QString,int,QString);
    QString getnom();
    int getprix();
    QString gettype();
    void setnom(QString);
    void setprix(int);
    void settype(QString);
    QSqlQueryModel*  afficher();
    bool supprimer(int);
    bool ajouter();
    bool recherchenom(QString);
    QSqlQueryModel* tri1(QString,QString);
    QSqlQueryModel* rechercher(QString,QString);



private:
    QString nom_chef,type;
    int prix,id_traiteur;
};

#endif // BUFFET_H
