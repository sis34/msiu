/********************************************************************************
** Form generated from reading UI file 'colordiagram.ui'
**
** Created by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORDIAGRAM_H
#define UI_COLORDIAGRAM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ColorDiagram
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSlider *horizontalSlider;
    QLabel *label;

    void setupUi(QMainWindow *ColorDiagram)
    {
        if (ColorDiagram->objectName().isEmpty())
            ColorDiagram->setObjectName(QString::fromUtf8("ColorDiagram"));
        ColorDiagram->resize(685, 407);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ColorDiagram->sizePolicy().hasHeightForWidth());
        ColorDiagram->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(ColorDiagram);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 671, 291));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 310, 661, 20));
        sizePolicy.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy);
        horizontalSlider->setMouseTracking(true);
        horizontalSlider->setMaximum(139);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 350, 121, 41));
        ColorDiagram->setCentralWidget(centralwidget);

        retranslateUi(ColorDiagram);

        QMetaObject::connectSlotsByName(ColorDiagram);
    } // setupUi

    void retranslateUi(QMainWindow *ColorDiagram)
    {
        ColorDiagram->setWindowTitle(QApplication::translate("ColorDiagram", "\320\224\320\270\320\260\320\263\321\200\320\260\320\274\320\274\320\260", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ColorDiagram: public Ui_ColorDiagram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORDIAGRAM_H
