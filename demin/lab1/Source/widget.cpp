#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    stepByStep=false;
}

Widget::~Widget()
{
    delete ui;
}

/* Метод, в котором происходит рисование
 * */
void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this); // Создаём объект отрисовщика
    // Устанавливаем кисть абриса
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));

    /* Проверяем, какой из радиобаттонов выбран
     * */

    int w=450;
    int h=450;
    painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
    painter.drawRect(0,0,h,w);
    while(resTable.size()&&!(resTable[0].empty())){
        res temp = resTable[0].top();
        painter.setBrush(QBrush(randColor(resTable[0].size()), Qt::SolidPattern));
        int size=(int)((double)temp.size/sizeField*h);
        int x=(int)((double)temp.x/sizeField*h);
        int y=(int)((double)temp.y/sizeField*h);
        painter.drawRect(x, y, size, size);
        resTable[0].pop();
    }
    if(resTable.size()){
        resTable.erase(resTable.begin());
    }
}


void Widget::printSquare(std::stack<res> a,int size){
    sizeField=size;
    resTable.push_back(a);
    if(!stepByStep){
        repaint();
    }
}
QColor Widget::randColor(int index){
    std::vector< QColor> colors = {Qt::black, Qt::red, Qt::darkRed, Qt::green,Qt::yellow,Qt::blue,Qt::darkMagenta,Qt::darkCyan,Qt::darkYellow,Qt::black,Qt::magenta, Qt::darkGreen,  Qt::darkGray, Qt::lightGray};
    const ptrdiff_t idx = index%colors.size();
    return  QColor( colors[idx] );
}

void Widget::next(){
    repaint();
}
void Widget::setStepByStep(bool temp){
       stepByStep=temp;
}

void Widget::clearData(){
    resTable.clear();
}

