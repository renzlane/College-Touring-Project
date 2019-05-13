#include "campuscreator.h"
#include "ui_campuscreator.h"
#include <QDebug>
#include <QPushButton>
#include "dbmanager.h"

Admin::campusCreator::campusCreator(QWidget *parent, const char *acceptWithNameSlot, QString oldName) :
	QDialog(parent),
	ui(new Ui::campusCreator),
	oldName{oldName}
{
	ui->setupUi(this);

	if(parent != nullptr) {

		if(acceptWithNameSlot != nullptr) {
			connect(this, SIGNAL(acceptedWithName(const QString &)), parent, acceptWithNameSlot);
		}
	}

	// This will trigger any checks for a valid name.
	// However, it does NOT trigger if the name was empty to begin with.
	ui->NameField->setText(oldName);

	if(oldName == "") {
		on_NameField_textChanged("");
	}
}

Admin::campusCreator::~campusCreator()
{
	delete ui;
}

void Admin::campusCreator::on_NameField_textChanged(const QString &arg1)
{
	qDebug() << "Called with" << arg1;
	newName = arg1;

	bool enabled = isNameValid(newName);
	ui->Buttons->button(QDialogButtonBox::Ok)->setEnabled(enabled);
}

bool Admin::campusCreator::isNameValid(QString name)
{
	return name.length() > 0
		&& !DbManager::instance().campusNames().contains(name);
}

void Admin::campusCreator::on_campusCreator_accepted()
{
	//qDebug() << "Not actually creating" << newName;

	if(oldName.length() > 0) {
		DbManager::instance().changeCampusName(oldName, newName);
	}
	else {
		DbManager::instance().addCampus(newName);
	}

	emit(acceptedWithName(newName));
}

