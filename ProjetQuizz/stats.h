#ifndef STATS_H
#define STATS_H

class stats {
public:
    stats stats();

    void const afficher_stat();
    double get_stats();
private:
        int m_bonne_reponse;
        int m_mauvaise_reponse;
};

#endif // STATS_H
