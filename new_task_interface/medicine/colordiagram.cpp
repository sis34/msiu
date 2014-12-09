#include "colordiagram.h"
#include "ui_colordiagram.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QLayout>

ColorDiagram::ColorDiagram(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ColorDiagram)
{
    ui->setupUi(this);
    fillGridLayoutTest(QString("/mnt/storage1/users/s/si/sis34/Desktop/edu/build-medicine-Desktop_Qt_5_0_2_GCC_32bit-Release/test/test1.txt"));
}

ColorDiagram::~ColorDiagram()
{
    delete ui;
}

void ColorDiagram::fillGridLayoutTest(QString filePath)
{
    QFile *file = new QFile(filePath);
    file->open(QIODevice::ReadOnly);
    QTextStream in(file);

    for(int x = 0; x <= 15; x++){
        for(int y = 0; y <= 4; y++){
            QString line = in.readLine();
            int number = line.toInt();
            QPushButton *btn = new QPushButton(this);
            btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            if(number > 750){
                btn->setStyleSheet("background-color: yellow;border:1px solid black;");
            } else if(number <= 750 && number >= 500){
                btn->setStyleSheet("background-color: red;border:1px solid black;");
            } else if(number < 500 && number >= 250){
                btn->setStyleSheet("background-color: blue;border:1px solid black;");
            } else {
                btn->setStyleSheet("background-color: green;border:1px solid black;");
            }
            btn->setDisabled(true);
            ui->gridLayout->addWidget(btn, y, x);
        }
    }

    file->close();
}

void ColorDiagram::on_horizontalSlider_sliderMoved(int position)
{
    qDebug() << position;
    QLayoutItem *child;
    QWidget *w;
    while((child = ui->gridLayout->takeAt(0)) != 0){
        w = child->widget();
        ui->gridLayout->removeItem(child);
        delete child;
        delete w;
   }
    if(position >= 0 && position < 10){
       fillGridLayoutTest(QString("/mnt/storage1/users/s/si/sis34/Desktop/edu/build-medicine-Desktop_Qt_5_0_2_GCC_32bit-Release/test/test1.txt"));
    } else if(position >=10 && position < 20) {
       fillGridLayoutTest(QString("/mnt/storage1/users/s/si/sis34/Desktop/edu/build-medicine-Desktop_Qt_5_0_2_GCC_32bit-Release/test/test2.txt"));
    } else if(position >= 20 && position < 30){
        fillGridLayoutTest(QString("/mnt/storage1/users/s/si/sis34/Desktop/edu/build-medicine-Desktop_Qt_5_0_2_GCC_32bit-Release/test/test3.txt"));
    } else if(position >= 30 && position < 40){
        fillGridLayoutTest(QString("/mnt/storage1/users/s/si/sis34/Desktop/edu/build-medicine-Desktop_Qt_5_0_2_GCC_32bit-Release/test/test4.txt"));
    } else if(position >= 40 && position < 50){
        fillGridLayoutTest(QString("/mnt/storage1/users/s/si/sis34/Desktop/edu/build-medicine-Desktop_Qt_5_0_2_GCC_32bit-Release/test/test5.txt"));
    } else if(position >= 50 && position < 60){
        fillGridLayoutTest(QString("/mnt/storage1/users/s/si/sis34/Desktop/edu/build-medicine-Desktop_Qt_5_0_2_GCC_32bit-Release/test/test6.txt"));
    } else if(position >= 60 && position < 70){
        fillGridLayoutTest(QString("/mnt/storage1/users/s/si/sis34/Desktop/edu/build-medicine-Desktop_Qt_5_0_2_GCC_32bit-Release/test/test7.txt"));
    } else if(position >= 70 && position < 80){
        fillGridLayoutTest(QString("/mnt/storage1/users/s/si/sis34/Desktop/edu/build-medicine-Desktop_Qt_5_0_2_GCC_32bit-Release/test/test8.txt"));
    } else if(position >= 80 && position < 90){
        fillGridLayoutTest(QString("/mnt/storage1/users/s/si/sis34/Desktop/edu/build-medicine-Desktop_Qt_5_0_2_GCC_32bit-Release/test/test9.txt"));
    } else {
        fillGridLayoutTest(QString("/mnt/storage1/users/s/si/sis34/Desktop/edu/build-medicine-Desktop_Qt_5_0_2_GCC_32bit-Release/test/test10.txt"));
    }

}
