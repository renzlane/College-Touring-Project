#include "displayinfoclass.h"
#include "ui_displayinfoclass.h"
#include "dbmanager.h"
#include <QString>
#include "tablebuilders.h"

const int DISTANCE_NAME_COL = 0;
const int DISTANCE_DIST_COL = 1;
const int SOUVENIR_NAME_COL = 0;
const int SOUVENIR_PRICE_COL = 1;

displayInfoClass::displayInfoClass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::displayInfoClass)
{
    ui->setupUi(this);

	ui->distanceTable->setHorizontalHeaderItem(DISTANCE_NAME_COL, new QTableWidgetItem("Name"));
	ui->distanceTable->setHorizontalHeaderItem(DISTANCE_DIST_COL, new QTableWidgetItem("Distance"));
	ui->distanceTable->horizontalHeader()->setSectionResizeMode(DISTANCE_NAME_COL, QHeaderView::Stretch);
	ui->distanceTable->horizontalHeader()->setSectionResizeMode(DISTANCE_DIST_COL, QHeaderView::Fixed);

	ui->souvenirTable->setHorizontalHeaderItem(SOUVENIR_NAME_COL, new QTableWidgetItem("Souvenir"));
	ui->souvenirTable->setHorizontalHeaderItem(SOUVENIR_PRICE_COL, new QTableWidgetItem("Price"));
	ui->souvenirTable->horizontalHeader()->setSectionResizeMode(SOUVENIR_NAME_COL, QHeaderView::Stretch);
	ui->souvenirTable->horizontalHeader()->setSectionResizeMode(SOUVENIR_PRICE_COL, QHeaderView::Fixed);



	ui->campusList->addItems(DbManager::instance().campusNames());
}

displayInfoClass::~displayInfoClass()
{
    delete ui;
}

void displayInfoClass::on_campusList_itemClicked(QListWidgetItem *item)
{
	QString selectedName = "";

	if(item != nullptr) {
		selectedName = item->text();
	}

	buildDistanceTable(ui->distanceTable, selectedName);
	buildSouvenirTable(ui->souvenirTable, selectedName);
}
