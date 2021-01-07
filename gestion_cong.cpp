#include "gestion_cong.h"
#include "ui_gestion_cong.h"
#include "conge.h"
#include "employe.h"
#include "ui_menu.h"
#include "menu.h"
#include <QMessageBox>
#include <QComboBox>
#include <QSqlQuery>
#include <QIntValidator>


#include <iostream>
#include <QDebug>
#include <QRadioButton>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include <QtPrintSupport/QPrinter>
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


gestion_cong::gestion_cong(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_cong)
{
    ui->setupUi(this);
    son=new QSound(":/sons/click.wav");
    ui->ref_ajouter->setValidator(new QIntValidator(0, 99999999, this));
    ui->ref_admin->setValidator(new QIntValidator(0, 99999999, this));
    ui->comboBox_motif->addItem("maladie");
    ui->comboBox_motif->addItem("voyage");
    ui->comboBox_motif->addItem("maternité");
    ui->comboBox_motif->addItem("raisons personnelles");

    QSqlQuery query;
    query.prepare("SELECT CIN FROM EMPLOYE");
    if(query.exec())
    {

            while(query.next())
            {
                ui->comboBox_CIN->addItem(query.value(0).toString());
                ui->comboBox_cin2->addItem(query.value(0).toString());
            }
    }

}

gestion_cong::~gestion_cong()
{
    delete ui;
}

void gestion_cong::on_pushButton_clicked()
{
    son->play();
    int ref=ui->ref_ajouter->text().toInt();
    int CIN=ui->comboBox_CIN->currentText().toInt();
    QString date_deb=ui->datecong_ajouter->text();
    QString date_fin=ui->datecong2->text();
    QString motif=ui->comboBox_motif->currentText();


    Conge Cg(ref,CIN,date_deb,date_deb,motif);
    bool test=Cg.ajouter();
     QMessageBox msgBox;

     if(test)

     {
         msgBox.setText("Ajout avec succes");
         //ui->tab_cong->setModel(C.afficher());

     }
     else
         msgBox.setText("Echec d'ajout");

     msgBox.exec();
}

void gestion_cong::on_consulter_mesconges_clicked()
{
    son->play();
    Conge C;
    int cin=ui->comboBox_cin2->currentText().toInt();

    if (C.rechercher(cin))
    {
            ui->tab_mesconges->setModel(C.afficher_mesconges(cin));
    }

}

void gestion_cong::on_bt_admin_clicked()
{
    son->play();
    Employe E;
    Conge C;
    if(E.recherche_admin(ui->CIN_admin->text()))
    {
        ui->tab_cong->setModel(C.afficher_admin("en cours"));
    }
}

void gestion_cong::on_bt_accepter_clicked()
{
    son->play();
    QMessageBox msg;
    Employe E;
    Conge C;
    if(E.recherche_admin(ui->CIN_admin->text()) && C.rechercher_ref(ui->ref_admin->text().toInt(),"accepte"))
    {
        msg.setText("acceptation réussie");
        msg.exec();
    }
}

void gestion_cong::on_bt_refuser_clicked()
{
    son->play();
    QMessageBox msg;
    Employe E;
    Conge C;
    if(E.recherche_admin(ui->CIN_admin->text()) && C.rechercher_ref(ui->ref_admin->text().toInt(),"refuse"))
    {
        msg.setText("refus réussi");
        msg.exec();
    }
}

void gestion_cong::on_bt_imprimer_cg_clicked()
{
    son->play();
    QPrinter printer;

          printer.setPrinterName("desiered printer name");

        QPrintDialog dialog(&printer,this);

          if(dialog.exec()== QDialog::Rejected)

              return;
}

void gestion_cong::on_bt_pdf_cg_clicked()
{
    son->play();
    QString strStream;
                          QTextStream out(&strStream);

                          const int rowCount = ui->tab_cong->model()->rowCount();
                          const int columnCount = ui->tab_cong->model()->columnCount();

                          out <<  "<html>\n"
                              "<head>\n"
                              "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                              <<  QString("<title>%1</title>\n").arg("strTitle")
                              <<  "</head>\n"
                              "<body bgcolor=#ffffff link=#5000A0>\n"

                             //     "<align='right'> " << datefich << "</align>"
                              "<center> <H1>Liste des conges </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                          // headers
                          out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                          for (int column = 0; column < columnCount; column++)
                              if (!ui->tab_cong->isColumnHidden(column))
                                  out << QString("<th>%1</th>").arg(ui->tab_cong->model()->headerData(column, Qt::Horizontal).toString());
                          out << "</tr></thead>\n";

                          // data table
                          for (int row = 0; row < rowCount; row++) {
                              out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                              for (int column = 0; column < columnCount; column++) {
                                  if (!ui->tab_cong->isColumnHidden(column)) {
                                      QString data = ui->tab_cong->model()->data(ui->tab_cong->model()->index(row, column)).toString().simplified();
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

void gestion_cong::on_quitter_bt2_clicked()
{
    son->play();
    Menu *m = new Menu();
    m->show();
    this->hide();
}

void gestion_cong::on_excel_clicked()
{
    QTableView *table;

                                table = ui->tab_cong;


                                QString filters("Excel Files (.xls)");

                                QString defaultFilter("Excel Files (*.xls)");

                                QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),

                                                   filters, &defaultFilter);

                                QFile file(fileName);


                                QAbstractItemModel *model =  table->model();

                                if (file.open(QFile::WriteOnly | QFile::Truncate)) {

                                    QTextStream data(&file);

                                    QStringList strList;

                                    for (int i = 0; i < model->columnCount(); i++) {

                                        if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)

                                            strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");

                                        else

                                            strList.append("");

                                    }

                                    data << strList.join(";") << "\n";

                                    for (int i = 0; i < model->rowCount(); i++) {

                                        strList.clear();

                                        for (int j = 0; j < model->columnCount(); j++) {


                                            if (model->data(model->index(i, j)).toString().length() > 0)

                                                strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");

                                            else

                                                strList.append("");

                                        }

                                        data << strList.join(";") + "\n";

                                    }

                                    file.close();

                                    QMessageBox::information(nullptr, QObject::tr("Export excel"),

                                                              QObject::tr("Export avec succes .\n"

                                                                          "Click OK to exit."), QMessageBox::Ok);
                }
}
