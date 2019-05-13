#ifndef checkout_H
#define checkout_H

#include <QDialog>
#include "student.h"

namespace Ui {
class checkout;
}

class checkout : public QDialog
{
    Q_OBJECT

public:
    explicit checkout(QWidget *parent = 0);
    ~checkout();
    /**
     * @brief ReturnPurchase : Returns a boolean if the person selected to confirm the purchase
     * @return
     */
    bool ReturnPurchase();
    /**
     * @brief RecieptOutput : Outputs the purchase information to the text box for the viewer to see
     * @param product1 : the amount of product 1 purchased
     * @param product2 : the amount of product 2 purchased
     * @param product3 : the amount of product 3 purchased
     * @param total : the total cost of the purchase
     * @param product1cost : the cost of product1
     * @param product2cost : the cost of product2
     * @param product3cost : the cost of product3
     */
    void RecieptOutput(QString product1, QString product2, QString product3, float total,
                       float product1cost, float product2cost, float product3cost);

    /**
     * @brief ReturnZip : Returns the zipCode for the card information
     * @return
     */
    unsigned int ReturnZip();
    /**
     * @brief ReturnCard : Returns the card number of the purchased
     * @return
     */
    unsigned int ReturnCard();
    /**
     * @brief ReturnCvv : Returns the securtity number for the card
     * @return
     */
    unsigned int ReturnCvv();

private slots:
    /**
     * @brief on_purchase_clicked : customer wants to complete purchase
     */
    void on_purchase_clicked();
    /**
     * @brief on_cancel_clicked : customer wants to cancel purchase
     */
    void on_cancel_clicked();

private:
    Ui::checkout *ui;
    bool purchase;
    // NOT NECESSARY
    unsigned int cardNum;
    unsigned int zipNum;
    unsigned int cvvNum;

};

#endif // checkout_H
