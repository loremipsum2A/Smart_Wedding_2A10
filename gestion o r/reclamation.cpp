#include "reclamation.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
reclamation::reclamation()
{
ref_rec=0 ; date_rec="" ; sujet="";descritpion="";
}

reclamation::reclamation(int ref_rec,QString date_rec,QString sujet,QString description)
{this->ref_rec=ref_rec;this->date_rec=date_rec;this->sujet=sujet;this->descritpion=description;}
int reclamation:: getref_rec(){return ref_rec;}
QString reclamation:: getdate_rec(){return date_rec;}
QString reclamation:: getsujet(){return sujet;}
QString reclamation:: getdescription(){return descritpion;}
void reclamation::setref_rec(int ref_rec) {this->ref_rec=ref_rec;}
void reclamation::setdate_rec(QString date_rec) {this->date_rec=date_rec;}
void reclamation::setsujet(QString sujet) {this->sujet=sujet;}
void reclamation::setdescription(QString description) {this->descritpion=description;}

bool reclamation::ajouter()
{

  QSqlQuery query;
  QString ref_rec_string= QString::number(ref_rec);

  query.prepare("INSERT INTO REC (ref_rec,date_rec,sujet,description) "
                "VALUES (:ref_rec,:date_rec,:sujet,:description)");
  query.bindValue(":ref_rec", ref_rec_string);
  query.bindValue(":date_rec", date_rec);
  query.bindValue(":sujet",sujet);
  query.bindValue(":description", descritpion);
        return query.exec();

}
bool reclamation::supprimer(int ref_rec)
{
    QSqlQuery query;
            query.prepare("select * from REC where ref_rec=:ref_rec");
            query.bindValue(0, ref_rec);
            query.exec();
            if (query.next())
            {
             query.prepare(" Delete from REC where ref_rec=:ref_rec");
             query.bindValue(0, ref_rec);

                    query.exec();
                 return true;

            }

             return false;


}

QSqlQueryModel* reclamation::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM REC");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref_rec"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_rec"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("sujet"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("description"));

  return  model;
}

QSqlQueryModel* reclamation::rechercher(QString row,QString txt)
{
     QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT * FROM REC WHERE UPPER("+row+") LIKE UPPER('"+txt+"%')");

     return model;
}
