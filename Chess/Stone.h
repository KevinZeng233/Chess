#pragma once
#include <QString>
#pragma execution_character_set("utf-8")

class Stone
{
public:
	Stone();
	~Stone();
	enum TYPE
	{
		JIANG,
		CHE,
		PAO,
		MA,
		BING,
		SHI,
		XIANG
	};
	int _row;//行
	int _col;//列
	int _id;
	bool _dead;
	bool _red;

	TYPE _type;

	void	 init(int id); 
	QString  getText(); 
	void	 rotate();
};

