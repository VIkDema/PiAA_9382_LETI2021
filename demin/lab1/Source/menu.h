#ifndef MENU_H
#define MENU_H
#include "mainwindow.h"
#include "analizwindow.h"

#include <QWidget>

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Menu *ui;
     MainWindow* w;
     AnalizWindow* aw;
};

#endif // MENU_H
