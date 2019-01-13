#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "container.h"
#include "container.cpp"
#include "choosetype.h"
#include "tankdialog.h"
#include "shipdialog.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Container<Tech> con;
    Ui::MainWindow *ui;
    void updateGrid();
public:
    virtual void closeEvent (QCloseEvent *event);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_clear_clicked();
    void on_delete_back_clicked();
    void on_delete_front_clicked();
    void on_add_back_clicked();
    void on_add_front_clicked();
};

#endif // MAINWINDOW_H
