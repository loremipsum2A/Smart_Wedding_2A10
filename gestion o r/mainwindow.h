#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "offre.h"
#include "reclamation.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_clicked();

    void on_taboffre_clicked(const QModelIndex &index);

    void on_taboffre_activated();

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_pushButton_17_clicked();

private:
    Ui::MainWindow *ui;
    Offre O1;
    reclamation R1;
    int offreSelect;
};
#endif // MAINWINDOW_H
