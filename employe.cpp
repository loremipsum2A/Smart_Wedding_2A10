#include "employe.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

Employe::Employe()
{
  CIN=0;tel=0;duree=0;salaire=0;
  nom="";prenom="";date_naissance="";adresse="";email="";fonction="";etat="";

}

Employe::Employe(int CIN,int tel,int duree,int salaire,QString nom,QString prenom,QString date_naissance,QString adresse,QString email,QString fonction)
{
    this->CIN=CIN; this->tel=tel; this->duree=duree; this->salaire=salaire;
    this->nom=nom; this->prenom=prenom; this->date_naissance=date_naissance; this->adresse=adresse; this->email=email; this->fonction=fonction; etat="";
}

int Employe::getCIN() {return CIN;}
int Employe::getTel(){return tel;}
int Employe::getDuree(){return duree;}
int Employe::getSalaire(){return salaire;}
QString Employe::getNom(){return nom;}
QString Employe::getPrenom(){return prenom;}
QString Employe::getDate(){return date_naissance;}
QString Employe::getAdresse(){return adresse;}
QString Employe::getEmail(){return email;}
QString Employe::getFonction(){return fonction;}
QString Employe::getEtat(){return etat;}
void Employe::setCIN(int CIN){this->CIN=CIN; }
void Employe::setTel(int tel){this->tel=tel;}
void Employe::setDuree(int duree){this->duree=duree;}
void Employe::setSalaire(int salaire){this->salaire=salaire;}
void Employe::setNom(QString nom){this->nom=nom;}
void Employe::setPrenom(QString prenom){this->prenom=prenom;}
void Employe::setDate(QString date_naissance){this->date_naissance=date_naissance;}
void Employe::setAdresse(QString adresse){this->adresse=adresse;}
void Employe::setEmail(QString email){this->email=email;}
void Employe::setFonction(QString fonction){this->fonction=fonction;}
void Employe::setEtat(QString etat){this->etat=etat;}

bool Employe::ajouter()
{
    QSqlQuery query;

    QString CIN_string=QString::number(CIN);
    QString tel_string=QString::number(tel);
    QString duree_string=QString::number(duree);
    QString salaire_string=QString::number(salaire);

          query.prepare("INSERT INTO EMPLOYE (CIN, NOM, PRENOM, DATE_NAISSANCE, ADRESSE, EMAIL, TEL, FONCTION, SALAIRE, DUREE)"
                        "VALUES (:CIN, :nom, :prenom, :date_naissance, :adresse, :email, :tel, :fonction, :salaire, :duree)");
          query.bindValue(0, CIN_string);
          query.bindValue(1, nom);
          query.bindValue(2, prenom);
          query.bindValue(3, date_naissance);
          query.bindValue(4, adresse);
          query.bindValue(5, email);
          query.bindValue(6, tel_string);
          query.bindValue(7, fonction);
          query.bindValue(8, salaire_string);
          query.bindValue(9, duree_string);

          return query.exec();
}

QSqlQueryModel* Employe::afficher()
{
  QSqlQueryModel* model= new QSqlQueryModel();

        model->setQuery("SELECT * FROM EMPLOYE");
        //model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
        //model->setHeaderData(1, Qt::Horizontal, QObject::tr("Salary"));
  return model;
}

bool Employe::supprimer(int CIN)
{
    QSqlQuery query;

          query.prepare("DELETE FROM EMPLOYE WHERE CIN=:CIN");
          query.bindValue(0, CIN);

          return query.exec();
}

QSqlQueryModel* Employe::rechercher(int CIN)
{
    QSqlQueryModel* model= new QSqlQueryModel();
    QString CIN_string=QString::number(CIN);
        model->setQuery("select * from EMPLOYE where CIN=CIN_string");
        return model;
}

bool Employe::modifier(int CIN)
{
    QSqlQuery query;

    QString CIN_string=QString::number(CIN);
    QString tel_string=QString::number(tel);
    QString duree_string=QString::number(duree);
    QString salaire_string=QString::number(salaire);

    query.prepare("UPDATE EMPLOYE SET NOM='"+nom+"', PRENOM='"+prenom+"', DATE_NAISSANCE='"+date_naissance+"', ADRESSE='"+adresse+"', EMAIL='"+email+"', TEL='"+tel_string+"', FONCTION='"+fonction+"', SALAIRE='"+salaire_string+"', DUREE='"+duree_string+"' WHERE CIN='"+CIN_string+"'");
    /*query.bindValue(":cin", CIN);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":date_naissance", date_naissance);
    query.bindValue(":adresse", adresse);
    query.bindValue(":email", email);
    query.bindValue(":tel", tel_string);
    query.bindValue(":fonction", fonction);
    query.bindValue(":salaire", salaire_string);
    query.bindValue(":duree", duree_string);*/

    return query.exec();

}
