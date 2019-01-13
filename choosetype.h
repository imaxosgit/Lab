#ifndef CHOOSETYPE_H
#define CHOOSETYPE_H
#include "technique.h"
#include <QDialog>

namespace Ui {
class ChooseType;
}

class ChooseType : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseType(QWidget *parent = 0);
    Technique *show();
    ~ChooseType();

private:
    Ui::ChooseType *ui;
};

#endif // CHOOSETYPE_H
