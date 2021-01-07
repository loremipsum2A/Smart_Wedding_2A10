#include "reclamation.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QComboBox>
reclamation::reclamation()
{
ref_rec=0 ; date_rec="" ; sujet="";descritpion="";
}

reclamation::reclamation(int ref_rec,QString date_rec,QString sujet,QString description,int id)
{this->ref_rec=ref_rec;this->date_rec=date_rec;this->sujet=sujet;this->descritpion=description;this->id=id;}
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
  QString id_string= QString::number(id);

  query.prepare("INSERT INTO REC (ref_rec,date_rec,sujet,description,id) "
                "VALUES (:ref_rec,:date_rec,:sujet,:description,:id)");
  query.bindValue(":ref_rec", ref_rec_string);
  query.bindValue(":date_rec", date_rec);
  query.bindValue(":sujet",sujet);
  query.bindValue(":description", descritpion);
  query.bindValue(":id",id_string);

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

  return  model;
}

QSqlQueryModel* reclamation::rechercher(QString row,QString txt)
{
     QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT * FROM REC WHERE UPPER("+row+") LIKE UPPER('"+txt+"%')");

     return model;
}

void reclamation::remplir(QComboBox* c)
{
    QSqlQuery *query=new QSqlQuery();
    QSqlQueryModel* model=new QSqlQueryModel();
    query->prepare("SELECT ID FROM RESERVATION ");
    query->exec();
    model->setQuery(*query);
    c->setModel(model);
}
