#include "arduino.h"
<<<<<<< HEAD


Arduino::Arduino()
=======
#include <QDebug>

arduino::arduino()
>>>>>>> 4f00f843afcdb778f75233acf25940670d89da8e
{
   data="";
   arduino_port_name="";
   arduino_is_available=false;
   serial= new QSerialPort;

}
<<<<<<< HEAD

int Arduino::connect_arduino()
{
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts())
    {
        if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier())
        {
            if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier() == arduino_uno_producy_id)
            {
                arduino_is_available=true;
                arduino_port_name=serial_port_info.portName();
            }
        }
    }
    qDebug() <<"arduino_port_name is :"<<arduino_port_name;
    if(arduino_is_available)
    {
        serial->setPortName(arduino_port_name);
        if(serial->open(QSerialPort::ReadWrite))
        {
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);
            return 0;
        }
        return 1;
    }
    return -1;
}

int Arduino::close_arduino()
{
    if(serial->isOpen())
    {
        serial->close();
        return 0;
    }
    return 1;
}

QByteArray Arduino::read_from_arduino()
=======
QString arduino::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort*arduino::getserial()
{
    return serial;
}

int arduino::connect_arduino()
{
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()){
        if (serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier())
        {
            if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier()== arduino_uno_producy_id)

         {
        arduino_is_available=true;
        arduino_port_name=serial_port_info.portName();
        }}}
        qDebug()<<"arduino_port_name is :"<< arduino_port_name;
        if(arduino_is_available){
            serial->setPortName(arduino_port_name);
            if (serial->open(QSerialPort::ReadWrite)){
               serial->setBaudRate(QSerialPort::Baud9600);
               serial->setDataBits(QSerialPort::Data8);
               serial->setParity(QSerialPort::NoParity);
               serial->setStopBits(QSerialPort::OneStop);
               serial->setFlowControl(QSerialPort::NoFlowControl);
               return 0;
            }return 1 ;
        }



    return -1 ;



    }
int arduino::close_arduino()
{
    if(serial->isOpen())
    {
    serial->close();
    return 0;
    }return 1;

}
int arduino::write_to_arduino(QByteArray d )
{
    if (serial->isWritable())
    {
        serial->write(d);
    }
    else
        qDebug()<<"error en ecriture";
}
QByteArray arduino::read_from_arduino()
>>>>>>> 4f00f843afcdb778f75233acf25940670d89da8e
{
    if(serial->isReadable())
    {
        data=serial->readAll();
        return data;
    }
<<<<<<< HEAD
}

int Arduino::write_to_arduino(QByteArray d)
{
    if(serial->isWritable())
    {
        serial->write(d);
    }
    else
    {
        qDebug() <<"Couldn't write to serial!";
    }
=======

>>>>>>> 4f00f843afcdb778f75233acf25940670d89da8e
}
