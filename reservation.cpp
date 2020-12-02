#include "reservation.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QSqlQueryModel>
#include <QSqlQuery>

#include "reservation.h"
reservation::reservation()
{
}

reservation::reservation(int CIN,int id, QString datemariage ,int acompteapayer ,int numoffre   )
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
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from RESERVATION");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("datemariage"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("acompteapayer"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("numoffre"));
    return model;
}

bool reservation::supprimer(int CIN)
{   QSqlQuery query;
    QString CIN_string=QString::number(CIN);
    query.prepare("Delete from RESERVATION where CIN= :CIN " );
    query.bindValue(":CIN",CIN_string);
   return query.exec();
}
bool reservation::modifier(int CIN,int id,QString datemariage ,int acompteapayer,int numoffre)
{
  QSqlQuery query;
  QString CIN_string=QString::number(CIN);
query.prepare("UPDATE RESERVATION SET  id= :id , datemariage= :datemariage , acompteapayer= :acompteapayer , numoffre= :numoffre WHERE CIN=:CIN ");
query.bindValue(":CIN",CIN);
query.bindValue(":id",id);
query.bindValue(":datemariage",datemariage);
query.bindValue(":acompteapayer",acompteapayer);
query.bindValue(":numoffre",numoffre);
return query.exec();
}




QSqlQueryModel *reservation::rechercher(QString datemariage)

{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select CIN,id,datemariage,acompteapayer,numoffre from RESERVATION where CIN like '"+datemariage+"%' or id like '"+datemariage+"%'  or datemariage like '"+datemariage+"%' or acompteapayer like '"+datemariage+"%' or numoffre like '"+datemariage+"%';");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("id "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("datemariage"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("acompteapayer"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("numoffre"));
return model;
}


QSqlQueryModel *reservation::showidreservation()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select id from RESERVATION");
model->setHeaderData(2, Qt::Horizontal, QObject::tr("datemariage"));
    return model;

}
