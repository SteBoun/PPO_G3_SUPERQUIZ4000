#ifndef QUESTION_H
#define QUESTION_H
#include <bddinterface.h>
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


    int aleatoire_sans_doublon(int min,int max,std::vector<int> &Tableau);
    char get_proposistions();
   char* get_path(int);
    int get_random();
    void set_random(int);
    void demarrer_jeu();
    void afficher();

private:

    std::vector<int> Tab_nbAleatoire;//Enregistrement des nombre aleatoire déja sorti

    Ui::question *ui;
    int random;
    bddinterface * m_bdd;
};

#endif // QUESTION_H
