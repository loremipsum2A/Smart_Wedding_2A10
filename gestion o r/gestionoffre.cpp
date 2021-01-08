#include "gestionoffre.h"
#include "ui_gestionoffre.h"

GestionOffre::GestionOffre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GestionOffre)
{
    ui->setupUi(this);
    ui->le_num_3->setValidator(new QIntValidator(0, 9999999, this));

    ui->taboffre->setModel(O1.afficher());

    ui->pushButton_7->setStyleSheet("background-color : lightpink");
    ui->pushButton_6->setStyleSheet("background-color : lightpink");
    ui->pushButton_27->setStyleSheet("background-color : lightpink");

    ui->pushPDF->setStyleSheet("background-color : lightpink");

    ui->pushButton_17->setStyleSheet("background-color : lightpink");

    ui->comboBox_5->setStyleSheet("background-color : pink");

    ui->comboBox_17->setStyleSheet("background-color : pink");
    ui->comboBox_18->setStyleSheet("background-color : pink");
    ui->comboBox_19->setStyleSheet("background-color : pink");
    ui->comboBox_2->setStyleSheet("background-color : pink");
    ui->comboBox_20->setStyleSheet("background-color : pink");
    ui->comboBox_3->setStyleSheet("background-color : pink");
    ui->comboBox_4->setStyleSheet("background-color : pink");
    ui->comboBox->setStyleSheet("background-color : pink");
    ui->taboffre->setStyleSheet("background-color : lightpink");

    O1.remplir1(ui->comboBox_4);
    O1.remplir1(ui->comboBox_18);
    O1.remplir2(ui->comboBox);
    O1.remplir2(ui->comboBox_20);
    O1.remplir3(ui->comboBox_2);
    O1.remplir3(ui->comboBox_17);
    O1.remplir4(ui->comboBox_3);
    O1.remplir4(ui->comboBox_19);


}

GestionOffre::~GestionOffre()
{
    delete ui;
}

void GestionOffre::on_pushButton_7_clicked()
{
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

void GestionOffre::on_pushButton_27_clicked()
{

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

void GestionOffre::on_pushButton_6_clicked()
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

void GestionOffre::on_pushButton_17_clicked()
{
    QPrinter printer;

        printer.setPrinterName("Printer");

      QPrintDialog dialog(&printer,this);

        if(dialog.exec()== QDialog::Rejected)

            return;
}

void GestionOffre::on_pushPDF_clicked()
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

void GestionOffre::on_lineEdit_3_textChanged(const QString &arg1)
{
     ui->taboffre->setModel(O1.rechercher(ui->comboBox_5->currentText(),arg1));
}

void GestionOffre::on_taboffre_activated(const QModelIndex &index)
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

void GestionOffre::on_taboffre_clicked(const QModelIndex &index)
{
    offreSelect=ui->taboffre->model()->data(index.sibling(index.row(),0)).toInt();
}
