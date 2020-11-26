#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"client.h"
#include"reservation.h"
#include<QMessageBox>
#include<QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
     , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_CIN->setValidator(new QIntValidator(0,99999999 , this));
    ui->lineEdit_numero_de_telephone->setValidator(new QIntValidator(0,99999999 , this));
    ui->CIN_reservation->setValidator(new QIntValidator(0,99999999 , this));
    ui->id->setValidator(new QIntValidator(0,99999999 , this));
     ui->date->setValidator(new QIntValidator(0,99999999 , this));
    ui->acompte->setValidator(new QIntValidator(0,99999999 , this));
    ui->numoffre->setValidator(new QIntValidator(0,99999999 , this));
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

             {msg.setText("ajout avec succes");
            ui->tab_afficher->setModel(c.afficher());}
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
    msg.setText("suppression avec succés");
    ui->tab_afficher->setModel(c.afficher());
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






//void MainWindow::on_modifier_clicked()
//{
    //int CIN = ui->CIN1->currentText();
            // QString nom= ui->nom_2->text();
            // QString prenom= ui->prenom_2->text();
            //  QString sexe= ui->sexe_2->text();
             //  QString date_de_naissance= ui->datenaissance_2->text();
             //  QString adressemail=ui->adressemail_2->text();


        // client c(id,nom,prenom,sexe,date_de_naissance,adressemail);


         // bool test=c.modifier(c);

        //  if (test)
        //  {
        //  QMessageBox::information(nullptr, QObject::tr("modifier un client"),
//                            QObject::tr(" client modifié .\n"
                                    //    "Click Cancel to exit."), QMessageBox::Cancel);
    // }
//}

void MainWindow::on_tri_clicked()
{
       Client c;
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
