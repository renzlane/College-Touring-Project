#ifndef CAMPUSCREATOR_H
#define CAMPUSCREATOR_H

#include <QDialog>

namespace Ui {
class campusCreator;
}

namespace Admin {

/**
 * @brief
 * This dialog allows one to create a new campus. It talks directly
 * to the database, creating a new campus as soon as the it's been
 * accepted.
 *
 * Normally, it creates a new campus. However, it can also be used
 * to allow the user to rename a campus. (See constructor.)
 */
class campusCreator : public QDialog
{
	Q_OBJECT

public:
	/**
	 * @brief Constructs a new instance of the campusCreator dialog.
	 * @param parent
	 *   Parent widget. Also object assumed to have acceptWithNameSlot.
	 * @param acceptWithNameSlot
	 *   Slot which gets triggered when the accept button is pressed.
	 *   The name of the new campus is passed in.
	 * @param oldName
	 *   Name of campus to rename. If blank, a new one is created
	 *   instead.
	 */
	explicit campusCreator(
			QWidget *parent = nullptr,
			const char *acceptWithNameSlot = nullptr,
			QString oldName = "");
	~campusCreator();

private:
	Ui::campusCreator *ui;

	/**
	 * @brief Attempted name of the new campus, or attempted rename.
	 */
	QString newName;

	/**
	 * @brief Name of campus we're renaming. If empty, we're making
	 *        a new campus.
	 */
	QString oldName;

	/**
	 * @brief Returns true if the given name can be used.
	 * @param name Name to test.
	 * @return True if name can be used; false otherwise.
	 */
	bool isNameValid(QString name);

signals:
	/**
	 * @brief Emitted when accepted is triggered, but has the name too.
	 * @param name Name of the new campus.
	 */
	void acceptedWithName(const QString &name);

private slots:
	void on_NameField_textChanged(const QString &arg1);
	void on_campusCreator_accepted();
};

}

#endif // CAMPUSCREATOR_H
