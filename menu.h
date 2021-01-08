#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include <QSound>

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_ge_emp_clicked();

    void on_decnx_bt_clicked();

    void on_ge_client_clicked();

    void on_ge_offres_clicked();

    void on_ge_reclam_clicked();

    void on_ge_salles_clicked();

    void on_ge_cong_clicked();

    void on_pushButton_clicked();

private:
    Ui::Menu *ui;
    QSound *son;
};

#endif // MENU_H
