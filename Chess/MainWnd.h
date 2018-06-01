#pragma once
#include "NetGame.h"

class MainWnd
{
public:
	MainWnd(int gameType);
	~MainWnd();
	void init();
	int _gameType;
};

