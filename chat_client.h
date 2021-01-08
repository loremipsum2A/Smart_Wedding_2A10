#ifndef CHAT_CLIENT_H
#define CHAT_CLIENT_H

#include <QDialog>
#include <QTcpSocket>
namespace Ui {
class chat_client;
}

class chat_client : public QDialog
{
    Q_OBJECT

public:
    explicit chat_client(QWidget *parent = nullptr);
    ~chat_client();
private slots:
    void on_pushButton_Connect_clicked() ;  // Connect button
    void on_pushButton_Send_clicked() ; //  Send button

    void sockt_recv_data();
    void socket_disconnect();
private:
    Ui::chat_client *ui;
     QTcpSocket *m_socket;
};

#endif // CHAT_CLIENT_H
