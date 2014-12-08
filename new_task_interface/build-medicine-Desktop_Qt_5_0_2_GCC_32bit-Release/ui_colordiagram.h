/********************************************************************************
** Form generated from reading UI file 'colordiagram.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORDIAGRAM_H
#define UI_COLORDIAGRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ColorDiagram
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSlider *horizontalSlider;

    void setupUi(QMainWindow *ColorDiagram)
    {
        if (ColorDiagram->objectName().isEmpty())
            ColorDiagram->setObjectName(QStringLiteral("ColorDiagram"));
        ColorDiagram->resize(814, 663);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ColorDiagram->sizePolicy().hasHeightForWidth());
        ColorDiagram->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(ColorDiagram);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 801, 601));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(300, 630, 160, 19));
        sizePolicy.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy);
        horizontalSlider->setOrientation(Qt::Horizontal);
        ColorDiagram->setCentralWidget(centralwidget);

        retranslateUi(ColorDiagram);

        QMetaObject::connectSlotsByName(ColorDiagram);
    } // setupUi

    void retranslateUi(QMainWindow *ColorDiagram)
    {
        ColorDiagram->setWindowTitle(QApplication::translate("ColorDiagram", "\320\224\320\270\320\260\320\263\321\200\320\260\320\274\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class ColorDiagram: public Ui_ColorDiagram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORDIAGRAM_H
