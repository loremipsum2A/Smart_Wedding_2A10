#ifndef GESTIONAVIS_H
#define GESTIONAVIS_H

#include <QDialog>
#include <QSound>
#include "arduino.h"
#include <QDebug>

namespace Ui {
class GestionAvis;
}

class GestionAvis : public QDialog
{
    Q_OBJECT

public:
    explicit GestionAvis(QWidget *parent = nullptr);
    ~GestionAvis();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void update_label();

private:
    Ui::GestionAvis *ui;
    QSound *son;
    Arduino A;
    QByteArray data;
};

#endif // GESTIONAVIS_H
