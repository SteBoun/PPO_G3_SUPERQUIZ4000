#include "question.h"
#include "ui_question.h"
#include <QPixmap>

#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <random>

#include <QtSql>


#include <vector>
#include <QDateTime>

using namespace std;


question::question(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::question)
{

    //la base de données

    m_bdd = bddinterface::instance();
    demarrer_jeu();
    m_bdd->afficher_sql();
}

void question::demarrer_jeu()
{

    /* const char* m_path_imgProp1 = get_path(2);
    const char* m_path_imgProp2 = get_path(get_random());
    const char* m_path_imgProp3 = get_path(get_random());
*/
        const char* m_path_imgPix = "C:/Users/florian.enet/Pictures/cap.png";
        const char* m_path_imgProp1 = get_path(get_random());
        const char* m_path_imgProp2 = get_path(get_random());
        const char* m_path_imgProp3 = get_path(get_random());


    ui->setupUi(this);
//Image pixelisé
    QPixmap imgPix(m_path_imgPix);
    int h = ui->pic_1->height();
    int w = ui->pic_1->width();
//propo 1
    QPixmap imgProp1(m_path_imgProp1);
    int h1 = ui->pic_1->height();
    int w1 = ui->pic_1->width();
//propo 2
    QPixmap imgProp2(m_path_imgProp2);

//prop 3
    QPixmap imgProp3(m_path_imgProp3);



    ui->pic_1->setPixmap(imgPix.scaled(450,450, Qt::KeepAspectRatio));

    ui->prop_1->setPixmap(imgProp1.scaled(200,200, Qt::KeepAspectRatio));

    ui->prop_2->setPixmap(imgProp2.scaled(200,200, Qt::KeepAspectRatio));

    ui->prop_3->setPixmap(imgProp3.scaled(200,200, Qt::KeepAspectRatio));


}



question::~question()
{
    delete ui;
    delete m_bdd;
}

int question::get_random(){

do {} while(aleatoire_sans_doublon(1,4,Tab_nbAleatoire) == -1);
    return random;
}

void question::set_random(int a){
    random = a;
}

char* question::get_path(int a){
    char* tableau[40];

    tableau[1] = "C:/Users/florian.enet/Documents/Projet_PO/PPO_G3_SUPERQUIZ4000/Image/original/avion.jpg";
    tableau[2] = "C:/Users/florian.enet/Documents/Projet_PO/PPO_G3_SUPERQUIZ4000/Image/original/batterie-voiture.jpg";
    tableau[3] = "C:/Users/florian.enet/Documents/Projet_PO/PPO_G3_SUPERQUIZ4000/Image/original/Borne_incendie.jpg";
    tableau[4] = "C:/Users/florian.enet/Pictures/cap.png";

    return tableau[a];
}

int question::aleatoire_sans_doublon(int min,int max,std::vector<int> &Tableau)
{
    int i = 0;
    unsigned int ms = static_cast<unsigned>(QDateTime::currentMSecsSinceEpoch() + rand());
        std::mt19937 gen(ms);
        std::uniform_int_distribution<> uid(min, max);
    int nbAleatoire = uid(gen);//distrib(RAND_E);//recuperation de la valeur aleatoire
    while(i < Tableau.size())//verification valeur deja existante
    {
        if(Tableau[i] == nbAleatoire)
        {
            std::cout << "Debug_Aleatoire = -1 \n";
            return -1 ;
        }
        i++;
    }
    std::cout << "Debug_Aleatoire = " << nbAleatoire << std::endl;//affiche le nombre aleatoire (debug)
    Tableau.push_back(nbAleatoire);
    set_random(nbAleatoire);
    return nbAleatoire;
}

