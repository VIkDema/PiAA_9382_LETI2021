#include "analizwindow.h"
#include "ui_analizwindow.h"

#include <QLabel>


AnalizWindow::AnalizWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnalizWindow)
{

    ui->setupUi(this);
     bar= new QProgressBar(this);
    ui->statusbar->addWidget(bar);
    bar->setMinimum(2);
    bar->setMaximum(37);
}

AnalizWindow::~AnalizWindow()
{
    delete ui;
}

double AnalizWindow::Lagrange(double x, QVector<double> xv, QVector<double> yv) { //Lagrange polynomial
    int size = xv.size(); //Количество точек (для удобства)
    double sum = 0; //Значение функции
    for(int i = 0; i < size; i++){
        double mul = 1; //Произведение
        for(int j = 0; j < size; j++){
            if(i!=j) mul *= (x - xv[j])/(xv[i]-xv[j]);
        }
        sum += yv[i]*mul;
    }

    return sum;
}

void AnalizWindow::on_pushButton_clicked()
{
    QVector<double> time;
     QVector<double> N;
    bar->reset();
    for (int i =2;i<=37 ;++i ) {
        Square* a =new Square(i,nullptr);
        clock_t start = clock();
        a->make();
        clock_t end = clock();
        double seconds = (double) (end - start) /CLOCKS_PER_SEC;
        qDebug()<<QString::number(seconds,'f',12);
        time.push_back(seconds);
        N.push_back(i);
        //ui->statusbar->showMessage(QString::number(i)+": "+QString::number(seconds));
        bar->setValue(i);
        delete a;
    }

    QMutableVectorIterator<double> i(time);
    QMutableVectorIterator<double> j(N);

    while(i.hasNext() && j.hasNext()) {
          i.next();
          int n = j.next();

          if(n!=2&&(n%2==0||n%3==0||n%5==0)){
            i.remove();
            j.remove();
          }
    }

    QVector<double> result;
    QVector<double> x;
    for(double i = 2;i<=37;i=i+1){
       result.push_back( Lagrange(i,N,time));
       x.push_back(i);
    }

    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x,result);
    ui->widget->yAxis->setRange(0, result[result.size()-1]+5);
    ui->widget->xAxis->setRange(0, 40);
    ui->widget->replot();
}
