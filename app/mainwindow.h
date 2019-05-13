#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "student.h"
#include "admin/administration.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_login_pressed();
    void on_login_clicked();

private:
    Ui::MainWindow *ui;
    student* studentPage;
    administration* adminPage;
    QString username;
    QString password;


};

#endif // MAINWINDOW_H
