#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include<QSqlQueryModel>


class Client
{
public:
 Client();
 Client  (int,QString,QString,QString,int);
  void setCIN(int);
 void setPrenom(QString);
 void setNom(QString);
 void setadresse_email(QString);
 void setnumero_de_telephone(int);


 int  get_CIN();
 QString get_Prenom();
 QString get_Nom();
 QString get_adresse_email();
 int get_numero_de_telephone();

 bool ajouter();
 QSqlQueryModel * afficher();
 bool supprimer(int);
 bool modifier(int,QString,QString,QString,int);
QSqlQueryModel *rechercher(QString);
  QSqlQueryModel *tri();
  QSqlQueryModel* tri_CIN();
   QSqlQueryModel* tri_Prenom();
    QSqlQueryModel* tri_Nom();
  QSqlQueryModel *shownomclient() ;
private:
    int CIN,numero_de_telephone;
    QString Prenom,Nom,adresse_email;

};

#endif // CLIENT_H
