#pragma once
#include <QWidget>
#include"Stone.h"
#include <QMouseEvent>  
class Board: public QWidget
{
	Q_OBJECT
public:
	explicit Board(QWidget *parent = 0);
	~Board();
	Stone stone[32];

	void    init(bool bRedSide);
	void	paintEvent(QPaintEvent *event);

	void	drawStone(QPainter &painter,int Id);
	QPoint  center(int row,int col);
	QPoint  center(int id);
	
	//棋子的矩形范围，判断点击到棋子
	QPolygonF stonePolygon(int id);

	//第二种方式
	bool getRowCol(QPoint pt, int& row, int& col);
	
	//点击
	void click(int id,int row,int col);

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
	int  getStoneCountAtLine(int row1, int col1, int row2, int col2);
	int  getStoneId(int row, int col);
private:
	int  _r;//棋子半径
	int  select_id;
	bool bRedTurn;//轮到红方
	bool _bSide;//上部分，还是下部分
protected:
	void mouseReleaseEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
};

