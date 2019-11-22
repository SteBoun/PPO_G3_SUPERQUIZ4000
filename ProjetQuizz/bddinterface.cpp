#include "bddinterface.h"
#include "define.h"
#include <iostream>

#include <QtSql>

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
    m_db = QSqlDatabase::addDatabase("QSQLITE");

    m_db.setHostName("10.16.38.200");
    m_db.setUserName("admin");
    m_db.setPassword("Nantes44");
    m_db.setDatabaseName("superquiz4000");

    if( m_db.open() )
        std::cout << "Vous êtes maintenant connecté à " << q2c(m_db.hostName()) << std::endl;
    else
        std::cout << "La connexion a echouee, desole" << std::endl;
}
