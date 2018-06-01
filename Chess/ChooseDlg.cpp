#include "ChooseDlg.h"
#include <QVBoxLayout> 


ChooseDlg::ChooseDlg()
{
	resize(QSize(800,600));
	QVBoxLayout* lay = new QVBoxLayout(this);
	lay->addWidget(button[0] = new QPushButton(u8"测试模式"));
	lay->addWidget(button[1] = new QPushButton(u8"网络对战(服务端)"));
	lay->addWidget(button[2] = new QPushButton(u8"网络对战(客户端)"));
	

	for (int i = 0; i < 3; ++i)
	{
		connect(button[i], SIGNAL(clicked()), this, SLOT(select()));
	}
}


ChooseDlg::~ChooseDlg()
{
}

void ChooseDlg::select()
{
	QObject* s = sender();
	for (int i = 0; i < 3; ++i)
	{
		if (button[i] == s)
		{
			this->selected = i;
			break;
		}
	}
	accept();
}
