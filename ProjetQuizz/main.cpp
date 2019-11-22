#include "question.h"
#include <QApplication>
#include<iostream>

void foo(void);

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    question w;
    w.show();

    return a.exec();
}


