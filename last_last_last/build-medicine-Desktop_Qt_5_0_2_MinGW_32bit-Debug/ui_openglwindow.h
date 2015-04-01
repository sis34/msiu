/********************************************************************************
** Form generated from reading UI file 'openglwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENGLWINDOW_H
#define UI_OPENGLWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenGLWindow
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *OpenGLWindow)
    {
        if (OpenGLWindow->objectName().isEmpty())
            OpenGLWindow->setObjectName(QStringLiteral("OpenGLWindow"));
        OpenGLWindow->resize(800, 600);
        menubar = new QMenuBar(OpenGLWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        OpenGLWindow->setMenuBar(menubar);
        centralwidget = new QWidget(OpenGLWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        OpenGLWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(OpenGLWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        OpenGLWindow->setStatusBar(statusbar);

        retranslateUi(OpenGLWindow);

        QMetaObject::connectSlotsByName(OpenGLWindow);
    } // setupUi

    void retranslateUi(QMainWindow *OpenGLWindow)
    {
        OpenGLWindow->setWindowTitle(QApplication::translate("OpenGLWindow", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class OpenGLWindow: public Ui_OpenGLWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENGLWINDOW_H
