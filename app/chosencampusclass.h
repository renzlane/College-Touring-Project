#ifndef CHOSENCAMPUSCLASS_H
#define CHOSENCAMPUSCLASS_H
#include <QListWidget>
#include <QDialog>

namespace Ui {
class chosencampusclass;
}

class chosencampusclass : public QDialog
{
    Q_OBJECT

public:
    explicit chosencampusclass(QWidget *parent = nullptr);
    ~chosencampusclass();

private slots:
    void on_finish_button_clicked();

    void on_choosecampus_listwidget_itemDoubleClicked(QListWidgetItem *item);

    void on_choosecampus_listwidget2_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::chosencampusclass *ui;
    QStringList campusesToVisit;
};

#endif // CHOSENCAMPUSCLASS_H
