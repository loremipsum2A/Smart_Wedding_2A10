#include "historique_avis.h"
#include "ui_historique_avis.h"
#include "menu.h"
#include "ui_menu.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

historique_avis::historique_avis(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::historique_avis)
{
    ui->setupUi(this);
    son=new QSound(":/sons/click.wav");
    //raed
    /*QFile inputFile("C:\\Users\\21694\\Desktop\\Historique.txt");
    if (inputFile.open(QIODevice::ReadOnly))
    {

       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString Avis1= in.readLine();
        ui->textEdit->append(Avis1);
       }
       inputFile.close();
    }
    int ret=A.connect_arduino();
        switch(ret)
        {
        case(0):qDebug() <<"arduino is available and connected to :"<<A.getarduino_port_name();
            break;
        case(1):qDebug() <<"arduino is available but not connected to :"<<A.getarduino_port_name();
            break;
        case(-1):qDebug() <<"arduino is not available";
            break;

        }

        QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(updatelabel()));*/
}


historique_avis::~historique_avis()
{
    delete ui;
}
void historique_avis::updatelabel()
{
    /*data=A.read_from_arduino();
    QString data_string=QString(data);
    qDebug()<<data;
    if (data=="1")
    {
        QFile file("C:/Users/21694/Desktop/Historique.txt");
        file.open(QIODevice::Append | QIODevice::Text);
        QTextStream stream(&file);
        stream << "Satisfait" << endl;

        file.close();
    }
    else
    {
        QFile file("C:/Users/21694/Desktop/Historique.txt");
        file.open(QIODevice::Append | QIODevice::Text);
        QTextStream stream(&file);
        stream << "Non satisfait" << endl;

        file.close();
    }*/
}

void historique_avis::on_pushButton_clicked()
{
    son->play();
    Menu *m = new Menu();
    m->show();
    this->hide();
}
