#include "chosencampusclass.h"
#include "ui_chosencampusclass.h"
#include "asu.h"
#include "dbmanager.h"

chosencampusclass::chosencampusclass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chosencampusclass)
{
    ui->setupUi(this);

    QStringList campusNames = DbManager::instance().campusNames();

      //      ui->chosencampus_listview->addItems(campusNames);
    ui->choosecampus_listwidget->addItems(campusNames);

}

chosencampusclass::~chosencampusclass()
{
    delete ui;
}

void chosencampusclass::on_finish_button_clicked()
{
    asu asuWindow;
    asuWindow.setModal(true);
    asuWindow.exec();
}


void chosencampusclass::on_choosecampus_listwidget_itemDoubleClicked(QListWidgetItem *item)
{

    ui->choosecampus_listwidget2->addItem(item->text());
    campusesToVisit.append(item->text());
    ui->choosecampus_listwidget->takeItem(ui->choosecampus_listwidget->row(item));
    delete item;

}



void chosencampusclass::on_choosecampus_listwidget2_itemDoubleClicked(QListWidgetItem *item)
{
    ui->choosecampus_listwidget->addItem(item->text());
    campusesToVisit.removeOne(item->text());
    ui->choosecampus_listwidget2->takeItem(ui->choosecampus_listwidget2->row(item));
    delete item;

}
