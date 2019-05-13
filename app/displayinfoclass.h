#ifndef DISPLAYINFOCLASS_H
#define DISPLAYINFOCLASS_H

#include <QDialog>
#include <QListWidget>
#include <QDebug>

namespace Ui {
class displayInfoClass;
}

class displayInfoClass : public QDialog
{
    Q_OBJECT

public:
    explicit displayInfoClass(QWidget *parent = nullptr);
    ~displayInfoClass();

private slots:
	void on_campusList_itemClicked(QListWidgetItem *item);

private:
	Ui::displayInfoClass *ui;
};

#endif // DISPLAYINFOCLASS_H
