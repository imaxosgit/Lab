#ifndef INPUT_H
#define INPUT_H
#include <string>
#include "ui_input.h"
#include <QDialog>
#include "technique.h"
using namespace std;
namespace Ui {
class input;
}

class Input : public QDialog
{
    Q_OBJECT

public:
    string getInput() const;
    Technique *show();
    explicit Input(QWidget *parent = 0);
    ~Input();

private:
    Ui::input *ui;
};

#endif // INPUT_H
