#include "bddinterface.h"
#include "define.h"
#include <iostream>

#include <QtSql>
#include <QtDebug>


#include"question.h"

// Initialisation de la variable membre statique
bddinterface* bddinterface::m_instance = NULL;

/** --------------------------------------------------------------------------------------
 * \brief Constructeur de la classe BddInterface.
 */
bddinterface::bddinterface()
{
    connexion_bdd();
}
/** --------------------------------------------------------------------------------------
 * \brief Destructeur de la classe BddInterface.
 */
bddinterface::~bddinterface()
{
    std::cout << "Fermeture de la connexion à la base de données" << std::endl;

    if(m_db.isOpen())
        m_db.close();

    m_instance = NULL;
}

/** --------------------------------------------------------------------------------------
 * \brief Accesseur de l'instance singleton AfficheurInterface.
 * \return Le pointeur sur le singleton AfficheurInterface.
 */
bddinterface* bddinterface::instance()
{
    if ( m_instance == NULL )
        m_instance = new bddinterface();

    return m_instance;
}

/** --------------------------------------------------------------------------------------
 * \brief Teste si la connexion à la base de données est correctement établie.
 * \return \b True si la connexion est établie, \b False sinon.
 */
bool bddinterface::connexionEtablie() const
{
    if ( m_instance == NULL )
        return false;

    if ( ! m_instance->m_db.isOpen() )
        m_instance->m_db.open();

    return m_instance->m_db.isOpen();
}
void bddinterface::connexion_bdd()
{
    m_db = QSqlDatabase::addDatabase("QMYSQL");

    m_db.setHostName("10.16.38.200");
    m_db.setUserName("Administrateur");
    m_db.setPassword("Nantes44");
    m_db.setDatabaseName("superquiz4000");
    //m_db.setPort(3306);


/*
    m_db.setHostName("217.128.90.45");
    m_db.setUserName("2019_escape_user");
    m_db.setPassword("Dijkstra");
    m_db.setDatabaseName("2019_escape_bts");
*/
 /*   if( !m_db.open() )
    {
      qDebug() << m_db.lastError();
      qFatal( "Failed to connect." );
    }
    if( m_db.open() )
        std::cout << "Vous êtes maintenant connecté à " << q2c(m_db.hostName()) << std::endl;
    else
        std::cout << "La connexion a echouee, desole =( " << std::endl;*/
}
char* bddinterface::get_path_image(int a ){
    std::cout << "get_path_image " << a << std::endl;

    char * path = NULL;
    std::string filename;
    std::string extension;
    QSqlQuery query;

    if( query.exec( "SELECT `filename`,`extension` FROM `photos` WHERE id=" + QString::number(a) ) )
    {
        if ( query.next() )
        {
            std::cout << "value 0 = " << query.value(0).toString().toStdString() << std::endl;
            std::cout << "value 1 = " << query.value(1).toString().toStdString() << std::endl;
         filename =    query.value(0).toString().toStdString();
         extension = query.value(1).toString().toStdString();

        }
    }
    else
        std::cout << "ELSE" << std::endl;

   // path  = filename.
    return path;
}

void bddinterface::afficher_sql(){
    if(connexionEtablie()){
        QSqlQuery query;

        std::cout << "ConnexionEtablie"<<std::endl;
    if(query.exec("SELECT MAX(id) FROM equipe"))
       {
        //std::cout << q2c(query.value(0).toString());

        std::cout << query.exec("SELECT MAX(id) FROM equipe") <<std::endl;

        while(query.next())
        {
            std::cout << "    Nouvelle entrée" << std::endl;
            for(int x=0; x < query.record().count(); ++x)
            {
                std::cout << "        " << q2c(query.record().value(x).toString()) << " = " << q2c(query.value(x).toString()) << std::endl;
            }

        }
}

    }
}
