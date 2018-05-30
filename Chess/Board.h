#pragma once
#include <QWidget>
#include"Stone.h"
#include <QMouseEvent>  
class Board: public QWidget
{
	Q_OBJECT
public:
	Board();
	~Board();
	Stone stone[32];

	void	paintEvent(QPaintEvent *event);

	void	drawStone(QPainter &painter,int Id);
	QPoint  center(int row,int col);
	QPoint  center(int id);
	
	//棋子的矩形范围，判断点击到棋子
	QPolygonF stonePolygon(int id);

	//第二种方式
	bool getRowCol(QPoint pt, int& row, int& col);
	
	//移动规则判断
	bool canmove(int moveid,int killid,int row,int col);
	bool canmoveChe(int moveid, int killid, int row, int col);
	bool canmoveMa(int moveid, int killid, int row, int col);
	bool canmoveXiang(int moveid, int killid, int row, int col);
	bool canmoveShi(int moveid, int killid, int row, int col);
	bool canmoveJiang(int moveid, int killid, int row, int col);
	bool canmovePao(int moveid, int killid, int row, int col);
	bool canmoveBing(int moveid, int killid, int row, int col);

	//辅助函数
	//颜色相同
	bool SameColor(int id_1,int id_2);
	int  relation(int row1, int col1, int row, int col);
	bool isBottomSide(int id);
private:
	int  _r;//棋子半径
	int  select_id;
	bool bRedTurn;//轮到哪方走
protected:
	void mouseReleaseEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
};

