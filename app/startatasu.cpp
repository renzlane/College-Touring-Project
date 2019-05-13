#include "startatasu.h"
#include "ui_startatasu.h"

startAtASU::startAtASU(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::startAtASU)
{
    ui->setupUi(this);
}

startAtASU::~startAtASU()
{
    delete ui;
}
