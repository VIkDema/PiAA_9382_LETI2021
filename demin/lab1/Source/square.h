#ifndef SQUARE_H
#define SQUARE_H
#include "Res.h"
#include <vector>
#include <stack>
#include <algorithm>
#include "widget.h"
#include "QDebug"

using namespace std;

class Square {
    vector<vector<int>> data;//Матрица основного квадрата
    int size;//размер матрицы
    int colors;//id квадратов
    Widget* widget;// виджет для отрисовки квадрата

    void checkSize() {
        if (data.size() != this->size) {
            qDebug() << "error size vector" << endl;
        }
        for (auto it = data.begin(); it < data.end(); ++it) {
            if (it->size() != this->size) {
                qDebug()<< "error size vector" << endl;
            }
        }
    }
    //создание квадрата
    void makeSquare(int x, int y, int size) {
        colors++;
        for (int i = x; i < x + size; ++i) {
            for (int j = y; j < y + size; ++j) {
                data[i][j] = colors;
            }
        }
    }
    //удаление квадрата
    void clearSquare(int x, int y, int size) {
        colors--;
        for (int i = x; i < x + size; ++i) {
            for (int j = y; j < y + size; ++j) {
                data[i][j] = 0;
            }
        }
    }
    //получение максимально возможного размера
    int getSize(int x, int y) {
        int max = size / 2 + 1;
        while (x + max > size || y + max > size) {
            max--;
        }
        bool flag = true;
        while (flag) {
            for (int i = 0; i < max; ++i) {
                for (int j = 0; j < max; ++j) {
                    if (data[x + i][y + j] == 0) {
                        continue;
                    } else {
                        flag = false;
                        break;
                    }
                }
            }
            if (!flag) {
                max--;
                flag = true;
            } else {
                break;
            }
        }
        return max;
    }

    static bool compaire(res a, res b) {
        return a.size < b.size;
    }

    //отрисовка квадрата
    void printQT(stack<res> stackOfRes){
        if(widget){
            widget->printSquare(stackOfRes,size);
        }
    }

public:

    Square(int N,Widget* a) {
        this->widget=a;
        this->size = N;
        data.resize(N);
        for (auto it = data.begin(); it < data.end(); ++it) {
            it->resize(N);
        }
        colors = 0;
        checkSize();
    }

    //функция решения задачи
    stack<res> make() {
        stack<res> a; //минимальное решение
        stack<res> temp;//текущее решение

        if (this->size % 2 == 0) { //решение квадрата размера кратным 2
            int k = size / 2;
            for (int i = 0; i < size; i = i + k) {
                for (int j = 0; j < size; j = j + k) {
                    makeSquare(i, j, k);
                    a.push(res(i, j, k));
                }
            }
        } else if (this->size % 3 == 0) { //решение квадрата размера кратным 3
            makeSquare(0, 0, size / 3 * 2);
            temp.push(res(0, 0, size / 3 * 2));
            printQT(temp);

            makeSquare(2 * size / 3, 0, size / 3);
            temp.push(res(2 * size / 3, 0, size / 3));
            printQT(temp);

            makeSquare(2 * size / 3, size / 3, size / 3);
            temp.push(res(2 * size / 3, size / 3, size / 3));
            printQT(temp);

            makeSquare(0, 2 * size / 3, size / 3);
            temp.push(res(0, 2 * size / 3, size / 3));
            printQT(temp);

            makeSquare(size / 3, 2 * size / 3, size / 3);
            temp.push(res(size / 3, 2 * size / 3, size / 3));
            printQT(temp);

            makeSquare(2 * size / 3, 2 * size / 3, size / 3);
            temp.push(res(2 * size / 3, 2 * size / 3, size / 3));
            printQT(temp);

            a = temp;

        } else if (this->size % 5 == 0) { //решение квадрата размера кратным 5
            makeSquare(0, 0, size * 3 / 5);
            temp.push(res(0, 0, size * 3 / 5));
            printQT(temp);

            makeSquare(size * 3 / 5, 0, size * 2 / 5);
            temp.push(res(size * 3 / 5, 0, size * 2 / 5));
            printQT(temp);

            makeSquare(0, size * 3 / 5, size * 2 / 5);
            temp.push(res(0, size * 3 / 5, size * 2 / 5));
            printQT(temp);

            makeSquare(size * 3 / 5, size * 3 / 5, size * 2 / 5);
            temp.push(res(size * 3 / 5, size * 3 / 5, size * 2 / 5));
            printQT(temp);
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    if (data[i][j] == 0) {
                        int k = getSize(i, j);
                        makeSquare(i, j, k);
                        temp.push(res(i, j, k));
                        printQT(temp);
                    }
                }
            }

            a = temp;
        } else {
            int minSize = size * size;
            //первые три квадрата размера N/2+1, N/2,N/2
            int kSize = getSize(0, 0);
            makeSquare(0, 0, kSize);
            temp.push(res(0, 0, kSize));

            int k = getSize(kSize, 0);
            makeSquare(kSize, 0, k);
            temp.push(res(kSize, 0, k));

            k = getSize(0, kSize);
            makeSquare(0, kSize, k);
            temp.push(res(0, kSize, k));

            bool flag = true;
            while (flag) {
                //заполнение квадрата
                for (int i = 0; i < size; ++i) {
                    for (int j = 0; j < size && temp.size() < minSize; ++j) {
                        if (data[i][j] == 0) {
                            k = getSize(i, j);
                            makeSquare(i, j, k);
                            temp.push(res(i, j, k));
                            printQT(temp);
                            if (temp.size() > minSize) {
                                break;
                            }
                        }
                    }

                }
                //проверка является ли текущее решение меньше текущего минимального
                if (temp.size() < minSize) {
                    minSize = temp.size();
                    a = temp;
                }
                //удаление квадратов размером 1
                while (temp.top().size == 1) {
                    clearSquare(temp.top().x, temp.top().y, temp.top().size);
                    temp.pop();
                }
                //проверка является закончены ли все варианты расположения квадратов, если нет, то уменьшаем последний квадрат размером больше 1 на 1
                if (temp.size() > 3) {
                    clearSquare(temp.top().x, temp.top().y, temp.top().size);
                    makeSquare(temp.top().x, temp.top().y, temp.top().size - 1);

                    res resTemp = res(temp.top().x, temp.top().y, temp.top().size - 1);

                    temp.pop();
                    temp.push(resTemp);
                } else {
                    flag = false;
                }
            }
        }
        printQT(a);
        return a;
    }
};

#endif // SQUARE_H
