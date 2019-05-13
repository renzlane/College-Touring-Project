    #include "student.h"
#include "dbmanager.h"
#include "ui_student.h"
#include "displayinfoclass.h"
#include "chooserouteclass.h"

#include <QStringListModel>
#include <QVariant>
#include <QDir>
#include <QPixmap>

using namespace std;

student::student(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::student)
{
    //while loop to load up all display items
    //while(
    //ui->campusBox->addItem();
    //end while loop

    ui->setupUi(this);

    QDir databaseDir(QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation));
    databaseDir.mkdir(DB_SUBFOLDER);
    databaseDir.cd(DB_SUBFOLDER);

    QPixmap campus(databaseDir.absoluteFilePath(CP_FILENAME));
    QPixmap route(databaseDir.absoluteFilePath(RD_FILENAME));
    ui -> label_pic_campus -> setPixmap(campus.scaled(100, 100, Qt::KeepAspectRatio));
    ui -> label_pic_route  -> setPixmap(route.scaled(100, 100, Qt::KeepAspectRatio));
}

student::~student() {
    delete ui;
}


void student::on_commandLinkButton_clicked()
{
	displayInfoClass *displayWindow = new displayInfoClass;

	//displayWindow.setModal(true);
	//displayWindow.exec();
	close();
	displayWindow->show();
}

void student::on_commandLinkButton_2_clicked()
{
	chooserouteclass *displayOptions = new chooserouteclass;
	//displayOptions.setModal(true);
	//displayOptions.exec();

	close();
	displayOptions->show();
}
