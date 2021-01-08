#include "uimayssa.h"
#include "ui_uimayssa.h"
#include "client.h"
#include "reservation.h"
#include "menu.h"
#include "ui_menu.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQuery>
#include "mainwindow.h"
#include  <QDebug>
#include <QString>
#include <QPrintDialog>
#include "QPainter"
#include "QPdfWriter"
#include "QDesktopServices"
#include "QtPrintSupport/QPrinter"
#include <QPropertyAnimation>
#include <QTextDocument>
#include <QFileDialog>
#include "chat_client.h"
#include "chat_server.h"

uimayssa::uimayssa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::uimayssa)
{
    nbclient=0;
    ui->setupUi(this);
    son=new QSound(":/sons/click.wav");
    MRE=QRegExp("^[0-9a-zA-Z]+([0-9a-zA-Z]*[-._+])*[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)*([0-9a-zA-Z]*[.])[a-zA-Z]{2,6}$");
        ui->comboBox_2->setModel(c.afficher());
        ui->tab_afficher->setModel(c.afficher());
        ui->tab_reservation->setModel(R.afficher());
        ui->lineEdit_CIN->setValidator(new QIntValidator(0,99999999 , this));
        ui->lineEdit_numero_de_telephone->setValidator(new QIntValidator(0,99999999 , this));
        ui->tab_afficher->setModel(c.afficher());
        ui->comboBox_tri->addItem("Nom");
        ui->comboBox_tri->addItem("Prenom");
        ui->comboBox_tri->addItem("CIN");
        ui->comboBox_4->setModel(R.afficher());
        ui->tab_reservation->setModel(R.afficher());
        remplir_cb_clientcin();
/*
        int ret=A.connect_arduino();
             switch(ret){
             case(0):qDebug()<< "arduino is availble and connected to :"<< A.getarduino_port_name();
                 break;
             case(1):qDebug()<< "arduino is availble but not connected to :"<< A.getarduino_port_name();
                 break;
             case(-1):qDebug()<< "arduino is not availble";
             }
             QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));*/

}

        void uimayssa::update_label()
        {
     /*       data=A.read_from_arduino();
            QString DataAsString = QString(data);
            qDebug()<< data;


            if (data == "1"){
                 nbclient++;
                 QString test=QString::number(nbclient);
                ui->label_arduino->setText(test);
            }
            if (data == "2"){
                 nbclient--;
                 QString test=QString::number(nbclient);
                ui->label_arduino->setText(test);
            }*/

        }
void uimayssa::remplir_cb_clientcin()
{

    QSqlQuery qry;
    qry.prepare("SELECT CIN FROM CLIENT");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->comboBox_reser->addItem(qry.value(0).toString());

        }
    }


}

uimayssa::~uimayssa()
{
    delete ui;
}



void uimayssa::on_ajouter_clicked() {

son->play();
int CIN= ui->lineEdit_CIN->text().toInt();
QString Prenom= ui->lineEdit_Prenom->text();
QString Nom= ui->lineEdit_Nom->text();
QString adresse_email = ui->lineEdit_adresse_email->text();
int numero_de_telephone= ui->lineEdit_numero_de_telephone->text().toInt();

Client c (CIN,Prenom,Nom,adresse_email,numero_de_telephone);

bool verifier = MRE.exactMatch(ui->lineEdit_adresse_email->text());


if ( ui->lineEdit_CIN->text()!= "" &&
     ui->lineEdit_Prenom->text()!= "" &&
     ui->lineEdit_Nom->text()!="" &&
     ui->lineEdit_adresse_email->text()!= "" &&
     ui->lineEdit_numero_de_telephone->text()!= "" )

{
    if (!verifier)

    {
        QMessageBox::warning(nullptr, QObject::tr("Ajouter client"),
                    QObject::tr("Vérifier E-mail ! .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
int CIN= ui->lineEdit_CIN->text().toInt();
QString Prenom= ui->lineEdit_Prenom->text();
QString Nom= ui->lineEdit_Nom->text();
QString adresse_email= ui->lineEdit_adresse_email->text();
int numero_de_telephone= ui->lineEdit_numero_de_telephone->text().toInt();

Client c (CIN,Prenom,Nom,adresse_email,numero_de_telephone);

        bool test=c.ajouter();
        if(test)

        {
            ui->tab_afficher->setModel(c.afficher());
            ui->comboBox_2->setModel(c.afficher());
            ui->comboBox_reser->clear();
                  remplir_cb_clientcin();
            QMessageBox::information(nullptr, QObject::tr("Ajouter client"),
                        QObject::tr("client ajouté.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("Ajouter client"),
                        QObject::tr("Ajout echoué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
     }


}
else
{
    QMessageBox::warning(nullptr, QObject::tr("Ajouter client"),
                QObject::tr("Ajout echoué ! Cases vides ! .\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

}





void uimayssa::on_supprimer_clicked()
{
    son->play();
    int CIN= ui->comboBox_2->currentText().toInt();
    bool test = c.supprimer(CIN);
    QMessageBox msg ;
    if (test)
     {
        ui->tab_afficher->setModel(c.afficher());
        ui->tab_reservation->setModel(R.afficher());
        ui->comboBox_reser->clear();
         remplir_cb_clientcin();
    msg.setText("suppression avec succés");
    }
    else
    {
    msg.setText("Echec au niveau de la suppression ");
    }
    msg.exec();
}




void uimayssa::on_modifier_clicked()

 {
        son->play();
        ui->tab_afficher->setModel(c.afficher());
            int CIN=ui->lineEdit_CIN->text().toInt();
            QString Nom=ui->lineEdit_Nom->text();
            QString Prenom=ui->lineEdit_Prenom->text();
            QString adresse_email=ui->lineEdit_adresse_email->text();
            int numero_de_telephone=ui->lineEdit_numero_de_telephone->text().toInt();
            bool test=c.modifier(CIN,Prenom,Nom,adresse_email,numero_de_telephone);
            QMessageBox msg;
            if (test)
             {
                msg.setText("modify avec succés");
                ui->tab_afficher->setModel(c.afficher());
                }
                else
                {
                msg.setText("Echec au niveau de la modif ");
                }
                msg.exec();

            ui->lineEdit_CIN->clear();
            ui->lineEdit_Prenom->clear();
            ui->lineEdit_Nom->clear();
            ui->lineEdit_adresse_email->clear();
            ui->lineEdit_numero_de_telephone->clear();
    }



void uimayssa::on_tri_clicked()
{
    son->play();
    Client c;
        if (ui->comboBox_tri->currentText()=="CIN")
        {
            ui->tab_afficher->setModel(c.tri_CIN());
        }
        else if (ui->comboBox_tri->currentText()=="Prenom")
        {
            ui->tab_afficher->setModel(c.tri_Prenom());
        }
        else
        {
            ui->tab_afficher->setModel(c.tri_Nom());
        }
}

void uimayssa::on_valider_reservation_clicked()
{
             son->play();
             int CIN= ui->comboBox_reser->currentText().toInt();
             int id= ui->id->text().toInt();
             QString datemariage= ui->dateEdit->text();
             int accompteapaye= ui->acompte->text().toInt();
             int numoffre= ui->numoffre->text().toInt();
             reservation R(CIN,id,datemariage,accompteapaye,numoffre) ;
             QMessageBox msg  ;
             bool test=R.valider();
             if(test){
             ui->tab_reservation->setModel(R.afficher());
             ui->comboBox_4->setModel(R.afficher());
              msg.setText("réservation ajouteé");

                     ;}
             else {
                 msg.setText("echec au niveau de l'ajout");
                  }
             msg.exec();
}
void uimayssa::on_supprimer_reservation_clicked()
{
    son->play();
    int CIN= ui->comboBox_4->currentText().toInt();
    bool test = R.supprimer(CIN);
    QMessageBox msg ;
    if (test)
     {
    ui->tab_reservation->setModel(R.afficher());
    msg.setText("suppression avec succés");

    }
    else
    {
    msg.setText("Echec au niveau de la suppression ");
    }
    msg.exec();
}


void uimayssa::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
QString CIN=ui->comboBox_2->currentText();
}
void uimayssa::on_comboBox_4_currentIndexChanged(const QString &arg1)
{
 QString CIN_reservation=ui->comboBox_4->currentText();
}



void uimayssa::on_resmodif_clicked()
{
            son->play();
          ui->tab_reservation->setModel(R.afficher());
         int CIN= ui->comboBox_reser->currentText().toInt();
           int id=ui->id->text().toInt();
           QString datemariage=ui->dateEdit->text();
           int acompteapayer=ui->acompte->text().toInt();
           int numoffre=ui->numoffre->text().toInt();
           bool test=R.modifier(CIN,id,datemariage,acompteapayer,numoffre);
           QMessageBox msg;
           if (test)
            {
               msg.setText("modification avec succés");
               ui->tab_reservation->setModel(R.afficher());
               }
               else
               {
               msg.setText("Echec au niveau de la modif ");
               }
               msg.exec();

           ui->comboBox_reser->clear();
           ui->id->clear();
           ui->dateEdit->clear();
           ui->acompte->clear();
           ui->numoffre->clear();



   }




void uimayssa::on_recherche_textChanged(const QString &arg1)
{
    if(arg1 == ""){
            ui->tab_afficher->setModel(c.afficher());//naabi m tab l je m base de donée te3i
        }else{
            ui->tab_afficher->setModel(c.rechercher(arg1));//naabi m tab l je m base de donée te3i
        }
    }



void uimayssa::on_lineEdit_CIN_returnPressed()
   {
    if("   *champ obligatoire"==ui->lineEdit_CIN->text() || "   id non valide"==ui->lineEdit_CIN->text())
        ui->lineEdit_CIN->clear();
    }


//void MainWindow::on_pushButton_13_clicked()
//{
//    ui->tab_reservation->setModel(R.tri());
//}



void uimayssa::on_rechercheres_textChanged(const QString &arg1)
{
    if(arg1 == ""){
            ui->tab_reservation->setModel(R.afficher());//naabi m tab l je m base de donée te3i
        }else{
            ui->tab_reservation->setModel(R.rechercher(arg1));//naabi m tab l je m base de donée te3i
        }
}

void uimayssa::on_pushButton_2_clicked()
{
    son->play();
    QString strStream;
                    QTextStream out(&strStream);

                    const int rowCount = ui->tab_afficher->model()->rowCount();
                    const int columnCount = ui->tab_afficher->model()->columnCount();

                    out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("strTitle")
                        <<  "</head>\n"
                        "<body bgcolor=#ffffff link=#5000A0>\n"

                       //     "<align='right'> " << datefich << "</align>"
                        "<center> <H1>Liste des clients </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                    // headers
                    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tab_afficher->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tab_afficher->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";

                    // data table
                    for (int row = 0; row < rowCount; row++) {
                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                        for (int column = 0; column < columnCount; column++) {
                            if (!ui->tab_afficher->isColumnHidden(column)) {
                                QString data = ui->tab_afficher->model()->data(ui->tab_afficher->model()->index(row, column)).toString().simplified();
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
                doc.setPageSize(printer.pageRect().size());
                doc.print(&printer);
}

void uimayssa::on_pushButton_3_clicked()
{
    son->play();
    QPrinter printer;

        printer.setPrinterName("desiered printer name");

      QPrintDialog dialog(&printer,this);

        if(dialog.exec()== QDialog::Rejected)

            return;
}

void uimayssa::on_pushButton_clicked()
{
    son->play();
    QString strStream;
                    QTextStream out(&strStream);

                    const int rowCount = ui->tab_reservation->model()->rowCount();
                    const int columnCount = ui->tab_reservation->model()->columnCount();

                    out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("strTitle")
                        <<  "</head>\n"
                        "<body bgcolor=#ffffff link=#5000A0>\n"

                       //     "<align='right'> " << datefich << "</align>"
                        "<center> <H1>Liste des reservations </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                    // headers
                    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tab_afficher->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tab_reservation->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";

                    // data table
                    for (int row = 0; row < rowCount; row++) {
                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                        for (int column = 0; column < columnCount; column++) {
                            if (!ui->tab_reservation->isColumnHidden(column)) {
                                QString data = ui->tab_reservation->model()->data(ui->tab_reservation->model()->index(row, column)).toString().simplified();
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
                doc.setPageSize(printer.pageRect().size());
                doc.print(&printer);
}

void uimayssa::on_pushButton_10_clicked()
{
    son->play();
    Menu *m = new Menu();
    m->show();
    this->hide();
}

void uimayssa::on_pushButton_4_clicked()
{
    son->play();
    QPrinter printer;

       printer.setPrinterName("desiered printer name");

      QPrintDialog dialog(&printer,this);

        if (dialog.exec()== QDialog::Rejected)

            return;
}


void uimayssa::on_pushButton_5_clicked()
{
    QTableView *table;

                                table = ui->tab_afficher;


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

void uimayssa::on_chat1_clicked()
{
    chat_client *w =new chat_client();
    w->show();
    chat_server *s = new chat_server();
    s->show();
}
