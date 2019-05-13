#include "asu.h"
#include "ui_asu.h"

asu::asu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::asu)
{
    ui->setupUi(this);
}

asu::~asu()
{
    delete ui;
}
