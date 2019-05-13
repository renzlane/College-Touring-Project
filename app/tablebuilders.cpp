#include "tablebuilders.h"
#include "dbmanager.h"
#include <QCoreApplication>

const int DISTANCE_NAME_COL = 0;
const int DISTANCE_DIST_COL = 1;

const int SOUVENIR_NAME_COL = 0;
const int SOUVENIR_PRICE_COL = 1;

void buildDistanceTable(QTableWidget *table, QString selectedCampus)
{
	if(selectedCampus == "") {
		table->setEnabled(false);
		table->setRowCount(0);
	}
	else {
		table->setEnabled(true);

		QStringList names = DbManager::instance().campusNames();
		names.removeOne(selectedCampus);
		table->setRowCount(names.length());

		// This will stop things like the cellChanged signal from being
		// fired repeatedly while building the table.
		bool oldState = table->blockSignals(true);


		for(int row = 0; row < names.length(); row++) {

			// Make sure the elements are allocated
			if(table->item(row, DISTANCE_NAME_COL) == nullptr) {
				QTableWidgetItem *item = new QTableWidgetItem();
				item->setFlags(item->flags() ^ Qt::ItemIsEditable);
				table->setItem(row, DISTANCE_NAME_COL, item);

			}

			if(table->item(row, DISTANCE_DIST_COL) == nullptr) {
				QTableWidgetItem *item = new QTableWidgetItem();
				item->setFlags(item->flags() ^ Qt::ItemIsEditable);
				table->setItem(row, DISTANCE_DIST_COL, item);
			}


			double distance = DbManager::instance().getDistance(selectedCampus, names[row]);
			QString distStr = QString::number(distance) + QString(" Miles");

			// Set the values for this row
			table->item(row, DISTANCE_NAME_COL)->setData(Qt::DisplayRole, names[row]);
			table->item(row, DISTANCE_DIST_COL)->setData(Qt::DisplayRole, distStr);

		}

		// Finally, restore signals so that we can resume sending them.
		table->blockSignals(oldState);
	}

	// This is a hack to force the enable/disable to go through
	QCoreApplication::sendPostedEvents();
}

void buildSouvenirTable(QTableWidget *table, QString selectedCampus) {
	if(selectedCampus == "") {
		table->setEnabled(false);
		table->setRowCount(0);
	}
	else {
		table->setEnabled(true);

		QMap<QString, double> souvenirs =
				DbManager::instance().getSouvenirs(selectedCampus);
		table->setRowCount(souvenirs.size());

		// This will stop things like the cellChanged signal from being
		// fired repeatedly while building the table.
		bool oldState = table->blockSignals(true);

		int row = 0;
		QMap<QString, double>::const_iterator it = souvenirs.constBegin();
		while(it != souvenirs.constEnd() && row < souvenirs.size())
		{

			// Make sure the elements are allocated
			if(table->item(row, SOUVENIR_NAME_COL) == nullptr) {
				QTableWidgetItem *item = new QTableWidgetItem();
				item->setFlags(item->flags() ^ Qt::ItemIsEditable);
				table->setItem(row, SOUVENIR_NAME_COL, item);

			}

			if(table->item(row, SOUVENIR_PRICE_COL) == nullptr) {
				QTableWidgetItem *item = new QTableWidgetItem();
				item->setFlags(item->flags() ^ Qt::ItemIsEditable);
				table->setItem(row, SOUVENIR_PRICE_COL, item);
			}


			QString price = QString("$") + QString::number(it.value());

			// Set the values for this row
			table->item(row, SOUVENIR_NAME_COL)->setData(Qt::DisplayRole, it.key());
			table->item(row, SOUVENIR_PRICE_COL)->setData(Qt::DisplayRole, price);


			// Gotta make sure to update these, otherwise we'll go nowhere.
			row++;
			it++;
		}

		// Finally, restore signals so that we can resume sending them.
		table->blockSignals(oldState);
	}

	// This is a hack to force the enable/disable to go through
	QCoreApplication::sendPostedEvents();
}
