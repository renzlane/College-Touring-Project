#include "checkout.h"
#include "ui_checkout.h"

#include <QIntValidator>

checkout::checkout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkout)
{
    ui->setupUi(this);
}

checkout::~checkout()
{
    delete ui;
}

void checkout::RecieptOutput(QString product1, QString product2, QString product3, float total,
                             float product1cost, float product2cost, float product3cost)
{
//    QString output;
//    output = "Product 1: " + product1 + "           " + QString::number(product1cost) + '\n' +
//             "Product 2: " + product2 + "           " + QString::number(product2cost) + '\n' +
//             "Product 3: " + product3 + "           " + QString::number(product3cost) + '\n' +
//             "Maintanance Plan    " + QString::number(MAINTENANCE_FEE) + '\n' +
//             "Total Cost               " + QString::number(total);

    //ui->receiptBox->setText(output);

}
void checkout::on_purchase_clicked()
{
    QString card;
    QString zip;
    QString cvv;

    bool fail;

    card = ui->cardNumber_line->text();
    zip = ui->zipCode_line->text();
    cvv = ui->CVV_line->text();

    cardNum = card.toInt();
    zipNum = zip.toInt();
    cvvNum = cvv.toInt();

    purchase = true;
    this->hide();
}

void checkout::on_cancel_clicked()
{
    purchase = false;
    this->hide();
}

bool checkout::ReturnPurchase()
{
    return purchase;
}

unsigned int checkout::ReturnCard()
{
    return cardNum;
}

unsigned int checkout::ReturnCvv()
{
    return cvvNum;
}

unsigned int checkout::ReturnZip()
{
    return zipNum;
}
