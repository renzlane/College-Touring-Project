#include "customtrip.h"
#include "ui_customtrip.h"

customTrip::customTrip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customTrip)
{
    ui->setupUi(this);
}

customTrip::~customTrip()
{
    delete ui;
}
