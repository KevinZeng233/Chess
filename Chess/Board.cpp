#include "Board.h"
#include <QPainter>

Board::Board()
{
	resize(QSize(1000, 800));
	for (int i=0;i<32;i++)
	{
		stone[i].init(i);
	}
}


Board::~Board()
{
}

void Board::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	int d = 60;
	_r = d / 2;

	//横线
	for (int i = 1; i <= 10; i++)
	{
		painter.drawLine(QPoint(d, d*i), QPoint(9 * d, d*i));
	}

	//竖线
	for (int i = 1; i <= 9; i++)
	{
		if (i == 1 || i == 9)
		{
			painter.drawLine(QPoint(d*i, d), QPoint(d*i, 10 * d));
		}
		else
		{
			painter.drawLine(QPoint(d*i, d), QPoint(d*i, 5 * d));
			painter.drawLine(QPoint(d*i, 6 * d), QPoint(d*i, 10 * d));
		}
	}

	//九宫格
	painter.drawLine(QPoint(4 * d, d), QPoint(6 * d, 3 * d));
	painter.drawLine(QPoint(4 * d, 3 * d), QPoint(6 * d, d));

	painter.drawLine(QPoint(4 * d, 8 * d), QPoint(6 * d, 10 * d));
	painter.drawLine(QPoint(4 * d, 10 * d), QPoint(6 * d, 8 * d));

	//32个棋子
	for (int i = 0;i < 32;i++)
	{
		drawStone(painter,i);
	}
}

QPoint Board::center(int row, int col)
{
	QPoint point;
	point.rx() = (col + 1) * _r * 2;
	point.ry() = (row + 1) * _r * 2;
	return point;
}

QPoint Board::center(int id)
{
	return center(stone[id]._row, stone[id]._col);
}

bool Board::isPointInPolygon(QVector<QPointF> points, QPointF point)
{
	QPolygonF polygon(points);
	return polygon.containsPoint(point, Qt::OddEvenFill);
}

QPolygonF Board::stonePolygon(int id)
{
	 
	QPointF LT(15, 0);
	QPointF LB(15, 30);
	QPointF RB(125, 30);
	QPointF RT(125, 0);
	QPolygonF poly;
	poly.append(LT);
	poly.append(LB);
	poly.append(RB);
	poly.append(RT);
 

	return poly;
}

void Board::drawStone(QPainter &painter, int Id)
{
	

	QPoint c = center(Id);
	QRect _rect = QRect(c.x() - _r, c.y() - _r, _r * 2, _r * 2);
	
	painter.setBrush(QBrush(Qt::yellow));
	painter.setPen(Qt::black);
	painter.drawEllipse(center(Id), _r, _r);

	if (stone[Id]._red)
	{
		painter.setPen(Qt::red);
	}
	painter.setFont(QFont("宋体", _r*0.8 ,700));
	painter.drawText(_rect, stone[Id].getText(), QTextOption(Qt::AlignCenter));

}