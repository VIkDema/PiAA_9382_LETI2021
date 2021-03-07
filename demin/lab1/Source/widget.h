#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <stack>
#include "Res.h"
using namespace std;
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void printSquare(std::stack<res> a,int size);
    QColor randColor(int index);
    void next();
    void setStepByStep(bool temp);
    void clearData();


protected:
    /* Определяем виртуальный метод родительского класса
     * для отрисовки содержимого виджета
     * */
    void paintEvent(QPaintEvent *event);

private:
    Ui::Widget *ui;
    vector<std::stack<res>> resTable;
    int sizeField;
    bool stepByStep;
};

#endif // WIDGET_H
