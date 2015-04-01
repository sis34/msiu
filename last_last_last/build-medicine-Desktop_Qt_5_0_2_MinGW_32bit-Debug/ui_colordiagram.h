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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
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
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *loadFile;

    void setupUi(QMainWindow *ColorDiagram)
    {
        if (ColorDiagram->objectName().isEmpty())
            ColorDiagram->setObjectName(QStringLiteral("ColorDiagram"));
        ColorDiagram->resize(750, 350);
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
        gridLayoutWidget->setGeometry(QRect(0, 0, 401, 141));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(0, 290, 431, 20));
        sizePolicy.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy);
        horizontalSlider->setMouseTracking(true);
        horizontalSlider->setMaximum(139);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 240, 121, 41));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(575, 15, 131, 61));
        label_2->setStyleSheet(QStringLiteral("rgb 255 255 0"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(560, 60, 181, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(570, 90, 171, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(580, 110, 111, 31));
        loadFile = new QPushButton(centralwidget);
        loadFile->setObjectName(QStringLiteral("loadFile"));
        loadFile->setGeometry(QRect(600, 190, 101, 23));
        ColorDiagram->setCentralWidget(centralwidget);

        retranslateUi(ColorDiagram);

        QMetaObject::connectSlotsByName(ColorDiagram);
    } // setupUi

    void retranslateUi(QMainWindow *ColorDiagram)
    {
        ColorDiagram->setWindowTitle(QApplication::translate("ColorDiagram", "\320\224\320\270\320\260\320\263\321\200\320\260\320\274\320\274\320\260", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("ColorDiagram", "\320\232\321\200\320\260\321\201\320\275\321\213\320\265 \320\276\321\202\321\202\320\265\320\275\320\272\320\270 < -150", 0));
        label_3->setText(QApplication::translate("ColorDiagram", "\320\226\320\265\320\273\321\202\321\213\320\265 \320\276\321\202\321\202\320\265\320\275\320\272\320\270 >-150 &&  < 0 ", 0));
        label_4->setText(QApplication::translate("ColorDiagram", "\320\227\320\265\320\273\320\265\320\275\321\213\320\265 \320\276\321\202\321\202\320\265\320\275\320\272\320\270 > 0 && < 150", 0));
        label_5->setText(QApplication::translate("ColorDiagram", "\320\241\320\270\320\275\320\270\320\265 \320\276\321\202\321\202\320\265\320\275\320\272\320\270 > 150", 0));
        loadFile->setText(QApplication::translate("ColorDiagram", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", 0));
    } // retranslateUi

};

namespace Ui {
    class ColorDiagram: public Ui_ColorDiagram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORDIAGRAM_H
