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
 void setPrenom(QString n);
 void setNom(QString n);
 void setadresse_email(QString n);
 void setnumero_de_telephone(int);
 int  get_CIN();
 QString get_Prenom();
 QString get_Nom();
 QString get_adresse_email();
 int get_numero_de_telephone();
 bool ajouter();
 QSqlQueryModel* afficher();
 bool supprimer(int);
 bool modifier(Client);


  QSqlQueryModel *tri();
private:
    int CIN,numero_de_telephone;
    QString Prenom,Nom,adresse_email;

};

#endif // CLIENT_H
