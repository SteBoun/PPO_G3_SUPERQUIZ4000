#ifndef CONNEXION_H
#define CONNEXION_H
#include <QtSql>

class connexion
{
public:
    connexion();
private:
QSqlDatabase dbQuizz;
};

#endif // CONNEXION_H
