#ifndef STUDENT_H
#define STUDENT_H

#include <QDialog>
#include <QMap>

namespace Ui {
class student;
}

class student : public QDialog
{
    Q_OBJECT

public:
    explicit student(QWidget *parent = 0);
    ~student();

private slots:
	/*
    void on_campusBox_currentIndexChanged(const QString &arg1);

    void on_selectedCampuses_listView_activated(const QModelIndex &index);

    void on_campus_selectView_activated(const QModelIndex &index);

    void on_listWidget_clicked(const QModelIndex &index);

    void on_souvenir_listWidget_clicked(const QModelIndex &index);

    void on_souvenir_listWidget_currentTextChanged(const QString &currentText);

    void on_spinBox_purchase_valueChanged(int arg1);

    void on_add_to_cart_clicked();

    void on_remove_from_cart_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_commandLinkButton_clicked();
	*/
	void on_commandLinkButton_clicked();


    void on_commandLinkButton_2_clicked();

private:
    Ui::student *ui;
    unsigned int numberOfSouvenirs;
    QMap<QString, double> receipt;
    //store currently selected campuses and send them to a separate UI
};

#endif // STUDENT_H
