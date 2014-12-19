#include "colordiagram.h"
#include "ui_colordiagram.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QLayout>
#include <QImage>
#include <QLabel>
#include <QScrollArea>
#include <QColor>
#include "QTime"
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
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
    QFile *file = new QFile(filePath);
    file->open(QIODevice::ReadOnly);
    QTextStream in(file);
    int  t[80];
    for(int x = 0; x <= 4; x++){
        for(int y = 0; y <= 15; y++){
            QString line = in.readLine();
            int number = line.toInt();
            t[x*16+y] = number;
            //ift[x*16+y-16]
            qDebug() << t[x*16+y];
            QPushButton *btn = new QPushButton(this);
            btn->setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);
            if(number < 100 && x < 1){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0.3, y1: 0, x2: 0.3, y2: 1, stop: 0 #ff0000, stop: 0.5 #ff0000, stop: 1 #00ff00); border:0px solid black;");
            } else if(number <= 200 && number >= 100 && x < 1){
               btn->setStyleSheet("background-color: qlineargradient(x1: 0.3, y1: 0, x2: 0.3, y2: 1, stop: 0 #00ff00, stop: 0.5 #00ff00, stop: 1 #0000ff); border:0px solid black;");
             }else if(number > 200  && x < 1){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0.3, y1: 0, x2: 0.3, y2: 1, stop: 0 #0000ff, stop: 0.5 #0000ff, stop: 1 #ff0000); border:0px solid black;");
            }
            else if(t[x*16+y-16]<100 && number < 100){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0.3, y1: 0, x2: 0.3, y2: 1, stop: 0 #00ff00, stop: 0.5 #ff0000, stop: 1 #ff0000); border:0px solid black;");
            }
            else if(t[x*16+y-16]<200 && t[x*16+y-16] >= 100 && number >=100 && number <=  200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0.3, y1: 0, x2: 0.3, y2: 1, stop: 0 #0000ff, stop: 0.5 #00ff00, stop: 1 #00ff00); border:0px solid black;");
            }
            else if(t[x*16+y-16]>200 && number >=200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0.3, y1: 0, x2: 0.3, y2: 1, stop: 0 #ff0000, stop: 0.5 #0000ff, stop: 1 #0000ff); border:0px solid black;");
            }
            else if(t[x*16+y-16]>200 && number < 100){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0.3, y1: 0, x2: 0.3, y2: 1, stop: 0 #ff0000, stop: 0.5 #00ff00, stop: 1 #00ff00); border:0px solid black;");
            }
            btn->setDisabled(true);
            ui->gridLayout->addWidget(btn, x, y);
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

    ui->label->setText(QString::number(position).append(" Секунда"));
}


