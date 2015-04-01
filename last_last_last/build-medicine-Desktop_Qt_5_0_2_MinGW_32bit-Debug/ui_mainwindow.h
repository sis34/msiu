/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *colorDiagramBtnOpen;
    QPushButton *createFormBtn;
    QPushButton *openglBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(503, 456);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setCursor(QCursor(Qt::ArrowCursor));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        colorDiagramBtnOpen = new QPushButton(centralWidget);
        colorDiagramBtnOpen->setObjectName(QStringLiteral("colorDiagramBtnOpen"));
        sizePolicy.setHeightForWidth(colorDiagramBtnOpen->sizePolicy().hasHeightForWidth());
        colorDiagramBtnOpen->setSizePolicy(sizePolicy);

        gridLayout->addWidget(colorDiagramBtnOpen, 0, 1, 1, 1);

        createFormBtn = new QPushButton(centralWidget);
        createFormBtn->setObjectName(QStringLiteral("createFormBtn"));
        sizePolicy.setHeightForWidth(createFormBtn->sizePolicy().hasHeightForWidth());
        createFormBtn->setSizePolicy(sizePolicy);

        gridLayout->addWidget(createFormBtn, 0, 0, 1, 1);

        openglBtn = new QPushButton(centralWidget);
        openglBtn->setObjectName(QStringLiteral("openglBtn"));
        sizePolicy.setHeightForWidth(openglBtn->sizePolicy().hasHeightForWidth());
        openglBtn->setSizePolicy(sizePolicy);

        gridLayout->addWidget(openglBtn, 0, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        colorDiagramBtnOpen->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\276\321\200\320\274\321\203 \320\264\320\270\320\260\320\263\321\200\320\260\320\274\320\274\321\213", 0));
        createFormBtn->setText(QApplication::translate("MainWindow", "\320\244\320\276\321\200\320\274\320\260 \320\264\320\273\321\217 \320\262\320\262\320\276\320\264\320\260", 0));
        openglBtn->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 openGL", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
