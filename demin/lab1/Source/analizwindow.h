#ifndef ANALIZWINDOW_H
#define ANALIZWINDOW_H

#include <QMainWindow>
#include "square.h"
#include <time.h>
#include <QProgressBar>
#include <QVector>


namespace Ui {
class AnalizWindow;
}

class AnalizWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AnalizWindow(QWidget *parent = nullptr);
    ~AnalizWindow();

private slots:
    void on_pushButton_clicked();

private:
    double Lagrange(double x, QVector<double> xv, QVector<double> yv);
    Ui::AnalizWindow *ui;
    QProgressBar* bar;
};

#endif // ANALIZWINDOW_H
