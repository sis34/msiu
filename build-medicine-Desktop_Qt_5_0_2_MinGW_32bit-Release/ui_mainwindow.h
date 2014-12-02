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
    QPushButton *loadFileBtn;
    QPushButton *createFormBtn;
    QPushButton *sqlLiteBtn;
    QPushButton *createWindowBtn;

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
        loadFileBtn = new QPushButton(centralWidget);
        loadFileBtn->setObjectName(QStringLiteral("loadFileBtn"));
        sizePolicy.setHeightForWidth(loadFileBtn->sizePolicy().hasHeightForWidth());
        loadFileBtn->setSizePolicy(sizePolicy);

        gridLayout->addWidget(loadFileBtn, 0, 1, 1, 1);

        createFormBtn = new QPushButton(centralWidget);
        createFormBtn->setObjectName(QStringLiteral("createFormBtn"));
        sizePolicy.setHeightForWidth(createFormBtn->sizePolicy().hasHeightForWidth());
        createFormBtn->setSizePolicy(sizePolicy);

        gridLayout->addWidget(createFormBtn, 1, 0, 1, 1);

        sqlLiteBtn = new QPushButton(centralWidget);
        sqlLiteBtn->setObjectName(QStringLiteral("sqlLiteBtn"));
        sizePolicy.setHeightForWidth(sqlLiteBtn->sizePolicy().hasHeightForWidth());
        sqlLiteBtn->setSizePolicy(sizePolicy);

        gridLayout->addWidget(sqlLiteBtn, 1, 1, 1, 1);

        createWindowBtn = new QPushButton(centralWidget);
        createWindowBtn->setObjectName(QStringLiteral("createWindowBtn"));
        sizePolicy.setHeightForWidth(createWindowBtn->sizePolicy().hasHeightForWidth());
        createWindowBtn->setSizePolicy(sizePolicy);
        createWindowBtn->setCursor(QCursor(Qt::ArrowCursor));
        createWindowBtn->setCheckable(false);

        gridLayout->addWidget(createWindowBtn, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        loadFileBtn->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", 0));
        createFormBtn->setText(QApplication::translate("MainWindow", "\320\244\320\276\321\200\320\274\320\260 \320\264\320\273\321\217 \320\262\320\262\320\276\320\264\320\260", 0));
        sqlLiteBtn->setText(QApplication::translate("MainWindow", "\320\241\321\207\320\270\321\202\320\260\321\202\321\214 \320\261\320\260\320\267\321\203 \320\264\320\260\320\275\320\275\321\213\321\205 \320\270 \320\262\321\213\320\262\320\265\321\201\321\202\320\270 \320\262 qDebug()", 0));
        createWindowBtn->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\264\320\270\320\260\320\273\320\276\320\263\320\276\320\262\320\276\320\265 \320\276\320\272\320\275\320\276", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
