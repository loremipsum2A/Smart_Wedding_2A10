#ifndef RECLAMATION_H
#define RECLAMATION_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QComboBox>
#include <QtDebug>
#include <QObject>

class reclamation
{
public:
    reclamation();
    reclamation(int,QString,QString,QString,int);
    int getref_rec();
    QString getdate_rec();
    QString getsujet();
    QString getdescription();
    void setref_rec(int);
    void setdate_rec(QString);
    void setsujet(QString);
    void setdescription(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    QSqlQueryModel* rechercher(QString,QString);
    void remplir(QComboBox*);

private:
    int ref_rec;
    QString date_rec , sujet , descritpion;
    int id;

};

#endif // RECLAMATION_H
