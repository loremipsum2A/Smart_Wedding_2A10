#include "gestion_emp.h"
#include "ui_gestion_emp.h"
#include "employe.h"
#include <QIntValidator>
#include <QMessageBox>

gestion_emp::gestion_emp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_emp)
{
    ui->setupUi(this);
    ui->cin_ajouter->setValidator(new QIntValidator(0, 99999999, this));
    ui->tab_emp->setModel(E.afficher());

}

gestion_emp::~gestion_emp()
{
    delete ui;
}

void gestion_emp::on_btajouter_emp_clicked()
{
    int CIN=ui->cin_ajouter->text().toInt();
    int tel=ui->tel_ajouter->text().toInt();
    int duree=ui->dureetr_ajouter->text().toInt();
    int salaire=ui->salaire_ajouter->text().toInt();
    QString nom=ui->nom_ajouter->text();
    QString prenom=ui->prenom_ajouter->text();
    QString date_naissance=ui->date_ajouter->text();
    QString adresse=ui->adresse_ajouter->text();
    QString email=ui->email_ajouter->text();
    QString fonction=ui->fonction_ajouter->text();

    Employe E(CIN,tel,duree,salaire,nom,prenom,date_naissance,adresse,email,fonction);
    bool test=E.ajouter();
     QMessageBox msgBox;

     if(test)

     {
         msgBox.setText("Ajout avec succes");
         ui->tab_emp->setModel(E.afficher());

     }
     else
         msgBox.setText("Echec d'ajout");

      msgBox.exec();


}

void gestion_emp::on_btsupp_emp_clicked()
{
    Employe E;
    E.setCIN(ui->cin_supprimer->text().toInt());
    bool test=E.supprimer(E.getCIN());
    QMessageBox msgBox;

    if(test)
      {  msgBox.setText("Suppression avec succes");
        ui->tab_emp->setModel(E.afficher());
      }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}

void gestion_emp::on_pushButton_3_clicked()
{
    Employe E;
    E.setCIN(ui->cin_rechercher->text().toInt());
    ui->tab_emp->setModel(E.rechercher(E.getCIN()));
}

void gestion_emp::on_btmod_emp_clicked()
{
    Employe E;
    E.setCIN(ui->cin_modifier->text().toInt());
    E.setPrenom(ui->prenom_modifier->text());
    E.setNom(ui->nom_modifier->text());
    E.setDate(ui->date_modifier->text());
    E.setEmail(ui->email_modifier->text());
    E.setAdresse(ui->adresse_modifier->text());
    E.setTel(ui->tel_modifier->text().toInt());
    E.setFonction(ui->fonction_modifier->text());
    E.setDuree(ui->dureetr_modifier->text().toInt());
    E.setSalaire(ui->salaire_modifier->text().toInt());
    bool test=E.modifier(E.getCIN());
    QMessageBox msgBox;

    if(test)
      {  msgBox.setText("Modification avec succes");
        ui->tab_emp->setModel(E.afficher());
      }
    else
        msgBox.setText("Echec de modification");
    msgBox.exec();
}
