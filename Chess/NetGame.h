#pragma once
#include "Board.h"
#include <QTcpServer>
#include <QTcpSocket>

class NetGame :public Board
{
	Q_OBJECT
public:
	explicit NetGame(bool Server,QWidget *parent = 0);
	~NetGame();

	QTcpServer*  _server;
	QTcpSocket*  _socket;

	bool bServer;

	void initFromNetwork(QByteArray buf);
	void clickFromNetwork(QByteArray buf);
public slots:
	void slotNewConnection();
	void slotDataArrive();
};

