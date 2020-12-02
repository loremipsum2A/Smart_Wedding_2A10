#include "salle.h"
#include "ui_salle.h"
#include "decorateur.h"
#include "gestion_salle.h"
#include <iostream>
#include <QMessageBox>
#include  <QDebug>
#include <QRadioButton>
#include<QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include <QPainter>
#include<QFileDialog>
#include<QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include<QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QSqlQuery>
#include<QDesktopServices>
#include <QMessageBox>
#include<QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include <QPrintDialog>
#include<QtSql/QSqlQuery>
#include<QVariant>
Salle::Salle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Salle)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0,9999999,this));
    ui->le_prix->setValidator(new QIntValidator(0,9999999,this));
    ui->le_id_theme->setValidator(new QIntValidator(0,9999999,this));
    ui->le_prix_theme->setValidator(new QIntValidator(0,9999999,this));
    ui->tab_salle->setModel(S.afficher());
    ui->tab_theme->setModel(T.affichert());

}

Salle::~Salle()
{
    delete ui;
}

void Salle::on_Ok_Ajoutsalle_clicked()
{
  int id=ui->le_id->text().toInt();
  QString nom=ui->le_nom->text();
  QString adresse=ui->le_adresse->text();
  int prix=ui->le_prix->text().toInt();
  Gestion_salle s(id,nom,adresse,prix);
  QMessageBox msg ;
  bool test=s.ajouter();
  if(test)
  {
 msg.setText("Ajout avec succes");
    ui->tab_salle->setModel(s.afficher());
  }
  else
    msg.setText("Echec de l'Ajout");
  msg.exec();



}

void Salle::on_pb_supprimer1_clicked()
{
    Gestion_salle S1; S1.setid(ui->le_id_supp->text().toInt());
    bool test =S1.supprimer(S1.getid());
    QMessageBox msgBox;
    if(test)

        {
          msgBox.setText("suppression avec succes.");
          ui->tab_salle->setModel(S1.afficher());
        }
        else
         msgBox.setText("Echec de suppression.");
    msgBox.exec();

}



void Salle::on_Ok_Ajouttheme_clicked()
{
    int id_dec=ui->le_id_theme->text().toInt();
    QString nom_dec=ui->le_nom_dec->text();
    QString nom_theme=ui->le_nom_theme->text();
    QString adresse_dec=ui->le_adresse_dec->text();
    int prix_theme=ui->le_prix_theme->text().toInt();
    Decorateur T(id_dec,prix_theme,nom_dec,nom_theme,adresse_dec);
    QMessageBox msg;
    bool test=T.ajoutert();
    if(test)
    {
   msg.setText("Ajout avec succes");
      ui->tab_theme->setModel(T.affichert());
    }
    else
      msg.setText("Echec de l'Ajout");
    msg.exec();

}


void Salle::on_pb_supprimertheme_clicked()
{
   Decorateur T1; T1.setiddec(ui->le_supp_theme->text().toInt());
    bool test =T1.supprimert(T1.getiddec());
    QMessageBox msgBox;
    if(test)

        {
          msgBox.setText("suppression avec succes.");
          ui->tab_theme->setModel(T1.affichert());
        }
        else
         msgBox.setText("Echec de suppression.");
    msgBox.exec();

}

void Salle::on_tri_nom_clicked()
{
    QMessageBox msgBox ;

        QSqlQueryModel *model = new QSqlQueryModel();
                 model->setQuery("SELECT * FROM SALLE order by id ASC");
                 model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
                 model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
                 model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
                 model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));

                 ui->tab_salle->setModel(model);
                 ui->tab_salle->show();
                 msgBox.setText("Tri avec succès.");
                 msgBox.exec();
}

void Salle::on_tri_id_clicked()
{
    QMessageBox msgBox ;

        QSqlQueryModel *model = new QSqlQueryModel();
                 model->setQuery("SELECT * FROM SALLE order by nom ASC");
                 model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
                 model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
                 model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
                 model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));

                 ui->tab_salle->setModel(model);
                 ui->tab_salle->show();
                 msgBox.setText("Tri avec succès.");
                 msgBox.exec();
}

void Salle::on_Annuler_Supprimersalle_clicked()
{
    close();
}


void Salle::on_Quitter_Ajoutsalle_clicked()
{
    close();
}

void Salle::on_tri_id_dec_clicked()
{
    QMessageBox msgBox ;

        QSqlQueryModel *model = new QSqlQueryModel();
                 model->setQuery("SELECT * FROM DECORATEUR order by id_dec ASC");
                 model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_dec"));
                 model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_dec"));
                 model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom_theme"));
                 model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse_dec"));
                   model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix_theme"));

                 ui->tab_theme->setModel(model);
                 ui->tab_theme->show();
                 msgBox.setText("Tri avec succès.");
                 msgBox.exec();
}




void Salle::on_tri_nom_dec_clicked()
{

    QMessageBox msgBox ;

        QSqlQueryModel *model = new QSqlQueryModel();
                 model->setQuery("SELECT * FROM DECORATEUR order by nom_dec ASC");
                 model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_dec"));
                 model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_dec"));
                 model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom_theme"));
                 model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse_dec"));
                   model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix_theme"));

                 ui->tab_theme->setModel(model);
                 ui->tab_theme->show();
                 msgBox.setText("Tri avec succès.");
                 msgBox.exec();

}

void Salle::on_Modifier_Modifiersalle_clicked()
    {
        int id=ui->le_id_mod->text().toInt();
         QString nom=ui->le_mod_nom->text();
        QString adresse = ui->le_mod_ad->text();
        int prix=ui->le_mod_p->text().toInt();

        Gestion_salle S(id,nom,adresse,prix);
        QMessageBox msg;
        bool test=S.modifier(id,nom,adresse,prix);

        if(test)
        {
            ui->le_id_mod->clear();
            ui->le_mod_nom->clear();
            ui->le_mod_ad->clear();
            ui->le_mod_p->clear();
            ui->tab_salle->setModel(S.afficher());

            msg.setText("modifiction avec succes");


        }

            else {
            msg.setText("Echec au niveau de la modification d un dossier medicale");
        }
        msg.exec();
}

void Salle::on_Modifier_Modifiertheme_clicked()
{

    int id_dec=ui->le_id_dec_mod->text().toInt();
     QString nom_dec=ui->le_nom_dec_mod->text();
      QString nom_theme=ui->le_nom_theme_mod->text();
    QString adresse_dec = ui->le_adresse_mod->text();
    int prix_theme=ui->le_prix_mod->text().toInt();

    Decorateur T (id_dec, prix_theme, nom_dec, nom_theme, adresse_dec);
    QMessageBox msg;
    bool test=T.modifier( id_dec, prix_theme, nom_dec, nom_theme, adresse_dec);

    if(test)
    {
        ui->le_id_dec_mod->clear();
        ui->le_nom_dec_mod->clear();
        ui->le_nom_theme_mod->clear();
        ui->le_adresse_mod->clear();
        ui->le_prix_mod->clear();
        ui->tab_theme->setModel(T.affichert());

        msg.setText("modifiction avec succes");


    }

        else {
        msg.setText("Echec au niveau de la modification d un dossier medicale");
    }
    msg.exec();
}

void Salle::on_Quitter_Ajouttheme_clicked()
{
    close();
}

void Salle::on_pushButton_2_clicked()
{
    close();
}

void Salle::on_pushButton_4_clicked()
{
    close();
}

void Salle::on_Annuler_Modifiersalle_clicked()
{
    close();
}

void Salle::on_Annuler_Modifiertheme_clicked()
{
    close();
}

void Salle::on_Annuler_Supprimertheme_clicked()
{
    close();
}

void Salle::on_tri_nom_2_clicked()
{
    QMessageBox msgBox ;

        QSqlQueryModel *model = new QSqlQueryModel();
                 model->setQuery("SELECT * FROM SALLE order by id DESC");
                 model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
                 model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
                 model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
                 model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));

                 ui->tab_salle->setModel(model);
                 ui->tab_salle->show();
                 msgBox.setText("Tri avec succès.");
                 msgBox.exec();
}


void Salle::on_tri_id_2_clicked()
{

    QMessageBox msgBox ;

        QSqlQueryModel *model = new QSqlQueryModel();
                 model->setQuery("SELECT * FROM SALLE order by nom DESC");
                 model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
                 model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
                 model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
                 model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));

                 ui->tab_salle->setModel(model);
                 ui->tab_salle->show();
                 msgBox.setText("Tri avec succès.");
                 msgBox.exec();
}

void Salle::on_tri_id_dec_2_clicked()
{
    QMessageBox msgBox ;

        QSqlQueryModel *model = new QSqlQueryModel();
                 model->setQuery("SELECT * FROM DECORATEUR order by id_dec DESC");
                 model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_dec"));
                 model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_dec"));
                 model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom_theme"));
                 model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse_dec"));
                   model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix_theme"));

                 ui->tab_theme->setModel(model);
                 ui->tab_theme->show();
                 msgBox.setText("Tri avec succès.");
                 msgBox.exec();
}


void Salle::on_tri_nom_dec_2_clicked()
{
    QMessageBox msgBox ;

        QSqlQueryModel *model = new QSqlQueryModel();
                 model->setQuery("SELECT * FROM DECORATEUR order by nom_dec DESC");
                 model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_dec"));
                 model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_dec"));
                 model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom_theme"));
                 model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse_dec"));
                   model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix_theme"));

                 ui->tab_theme->setModel(model);
                 ui->tab_theme->show();
                 msgBox.setText("Tri avec succès.");
                 msgBox.exec();
}


void Salle::on_pushButton_3_clicked()
{
     bool test;
     Decorateur T;
     int id_dec=0;
     QString nom_dec=ui->le_recherche->text();
     QString nom_theme=ui->le_recherche->text();
     QString choix=ui->comboBox->currentText();

   if(choix=="id_dec")
   {
       id_dec= nom_dec.toInt();
       test=T.recherche(id_dec,nom_dec,nom_theme);
   }
   if(choix=="Nom_dec")
   {
      test=T.recherche(id_dec,nom_dec,nom_theme);
   }
   if(choix=="Nom_theme")
   {
       test=T.recherche(id_dec,nom_dec,nom_theme);
   }
if(test)
{
  ui->tab_theme->setModel(T.affichert());
}
}

void Salle::on_pushButton_clicked()
{
    bool test;
   Gestion_salle S;
       int id=0;
       int prix=0;
     QString nom=ui->lineEdit->text();
     QString choix=ui->comboBox_2->currentText();

   if(choix=="id")
   {
        id= nom.toInt();
       test=S.recherche(id,nom,prix);
   }
   if(choix=="nom")
   {

       test=S.recherche(id,nom,prix);
   }
   if(choix=="prix")
   {
       prix= nom.toInt();
 test=S.recherche(id,nom,prix);
   }
if(test)
{

ui->tab_salle->setModel(S.afficher());
}
}


void Salle::on_pdf_salle_clicked()
{
    QString strStream;
                      QTextStream out(&strStream);

                      const int rowCount = ui->tab_salle->model()->rowCount();
                      const int columnCount = ui->tab_salle->model()->columnCount();

                      out <<  "<html>\n"
                          "<head>\n"
                          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                          <<  QString("<title>%1</title>\n").arg("strTitle")
                          <<  "</head>\n"
                          "<body bgcolor=#ffffff link=#5000A0>\n"

                         //     "<align='right'> " << datefich << "</align>"
                          "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                      // headers
                      out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                      for (int column = 0; column < columnCount; column++)
                          if (!ui->tab_salle->isColumnHidden(column))
                              out << QString("<th>%1</th>").arg(ui->tab_salle->model()->headerData(column, Qt::Horizontal).toString());
                      out << "</tr></thead>\n";

                      // data table
                      for (int row = 0; row < rowCount; row++) {
                          out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                          for (int column = 0; column < columnCount; column++) {
                              if (!ui->tab_salle->isColumnHidden(column)) {
                                  QString data = ui->tab_salle->model()->data(ui->tab_salle->model()->index(row, column)).toString().simplified();
                                  out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                              }
                          }
                          out << "</tr>\n";
                      }
                      out <<  "</table> </center>\n"
                          "</body>\n"
                          "</html>\n";

                QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                  if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                 QPrinter printer (QPrinter::PrinterResolution);
                  printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                printer.setOutputFileName(fileName);

                 QTextDocument doc;
                  doc.setHtml(strStream);
                  doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                  doc.print(&printer);
}

void Salle::on_pdf_decorateur_clicked()
{
    QString strStream;
                      QTextStream out(&strStream);

                      const int rowCount = ui->tab_theme->model()->rowCount();
                      const int columnCount = ui->tab_theme->model()->columnCount();

                      out <<  "<html>\n"
                          "<head>\n"
                          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                          <<  QString("<title>%1</title>\n").arg("strTitle")
                          <<  "</head>\n"
                          "<body bgcolor=#ffffff link=#5000A0>\n"

                         //     "<align='right'> " << datefich << "</align>"
                          "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                      // headers
                      out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                      for (int column = 0; column < columnCount; column++)
                          if (!ui->tab_theme->isColumnHidden(column))
                              out << QString("<th>%1</th>").arg(ui->tab_theme->model()->headerData(column, Qt::Horizontal).toString());
                      out << "</tr></thead>\n";

                      // data table
                      for (int row = 0; row < rowCount; row++) {
                          out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                          for (int column = 0; column < columnCount; column++) {
                              if (!ui->tab_theme->isColumnHidden(column)) {
                                  QString data = ui->tab_salle->model()->data(ui->tab_theme->model()->index(row, column)).toString().simplified();
                                  out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                              }
                          }
                          out << "</tr>\n";
                      }
                      out <<  "</table> </center>\n"
                          "</body>\n"
                          "</html>\n";

                QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                  if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                 QPrinter printer (QPrinter::PrinterResolution);
                  printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                printer.setOutputFileName(fileName);

                 QTextDocument doc;
                  doc.setHtml(strStream);
                  doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                  doc.print(&printer);
}

void Salle::on_pushButton_5_clicked()
{
    //imprimer

           QPrinter printer;

           printer.setPrinterName("desiered printer name");

         QPrintDialog dialog(&printer,this);

           if(dialog.exec()== QDialog::Rejected)

               return;
}

void Salle::on_pushButton_imprimerdeco_clicked()
{
    //imprimer

       QPrinter printer;

       printer.setPrinterName("desiered printer name");

     QPrintDialog dialog(&printer,this);

       if(dialog.exec()== QDialog::Rejected)

           return;
}
