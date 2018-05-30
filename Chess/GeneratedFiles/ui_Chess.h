/********************************************************************************
** Form generated from reading UI file 'Chess.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESS_H
#define UI_CHESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChessClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ChessClass)
    {
        if (ChessClass->objectName().isEmpty())
            ChessClass->setObjectName(QStringLiteral("ChessClass"));
        ChessClass->resize(600, 400);
        menuBar = new QMenuBar(ChessClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        ChessClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ChessClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ChessClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ChessClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ChessClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ChessClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ChessClass->setStatusBar(statusBar);

        retranslateUi(ChessClass);

        QMetaObject::connectSlotsByName(ChessClass);
    } // setupUi

    void retranslateUi(QMainWindow *ChessClass)
    {
        ChessClass->setWindowTitle(QApplication::translate("ChessClass", "Chess", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChessClass: public Ui_ChessClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESS_H
