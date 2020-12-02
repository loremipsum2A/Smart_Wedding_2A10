#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>
#include "offre.h"
#include <QTextEdit>
#include "reclamation.h"
#include <QSqlError>
#include <QPrinter>
#include <QPrintDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->le_num_3->setValidator(new QIntValidator(0, 9999999, this));
    ui->lineEdit_5->setValidator(new QIntValidator(0, 9999999, this));
    ui->taboffre->setModel(O1.afficher());
    ui->tabrec->setModel(R1.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}
//partie offre
            //ajout offre
void MainWindow::on_pushButton_7_clicked()
{
    int num_offre=ui->le_num_3->text().toInt();
    QString periode=ui->lineEdit_11->text();
    QString type=ui->lineEdit_13->text();
    int prix_offre=ui->le_prix_3->text().toInt();
    Offre O (num_offre,periode,type,prix_offre);
    bool test=O.ajouter();

    if (test)
         {
             QMessageBox::information(nullptr, QObject::tr("Ajouter offre"),
                         QObject::tr("Ajout avec succes.\n"
                                     "Click OK to exit."), QMessageBox::Ok);
             ui->taboffre->setModel(O1.afficher());
         }
         else
         {
             QMessageBox::information(nullptr, QObject::tr("Ajouter offre"),
                         QObject::tr("Echec d ajout.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         }
   }


void MainWindow::on_pushButton_9_clicked()
{

}
        //suppression offre
void MainWindow::on_pushButton_6_clicked()
{
        QMessageBox msgBox;
        if(O1.supprimer(offreSelect))
           { msgBox.setText("Suppression avec succes.");
        ui->taboffre->setModel(O1.afficher());

        }
        else
            msgBox.setText("Echec de suppression");
            msgBox.exec();
}

        //modification offre
void MainWindow::on_pushButton_27_clicked()
{

    int num_offre=ui->lineEdit_39->text().toInt();
    QString periode=ui->lineEdit_37->text();
    QString type=ui->lineEdit_38->text();
    int prix_offre=ui->lineEdit_36->text().toInt();
    QString value;

            QSqlQuery query;
            query.prepare("UPDATE OFFRE SET   periode='"+periode+"', type='"+type+"', prix_offre=:prix_offre where num_offre=:num_offre");
            query.bindValue(":num_offre", num_offre);
            query.bindValue(":prix_offre", prix_offre);

            if (query.exec())
            {
                QMessageBox msgBox;
                  msgBox.setText("MODIFIED.");
                  msgBox.exec();
             ui->taboffre->setModel(O1.afficher());
            }

            else
            {
                QMessageBox::critical(this,tr("error::"), query.lastError().text());
            }
}

//Partie reclamation
         //ajout reclamation
void MainWindow::on_pushButton_21_clicked()
{
    int ref_rec=ui->lineEdit_5->text().toInt();
    QString date_rec=ui->lineEdit->text();
    QString sujet=ui->lineEdit_15->text();
    QString description=ui->lineEdit_2->text();
    reclamation R (ref_rec,date_rec,sujet,description);
    bool test=R.ajouter();

    if (test)
         {
             QMessageBox::information(nullptr, QObject::tr("Ajouter reclamation"),
                         QObject::tr("Ajout avec succes.\n"
                                     "Click OK to exit."), QMessageBox::Ok);
             ui->tabrec->setModel(R1.afficher());
         }
         else
         {
             QMessageBox::information(nullptr, QObject::tr("Ajouter reclamation"),
                         QObject::tr("Echec d ajout.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         }
}

            //suppression reclamation
void MainWindow::on_pushButton_clicked()
{
    int ref_rec=ui->lineEdit_5->text().toInt();
    bool test1=R1.recherche(ref_rec);
    QMessageBox msgBox;
    if(test1)
    {
        bool test=R1.supprimer(ref_rec);

    if (test)
         {
             QMessageBox::information(nullptr, QObject::tr("Supprimer reclamation"),
                         QObject::tr("Suppression avec succes.\n"
                                     "Click OK to exit."), QMessageBox::Ok);
             ui->taboffre->setModel(R1.afficher());
         }
         else
         {
             QMessageBox::information(nullptr, QObject::tr("Supprimer reclamation"),
                         QObject::tr("Echec de suppression.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         }
    }
    else
    {
        QMessageBox messagebox1;
        messagebox1.setText("cette reclamation n existe pas ");
        messagebox1.exec();
    }
}

void MainWindow::on_taboffre_clicked(const QModelIndex &index)
{
    offreSelect=ui->taboffre->model()->data(index.sibling(index.row(),0)).toInt();
}

void MainWindow::on_taboffre_activated()
{
    QSqlQuery query;
          query.prepare("SELECT * FROM OFFRE WHERE num_offre=:val");
          query.bindValue(":val",offreSelect);
          if (query.exec())
          {

              while(query.next())
              {
                  ui->lineEdit_39->setText(query.value(0).toString());
                  ui->lineEdit_37->setText(query.value(1).toString());
                  ui->lineEdit_38->setText(query.value(2).toString());
                  ui->lineEdit_36->setText(query.value(3).toString());

              }

               }

              else {
                      QMessageBox::critical(this,tr("error::"), query.lastError().text());
              }
}

void MainWindow::on_lineEdit_3_textChanged(const QString &arg1)
{
    ui->taboffre->setModel(O1.rechercher(ui->comboBox_5->currentText(),arg1));

}

void MainWindow::on_pushButton_17_clicked()
{
    QPrinter printer;

        printer.setPrinterName("desiered printer name");

      QPrintDialog dialog(&printer,this);

        if(dialog.exec()== QDialog::Rejected)

            return;
}
