
#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QObject>
class QTcpServer;
class QTcpSocket;
class QNetworkSession;

class Client : public QObject
{
    Q_OBJECT

public:
    Client();

private slots:
    void lireTexte();
    void afficherErreur(QAbstractSocket::SocketError socketError);
    void lireTexte2();
    void envoiTexte( const std::string& s);

private:
    QTcpSocket *m_tcpSocket;
    quint16 m_blockSize;
    QNetworkSession *m_networkSession;

    QTcpServer *m_tcp_server; // La socket général
    QTcpSocket *m_socket_client; // La socket client
};

#endif
