#ifndef SOUVENIRCREATOR_H
#define SOUVENIRCREATOR_H

#include <QDialog>
#include <QString>

namespace Ui {
class souvenirCreator;
}

namespace Admin {

class souvenirCreator : public QDialog
{
	Q_OBJECT

public:
	explicit souvenirCreator(
			QString campus,
			QWidget *parent = nullptr,
			const char *acceptSlot = nullptr);
	~souvenirCreator();


private slots:
	void on_nameField_textChanged(const QString &arg1);
	void on_buttonBox_accepted();

signals:
	void afterAccepted();

private:
	Ui::souvenirCreator *ui;
	QString campusName;
};

} // End namespace

#endif // SOUVENIRCREATOR_H
