#include "gestion_salle.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QSqlQueryModel>
#include <QMessageBox>

Gestion_salle::Gestion_salle()
{
id=0;
nom=" ";
adresse=" ";
prix=0;
}
Gestion_salle::Gestion_salle(int id,QString nom,QString adresse,int prix)
{
 this->id=id;
 this->nom=nom;
 this->adresse=adresse;
 this->prix=prix;
}


bool Gestion_salle::ajouter()
{

QSqlQuery query;

 QString id_string=QString::number(id);
 QString prix_string=QString::number(prix);

 query.prepare("INSERT INTO SALLE(id,nom,adresse,prix)"
               "VALUES(:id,:nom,:adresse,:prix)");

 query.bindValue(":id",id_string);
 query.bindValue(":nom",nom);
 query.bindValue(":adresse",adresse);
 query.bindValue(":prix",prix);

return query.exec();
}
bool Gestion_salle::supprimer(int id)
{
   QSqlQuery query;
    query.prepare("Delete from salle where id=:id");

    query.bindValue(0,id);

    return query.exec();


}
QSqlQueryModel*Gestion_salle::afficher()
{

   QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM salle");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("ADRESSE"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRIX"));


   return model;
}

bool Gestion_salle::modifier(int id)
{
    QSqlQuery query;

    QString id_string= QString::number(id);
    if(rechercheid(id))
    {
    query.prepare("UPDATE SALLE SET  id = :id, nom= :nom, adresse=:adresse,prix=:prix  WHERE id = :id ");
    query.bindValue(":id", id_string);
    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":prix", prix);
}
    return  query.exec();

}


bool Gestion_salle::rechercheid(int id)
{


    QMessageBox msgBox;
       QSqlQuery query;
        QString id_string=QString::number(id);
       query.prepare("SELECT * FROM SALLE WHERE id= :id");
       query.bindValue(":id", id_string);
       if (query.exec() && query.next())
       {
               return true;
       }
       else
       {
           msgBox.setText("non existant");
           msgBox.exec();
           return false;
       }
}

bool Gestion_salle::recherchenom(QString nom)
{
    QMessageBox msgBox;
       QSqlQuery query;

       query.prepare("SELECT * FROM SALLE WHERE nom= :nom");
       query.bindValue(":nom", nom);
       if (query.exec() && query.next())
       {
               return true;
       }
       else
       {
           msgBox.setText("non existant");
           msgBox.exec();
           return false;
       }
 }


bool Gestion_salle::rechercheprix(int prix)
{

    QMessageBox msgBox;
       QSqlQuery query;
        QString prix_string=QString::number(prix);
       query.prepare("SELECT * FROM SALLE WHERE prix= :prix");
       query.bindValue(":prix", prix_string);
       if (query.exec() && query.next())
       {
               return true;
       }
       else
       {
           msgBox.setText("non existant");
           msgBox.exec();
           return false;
       }


 }


 QSqlQueryModel* Gestion_salle::afficherid(int id)
 {

     QSqlQueryModel* model= new QSqlQueryModel();
       QString id_string=QString::number(id);

             model->setQuery("SELECT * FROM SALLE WHERE ID='"+id_string+"'");

       return model;
 }

 QSqlQueryModel* Gestion_salle::affichernom(QString nom)
 {

     QSqlQueryModel* model= new QSqlQueryModel();


        model->setQuery("SELECT * FROM SALLE WHERE nom='"+nom+"'");

       return model;

 }

 QSqlQueryModel* Gestion_salle::afficherprix(int prix)
 {

     QSqlQueryModel* model= new QSqlQueryModel();
       QString prix_string=QString::number(prix);

             model->setQuery("SELECT * FROM SALLE WHERE prix='"+prix_string+"'");

       return model;
 }

