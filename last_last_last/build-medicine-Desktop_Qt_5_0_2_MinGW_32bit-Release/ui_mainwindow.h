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
        colorDiagramBtnOpen->setStyleSheet(QStringLiteral("background-color: rgb(0 ,100, 100); font-size: 200%;"));

        gridLayout->addWidget(colorDiagramBtnOpen, 0, 1, 1, 1);

        createFormBtn = new QPushButton(centralWidget);
        createFormBtn->setObjectName(QStringLiteral("createFormBtn"));
        sizePolicy.setHeightForWidth(createFormBtn->sizePolicy().hasHeightForWidth());
        createFormBtn->setSizePolicy(sizePolicy);

        gridLayout->addWidget(createFormBtn, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        colorDiagramBtnOpen->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\321\200\321\213\320\271 \320\264\320\265\320\275\321\214!\n"
"\320\232\320\273\320\270\320\272\320\275\320\270\321\202\320\265 \320\264\320\273\321\217 \320\277\321\200\320\276\320\264\320\276\320\273\320\266\320\265\320\275\320\270\321\217!", 0));
        createFormBtn->setText(QApplication::translate("MainWindow", "\320\244\320\276\321\200\320\274\320\260 \320\264\320\273\321\217 \320\262\320\262\320\276\320\264\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
