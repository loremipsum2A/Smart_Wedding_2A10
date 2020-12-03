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
#include <iostream>
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
#include <QTextStream>
#include <QDateEdit>
#include <QPalette>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->le_num_3->setValidator(new QIntValidator(0, 9999999, this));
    ui->lineEdit_5->setValidator(new QIntValidator(0, 9999999, this));
    ui->taboffre->setModel(O1.afficher());
    ui->tabrec->setModel(R1.afficher());
    ui->pushButton_7->setStyleSheet("background-color : lightpink");
    ui->pushButton_6->setStyleSheet("background-color : lightpink");
    ui->pushButton_27->setStyleSheet("background-color : lightpink");
    ui->pushButton_21->setStyleSheet("background-color : lightpink");
    ui->pushPDF->setStyleSheet("background-color : lightpink");
    ui->pushPDF1->setStyleSheet("background-color : lightpink");
    ui->pushButton_17->setStyleSheet("background-color : lightpink");
    ui->pushButton_18->setStyleSheet("background-color : lightpink");
    ui->pushButton_2->setStyleSheet("background-color : lightpink");
    ui->pushButton_28->setStyleSheet("background-color : lightpink");
    ui->comboBox_5->setStyleSheet("background-color : pink");
    ui->comboBox_6->setStyleSheet("background-color : pink");
    ui->comboBox_17->setStyleSheet("background-color : pink");
    ui->comboBox_18->setStyleSheet("background-color : pink");
    ui->comboBox_19->setStyleSheet("background-color : pink");
    ui->comboBox_2->setStyleSheet("background-color : pink");
    ui->comboBox_20->setStyleSheet("background-color : pink");
    ui->comboBox_3->setStyleSheet("background-color : pink");
    ui->comboBox_4->setStyleSheet("background-color : pink");
    ui->comboBox->setStyleSheet("background-color : pink");
    ui->taboffre->setStyleSheet("background-color : lightpink");
    ui->tabrec->setStyleSheet("background-color : lightpink");
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

    if (test==true and num_offre!=0 )
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
    QString date_rec=ui->dateEdit->text();
    QString sujet=ui->lineEdit_15->text();
    QString description=ui->textEdit->toPlainText();
    reclamation R (ref_rec,date_rec,sujet,description);
    bool test=R.ajouter();

    if (test==true and ref_rec!=0 )
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
//imprimer offre
void MainWindow::on_pushButton_17_clicked()
{
    QPrinter printer;

        printer.setPrinterName("desiered printer name");

      QPrintDialog dialog(&printer,this);

        if(dialog.exec()== QDialog::Rejected)

            return;
}
// PDF offre
void MainWindow::on_pushPDF_clicked()
{
    QString strStream;
                      QTextStream out(&strStream);

                      const int rowCount = ui->taboffre->model()->rowCount();
                      const int columnCount = ui->taboffre->model()->columnCount();

                      out <<  "<html>\n"
                          "<head>\n"
                          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                          <<  QString("<title>%1</title>\n").arg("strTitle")
                          <<  "</head>\n"
                          "<body bgcolor=#ffffff link=#5000A0>\n"

                         //     "<align='right'> " << datefich << "</align>"
                          "<center> <H1>Liste des offres </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                      // headers
                      out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                      for (int column = 0; column < columnCount; column++)
                          if (!ui->taboffre->isColumnHidden(column))
                              out << QString("<th>%1</th>").arg(ui->taboffre->model()->headerData(column, Qt::Horizontal).toString());
                      out << "</tr></thead>\n";

                      // data table
                      for (int row = 0; row < rowCount; row++) {
                          out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                          for (int column = 0; column < columnCount; column++) {
                              if (!ui->taboffre->isColumnHidden(column)) {
                                  QString data = ui->taboffre->model()->data(ui->taboffre->model()->index(row, column)).toString().simplified();
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
 // supprimer reclamation
void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox msgBox;
    if(R1.supprimer(recSelect))
       { msgBox.setText("Suppression avec succes.");
    ui->tabrec->setModel(R1.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
}

void MainWindow::on_tabrec_clicked(const QModelIndex &index)
{
    recSelect=ui->tabrec->model()->data(index.sibling(index.row(),0)).toInt();

}

void MainWindow::on_tabrec_activated()
{
    QSqlQuery query;
          query.prepare("SELECT * FROM REC WHERE ref_rec=:val");
          query.bindValue(":val",recSelect);
          if (query.exec())
          {

              while(query.next())
              {
                  ui->lineEdit_14->setText(query.value(0).toString());
                  ui->dateEdit_2->setDate(query.value(1).toDate());
                  ui->lineEdit_19->setText(query.value(2).toString());
                  ui->textEdit_2->setText(query.value(3).toString());

              }

               }

              else {
                      QMessageBox::critical(this,tr("error::"), query.lastError().text());
              }
}
// rechercher reclamation
void MainWindow::on_lineEdit_7_textChanged(const QString &arg1)
{
     ui->tabrec->setModel(R1.rechercher(ui->comboBox_6->currentText(),arg1));
}
// imprimer reclamation
void MainWindow::on_pushButton_18_clicked()
{
    QPrinter printer;

        printer.setPrinterName("desiered printer name");

      QPrintDialog dialog(&printer,this);

        if(dialog.exec()== QDialog::Rejected)

            return;
}
// PDF reclamation
void MainWindow::on_pushPDF1_clicked()
{
    QString strStream;
                      QTextStream out(&strStream);

                      const int rowCount = ui->tabrec->model()->rowCount();
                      const int columnCount = ui->tabrec->model()->columnCount();

                      out <<  "<html>\n"
                          "<head>\n"
                          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                          <<  QString("<title>%1</title>\n").arg("strTitle")
                          <<  "</head>\n"
                          "<body bgcolor=#ffffff link=#5000A0>\n"

                         //     "<align='right'> " << datefich << "</align>"
                          "<center> <H1>Liste des reclamations </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                      // headers
                      out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                      for (int column = 0; column < columnCount; column++)
                          if (!ui->tabrec->isColumnHidden(column))
                              out << QString("<th>%1</th>").arg(ui->tabrec->model()->headerData(column, Qt::Horizontal).toString());
                      out << "</tr></thead>\n";

                      // data table
                      for (int row = 0; row < rowCount; row++) {
                          out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                          for (int column = 0; column < columnCount; column++) {
                              if (!ui->tabrec->isColumnHidden(column)) {
                                  QString data = ui->tabrec->model()->data(ui->tabrec->model()->index(row, column)).toString().simplified();
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
// modification reclamation
void MainWindow::on_pushButton_28_clicked()
{

    int ref_rec=ui->lineEdit_14->text().toInt();
    QString date_rec=ui->dateEdit_2->text();
    QString sujet=ui->lineEdit_19->text();
    QString description=ui->textEdit_2->toPlainText();
    QString value;

            QSqlQuery query;
            query.prepare("UPDATE REC SET   DATE_REC='"+date_rec+"', SUJET='"+sujet+"', DESCRIPTION='"+description+"' where ref_rec=:ref_rec");
            query.bindValue(":ref_rec", ref_rec);

            if (query.exec())
            {
                QMessageBox msgBox;
                  msgBox.setText("MODIFIED.");
                  msgBox.exec();
             ui->tabrec->setModel(R1.afficher());
            }

            else
            {
                QMessageBox::critical(this,tr("error::"), query.lastError().text());
            }
}

void MainWindow::on_tabrec_activated(const QModelIndex &index)
{
    QString val=ui->tabrec->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("SELECT * FROM REC WHERE REF_REC='"+val+"' or SUJET='"+val+"' or DESCRIPTION='"+val+"' ");
    if (query.exec())
    {
        while (query.next())
        {
            ui->lineEdit_14->setText(query.value(0).toString());
            ui->dateEdit_2->setDate(query.value(1).toDate());
            ui->lineEdit_19->setText(query.value(2).toString());
            ui->textEdit_2->setText(query.value(3).toString());
        }
    }
}

void MainWindow::on_taboffre_activated(const QModelIndex &index)
{
    QString val=ui->taboffre->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("SELECT * FROM OFFRE WHERE NUM_OFFRE='"+val+"' or PERIODE='"+val+"' or TYPE='"+val+"' or PRIX_OFFRE='"+val+"' ");
    if (query.exec())
    {
        while (query.next())
        {
            ui->lineEdit_39->setText(query.value(0).toString());
            ui->lineEdit_37->setText(query.value(1).toString());
            ui->lineEdit_38->setText(query.value(2).toString());
            ui->lineEdit_36->setText(query.value(3).toString());
        }
    }
}
