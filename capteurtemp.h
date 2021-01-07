#ifndef CAPTEURTEMP_H
#define CAPTEURTEMP_H

#include <QDialog>
#include "arduino.h"

namespace Ui {
class Capteurtemp;
}

class Capteurtemp : public QDialog
{
    Q_OBJECT

public:

    void update_lcdnumber(const QString);
    explicit Capteurtemp(QWidget *parent = nullptr);
    ~Capteurtemp();
public slots:
    void readSerial();

private:
    Ui::Capteurtemp *ui;
    QByteArray data;
    Arduino A;
};

#endif // CAPTEURTEMP_H
