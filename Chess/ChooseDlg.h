#pragma once
#include <QDialog>
#include <QPushButton>
class ChooseDlg:public QDialog
{
	Q_OBJECT
public:
	ChooseDlg();
	~ChooseDlg();
	QPushButton * button[3];
	int selected;
public slots:
	void select();

};

