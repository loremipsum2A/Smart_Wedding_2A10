#include "offre.h"
#include "gestionoffre.h"
#include "ui_gestionoffre.h"
#include "ui_menu.h"
#include "menu.h"
#include <QDialog>
#include "offre.h"
#include <QPrinter>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlError>
#include <QPrintDialog>
#include <QTextStream>
#include <QFileDialog>
#include <QFileInfo>
#include <QTextDocument>

gestionoffre::gestionoffre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionoffre)
{
    ui->setupUi(this);
    son=new QSound(":/sons/click.wav");
    ui->le_num_3->setValidator(new QIntValidator(0, 9999999, this));
    ui->taboffre->setModel(O1.afficher());

    QSqlQuery query1,query2, query3,query4;
    query1.prepare("SELECT ID_DEC FROM DECORATEUR");
    if(query1.exec())
    {

            while(query1.next())
            {
                ui->comboBox_2->addItem(query1.value(0).toString());
                ui->comboBox_17->addItem(query1.value(0).toString());
            }
    }

    query2.prepare("SELECT ID FROM SALLE");
    if(query2.exec())
    {

            while(query2.next())
            {
                ui->comboBox_3->addItem(query2.value(0).toString());
                ui->comboBox_19->addItem(query2.value(0).toString());
            }
    }
    query3.prepare("SELECT ID_TRAITEUR FROM BUFFET");
    if(query3.exec())
    {

            while(query3.next())
            {
                ui->comboBox_4->addItem(query3.value(0).toString());
                ui->comboBox_18->addItem(query3.value(0).toString());
            }
    }
    query4.prepare("SELECT ID_TROUPE FROM TROUPE");
    if(query4.exec())
    {

            while(query4.next())
            {
                ui->comboBox->addItem(query4.value(0).toString());
                ui->comboBox_20->addItem(query4.value(0).toString());
            }
    }
}

gestionoffre::~gestionoffre()
{
    delete ui;
}

void gestionoffre::on_pushButton_7_clicked()
{
    son->play();
    int num_offre=ui->le_num_3->text().toInt();
    QString periode=ui->lineEdit_11->text();
    QString type=ui->lineEdit_13->text();
    int prix_offre=ui->le_prix_3->text().toInt();
    int id_traiteur=ui->comboBox_4->currentText().toInt();
    int id_troupe=ui->comboBox->currentText().toInt();
    int id_dec=ui->comboBox_2->currentText().toInt();
    int id=ui->comboBox_3->currentText().toInt();
    Offre O (num_offre,periode,type,prix_offre,id_traiteur,id_troupe,id_dec,id);
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

void gestionoffre::on_pushButton_27_clicked()
{
    son->play();
    int num_offre=ui->lineEdit_39->text().toInt();
    QString periode=ui->lineEdit_37->text();
    QString type=ui->lineEdit_38->text();
    int prix_offre=ui->lineEdit_36->text().toInt();
    int id_traiteur=ui->comboBox_18->currentText().toInt();
    int id_troupe=ui->comboBox_20->currentText().toInt();
    int id_dec=ui->comboBox_17->currentText().toInt();
    int id=ui->comboBox_19->currentText().toInt();
    QString value;

            QSqlQuery query;
            query.prepare("UPDATE OFFRE SET   periode='"+periode+"', type='"+type+"', prix_offre=:prix_offre, id_traiteur=:id_traiteur , id_troupe=:id_troupe , id_dec=:id_dec , id=:id where num_offre=:num_offre");
            query.bindValue(":num_offre", num_offre); // to prevent sql injection
            query.bindValue(":prix_offre", prix_offre);
            query.bindValue(":id_traiteur", id_traiteur);
            query.bindValue(":id_troupe", id_troupe);
            query.bindValue(":id_dec", id_dec);
            query.bindValue(":id", id);

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

void gestionoffre::on_pushButton_6_clicked()
{
    son->play();
    QMessageBox msgBox;
    if(O1.supprimer(offreSelect))
       { msgBox.setText("Suppression avec succes.");
    ui->taboffre->setModel(O1.afficher());

    }
    else
        msgBox.setText("Echec de suppression");

            msgBox.exec();
}

void gestionoffre::on_pushButton_17_clicked()
{
    son->play();
    QPrinter printer;

        printer.setPrinterName("Printer");

      QPrintDialog dialog(&printer,this);

        if(dialog.exec()== QDialog::Rejected)

            return;
}

void gestionoffre::on_pushPDF_clicked()
{
    son->play();
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

void gestionoffre::on_lineEdit_3_textChanged(const QString &arg1)
{
    ui->taboffre->setModel(O1.rechercher(ui->comboBox_5->currentText(),arg1));
}

void gestionoffre::on_taboffre_activated(const QModelIndex &index)
{
    QSqlQuery query;
          query.prepare("SELECT * FROM OFFRE WHERE num_offre=:val");//accede l sql pour manipulé its statement
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

void gestionoffre::on_taboffre_clicked(const QModelIndex &index)
{
    son->play();
     offreSelect=ui->taboffre->model()->data(index.sibling(index.row(),0)).toInt();
}

void gestionoffre::on_quitter_bt_clicked()
{
    son->play();
    Menu *m = new Menu();
    m->show();
    this->hide();
}


