#include "stats.h"
#include <stdio.h>
#include <iostream>



void stats::afficher_stat(){
std::cout<<"Vous avez eu"<<m_bonne_reponse<<" de bonnes réponse. Pour un total de "<<m_bonne_reponse+m_mauvaise_reponse<<" essais. Ce qu'il vous fait un ratio de "<< get_stats()<< std::endl;
}
double stats::get_stats(){
    double m_stats;
    m_stats = m_bonne_reponse / (m_bonne_reponse + m_mauvaise_reponse);
    return m_stats;
}
