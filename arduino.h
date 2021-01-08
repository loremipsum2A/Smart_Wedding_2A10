#ifndef ARDUINO_H
#define ARDUINO_H
<<<<<<< HEAD
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QObject>

class Arduino
{
public:
    Arduino();
=======
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>


class arduino
{
public:
    arduino();
>>>>>>> 4f00f843afcdb778f75233acf25940670d89da8e
    int connect_arduino();
    int close_arduino();
    int write_to_arduino(QByteArray);
    QByteArray read_from_arduino();
<<<<<<< HEAD
    QSerialPort* getserial(){return serial;}
    QString getarduino_port_name(){return arduino_port_name;}
private:
    QSerialPort* serial;
=======
    QSerialPort * getserial();
    QString getarduino_port_name();
private:
    QSerialPort * serial;
>>>>>>> 4f00f843afcdb778f75233acf25940670d89da8e
    static const quint16 arduino_uno_vendor_id=9025;
    static const quint16 arduino_uno_producy_id=67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data;
<<<<<<< HEAD
=======


>>>>>>> 4f00f843afcdb778f75233acf25940670d89da8e
};

#endif // ARDUINO_H
