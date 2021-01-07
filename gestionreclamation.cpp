#include "gestionreclamation.h"
#include "ui_gestionreclamation.h"
#include "ui_menu.h"
#include "menu.h"

gestionreclamation::gestionreclamation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionreclamation)
{
    ui->setupUi(this);
    son=new QSound(":/sons/click.wav");


    ui->lineEdit_5->setValidator(new QIntValidator(0, 9999999, this));

    ui->tabrec->setModel(R1.afficher());

    R1.remplir(ui->comboBox_7);
    R1.remplir(ui->comboBox_8);

    ui->dateEdit->setDate(QDate::currentDate());

    QSqlQuery query3;
    query3.prepare("SELECT ID FROM RESERVATION");
    if(query3.exec())
    {

            while(query3.next())
            {
                ui->comboBox_7->addItem(query3.value(1).toString());
                ui->comboBox_8->addItem(query3.value(1).toString());
            }
    }
}

gestionreclamation::~gestionreclamation()
{
    delete ui;
}

void gestionreclamation::on_pushButton_21_clicked()
{
    son->play();
    int ref_rec=ui->lineEdit_5->text().toInt();
    QString date_rec=ui->dateEdit->text();
    QString sujet=ui->lineEdit_15->text();
    QString description=ui->textEdit->toPlainText();
    int id=ui->comboBox_7->currentText().toInt();
    QString avis = "";
    reclamation R (ref_rec,date_rec,sujet,description,id);
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

void gestionreclamation::on_pushButton_28_clicked()
{
    son->play();
    int ref_rec=ui->lineEdit_14->text().toInt();
    QString date_rec=ui->dateEdit_2->text();
    QString sujet=ui->lineEdit_19->text();
    QString description=ui->textEdit_2->toPlainText();
    int id=ui->comboBox_8->currentText().toInt();
    QString value;

            QSqlQuery query;
            query.prepare("UPDATE REC SET DATE_REC='"+date_rec+"', SUJET='"+sujet+"', DESCRIPTION='"+description+"',ID=:ID where ref_rec=:ref_rec");
            query.bindValue(":ref_rec", ref_rec);
            query.bindValue(":ID", id);

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

void gestionreclamation::on_pushButton_2_clicked()
{
    son->play();
    QMessageBox msgBox;
    if(R1.supprimer(recSelect))
       { msgBox.setText("Suppression avec succes.");
    ui->tabrec->setModel(R1.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
}

void gestionreclamation::on_pushButton_18_clicked()
{
    son->play();
    QPrinter printer;

        printer.setPrinterName("Printer");

      QPrintDialog dialog(&printer,this);

        if(dialog.exec()== QDialog::Rejected)

            return;
}

void gestionreclamation::on_pushPDF1_clicked()
{
    son->play();
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

void gestionreclamation::on_lineEdit_7_textChanged(const QString &arg1)
{
    ui->tabrec->setModel(R1.rechercher(ui->comboBox_6->currentText(),arg1));
}

void gestionreclamation::on_tabrec_activated(const QModelIndex &index)
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

void gestionreclamation::on_tabrec_clicked(const QModelIndex &index)
{
    son->play();
    recSelect=ui->tabrec->model()->data(index.sibling(index.row(),0)).toInt();
}


void gestionreclamation::on_quitter_bt_clicked()
{
    son->play();
    Menu *m = new Menu();
    m->show();
    this->hide();
}
