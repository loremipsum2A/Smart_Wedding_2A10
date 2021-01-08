#include "gestionavis.h"
#include "ui_gestionavis.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <iostream>
GestionAvis::GestionAvis(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GestionAvis)
{
    ui->setupUi(this);

    int ret = A.connect_arduino();
        switch (ret)
        {
            case(0):qDebug()<<"arduino is available and connected to :" << A.getarduino_port_name();
            break;
            case(1):qDebug()<<"arduino is available but not connected to :" << A.getarduino_port_name();
            break;
            case(-1):qDebug()<<"arduino is not available";
            break;

        }
        QObject::connect(A.getserial(), SIGNAL(readyRead()), this, SLOT(update_label()));

        QSqlQuery *query=new QSqlQuery();
        QSqlQueryModel* model=new QSqlQueryModel();
        query->prepare("SELECT REF_REC FROM REC ");
        query->exec();
        model->setQuery(*query);
        ui->comboBox->setModel(model);

   son = new QSound(":/son/thank-you-come-again_JAPcAiH.wav");
}

GestionAvis::~GestionAvis()
{
    delete ui;
}
//like
void GestionAvis::on_pushButton_clicked()
{
    A.write_to_arduino("1");
    son->play();
}
//dislike
void GestionAvis::on_pushButton_2_clicked()
{
    A.write_to_arduino("0");
    son->play();
}

void GestionAvis::update_label()
{
    data=A.read_from_arduino();
    QString idr = ui->comboBox->currentText();

    QString like = "LIKE";
    QString dislike = "DISLIKE";
    QSqlQuery query;

    if(data=="1")
    {
        query.prepare("UPDATE REC SET AVIS ='"+like+"' where ref_rec ='"+idr+"'");
        query.bindValue(":id", idr);
        query.exec();
    }
    else if (data=="0")
    {
        query.prepare("UPDATE REC SET AVIS ='"+dislike+"' where ref_rec ='"+idr+"'");
        query.bindValue(":id", idr);
        query.exec();
    }

}
