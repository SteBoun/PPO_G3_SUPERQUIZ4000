#include "question.h"
#include "ui_question.h"

question::question(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::question)
{
    ui->setupUi(this);
}

question::~question()
{
    delete ui;
}
