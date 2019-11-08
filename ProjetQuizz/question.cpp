#include "question.h"
#include "ui_question.h"
#include <QPixmap>

#include <iostream>
#include <string>
using namespace std;


question::question(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::question)
{
    const char* m_path= "C:/Users/florian.enet/Pictures/cap.png";


    ui->setupUi(this);

    QPixmap pix(m_path);
    int h = ui->pic_1->height();
    int w = ui->pic_1->width();

    ui->pic_1->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));
}

question::~question()
{
    delete ui;
}
