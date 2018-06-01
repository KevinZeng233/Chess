#include "MainWnd.h"
#include "Board.h"
#include <QHBoxLayout> 

MainWnd::MainWnd(int gameType)
{
	_gameType = gameType;
	init();
}


MainWnd::~MainWnd()
{
}

void MainWnd::init()
{
	if (_gameType == 0)
	{
		Board *bo = new Board();
		bo->show();
	}
	else if (_gameType == 1)
	{
		NetGame* natgame = new NetGame(true);
		natgame->show();
		//QHBoxLayout* hLay = new QHBoxLayout(this);
		//hLay->addWidget(natgame, 1);
	}
	else if(_gameType == 2)
	{
		NetGame* natgame = new NetGame(false);
		natgame->show();
		//QHBoxLayout* hLay = new QHBoxLayout(this);
		//hLay->addWidget(natgame, 1);
	}
}
