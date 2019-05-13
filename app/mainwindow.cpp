#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	//studentPage = new student;

    //studentPage -> show();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    password = ui->lineedit_password->text();
    username = ui->lineedit_username->text();

    if(username == "student" && password == "1234")
    {
        QMessageBox::information(this, "Login", "Login Successful. Welcome Student. ");
        close();
        studentPage = new student;
        studentPage -> show();
    }
    else if(username == "admin" && password == "1234")
    {
        QMessageBox::information(this, "Login", "Login Successful. Welcome Admin. ");
        close();
        adminPage = new administration;
        adminPage -> show();
    }
    else
    {
        QMessageBox::information(this, "Login", "Invalid Login. Try again.  ");
    }
}
void MainWindow::on_login_clicked()
{
}
void MainWindow::on_login_pressed()
{
}
