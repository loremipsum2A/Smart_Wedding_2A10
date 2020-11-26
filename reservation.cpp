#include "reservation.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QSqlQueryModel>
#include <QSqlQuery>

#include "reservation.h"
reservation::reservation()
{
}

reservation::reservation(int CIN,int id,int datemariage ,int acompteapayer ,int numoffre   )
{

       this->CIN=CIN;
       this->id=id;
       this->datemariage=datemariage;
       this->acompteapayer=acompteapayer;
       this->numoffre=numoffre;
}

bool reservation::valider()
{
    QSqlQuery query;
    query.prepare("INSERT INTO RESERVATION (CIN,id,datemariage,acompteapayer,numoffre)"
                  "VALUES (:CIN,:id,:datemariage,:acompteapayer,:numoffre)");
    query.bindValue(":CIN",CIN);
    query.bindValue(":id",id);
    query.bindValue(":datemariage",datemariage);
    query.bindValue(":acompteapayer",acompteapayer);
    query.bindValue(":numoffre",numoffre);
    return query.exec();
}
QSqlQueryModel* reservation::afficher()
{
QSqlQueryModel* Model= new QSqlQueryModel();
Model->setQuery("SELECT * FROM RESERVATION ");
return Model;
}

 bool reservation::supprimer(int CIN)
{   QSqlQuery query;
    QString CIN_string=QString::number(CIN);
    query.prepare("Delete from RESERVATION where CIN= :CIN " );
    query.bindValue(":CIN",CIN_string);
   return query.exec();

}
