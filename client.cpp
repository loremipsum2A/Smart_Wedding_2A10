#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QSqlQueryModel>

Client::Client()
{

}
Client::Client(int CIN,QString Prenom,QString Nom , QString adresse_email,int numero_de_telephone )
{

       this->CIN=CIN;
       this->Prenom=Prenom;
       this->Nom=Nom;
       this->adresse_email=adresse_email;
       this->numero_de_telephone=numero_de_telephone;
}


bool Client::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENT (CIN,Prenom,Nom,adresse_email,numero_de_telephone)"
                  "VALUES (:CIN,:Prenom,:Nom,:adresse_email,:numero_de_telephone)");
    query.bindValue(":CIN",CIN);
    query.bindValue(":Prenom",Prenom);
    query.bindValue(":Nom",Nom);
    query.bindValue(":adresse_email",adresse_email);
    query.bindValue(":numero_de_telephone",numero_de_telephone);
    return query.exec();
}
 QSqlQueryModel* Client::afficher()
{
 QSqlQueryModel* Model= new QSqlQueryModel();
 Model->setQuery("SELECT * FROM CLIENT ");
 return Model;

}


 bool Client::supprimer(int CIN)
 {   QSqlQuery query;
     QString CIN_string=QString::number(CIN);
     query.prepare("Delete from client where CIN= :CIN " );
     query.bindValue(":CIN",CIN_string);
     return query.exec();

 }

 bool Client::modifier(Client )
 {
 QSqlQuery query;
    query.prepare("UPDATE CLIENT SET Prenom =:prenom , Nom= :nom , adresse_email= :adresse_email , numero_de_telephone= :numero_de_telephone  WHERE CIN =:cin ");
    query.bindValue(":CIN", CIN);
    query.bindValue(":Prenom", Prenom);
    query.bindValue(":Nom", Nom);
    query.bindValue(":adresse_email", adresse_email);
    query.bindValue(":numero_de_telephone", numero_de_telephone);
 return query.exec();
 }

 QSqlQueryModel *Client::tri()
 {
 QSqlQuery *q = new QSqlQuery();
 QSqlQueryModel *model = new QSqlQueryModel();
 q->prepare("SELECT * FROM CLIENT ORDER BY NOM");
 q->exec();
 model->setQuery(*q);
 return model;
 }

