#ifndef CUSTOMTRIP_H
#define CUSTOMTRIP_H

#include <QDialog>

namespace Ui {
class customTrip;
}

class customTrip : public QDialog
{
    Q_OBJECT

public:
    explicit customTrip(QWidget *parent = nullptr);
    ~customTrip();

private:
    Ui::customTrip *ui;
};

#endif // CUSTOMTRIP_H
