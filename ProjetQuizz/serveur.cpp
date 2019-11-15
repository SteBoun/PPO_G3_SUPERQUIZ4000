#include "serveur.h"
#include <QThread>
#include <sstream>
#include <QtNetwork>
#include <stdlib.h>
#include <iostream>



//###############################################################################################################
// Méthode appelée lors de l'ouverture de session
void Serveur::sessionOuverte()
{
    m_tcp_serveur = new QTcpServer(this); // instanciation

    if (!m_tcp_serveur->listen(QHostAddress::Any, 53000)) // on écoute sur le port 53000
    {
        std::cout << "Le serveur n'a pas été correctement lancee." << std::endl;
    }
    else
    {
        std::cout << "Le serveur est pret \n\nIP: " << m_tcp_serveur->serverAddress().toString().toStdString()
                  << std::endl << "port: " << m_tcp_serveur->serverPort() << std::endl
                  <<  "Lancez l'application Client maintenant." << std::endl;
    }
}

//###############################################################################################################
// Méthode appelée lors de l'ouverture d'une connexion avec un client
void Serveur::connexionClient()
{
    // instanciation
    m_socket_client = m_tcp_serveur->nextPendingConnection();

    // La méthode lireTexte sera appelée sur le signal readyRead
    connect(m_socket_client, SIGNAL(readyRead()), this, SLOT(lireTexte2()));

}

