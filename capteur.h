#ifndef CAPTEUR_H
#define CAPTEUR_H

#include <QDialog>

namespace Ui {
class capteur;
}

class capteur : public QDialog
{
    Q_OBJECT

public:
    explicit capteur(QWidget *parent = nullptr);
    ~capteur();

private:
    Ui::capteur *ui;
};

#endif // CAPTEUR_H
