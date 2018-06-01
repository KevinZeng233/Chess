#include "Chess.h"
#include <QtWidgets/QApplication>
#include "ChooseDlg.h"
#include "MainWnd.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	ChooseDlg dlg;
	if (dlg.exec() != QDialog::Accepted)
	{
		return 0;
	}
	MainWnd mainwnd(dlg.selected);
	

	return a.exec();
}
