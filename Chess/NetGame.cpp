#include "NetGame.h"

NetGame::NetGame(bool Server, QWidget *parent /*= 0*/)
{
	_server = NULL;
	_socket = NULL;
	bServer = Server;

	if (bServer)
	{
		_server = new QTcpServer(this);
		_server->listen(QHostAddress::Any,8990);
		connect(_server,SIGNAL(newConnection()),this,SLOT(slotNewConnection()));
	} 
	else
	{
		_socket = new QTcpSocket(this);
		_socket->connectToHost(QHostAddress("127.0.0.1"),8990);
		connect(_socket, SIGNAL(readyRead()), this, SLOT(slotDataArrive()));
	}
}

NetGame::~NetGame()
{

}

void NetGame::initFromNetwork(QByteArray buf)
{
	bool bRedSide = buf.at(1) > 0 ? true : false;
	init(bRedSide);
}

void NetGame::clickFromNetwork(QByteArray buf)
{

}

void NetGame::slotNewConnection()
{
	if (_socket) return;

}

void NetGame::slotDataArrive()
{
	QByteArray buf = _socket->readAll();
	switch (buf.at(0)) {
	case 1:
		initFromNetwork(buf);
		break;
	case 2:
		clickFromNetwork(buf);
		break;
	default:
		break;
	}
}
