#include "administration.h"
#include "ui_administration.h"
#include "admin/campuscreator.h"
#include "admin/souvenircreator.h"
#include "dbmanager.h"

// Unless we add more columns, these constants should be zero and one
const int SOUVENIR_NAME_COL = 0;
const int SOUVENIR_PRICE_COL = 1;
const int DISTANCE_NAME_COL = 0;
const int DISTANCE_DIST_COL = 1;


administration::administration(QWidget *parent) :
	QDialog(parent),
	selectedCampus{""},
	selectedSouvenir{""},
	ui(new Ui::administration)
{
    ui->setupUi(this);

	ui->distancesTable->setHorizontalHeaderItem(DISTANCE_NAME_COL, new QTableWidgetItem("Name"));
	ui->distancesTable->setHorizontalHeaderItem(DISTANCE_DIST_COL, new QTableWidgetItem("Distance"));
	ui->distancesTable->horizontalHeader()->setSectionResizeMode(DISTANCE_NAME_COL, QHeaderView::Stretch);
	ui->distancesTable->horizontalHeader()->setSectionResizeMode(DISTANCE_DIST_COL, QHeaderView::Fixed);

	ui->souvenirTable->setHorizontalHeaderItem(SOUVENIR_NAME_COL, new QTableWidgetItem("Souvenir"));
	ui->souvenirTable->setHorizontalHeaderItem(SOUVENIR_PRICE_COL, new QTableWidgetItem("Price"));
	ui->souvenirTable->horizontalHeader()->setSectionResizeMode(SOUVENIR_NAME_COL, QHeaderView::Stretch);
	ui->souvenirTable->horizontalHeader()->setSectionResizeMode(SOUVENIR_PRICE_COL, QHeaderView::Fixed);


	on_campusInfoChanged();
}

administration::~administration()
{
	delete ui;
}

void administration::updateSelectedSouvenir(QString newSouvenir)
{
	selectedSouvenir = newSouvenir;
	ui->souvenirDelete->setEnabled(newSouvenir != "");
}


void administration::reloadDistances()
{
	if(selectedCampus == "") {

		ui->distancesTable->setEnabled(false);
		ui->distancesTable->setRowCount(0);
	}
	else {
		ui->distancesTable->setEnabled(true);

		QStringList names = DbManager::instance().campusNames();
		names.removeOne(selectedCampus);
		ui->distancesTable->setRowCount(names.length());

		// This will stop things like the cellChanged signal from being
		// fired repeatedly while building the table.
		bool oldState = ui->distancesTable->blockSignals(true);


		for(int row = 0; row < names.length(); row++) {

			// Make sure the elements are allocated
			if(ui->distancesTable->item(row, DISTANCE_NAME_COL) == nullptr) {
				QTableWidgetItem *item = new QTableWidgetItem();
				item->setFlags(item->flags() ^ Qt::ItemIsEditable);
				ui->distancesTable->setItem(row, 0, item);
			}

			if(ui->distancesTable->item(row, DISTANCE_DIST_COL) == nullptr) {
				ui->distancesTable->setItem(row, 1, new QTableWidgetItem());
			}

			double distance = DbManager::instance().getDistance(selectedCampus, names[row]);


			// Set the values for this row
			ui->distancesTable->item(row, DISTANCE_NAME_COL)->setData(Qt::DisplayRole, names[row]);
			ui->distancesTable->item(row, DISTANCE_DIST_COL)->setData(Qt::EditRole, distance);

		}

		// Finally, restore signals so that we can resume sending them.
		ui->distancesTable->blockSignals(oldState);
	}

	// This is a hack to force the enable/disable to go through
	QCoreApplication::sendPostedEvents();
}

void administration::reloadSouvenirs()
{

	// Deselect anything that's already selected. This prevents anything oddities
	// caused by having elements selected before the reload.
	QList<QTableWidgetSelectionRange> selection = ui->souvenirTable->selectedRanges();
	for(auto it = selection.constBegin(); it != selection.constEnd(); it++) {
		ui->souvenirTable->setRangeSelected(*it, false);
	}

	updateSelectedSouvenir("");

	if(selectedCampus == "") {
		ui->souvenirTable->setEnabled(false);
		ui->souvenirTable->setRowCount(0);
		ui->souvenirTable->update();

		ui->souvenirAdd->setEnabled(false);
	}
	else {
		ui->souvenirTable->setEnabled(true);
		ui->souvenirAdd->setEnabled(true);

		// This FORCES a redisplay
		ui->souvenirTable->clearContents();

		QMap<QString, double> souvenirs =
				DbManager::instance().getSouvenirs(selectedCampus);

		ui->souvenirTable->setRowCount(souvenirs.size());

		// This will stop things like the cellChanged signal from being
		// fired repeatedly while building the table.
		bool oldState = ui->souvenirTable->blockSignals(true);

		int row = 0;
		QMap<QString, double>::const_iterator it = souvenirs.constBegin();
		while(it != souvenirs.constEnd() && row < souvenirs.size())
		{
			// Make sure the elements are allocated
			if(ui->souvenirTable->item(row, SOUVENIR_NAME_COL) == nullptr) {
				QTableWidgetItem *item = new QTableWidgetItem();
				ui->souvenirTable->setItem(row, SOUVENIR_NAME_COL, item);
			}

			if(ui->souvenirTable->item(row, SOUVENIR_PRICE_COL) == nullptr) {
				QTableWidgetItem *item = new QTableWidgetItem();
				ui->souvenirTable->setItem(row, SOUVENIR_PRICE_COL, item);
			}

			// Set the values for this row
			ui->souvenirTable->item(row, SOUVENIR_NAME_COL)->setData(Qt::EditRole, it.key());
			ui->souvenirTable->item(row, SOUVENIR_PRICE_COL)->setData(Qt::EditRole, it.value());

			// Gotta make sure to update these, otherwise we'll go nowhere.
			row++;
			it++;
		}

		if(souvenirs.size() > 0) {
			ui->souvenirTable->setCurrentCell(0, 0);
			updateSelectedSouvenir( ui->souvenirTable->item(0, 0)->text() );
		}

		// Finally, restore signals so that we can resume sending them.
		ui->souvenirTable->blockSignals(oldState);

	}

	// This is a hack to force the enable/disable to go through
	QCoreApplication::sendPostedEvents();
}


void administration::on_campusInfoChanged()
{
	ui->campusSelector->clear();
	ui->campusSelector->addItems(DbManager::instance().campusNames());
}

void administration::on_addedNewCampus(const QString &name)
{
	on_campusInfoChanged();

	QList<QListWidgetItem *> list =
			ui->campusSelector->findItems(name, Qt::MatchExactly);

	if(list.length() != 1) {
		qDebug() << "on_addedNewCampus could not find the target" << name;
	}
	else {
		ui->campusSelector->setCurrentItem(list[0]);
	}
}



void administration::on_pushButton_clicked()
{
	// This is the create button. Didn't rename it before creating this function.
	Admin::campusCreator creationDialog(this, SLOT(on_addedNewCampus(const QString &)));
	creationDialog.setModal(true);
	creationDialog.exec();
}

void administration::on_renameButton_clicked()
{
	Admin::campusCreator creationDialog(
				this,
				SLOT(on_addedNewCampus(const QString &)),
				selectedCampus
	);
	creationDialog.setModal(true);
	creationDialog.exec();
}

void administration::on_deleteButton_clicked()
{
	if(selectedCampus != "") {
		DbManager::instance().deleteCampus(selectedCampus);
		on_campusInfoChanged();
	}
}

void administration::on_souvenirAdd_clicked()
{
	Admin::souvenirCreator creationDialog(selectedCampus, this, SLOT(reloadSouvenirs()));
	creationDialog.setModal(true);
	creationDialog.exec();
}

void administration::on_souvenirDelete_clicked()
{

	// Just make sure we have this before we do anything
	if(selectedSouvenir != "" && selectedCampus != "") {
		DbManager::instance().deleteSouvenir(selectedCampus, selectedSouvenir);
		reloadSouvenirs();
	}
}



void administration::on_campusSelector_currentItemChanged(
		QListWidgetItem *current, QListWidgetItem *previous)
{

	if(current != nullptr) {
		selectedCampus = current->text();
	}
	else {
		selectedCampus = "";
	}

	reloadDistances();
	reloadSouvenirs();
}

void administration::on_distancesTable_cellChanged(int row, int /*column*/)
{
	QTableWidgetItem *distanceItem = ui->distancesTable->item(row, DISTANCE_DIST_COL);
	QTableWidgetItem *nameItem = ui->distancesTable->item(row, DISTANCE_NAME_COL);

	//qDebug() << "Run with" << row << column;

	if(distanceItem != nullptr && nameItem != nullptr) {
		double newDistance  = distanceItem->data(Qt::EditRole).toDouble();
		QString otherCampus = nameItem->data(Qt::DisplayRole).toString();

		if(newDistance < 0) {
			// Enforce the rule of negative 1
			newDistance = -1;
			distanceItem->setData(Qt::EditRole, newDistance);
		}

		DbManager::instance().changeCampusDistance(
					selectedCampus, otherCampus, newDistance);
	}

}

void administration::on_souvenirTable_currentCellChanged(int currentRow, int , int , int )
{
	//qDebug() << "Current:" << currentRow << currentColumn
	//		 << " Old" << previousRow << previousColumn;

	QTableWidgetItem *item = ui->souvenirTable->item(currentRow, SOUVENIR_NAME_COL);
	if(item != nullptr) {
		updateSelectedSouvenir(item->text());
	}
	else {
		updateSelectedSouvenir("");
	}
}

void administration::on_souvenirTable_cellChanged(int row, int column)
{
	QTableWidgetItem *item = ui->souvenirTable->item(row, column);

	// Cannot use a switch due to a C++ limiation
	if(item != nullptr && selectedCampus != "" && selectedSouvenir != "") {
		if(column == SOUVENIR_NAME_COL) {
			QString newName = item->data(Qt::EditRole).toString();
			bool success = DbManager::instance().changeSouvenirName(
				selectedCampus, selectedSouvenir, newName
			);

			if(success) {
				updateSelectedSouvenir(newName);
			}
			else {
				// Reset the text because it failed to rename
				item->setText(selectedSouvenir);
			}
		}
		else if(column == SOUVENIR_PRICE_COL) {
			double newPrice = item->data(Qt::EditRole).toDouble();
			DbManager::instance().changeSouvenirPrice(
				selectedCampus, selectedSouvenir, newPrice
			);
		}
		else {
			qDebug() << "ERROR: Changed unknown column!";
		}
	}
}
