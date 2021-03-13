#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
  w=new MainWindow();
  aw=new AnalizWindow();
}

Menu::~Menu()
{
    delete ui;
    delete aw;
    delete w;
}

void Menu::on_pushButton_clicked()
{
    this->hide();
    w->show();
}

void Menu::on_pushButton_2_clicked()
{
    this->hide();
    aw->show();
}
