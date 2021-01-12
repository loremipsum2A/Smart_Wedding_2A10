#include "troup.h"
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

troup::troup()
{
nom_troop=genre="";
rating=0;
}


troup::troup(int id_troup,QString nom_troop,int rating,QString genre)
{
    this->id_troup=id_troup; this->nom_troop=nom_troop; this->rating=rating; this->genre=genre;

}

QString troup::getnom(){return nom_troop;}
int troup::getrate(){return rating;}
QString troup::getgenre(){return genre;}
void troup::setnom(QString nom_toup){this->nom_troop=nom_troop;}
void troup::setrate(int rating){this->rating=rating;}
void troup::setgenre(QString genre){this->genre=genre;}

int troup::max()
{
    QMessageBox msg;

    int i;
    QString rating;
    QSqlQuery query;
          query.prepare("SELECT MAX(RATING) FROM troop");

    i=query.exec();


    rating = QString::number(i);
    msg.setText(rating);
    msg.exec();

    return i;
}

bool troup::ajouter()
{
    QString val_string=QString::number(rating);
    QString val_string1=QString::number(id_troup);

    QSqlQuery query;
          query.prepare("INSERT INTO troop (id_troup, nom_troop, rating, genre) "
                        "VALUES (:id_troup, :nom_troop, :rating, :genre)");
          query.bindValue(":id_troup", val_string1);
          query.bindValue(":nom_troop", nom_troop);
          query.bindValue(":rating", val_string);
          query.bindValue(":genre", genre);
          return query.exec();

}
QSqlQueryModel*  troup::afficher()
{
        QSqlQueryModel *model = new QSqlQueryModel;
          model->setQuery("SELECT * FROM troop");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name troup"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("rating"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("genre"));

    return model;


}

 bool troup::supprimer(int id_troup)
 {
     QSqlQuery query;

     /*QSqlQuery query;
     query.prepare(" Delete from troop where nom_troop=:nom_troop");
     query.bindValue(":nom_troop", nom_troop);
     */


     query.prepare("select * from troop where id_troup=:id_troup");
     query.bindValue(":id_troup", id_troup);
     query.exec();
     if (query.next())
     {
      query.prepare(" Delete from troop where id_troup=:id_troup");
      query.bindValue(":id_troup", id_troup);

             query.exec();
          return true;

     }

      return false;

     return query.exec();
 }


 bool troup::recherchenom(QString nom_chef)
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

 QSqlQueryModel*  troup::tri1(QString colone, QString ordre)
 {
 QSqlQueryModel* model=new QSqlQueryModel();
 model->setQuery("select * from troop order by "+colone+" "+ordre+"");
 return model;
 }

 QSqlQueryModel* troup::rechercher(QString colone,QString text)
 {
      QSqlQueryModel* model=new QSqlQueryModel();

      model->setQuery("SELECT * FROM troop WHERE UPPER("+colone+") LIKE UPPER('"+text+"%')");

      return model;
 }
