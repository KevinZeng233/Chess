#include "Stone.h"



Stone::Stone()
{
}

Stone::~Stone()
{
}

void Stone::init(int id)
{
	_id = id;
	_dead = false;
	_red = id < 16;

	struct
	{
		int row, col;
		Stone::TYPE type;
	}pos[16] =
	{
		{ 0,0,Stone::CHE},
		{ 0,8,Stone::CHE },
		{ 0,1,Stone::MA },
		{ 0,7,Stone::MA },
		{ 0,2,Stone::XIANG },
		{ 0,6,Stone::XIANG },
		{ 0,3,Stone::SHI },
		{ 0,5,Stone::SHI },

		{ 0,4,Stone::JIANG },

		{ 2,1,Stone::PAO },
		{ 2,7,Stone::PAO },

		{ 3,0,Stone::BING },
		{ 3,2,Stone::BING },
		{ 3,4,Stone::BING },
		{ 3,6,Stone::BING },
		{ 3,8,Stone::BING },

	};

	if (id < 16)
	{
		_row = pos[id].row;
		_col = pos[id].col;
		_type = pos[id].type;
	}
	else
	{
		_row = 9 - pos[id - 16].row;
		_col = 8 - pos[id - 16].col;
		_type = pos[id - 16].type;
	}
}