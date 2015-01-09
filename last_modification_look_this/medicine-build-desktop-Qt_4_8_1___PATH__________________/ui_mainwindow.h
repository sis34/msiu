/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *createFormBtn;
    QPushButton *colorDiagramBtnOpen;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(503, 456);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setCursor(QCursor(Qt::ArrowCursor));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        createFormBtn = new QPushButton(centralWidget);
        createFormBtn->setObjectName(QString::fromUtf8("createFormBtn"));
        sizePolicy.setHeightForWidth(createFormBtn->sizePolicy().hasHeightForWidth());
        createFormBtn->setSizePolicy(sizePolicy);

        gridLayout->addWidget(createFormBtn, 0, 0, 1, 1);

        colorDiagramBtnOpen = new QPushButton(centralWidget);
        colorDiagramBtnOpen->setObjectName(QString::fromUtf8("colorDiagramBtnOpen"));
        sizePolicy.setHeightForWidth(colorDiagramBtnOpen->sizePolicy().hasHeightForWidth());
        colorDiagramBtnOpen->setSizePolicy(sizePolicy);

        gridLayout->addWidget(colorDiagramBtnOpen, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        createFormBtn->setText(QApplication::translate("MainWindow", "\320\244\320\276\321\200\320\274\320\260 \320\264\320\273\321\217 \320\262\320\262\320\276\320\264\320\260", 0, QApplication::UnicodeUTF8));
        colorDiagramBtnOpen->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\276\321\200\320\274\321\203 \320\264\320\270\320\260\320\263\321\200\320\260\320\274\320\274\321\213", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
