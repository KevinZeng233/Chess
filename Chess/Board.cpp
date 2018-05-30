#include "Board.h"
#include <QPainter>
#pragma execution_character_set("utf-8")

#define GetRowCol(__row, __col, __id) \
    int __row = stone[__id]._row;\
    int __col = stone[__id]._col

Board::Board(bool bRedSide)
{
	resize(QSize(1000, 800));
	for (int i=0;i<32;i++)
	{
		stone[i].init(i);
	}
	if (bRedSide)
	{
		for (int i = 0; i < 32; ++i)
		{
			stone[i].rotate();//上下互换
		}
	}
	select_id = -1;
	bRedTurn = true;
	_bSide = bRedSide;
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

void Board::drawStone(QPainter &painter, int Id)
{
	if (stone[Id]._dead)
		return;
	
	QPoint c = center(Id);
	QRect _rect = QRect(c.x() - _r, c.y() - _r, _r * 2, _r * 2);

	if (Id == select_id)
		painter.setBrush(QBrush(Qt::gray));
	else
		painter.setBrush(QBrush(Qt::yellow));

	//painter.setBrush(QBrush(Qt::yellow));
	
	if (stone[Id]._red)
	{
		painter.setPen(Qt::red);
	} 
	else
	{
		painter.setPen(Qt::black);
	}

	painter.drawEllipse(center(Id), _r, _r);

	if (stone[Id]._red)
	{
		painter.setPen(Qt::red);
	}
	painter.setFont(QFont("宋体", _r*0.8, 700));
	painter.drawText(_rect, stone[Id].getText(), QTextOption(Qt::AlignCenter));

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

QPolygonF Board::stonePolygon(int id)
{
	int r = _r ;
	QPointF LT(center(id).rx() - r, center(id).ry() - r);
	QPointF LB(center(id).rx() - r, center(id).ry() + r);
	QPointF RT(center(id).rx() + r, center(id).rx() - r);
	QPointF RB(center(id).rx() + r, center(id).rx() + r);
	QPolygonF poly;
	poly.append(LT);
	poly.append(LB);
	poly.append(RB);
	poly.append(RT);
	poly.append(LT);
 
	return poly;
}

bool Board::getRowCol(QPoint pt, int& row, int& col)
{
	for (row = 0; row <= 9; row++)
	{
		for (col = 0; col <= 8; col++)
		{
			QPoint c = center(row, col);
			int dx = c.x() - pt.x();
			int dy = c.y() - pt.y();
			int dist = dx * dx + dy * dy;
			if (dist < _r*_r)
				return true;
		}
	}
	return false;
}

bool Board::canmove(int moveid, int killid, int row, int col)
{
	if (SameColor(moveid,killid))
	{
		return false;
	}

	switch (stone[moveid]._type)
	{
	case Stone::CHE:
		return canmoveChe(moveid, killid, row, col);
	case Stone::MA:
		return canmoveMa(moveid, killid, row, col);
	case Stone::XIANG:
		return canmoveXiang(moveid, killid, row, col);
	case Stone::SHI:
		return canmoveShi(moveid, killid, row, col);
	case Stone::PAO:
		return canmovePao(moveid, killid, row, col);
	case Stone::BING:
		return canmoveBing(moveid, killid, row, col);
	case Stone::JIANG:
		return canmoveJiang(moveid, killid, row, col);
	}

	return false;
}

bool Board::canmoveChe(int moveid, int killid, int row, int col)
{
	GetRowCol(row1, col1, moveid);
	int ret = getStoneCountAtLine(row1, col1, row, col);
	if (ret == 0)
		return true;
	return false;
}

bool Board::canmoveMa(int moveid, int killid, int row, int col)
{
	GetRowCol(row1, col1, moveid);
	int r = relation(row1, col1, row, col);
	if (r != 12 && r != 21)
		return false;

	if (r == 12)
	{
		if (getStoneId(row1, (col + col1) / 2) != -1)
			return false;
	}
	else
	{
		if (getStoneId((row + row1) / 2, col1) != -1)
			return false;
	}

	return true;
}

bool Board::canmoveXiang(int moveid, int killid, int row, int col)
{
	GetRowCol(row1, col1, moveid);
	int r = relation(row1, col1, row, col);
	if (r != 22) return false;

	int rEye = (row + row1) / 2;
	int cEye = (col + col1) / 2;
	if (getStoneId(rEye, cEye) != -1)
		return false;

	if (isBottomSide(moveid))
	{
		if (row < 4) return false;
	}
	else
	{
		if (row > 5) return false;
	}
	return true;
}

bool Board::canmoveShi(int moveid, int killid, int row, int col)
{
	GetRowCol(row1, col1, moveid);
	int r = relation(row1, col1, row, col);
	if (r != 11) return false;

	if (col < 3 || col > 5) return false;
	if (isBottomSide(moveid))
	{
		if (row < 7) return false;
	}
	else
	{
		if (row > 2) return false;
	}
	return true;
}

bool Board::canmoveJiang(int moveid, int killid, int row, int col)
{
	if (killid != -1 && stone[killid]._type == Stone::JIANG)//面对面
		return canmoveChe(moveid, killid, row, col);

	GetRowCol(row1, col1, moveid);
	int r = relation(row1, col1, row, col);
	if (r != 1 && r != 10) return false;

	if (col < 3 || col > 5) return false;
	if (isBottomSide(moveid))
	{
		if (row < 7) return false;
	}
	else
	{
		if (row > 2) return false;
	}
	return true;
}

bool Board::canmovePao(int moveid, int killid, int row, int col)
{
	GetRowCol(row1, col1, moveid);
	int ret = getStoneCountAtLine(row, col, row1, col1);
	if (killid != -1)
	{
		if (ret == 1) return true;
	}
	else
	{
		if (ret == 0) return true;
	}
	return false;
}

bool Board::canmoveBing(int moveid, int killid, int row, int col)
{
	GetRowCol(row1, col1, moveid);
	int r = relation(row1, col1, row, col);
	if (r != 1 && r != 10) return false;

	if (isBottomSide(moveid))
	{
		if (row > row1) return false;
		if (row1 >= 5 && row == row1) return false;
	}
	else
	{
		if (row < row1) return false;
		if (row1 <= 4 && row == row1) return false;
	}

	return true;
}

bool Board::SameColor(int id_1, int id_2)
{
	if (id_1 == -1 || id_2 == -1)
	{
		return false;
	}
	return stone[id_1]._red == stone[id_2]._red;
}

int Board::relation(int row1, int col1, int row, int col)
{
	return qAbs(row1 - row) * 10 + qAbs(col1 - col);
}



bool Board::isBottomSide(int id)
{
	return _bSide == stone[id]._red;
}

int Board::getStoneCountAtLine(int row1, int col1, int row2, int col2)
{
	int ret = 0;
	if (row1 != row2 && col1 != col2)
		return -1;
	if (row1 == row2 && col1 == col2)
		return -1;

	if (row1 == row2)
	{
		int min = col1 < col2 ? col1 : col2;
		int max = col1 < col2 ? col2 : col1;
		for (int col = min + 1; col < max; ++col)
		{
			if (getStoneId(row1, col) != -1) ++ret;
		}
	}
	else
	{
		int min = row1 < row2 ? row1 : row2;
		int max = row1 < row2 ? row2 : row1;
		for (int row = min + 1; row < max; ++row)
		{
			if (getStoneId(row, col1) != -1) ++ret;
		}
	}

	return ret;
}

int Board::getStoneId(int row, int col)
{
	for (int i = 0; i < 32; ++i)
	{
		if (stone[i]._row == row && stone[i]._col == col && !stone[i]._dead)
			return i;
	}
	return -1;
}

void Board::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() != Qt::LeftButton)
		return;
	
	QPoint pt = event->pos();
	// 将pt转化成象棋的行列值
	// 判断这个行列值上面有没有棋子
	int row, col;
	bool bRet = getRowCol(pt, row, col);
	if (bRet == false) // 点到棋盘外
		return;

	int i;
	int clickid = -1;
	for (i = 0; i < 32; ++i)
	{
		if (stone[i]._row == row && stone[i]._col == col && stone[i]._dead == false)
		{
			break;
		}
	}

	if (i < 32)
	{
		clickid = i;//棋子被选中
	}

	if (select_id == -1)
	{
		if (clickid != -1)
		{
			if (bRedTurn == stone[clickid]._red)
			{
				select_id = clickid;
				update();
			}
		}
	} 
	else//移动
	{
		if (canmove(select_id,clickid,row,col))
		{
			stone[select_id]._row = row;
			stone[select_id]._col = col;
			if (clickid != -1)
			{
				stone[clickid]._dead = true;
			}
			bRedTurn = !bRedTurn;
			select_id = -1;
			update();
		}
	}
}

void Board::mousePressEvent(QMouseEvent *event)
{
	//QPoint pt = event->pos();
	//qDebug("posX:%d,posY:%d", event->x(), event->y());
	//for (int i = 0; i < 32; i++)
	//{
	//	if (stonePolygon(i).containsPoint(pt, Qt::OddEvenFill) && !stone[i]._dead)//命中区域
	//	{
	//		select_id = i;
	//		update();
	//		break;
	//	}
	//}
}

