#include "mainwindow.h"
#include <QApplication>
/* Осипов Максим Михайлович, БИВ-143, лабораторная 5.
 * Переработать контейнерный класс с использование шаблонов.*/


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

/* Контейнерный класс был переработан с использованием шаблонов.
 @toDo можно переработать класс техники с использованием шаблонов.*/

