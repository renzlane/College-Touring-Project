#ifndef ASU_H
#define ASU_H

#include <QDialog>

namespace Ui {
class asu;
}

class asu : public QDialog
{
    Q_OBJECT

public:
    explicit asu(QWidget *parent = nullptr);
    ~asu();

private:
    Ui::asu *ui;
};

#endif // ASU_H
