#ifndef CHOOSEROUTECLASS_H
#define CHOOSEROUTECLASS_H

#include <QDialog>

namespace Ui {
class chooserouteclass;
}

class chooserouteclass : public QDialog
{
    Q_OBJECT

public:
    explicit chooserouteclass(QWidget *parent = nullptr);
    ~chooserouteclass();

private slots:
    void on_go_back_button_clicked();

    void on_initial_asu_button_clicked();

    void on_short_trip_uci_button_clicked();

    void on_custom_trip_button_clicked();

private:
    Ui::chooserouteclass *ui;

};

#endif // CHOOSEROUTECLASS_H
