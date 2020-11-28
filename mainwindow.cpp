#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"client.h"
#include"reservation.h"
#include<QMessageBox>
#include<QIntValidator>
#include<QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
     , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_afficher->setModel(c.afficher());
    ui->lineEdit_CIN->setValidator(new QIntValidator(0,99999999 , this));
    ui->lineEdit_numero_de_telephone->setValidator(new QIntValidator(0,99999999 , this));
    ui->tab_afficher->setModel(c.afficher());
    ui->tab_reservation->setModel(c.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_ajouter_clicked()
{

   int CIN= ui->lineEdit_CIN->text().toInt();
            QString Prenom= ui->lineEdit_Prenom->text();
            QString Nom= ui->lineEdit_Nom->text();
            QString adresse_email= ui->lineEdit_adresse_email->text();
            int numero_de_telephone=ui->lineEdit_numero_de_telephone->text().toInt();
            Client c(CIN,Prenom,Nom,adresse_email,numero_de_telephone);
            QMessageBox msg  ;
            bool test=c.ajouter();
            if(test)

             {
                ui->tab_afficher->setModel(c.afficher());
                msg.setText("ajout avec succes");
            }
            else {
                msg.setText("echec au niveau de l'ajout");
                 }
            msg.exec();
}





void MainWindow::on_supprimer_clicked()
{
    int CIN= ui->CIN_supprimer->text().toInt();
    bool test = c.supprimer(CIN);
    QMessageBox msg ;
    if (test)
     {
        ui->tab_afficher->setModel(c.afficher());

    msg.setText("suppression avec succés");
    }
    else
    {
    msg.setText("Echec au niveau de la suppression ");
    }
    msg.exec();
}

void MainWindow::on_valider_reservation_clicked()
{
             int CIN= ui->CIN_reservation->text().toInt();
             int id= ui->id->text().toInt();
             int date_mariage= ui->date->text().toInt();
             int accompteapaye= ui->acompte->text().toInt();
             int numoffre= ui->numoffre->text().toInt();
             reservation c(CIN,id,date_mariage,accompteapaye,numoffre) ;
             QMessageBox msg  ;
             bool test=c.valider();
             if(test)

              {msg.setText("réservation ajouteé");
             ui->tab_reservation->setModel(c.afficher());}
             else {
                 msg.setText("echec au niveau de l'ajout");
                  }
             msg.exec();
}






void MainWindow::on_modifier_clicked()
{
    {
        ui->tab_afficher->setModel(c.afficher());
            int CIN=ui->lineEdit_CIN->text().toInt();
            QString Nom=ui->lineEdit_Nom->text();
            QString Prenom=ui->lineEdit_Prenom->text();
            QString adresse_email=ui->lineEdit_adresse_email->text();
            int numero_de_telephone=ui->lineEdit_numero_de_telephone->text().toInt();
            bool test=c.modifier(CIN,Prenom,Nom,adresse_email,numero_de_telephone);
            QMessageBox msg;
            if (test)
             {
                msg.setText("modify avec succés");
                ui->tab_afficher->setModel(c.afficher());
                }
                else
                {
                msg.setText("Echec au niveau de la modif ");
                }
                msg.exec();

            ui->lineEdit_CIN->clear();
            ui->lineEdit_Prenom->clear();
            ui->lineEdit_Nom->clear();
            ui->lineEdit_adresse_email->clear();
            ui->lineEdit_numero_de_telephone->clear();

    
    
    }
        
}

void MainWindow::on_tri_clicked()
{
       ui->tab_afficher->setModel(c.tri());
}


void MainWindow::on_supprimer_reservation_clicked()
{
    int CIN= ui->CIN_supprimer->text().toInt();
    bool test = c.supprimer(CIN);
    QMessageBox msg ;
    if (test)
     {
    msg.setText("suppression avec succés");
    ui->tab_reservation->setModel(c.afficher());
    }
    else
    {
    msg.setText("Echec au niveau de la suppression ");
    }
    msg.exec();
}



