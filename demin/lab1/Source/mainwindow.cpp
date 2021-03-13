#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    widget=new Widget();
    ui->verticalLayout_2->addWidget(widget);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    widget->clearData();
    widget->setStepByStep(false);
    Square *a = new Square(ui->spinBox->value(),widget);
    stack<res> resTable = a->make();
    ui->textEdit->setText(  QString::number(resTable.size())+"\n" );
        for (; !resTable.empty();) {
            ui->textEdit->setText(ui->textEdit->toPlainText()+ QString::number(resTable.top().x+1)+" "+QString::number(resTable.top().y+1)+" "+QString::number(resTable.top().size)+"\n");
            resTable.pop();
        }
    delete  a;
}

void MainWindow::on_pushButton_3_clicked()
{
    widget->next();
}

void MainWindow::on_pushButton_2_clicked()
{
    widget->clearData();
    widget->next();
    widget->setStepByStep(true);
    Square *a = new Square(ui->spinBox_2->value(),widget);
    stack<res> resTable = a->make();
    ui->textEdit->setText(  QString::number(resTable.size())+"\n" );
        for (; !resTable.empty();) {
            ui->textEdit->setText(ui->textEdit->toPlainText()+ QString::number(resTable.top().x+1)+" "+QString::number(resTable.top().y+1)+" "+QString::number(resTable.top().size)+"\n");
            resTable.pop();
        }
    delete a;
}
