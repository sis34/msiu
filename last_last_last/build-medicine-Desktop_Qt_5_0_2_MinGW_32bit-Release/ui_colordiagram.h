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
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *playBtn;
    QPushButton *scalaBtn;
    QPushButton *sbrosBtn;

    void setupUi(QMainWindow *ColorDiagram)
    {
        if (ColorDiagram->objectName().isEmpty())
            ColorDiagram->setObjectName(QStringLiteral("ColorDiagram"));
        ColorDiagram->resize(681, 372);
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
        gridLayoutWidget->setGeometry(QRect(0, 0, 441, 231));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(0, 230, 441, 20));
        sizePolicy.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy);
        horizontalSlider->setCursor(QCursor(Qt::ArrowCursor));
        horizontalSlider->setMouseTracking(true);
        horizontalSlider->setFocusPolicy(Qt::TabFocus);
        horizontalSlider->setContextMenuPolicy(Qt::DefaultContextMenu);
        horizontalSlider->setAutoFillBackground(false);
        horizontalSlider->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0); "));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(0);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(240, 290, 301, 31));
        label->setStyleSheet(QStringLiteral("color: rgb(0, 0, 200)"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(550, 230, 31, 31));
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0)"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(550, 120, 20, 20));
        label_4->setStyleSheet(QStringLiteral("color: rgb(0, 255, 0)"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(550, 0, 21, 20));
        label_5->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255)"));
        playBtn = new QPushButton(centralwidget);
        playBtn->setObjectName(QStringLiteral("playBtn"));
        playBtn->setGeometry(QRect(10, 280, 101, 41));
        playBtn->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 0)"));
        scalaBtn = new QPushButton(centralwidget);
        scalaBtn->setObjectName(QStringLiteral("scalaBtn"));
        scalaBtn->setGeometry(QRect(490, 0, 51, 251));
        scalaBtn->setStyleSheet(QLatin1String("    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,0,255),stop: 0.2 rgb(0,100,200), stop: 0.4 rgb(0, 200, 100), stop: 0.6 rgb(100,200, 0), stop: 0.8 rgb(200,100, 0), stop: 1 rgb(255,0,0)); border:0px solid black;\n"
""));
        sbrosBtn = new QPushButton(centralwidget);
        sbrosBtn->setObjectName(QStringLiteral("sbrosBtn"));
        sbrosBtn->setGeometry(QRect(130, 280, 91, 41));
        sbrosBtn->setStyleSheet(QStringLiteral("    background-color: rgb(255, 0 ,0); border-radius: 20px; border: 2px solid #0,255,0 ;"));
        ColorDiagram->setCentralWidget(centralwidget);

        retranslateUi(ColorDiagram);

        QMetaObject::connectSlotsByName(ColorDiagram);
    } // setupUi

    void retranslateUi(QMainWindow *ColorDiagram)
    {
        ColorDiagram->setWindowTitle(QApplication::translate("ColorDiagram", "\320\224\320\270\320\260\320\263\321\200\320\260\320\274\320\274\320\260", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("ColorDiagram", "-300", 0));
        label_4->setText(QApplication::translate("ColorDiagram", "0", 0));
        label_5->setText(QApplication::translate("ColorDiagram", "300", 0));
        playBtn->setText(QApplication::translate("ColorDiagram", "\320\241\321\202\320\260\321\200\321\202", 0));
        scalaBtn->setText(QString());
        sbrosBtn->setText(QApplication::translate("ColorDiagram", "\320\241\320\261\321\200\320\276\321\201", 0));
    } // retranslateUi

};

namespace Ui {
    class ColorDiagram: public Ui_ColorDiagram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORDIAGRAM_H
