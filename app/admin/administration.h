#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class administration;
}

// NOTE: We CANNOT easily put this into the admin namespace.
//       This is a lame bug in QtCreator.
class administration : public QDialog
{
    Q_OBJECT

public:
	explicit administration(QWidget *parent = nullptr);
    ~administration();

private:
	QString selectedCampus;

	// Don't change this directly; call updateSelectedSouvenir
	QString selectedSouvenir;

	void updateSelectedSouvenir(QString newSouvenir);


private slots:
	// Custom slots follow

	// These depend strictly on the selectedCampus
	// variable. When that gets updated via
	// on_campusSelector_currentItemChanged, these get called.
	void reloadDistances();
	void reloadSouvenirs();

	/**
	 * @brief Forces all database-dependant things to reload.
	 */
	void on_campusInfoChanged();

	/**
	 * @brief After a reload, attempts to select the given campus.
	 *        A qDebug message is printed if it cannot be found.
	 * @param name Name of campus to select.
	 */
	void on_addedNewCampus(const QString &name);


	// Automacially generated slots follow

	void on_pushButton_clicked();
	void on_campusSelector_currentItemChanged(
			QListWidgetItem *current, QListWidgetItem *previous);
	void on_renameButton_clicked();
	void on_deleteButton_clicked();
	void on_distancesTable_cellChanged(int row, int column);
	void on_souvenirTable_currentCellChanged(
			int currentRow, int currentColumn,
			int previousRow, int previousColumn);
	void on_souvenirTable_cellChanged(int row, int column);

	void on_souvenirAdd_clicked();

	void on_souvenirDelete_clicked();

private:
    Ui::administration *ui;
};

#endif // ADMINISTRATION_H
