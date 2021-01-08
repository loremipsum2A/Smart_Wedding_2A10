#ifndef HISTORIQUE_AVIS_H
#define HISTORIQUE_AVIS_H

#include <QDialog>
#include <QSound>
#include "arduino.h"

namespace Ui {
class historique_avis;
}

class historique_avis : public QDialog
{
    Q_OBJECT

public:
    explicit historique_avis(QWidget *parent = nullptr);
    ~historique_avis();
    void updatelabel();

private slots:
    void on_pushButton_clicked();

private:
    Ui::historique_avis *ui;
    Arduino A;
    QByteArray data;
    QSound *son;

};

#endif // HISTORIQUE_AVIS_H
