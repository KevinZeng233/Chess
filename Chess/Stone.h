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

	void init(int id);

	QString getText()
	{
		//switch (this->_type)
		//{
		//case CHE:
		//	return u8"车";
		//case MA:
		//	return u8"马";
		//case PAO:
		//	return u8"炮";
		//case BING:
		//	return u8"兵";
		//case JIANG:
		//	return u8"将";
		//case SHI:
		//	return u8"士";
		//case XIANG:
		//	return u8"相";
		//}
		//return u8"错误";
		switch (this->_type)
		{
		case CHE:
			return "车";
		case MA:
			return "马";
		case PAO:
			return "炮";
		case BING:
			return "兵";
		case JIANG:
			return "将";
		case SHI:
			return "士";
		case XIANG:
			return "相";
		}
		return "错误";
	}
};

