#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QCloseEvent"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    con.load();
    updateGrid();
}


MainWindow::~MainWindow()
{
    delete ui;
}

//сохранение в файл по закрытию главного окна
void MainWindow::closeEvent (QCloseEvent *event)
{
    con.save();
    event->accept();
}

//перерсовка окна при изменении контейнера
void MainWindow::updateGrid() {
    ui->tableWidget->setRowCount(con.size());
    int rowIndex = 0;
    for(deque<Tech>::const_iterator it = con.begin(); it != con.end(); it++, rowIndex++)
        ui->tableWidget->setItem(rowIndex, 0, new QTableWidgetItem((*it)->getData().c_str()));
}

//очистка контейнера с подтверждением
void MainWindow::on_clear_clicked()
{
    QMessageBox *msg = new QMessageBox;
    msg->setInformativeText("Are you sure?");
    msg->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msg->setDefaultButton(QMessageBox::Yes);

    int returned = msg->exec();

    if (returned == QMessageBox::Yes){
        con.clear();
        updateGrid();
    }
}

//обработка событий нажатия кнопок
void MainWindow::on_delete_back_clicked()
{
    con.delete_back();
    updateGrid();
}

void MainWindow::on_delete_front_clicked()
{
    --con;
    updateGrid();
}

void MainWindow::on_add_back_clicked()
{
    ChooseType dialog;
    Tech newTech = dialog.show();
    if(newTech != NULL) {
        con.add_back(newTech);
        updateGrid();
    }
}

void MainWindow::on_add_front_clicked()
{
    ChooseType dialog;
    Tech newTech = dialog.show();
    if(newTech != NULL) {
        con.add_front(newTech);
        updateGrid();
    }
}
