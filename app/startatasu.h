#ifndef STARTATASU_H
#define STARTATASU_H

#include <QDialog>

namespace Ui {
class startAtASU;
}

class startAtASU : public QDialog
{
    Q_OBJECT

public:
    explicit startAtASU(QWidget *parent = nullptr);
    ~startAtASU();

private:
    Ui::startAtASU *ui;
};

#endif // STARTATASU_H
