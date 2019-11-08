#ifndef QUESTION_H
#define QUESTION_H

#include <QMainWindow>

namespace Ui {
class question;
}

class question : public QMainWindow
{
    Q_OBJECT

public:
    explicit question(QWidget *parent = 0);
    ~question();

private:
    Ui::question *ui;
};

#endif // QUESTION_H
