#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQueryModel>

class Employe
{
private:
    int CIN,tel,duree,salaire;
    QString nom,prenom,date_naissance,adresse,email,fonction,etat;

public:
    Employe();
    Employe(int,int,int,int,QString,QString,QString,QString,QString,QString);
    int getCIN();
    int getTel();
    int getDuree();
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
    void setDuree(int);
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
    QSqlQueryModel* rechercher(int);
    bool modifier(int);
};

#endif // EMPLOYE_H