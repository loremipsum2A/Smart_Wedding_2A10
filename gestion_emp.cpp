#include "gestion_emp.h"
#include "ui_gestion_emp.h"
#include "employe.h"
#include "gestion_cong.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QSqlQuery>
#include <QComboBox>

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

gestion_emp::gestion_emp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_emp)
{
    ui->setupUi(this);
    son=new QSound(":/sons/click.wav");
    ui->cin_ajouter->setValidator(new QIntValidator(0, 99999999, this));
    ui->cin_modifier->setValidator(new QIntValidator(0, 99999999, this));
    ui->cin_supprimer->setValidator(new QIntValidator(0, 99999999, this));
    ui->tel_ajouter->setValidator(new QIntValidator(0, 99999999, this));
    ui->tel_modifier->setValidator(new QIntValidator(0, 99999999, this));
    ui->tab_emp->setModel(E.afficher());
    ui->comboBox_fct->addItem("admin");
    ui->comboBox_fct->addItem("employe");
    ui->comboBox_fct_2->addItem("admin");
    ui->comboBox_fct_2->addItem("employe");
    ui->comboBox_critere->addItem("cin");
    ui->comboBox_critere->addItem("nom");
    ui->comboBox_critere->addItem("prenom");
    connect(ui->bt_gonext, SIGNAL(click()), this, SLOT(openNewWindow()));

}

gestion_emp::~gestion_emp()
{
    delete ui;
}

void gestion_emp::on_btajouter_emp_clicked()
{
    son->play();
    int CIN=ui->cin_ajouter->text().toInt();
    int tel=ui->tel_ajouter->text().toInt();
    int salaire=ui->salaire_ajouter->text().toInt();
    QString nom=ui->nom_ajouter->text();
    QString prenom=ui->prenom_ajouter->text();
    QString date_naissance=ui->date_ajouter->text();
    QString adresse=ui->adresse_ajouter->text();
    QString email=ui->email_ajouter->text();
    QString fonction=ui->comboBox_fct->currentText();

    Employe E(CIN,tel,salaire,nom,prenom,date_naissance,adresse,email,fonction);
    bool test=E.ajouter();
     QMessageBox msgBox;

     if(test)

     {
         msgBox.setText("Ajout avec succes");
         ui->tab_emp->setModel(E.afficher());

     }
     else
         msgBox.setText("Echec d'ajout");

      msgBox.exec();


}

void gestion_emp::on_btsupp_emp_clicked()
{
    son->play();
    Employe E;
    //E.setCIN();
    E.supprimer(ui->cin_supprimer->text().toInt());
    ui->tab_emp->setModel(E.afficher());

}

void gestion_emp::on_pushButton_clicked()
{
    son->play();
    Employe E;
    QSqlQuery query;
    int cin=ui->cin_modifier->text().toInt();
    QString CIN_string=QString::number(cin);
   if(E.recherche(cin))
   {
       query.prepare("SELECT * FROM EMPLOYE WHERE CIN like :cin");
       query.bindValue(0,CIN_string);
       query.exec();
       while(query.next()){
       ui->nom_modifier->setText(query.value(1).toString());
       ui->prenom_modifier->setText(query.value(2).toString());
       QDate date = QDate::fromString(query.value(3).toString(),"dd/MM/yyyy");
       ui->date_modifier->setDate(date);
       ui->adresse_modifier->setText(query.value(4).toString());
       ui->email_modifier->setText(query.value(5).toString());
       ui->tel_modifier->setText(query.value(6).toString());
       ui->comboBox_fct_2->setCurrentText(query.value(7).toString());
       ui->salaire_modifier->setText(query.value(8).toString());}
   }

}

void gestion_emp::on_btmod_emp_clicked()
{
    son->play();
    Employe E;
    QMessageBox msg;
    E.setCIN(ui->cin_modifier->text().toInt());
    E.setPrenom(ui->prenom_modifier->text());
    E.setNom(ui->nom_modifier->text());
    E.setDate(ui->date_modifier->text());
    E.setEmail(ui->email_modifier->text());
    E.setAdresse(ui->adresse_modifier->text());
    E.setTel(ui->tel_modifier->text().toInt());
    E.setFonction(ui->comboBox_fct_2->currentText());
    E.setSalaire(ui->salaire_modifier->text().toInt());

    bool test=E.modifier(E.getCIN());
    if(test)
    {
        msg.setText("modification avec succès");
        ui->tab_emp->setModel(E.afficher());
    }
    else
        msg.setText("echec de modification");

    msg.exec();
}

void gestion_emp::on_recherche_multicritere_clicked()
{
    son->play();
    Employe E;
    if (ui->comboBox_critere->currentText()=="cin")
    {
        int cin=ui->le_valeur->text().toInt();
        if (E.recherche(cin))
        {
            ui->tab_emp->setModel(E.afficher_cin(cin));
        }
    }
    else if(ui->comboBox_critere->currentText()=="nom")
    {
        QString nom=ui->le_valeur->text();
        if (E.recherche_nom(nom))
        {
            ui->tab_emp->setModel(E.afficher_nom(nom));
        }

    }
    else
    {
        QString prenom=ui->le_valeur->text();
        if(E.recherche_prenom(prenom))
        {
            ui->tab_emp->setModel(E.afficher_prenom(prenom));
        }
    }
}

void gestion_emp::on_tri_multicritere_clicked()
{
    son->play();
    Employe E;
    if (ui->comboBox_critere->currentText()=="cin")
    {
        ui->tab_emp->setModel(E.tri_cin());
    }
    else if (ui->comboBox_critere->currentText()=="nom")
    {
        ui->tab_emp->setModel(E.tri_nom());
    }
    else
    {
        ui->tab_emp->setModel(E.tri_prenom());
    }
}

void gestion_emp::on_bt_imprimer_clicked()
{
    son->play();
    QPrinter printer;

          printer.setPrinterName("desiered printer name");

        QPrintDialog dialog(&printer,this);

          if(dialog.exec()== QDialog::Rejected)

              return;
}

void gestion_emp::on_bt_pdf_clicked()
{
    son->play();
    QString strStream;
                          QTextStream out(&strStream);

                          const int rowCount = ui->tab_emp->model()->rowCount();
                          const int columnCount = ui->tab_emp->model()->columnCount();

                          out <<  "<html>\n"
                              "<head>\n"
                              "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                              <<  QString("<title>%1</title>\n").arg("strTitle")
                              <<  "</head>\n"
                              "<body bgcolor=#ffffff link=#5000A0>\n"

                             //     "<align='right'> " << datefich << "</align>"
                              "<center> <H1>Liste des employes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                          // headers
                          out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                          for (int column = 0; column < columnCount; column++)
                              if (!ui->tab_emp->isColumnHidden(column))
                                  out << QString("<th>%1</th>").arg(ui->tab_emp->model()->headerData(column, Qt::Horizontal).toString());
                          out << "</tr></thead>\n";

                          // data table
                          for (int row = 0; row < rowCount; row++) {
                              out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                              for (int column = 0; column < columnCount; column++) {
                                  if (!ui->tab_emp->isColumnHidden(column)) {
                                      QString data = ui->tab_emp->model()->data(ui->tab_emp->model()->index(row, column)).toString().simplified();
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

void gestion_emp::openNewWindow()
{
    g = new gestion_cong();
    g->show();
}

void gestion_emp::on_bt_gonext_clicked()
{
    son->play();
    openNewWindow();
}
