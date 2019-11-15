#ifndef STATS_H
#define STATS_H

class stats {
public:

    void afficher_stat();
    double get_stats();
private:
        int m_bonne_reponse;
        int m_mauvaise_reponse;
};

#endif // STATS_H
