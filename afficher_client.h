#ifndef AFFICHER_CLIENT_H
#define AFFICHER_CLIENT_H
#include"client.h"
#include <QDialog>

namespace Ui {
class afficher_client;
}

class afficher_client : public QDialog
{
    Q_OBJECT

public:
    explicit afficher_client(QWidget *parent = nullptr);
    void setclient(Client c);
    ~afficher_client();

private:
    Ui::afficher_client *ui;
};

#endif // AFFICHER_CLIENT_H
