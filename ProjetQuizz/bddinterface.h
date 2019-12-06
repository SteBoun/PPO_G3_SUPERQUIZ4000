#ifndef BDDINTERFACE_H
#define BDDINTERFACE_H

#include <stdio.h>
#include <iostream>
#include <QSqlDatabase>
#include <set>


class bddinterface
{

private:
    bddinterface();

public:
    ~bddinterface();

public:
    static bddinterface* instance();
    bool connexionEtablie() const;
    void afficher_sql();
    char* get_path_image(int);

private:
    void connexion_bdd();


private:
    /** \brief Pointeur sur l'instance singleton BddInterface. */
    static bddinterface* m_instance;

    /** \brief Connecteur à la base MySQL. */
    QSqlDatabase m_db;
};

#endif // BDDINTERFACE_H
