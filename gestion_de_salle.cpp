#include "gestion_de_salle.h"
#include "ui_gestion_de_salle.h"
#include "decorateur.h"
#include "ui_menu.h"
#include "menu.h"
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
#include "ui_capteurtemp.h"
#include "capteurtemp.h"

gestion_de_salle::gestion_de_salle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_de_salle)
{
    ui->setupUi(this);
    son=new QSound(":/sons/click.wav");
    ui->le_id->setValidator(new QIntValidator(0,9999999,this));
    ui->le_prix->setValidator(new QIntValidator(0,9999999,this));
    ui->le_id_theme->setValidator(new QIntValidator(0,9999999,this));
    ui->le_prix_theme->setValidator(new QIntValidator(0,9999999,this));
    ui->tab_salle->setModel(S.afficher());
    ui->tab_theme->setModel(T.affichert());
    animation = new QPropertyAnimation(ui->heart, "geometry");
                animation->setDuration(9000);
                animation->setStartValue(ui->heart->geometry());
                animation->setEndValue(QRect(200,450,100,50));
                animation->start();
                /*int ret = A.connect_arduino() ;
                switch (ret) {
                case (0) : qDebug ()<<"arduinois available and connected to:"<<A.getarduino_port_name() ;
                    break ;
                case(1) : qDebug () <<"arduino is available but not connected to : "<<A.getarduino_port_name() ;
                    break ;
                 case(-1) : qDebug ()<<"arduino is not available" ;

                }*/


}

gestion_de_salle ::~gestion_de_salle()
{
    delete ui;
}

void gestion_de_salle ::on_Ok_Ajoutsalle_clicked()
{
    son->play();
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

void gestion_de_salle ::on_pb_supprimer1_clicked()
{
    son->play();
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



void gestion_de_salle ::on_Ok_Ajouttheme_clicked()
{
    son->play();
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


void gestion_de_salle ::on_pb_supprimertheme_clicked()
{
    son->play();
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

void gestion_de_salle ::on_tri_nom_clicked()
{
    son->play();
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

void gestion_de_salle ::on_tri_id_clicked()
{
    son->play();
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

void gestion_de_salle ::on_Quitter_Ajoutsalle_clicked()
{
    son->play();
    Menu *m = new Menu();
    m->show();
    this->hide();
}

void gestion_de_salle ::on_tri_id_dec_clicked()
{
    son->play();
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




void gestion_de_salle ::on_tri_nom_dec_clicked()
{
    son->play();

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

void gestion_de_salle ::on_Modifier_Modifiersalle_clicked()
{
    son->play();

    Gestion_salle S;
        QMessageBox msg;
        S.setid(ui->le_id_mod->text().toInt());
       S.setnom(ui->le_mod_nom->text());
        S.setadresse(ui->le_mod_ad->text());
        S.setprix(ui->le_prix_mod->text().toInt());



        bool test=S.modifier(S.getid());
        if(test)
        {
            msg.setText("modification avec succès");
            ui->tab_salle->setModel(S.afficher());
        }
        else
            msg.setText("echec de modification");

        msg.exec();


}

void gestion_de_salle ::on_Modifier_Modifiertheme_clicked()
{
son->play();
    Decorateur T;
        QMessageBox msg;
       T.setiddec(ui->le_id_dec_mod->text().toInt());
       T.setnomdec(ui->le_nom_dec_mod->text());
       T.setnomtheme(ui->le_nom_theme_mod->text());
        T.setadressedec(ui->le_adresse_mod->text());
        T.setprixtheme(ui->le_prix_mod->text().toInt());



        bool test=T.modifier(T.getiddec());
        if(test)
        {
            msg.setText("modification avec succès");
            ui->tab_theme->setModel(T.affichert());
        }
        else
            msg.setText("echec de modification");

        msg.exec();
}

void gestion_de_salle ::on_tri_nom_2_clicked()
{
    son->play();
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


void gestion_de_salle ::on_tri_id_2_clicked()
{
son->play();
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

void gestion_de_salle ::on_tri_id_dec_2_clicked()
{
    son->play();
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


void gestion_de_salle ::on_tri_nom_dec_2_clicked()
{
    son->play();
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


void gestion_de_salle ::on_pushButton_3_clicked()
{
    son->play();
    Decorateur T;
           if (ui->comboBox->currentText()=="id_dec")
           {
               int id_dec=ui->le_recherche->text().toInt();
               if (T.rechercheiddec(id_dec))
               {
                   ui->tab_theme->setModel(T.afficheriddec(id_dec));
               }
           }
           else if(ui->comboBox->currentText()=="Nom_dec")
           {
               QString nom_dec=ui->le_recherche->text();
               if (T.recherchenomdec(nom_dec))
               {
                   ui->tab_theme->setModel(T.affichernomdec(nom_dec));
               }

           }
           else
           {
               QString nom_theme=ui->le_recherche->text();
               if(T.recherchenomtheme(nom_theme))
               {
                   ui->tab_theme->setModel(T.affichernomtheme(nom_theme));
               }
           }
}

void gestion_de_salle ::on_pushButton_clicked()
{
    son->play();

   Gestion_salle S;
        if (ui->comboBox_2->currentText()=="id")
        {
            int id=ui->lineEdit->text().toInt();
            if (S.rechercheid(id))
            {
                ui->tab_salle->setModel(S.afficherid(id));
            }
        }
        else if(ui->comboBox_2->currentText()=="nom")
        {
            QString nom=ui->lineEdit->text();
            if (S.recherchenom(nom))
            {
                ui->tab_salle->setModel(S.affichernom(nom));
            }

        }
        else
        {
            int prix=ui->lineEdit->text().toInt();
            if(S.rechercheprix(prix))
            {
                ui->tab_salle->setModel(S.afficherprix(prix));
            }
        }
}


void gestion_de_salle ::on_pdf_salle_clicked()
{
    son->play();
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

void gestion_de_salle ::on_pdf_decorateur_clicked()
{
    son->play();
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

void gestion_de_salle ::on_pushButton_5_clicked()
{
    son->play();
    //imprimer

           QPrinter printer;

           printer.setPrinterName("desiered printer name");

         QPrintDialog dialog(&printer,this);

           if(dialog.exec()== QDialog::Rejected)

               return;
}

void gestion_de_salle ::on_pushButton_imprimerdeco_clicked()
{
    son->play();
    //imprimer

       QPrinter printer;

       printer.setPrinterName("desiered printer name");

     QPrintDialog dialog(&printer,this);

       if(dialog.exec()== QDialog::Rejected)

           return;
}



void gestion_de_salle ::on_consulter_mod_salle_clicked()
{
    son->play();
   Gestion_salle S;
            QSqlQuery query;
            int id=ui->le_id_mod->text().toInt();
            QString id_string=QString::number(id);
           if(S.rechercheid(id))
           {
               query.prepare("SELECT * FROM SALLE WHERE id like :id");
               query.bindValue(0,id_string);
               query.exec();
               while(query.next()){
               ui->le_mod_nom->setText(query.value(1).toString());
               ui->le_mod_ad->setText(query.value(2).toString());
               ui->le_mod_p->setText(query.value(3).toString());


            }
           }
}



void gestion_de_salle ::on_Modifier_Modifiertheme_2_clicked()
{
    son->play();
    Decorateur T;
             QSqlQuery query;
             int id_dec=ui->le_id_dec_mod->text().toInt();
             QString id_dec_string=QString::number(id_dec);
            if(T.rechercheiddec(id_dec))
            {
                query.prepare("SELECT * FROM DECORATEUR WHERE id_dec like :id_dec");
                query.bindValue(0,id_dec_string);
                query.exec();
                while(query.next()){
                ui->le_nom_dec_mod->setText(query.value(1).toString());
                ui->le_nom_theme_mod->setText(query.value(2).toString());
                ui->le_adresse_mod->setText(query.value(3).toString());
                 ui->le_prix_mod->setText(query.value(4).toString());


             }
            }
}

void gestion_de_salle ::on_pushButton_7_clicked()
{
    /*
     son->play();
     A.getserial()->write("on") ;

    QString status=A.read_from_arduino() ;



        ui->label_6->setText("ventilateur en marche") ;*/
}

void gestion_de_salle ::on_pushButton_6_clicked()
{
    /*
     son->play();
     A.getserial()->write("off") ;
    A.read_from_arduino() ;
    QString status=A.read_from_arduino() ;

        ui->label_6->setText("ventilateur fermee") ;*/

}

void gestion_de_salle::on_Quitter_Ajoutsalle_2_clicked()
{
    son->play();
    Menu *m = new Menu();
    m->show();
    this->hide();
}

void gestion_de_salle::on_captemp_clicked()
{
    son->play();
    Capteurtemp *cap = new Capteurtemp();
    cap->show();
    this->hide();
}
