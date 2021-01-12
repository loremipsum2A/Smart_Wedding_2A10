#include "buffet.h"

#include <QSqlQuery>
#include <QDebug>
#include <QtSql>
#include <QMessageBox>

buffet::buffet()
{
nom_chef=type="";
prix=0;
}


buffet::buffet(int id_traiteur,QString nom_chef,int prix,QString type)
{
   this->id_traiteur=id_traiteur; this->nom_chef=nom_chef; this->prix=prix; this->type=type;

}

QString buffet::getnom(){return nom_chef;}
int buffet::getprix(){return prix;}
QString buffet::gettype(){return type;}
void buffet::setnom(QString nom_chef){this->nom_chef=nom_chef;}
void buffet::setprix(int prix){this->prix=prix;}
void buffet::settype(QString type){this->type=type;}

bool buffet::ajouter()
{
    QString val_string=QString::number(prix);
    QString val_string1=QString::number(id_traiteur);

    QSqlQuery query;
          query.prepare("INSERT INTO buffet (id_traiteur, nom_chef, prix, type) "
                        "VALUES (:id_traiteur, :nom_chef, :prix, :type)");
          query.bindValue(":id_traiteur", val_string1);
          query.bindValue(":nom_chef", nom_chef);
          query.bindValue(":prix", val_string);
          query.bindValue(":type", type);
          return query.exec();

}
QSqlQueryModel*  buffet::afficher()
{
        QSqlQueryModel *model = new QSqlQueryModel;
          model->setQuery("SELECT * FROM buffet");        
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name chef"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("id traiteur"));

    return model;


}

 bool buffet::supprimer(int id_traiteur)
 {

     QSqlQuery query;
    /* query.prepare(" Delete from buffet where QString nom_chef");
     query.bindValue(":nom_chef", nom_chef);

     return query.exec();*/

     query.prepare("select * from buffet where id_traiteur=:id_traiteur");
     query.bindValue(":id_traiteur", id_traiteur);
     query.exec();
     if (query.next())
     {
      query.prepare(" Delete from buffet where id_traiteur=:id_traiteur");
      query.bindValue(":id_traiteur", id_traiteur);

             query.exec();
          return true;

     }

      return false;

     return query.exec();
 }

 bool buffet::recherchenom(QString nom_chef)
 {


     QMessageBox msgBox;
        QSqlQuery query;

        query.prepare("SELECT * FROM SALLE WHERE QString nom_chef");
        query.bindValue(":nom_chef", nom_chef);
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

 QSqlQueryModel*  buffet::tri1(QString colone, QString ordre)
 {
 QSqlQueryModel* model=new QSqlQueryModel();
 model->setQuery("select * from buffet order by "+colone+" "+ordre+"");
 return model;
 }

 QSqlQueryModel* buffet::rechercher(QString colone,QString text)
 {
      QSqlQueryModel* model=new QSqlQueryModel();

      model->setQuery("SELECT * FROM buffet WHERE UPPER("+colone+") LIKE UPPER('"+text+"%')");

      return model;
 }

