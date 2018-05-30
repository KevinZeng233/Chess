#pragma once
#include <QWidget>
#include"Stone.h"

class Board: public QWidget
{
	Q_OBJECT
public:
	Board();
	~Board();
	Stone stone[32];

	void paintEvent(QPaintEvent *event);

	void drawStone(QPainter &painter,int Id);
	QPoint  center(int row,int col);
	QPoint  center(int id);
	bool isPointInPolygon(QVector<QPointF> points, QPointF point);
	//棋子的矩形范围
	QPolygonF stonePolygon(int id);
private:
	int _r;//棋子半径
};

