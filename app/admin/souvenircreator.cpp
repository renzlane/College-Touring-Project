#include "souvenircreator.h"
#include "ui_souvenircreator.h"
#include "dbmanager.h"
#include <QPushButton>

Admin::souvenirCreator::souvenirCreator(
		QString campus, QWidget *parent, const char *acceptSlot) :
	QDialog(parent),
	ui(new Ui::souvenirCreator),
	campusName{campus}
{
	ui->setupUi(this);
	ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

	if(parent != nullptr && acceptSlot != nullptr) {
		connect(this, SIGNAL(afterAccepted()),
				parent, acceptSlot);
	}
}

Admin::souvenirCreator::~souvenirCreator()
{
	delete ui;
}


void Admin::souvenirCreator::on_nameField_textChanged(const QString &arg1)
{
	bool enabled = arg1 != ""
			&& !DbManager::instance().getSouvenirs(campusName).contains(arg1);

	ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(enabled);
}

void Admin::souvenirCreator::on_buttonBox_accepted()
{
	//qDebug() << ui->nameField->text() << ui->priceField->value();
	DbManager::instance().addSouvenir(
				campusName,
				ui->nameField->text(),
				ui->priceField->value()
	);

	emit(afterAccepted());
}
