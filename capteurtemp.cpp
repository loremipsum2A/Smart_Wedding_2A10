#include "capteurtemp.h"
#include "ui_capteurtemp.h"
#include <QObject>
#include <QStringList>

Capteurtemp::Capteurtemp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Capteurtemp)
{
    ui->setupUi(this);
    //moshkel lena

    /*int ret=A.connect_arduino();
    switch(ret)
    {
    case(0):qDebug() <<"arduino is available and connected to :"<<A.getarduino_port_name();
        break;
    case(1):qDebug() <<"arduino is available but not connected to :"<<A.getarduino_port_name();
        break;
    case(-1):qDebug() <<"arduino is not available";
        break;

    }

    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(readSerial()));*/



}

Capteurtemp::~Capteurtemp()
{
    delete ui;
}

void Capteurtemp::readSerial()
{
    /*QString serialBuffer(A.read_from_arduino());
    QStringList bufferSplit = serialBuffer.split(",");

 //qDebug() << A.read_from_arduino();
 qDebug() << serialBuffer;

    if(serialBuffer<3)
    {
        data = A.read_from_arduino();


        serialBuffer += QString::fromStdString(data.toStdString());
       // Capteurtemp::update_lcdnumber("20");
       // qDebug() << serialBuffer;

    }
    else
    {
        qDebug() << "here";
        qDebug() << bufferSplit;

        Capteurtemp::update_lcdnumber(bufferSplit[1]);
        serialBuffer="";
    }

// Capteurtemp::update_lcdnumber(command(A.read_from_arduino()));

    //qDebug() << "serial port works";*/
}

void Capteurtemp::update_lcdnumber(const QString sensor_reading)
{
    //ui->tempLcdNumber->display(sensor_reading);
}



