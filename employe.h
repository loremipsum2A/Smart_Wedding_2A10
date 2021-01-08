#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQueryModel>

class Employe
{
private:
    int CIN,tel,salaire;
    QString nom,prenom,date_naissance,adresse,email,fonction,etat;
    QRegExp MRE ;

public:
    Employe();
    Employe(int,int,int,QString,QString,QString,QString,QString,QString);
    int getCIN();
    int getTel();
    int getSalaire();
    QString getNom();
    QString getPrenom();
    QString getDate();
    QString getAdresse();
    QString getEmail();
    QString getFonction();
    QString getEtat();
    void setCIN(int);
    void setTel(int);
    void setSalaire(int);
    void setNom(QString);
    void setPrenom(QString);
    void setDate(QString);
    void setAdresse(QString);
    void setEmail(QString);
    void setFonction(QString);
    void setEtat(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int);
    bool recherche(int);
    bool recherche_nom(QString);
    bool recherche_prenom(QString);
    QSqlQueryModel* afficher_cin(int);
    QSqlQueryModel* afficher_nom(QString);
    QSqlQueryModel* afficher_prenom(QString);
    QSqlQueryModel* tri_cin();
    QSqlQueryModel* tri_nom();
    QSqlQueryModel* tri_prenom();
    bool recherche_admin(QString);
    bool login(QString,QString,int);
};

#endif // EMPLOYE_H
