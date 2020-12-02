#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QSqlQueryModel>
#include <QString>
#include <QFileDialog>
#include <QTextDocument>


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


int Client::get_CIN(){return CIN;}
QString Client::get_Prenom(){return this->Prenom;}
QString Client::get_Nom(){return Nom;}
QString Client::get_adresse_email(){return adresse_email;}
int Client::get_numero_de_telephone(){return numero_de_telephone ;}

void Client::setCIN (int value){this->CIN=value;}
void Client::setPrenom(QString value){this->Prenom=value;}
void Client::setNom(QString value){this->Nom=value;}
void Client::setadresse_email(QString value){this->adresse_email=value;}
void Client::setnumero_de_telephone(int value){this->numero_de_telephone=value;}


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
     QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("select * from CLIENT");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse_email"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("numero_de_telephone"));
     return model;

}


 bool Client::supprimer(int CIN)
 {   QSqlQuery query;
     QString CIN_string=QString::number(CIN);
     query.prepare("Delete from client where CIN= :CIN " );
     query.bindValue(":CIN",CIN_string);
     return query.exec();

 }

 bool Client::modifier(int CIN,QString Prenom,QString Nom, QString adresse_email,int numero_de_telephone)
 {
   QSqlQuery query;
   QString CIN_string=QString::number(CIN);


query.prepare("UPDATE CLIENT SET  PRENOM= :Prenom , Nom= :Nom , adresse_email= :adresse_email , numero_de_telephone= :numero_de_telephone WHERE CIN=:CIN ");
query.bindValue(":CIN",CIN);
query.bindValue(":Prenom",Prenom);
query.bindValue(":Nom",Nom);
query.bindValue(":adresse_email",adresse_email);
query.bindValue(":numero_de_telephone",numero_de_telephone);
return query.exec();
 }

 QSqlQueryModel* Client::tri_CIN()
 {
     QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT * FROM CLIENT ORDER BY CIN ASC");

     return model;
 }

 QSqlQueryModel* Client::tri_Prenom()
 {
     QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT * FROM CLIENT ORDER BY Prenom ASC");

     return model;
 }

 QSqlQueryModel* Client::tri_Nom()
 {
     QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT * FROM CLIENT ORDER BY NOM ASC");

     return model;
 }


 QSqlQueryModel * Client::rechercher(QString Nom)

 {
 QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("select CIN,Prenom,Nom,adresse_email,numero_de_telephone from CLIENT where CIN like '"+Nom+"%' or Prenom like '"+Nom+"%'  or Nom like '"+Nom+"%' or adresse_email like '"+Nom+"%' or numero_de_telephone like '"+Nom+"%';");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom "));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse_email"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("numero_de_telephone"));
 return model;
 }


 QSqlQueryModel *Client::shownomclient()
 {
     QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("select NOM from CLIENT");
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom "));
     return model;

 }







