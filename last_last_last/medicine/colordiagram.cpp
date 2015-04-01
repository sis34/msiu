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
ColorDiagram::ColorDiagram(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::ColorDiagram),
    autoPlayTimer(new QTimer)
{
    ui->setupUi(this);
   fillGridLayoutTest(QString("C:\\msiu-master\\last_modification_look_this\\logs\\log1000"));
   autoPlayTimer->setInterval(1000);
   connect(autoPlayTimer, SIGNAL(timeout()), this, SLOT(nextStep()));
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

    /*int test_ar[80];
    for(int i = 0; i <80; i++){
        QString qqq = in.readLine();
        int num = qqq.toInt();
        test_ar[i] = num;
    }
    for(int i = 0; i < 80; i++){
        qDebug() << test_ar[i];
    }*/

   int  t[1105];
    for(int x = 0; x <= 16; x++){
        for(int y = 0; y <= 64; y++){
            QString line = in.readLine();
            int number = line.toInt();
             t[65*x+y] = number;

             qDebug() << t[0];
             //qDebug() << t[62];
            QPushButton *btn = new QPushButton(this);
            btn->setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);


            //конкретно данные
            if(x == 0 ){
            if(number < -250 ){
                btn->setStyleSheet("background-color: rgb(255, 0, 0); border:0px solid black;");
            }
            else if(number >= -250 && number < -225){
                btn->setStyleSheet("background-color: rgb(255, 50, 0); border:0px solid black;");
            }
            else if(number >= -225 && number < -200){
                btn->setStyleSheet("background-color: rgb(225, 50, 0); border:0px solid black;");
            }

            else if(number >= -200 && number < -175 ){
                btn->setStyleSheet("background-color: rgb(200, 50, 0); border:0px solid black;");
            }
            else if(number >= -175 && number < -150){
                btn->setStyleSheet("background-color: rgb(200, 75,0); border:0px solid black;");
            }
            else if(number >= -150 && number < -125){
                btn->setStyleSheet("background-color: rgb(175, 100, 0); border:0px solid black;");
            }
            else if(number >= -125 && number < -100){
                btn->setStyleSheet("background-color: rgb(150, 125, 0); border:0px solid black;");
            }
            else if(number >= -100 && number < -75){
                btn->setStyleSheet("background-color: rgb(125, 150, 0); border:0px solid black;");
            }
            else if(number >= -75 && number < -50){
                btn->setStyleSheet("background-color: rgb(125, 175, 0); border:0px solid black;");
            }
            else if(number >= -50 && number < -25 ){
                btn->setStyleSheet("background-color: rgb(100, 200, 0); border:0px solid black;");
            }
             else if(number >= -25 && number < 0 ){
               btn->setStyleSheet("background-color: rgb(100,255, 0); border:0px solid black;");
            }
            else if(number >= 0 && number < 25 ){
              btn->setStyleSheet("background-color: rgb(0, 255, 50); border:0px solid black;");
           }
            else if(number >= 25 && number < 50 ){
              btn->setStyleSheet("background-color: rgb(0, 225, 50); border:0px solid black;");
           }
               else if(number >= 50 && number < 75 ){
                 btn->setStyleSheet("background-color: rgb(0, 200, 75); border:0px solid black;");
            }
            else if(number >= 75 && number < 100 ){
              btn->setStyleSheet("background-color: rgb(0, 175, 100); border:0px solid black;");
           }
            else if(number >= 100 && number < 125 ){
                btn->setStyleSheet("background-color: rgb(0, 150, 125); border:0px solid black;");
            }
            else if(number >= 125 && number < 150 ){
              btn->setStyleSheet("background-color: rgb(0, 125, 150); border:0px solid black;");
           }else if(number >= 150 && number < 175 ){
                btn->setStyleSheet("background-color: rgb(0, 100, 175); border:0px solid black;");
            }
            else if(number >= 175 && number < 200 ){
              btn->setStyleSheet("background-color: rgb(0, 75, 200); border:0px solid black;");
           }
            else if(number >= 200 && number < 225 ){
                 btn->setStyleSheet("background-color: rgb(0, 50, 225); border:0px solid black;");
              }
            else if(number >= 225 && number < 250 ){
              btn->setStyleSheet("background-color: rgb(0, 50, 255); border:0px solid black;");
           }
            else if(number >= 250){
                 btn->setStyleSheet("background-color: rgb(0, 0, 255); border:0px solid black;");
              }
           }







//усреднение

            if(x>0){
                //<-250
                 if(number < -250 && t[65*x+y-65] < -250){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255, 0, 0), stop: 0.8 rgb(255,0,0)); border:0px solid black;");
            }
                else if(number < -250 && t[65*x+y-65] < -225 && t[65*x+y-65] >= -250){
               btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255, 50, 0), stop: 0.8 rgb(255,0,0)); border:0px solid black;");
             }
                else if(number < -250 && t[65*x+y-65] < -200 && t[65*x+y-65] >= -225){
               btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(225, 50, 0), stop: 0.8 rgb(255,0, 0)); border:0px solid black;");
             }
                else if(number < -250 && t[65*x+y-65] < -175 && t[65*x+y-65] >= -200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200, 50, 0), stop: 0.8 rgb(255,0,0)); border:0px solid black;");
             }
                else if(number < -250 && t[65*x+y-65] < -150 && t[65*x+y-65] >= -175){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200, 75, 0), stop: 0.8 rgb(255,0,0)); border:0px solid black;");
             }
                else if(number < -250 && t[65*x+y-65] < -125 && t[65*x+y-65] >= -150){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(175, 100, 0), stop: 0.8 rgb(255,0,0)); border:0px solid black;");
             }
                else if(number < -250 && t[65*x+y-65] < -100 && t[65*x+y-65] >= -125){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(150, 125, 0), stop: 0.8 rgb(255,0,0)); border:0px solid black;");
             }
                else if(number < -250 && t[65*x+y-65] < -75 && t[65*x+y-65] >= -100){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125, 150, 0), stop: 0.8 rgb(255,0,0)); border:0px solid black;");
             }
                else if(number < -250 && t[65*x+y-65] < -50 && t[65*x+y-65] >= -75){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125, 175, 0), stop: 0.8 rgb(255,0,0)); border:0px solid black;");
             }
                else if(number < -250 && t[65*x+y-65] < -25 && t[65*x+y-65] >= -50){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100, 200, 0), stop: 0.8 rgb(255,0,0)); border:0px solid black;");
             }
                else if(number < -250 && t[65*x+y-65] < 0 && t[65*x+y-65] >= -25){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100, 255, 0), stop: 0.8 rgb(255,0,0)); border:0px solid black;");
             }
                else if(number < -250 && t[65*x+y-65] < 25 && t[65*x+y-65] >= 0){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 255, 50), stop: 0.8 rgb(255,0,0)); border:0px solid black;");
             }
                else if(number < -250 && t[65*x+y-65] < 50 && t[65*x+y-65] >= 25){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 225, 50), stop: 0.8 rgb(255,0,0)); border:0px solid black;");
             }
                else if(number < -250 && t[65*x+y-65] < 75 && t[65*x+y-65] >= 50){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 200, 75), stop: 0.8 rgb(255,0,0)); border:0px solid black;");
             }
                else if(number < -250 && t[65*x+y-65] < 100 && t[65*x+y-65] >= 75){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 175, 100), stop: 0.8 rgb(255,0,0)); border:0px solid black;");
             }
                else if(number < -250 && t[65*x+y-65] < 125 && t[65*x+y-65] >= 100){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 150, 125), stop: 0.8 rgb(255,0,0)); border:0px solid black;");
             }
                else if(number < -250 && t[65*x+y-65] < 150 && t[65*x+y-65] >= 125){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 125, 150), stop: 0.8 rgb(255,0,0)); border:0px solid black;");
             }
                else if(number < -250 && t[65*x+y-65] < 175 && t[65*x+y-65] >= 150){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 100, 175), stop: 0.8 rgb(255,0,0)); border:0px solid black;");
             }
                else if(number < -250 && t[65*x+y-65] < 200 && t[65*x+y-65] >= 175){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 75, 200), stop: 0.8 rgb(255,0,0)); border:0px solid black;");
             }
                else if(number < -250 && t[65*x+y-65] < 225 && t[65*x+y-65] >= 200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 50, 225), stop: 0.8 rgb(255,0,0)); border:0px solid black;");
             }
                else if(number < -250 && t[65*x+y-65] < 250 && t[65*x+y-65] >= 225){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 50, 255), stop: 0.8 rgb(255,0,0)); border:0px solid black;");
             }
                else if(number < -250 && t[65*x+y-65] >= 250){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 0, 255), stop: 0.8 rgb(255,0,0)); border:0px solid black;");
             }

                //<-225 && >-250
                else if(number < -225 && number >= -250 && t[65*x+y-65] < -250){
                 btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255, 0, 0), stop: 0.8 rgb(255,50,0)); border:0px solid black;");
            }
                else if(number < -225 && number >= -250 && t[65*x+y-65] < -225 && t[65*x+y-65] >= -250){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255, 50, 0), stop: 0.8 rgb(255,50,0)); border:0px solid black;");
             }
                else if(number < -225 && number >= -250 && t[65*x+y-65] < -200 && t[65*x+y-65] >= -225){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(225, 50, 0), stop: 0.8 rgb(255,50,0)); border:0px solid black;");
             }
                else if(number < -225 && number >= -250 && t[65*x+y-65] < -175 && t[65*x+y-65] >= -200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200, 50, 0), stop: 0.8 rgb(255,50,0)); border:0px solid black;");
             }
                else if(number < -225 && number >= -250 && t[65*x+y-65] < -150 && t[65*x+y-65] >= -175){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200, 75, 0), stop: 0.8 rgb(255,50,0)); border:0px solid black;");
             }
                else if(number < -225 && number >= -250 && t[65*x+y-65] < -125 && t[65*x+y-65] >= -150){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(175, 100, 0), stop: 0.8 rgb(255,50,0)); border:0px solid black;");
             }
                else if(number < -225 && number >= -250 && t[65*x+y-65] < -100 && t[65*x+y-65] >= -125){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(150, 125, 0), stop: 0.8 rgb(255,50,0)); border:0px solid black;");
             }
                else if(number < -225 && number >= -250 && t[65*x+y-65] < -75 && t[65*x+y-65] >= -100){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125, 150, 0), stop: 0.8 rgb(255,50,0)); border:0px solid black;");
             }
                else if(number < -225 && number >= -250 && t[65*x+y-65] < -50 && t[65*x+y-65] >= -75){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125, 175, 0), stop: 0.8 rgb(255,50,0)); border:0px solid black;");
            }
                else if(number < -225 && number >= -250 && t[65*x+y-65] < -25 && t[65*x+y-65] >= -50){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100, 200, 0), stop: 0.8 rgb(255,50,0)); border:0px solid black;");
             }
                else if(number < -225 && number >= -250 && t[65*x+y-65] < 0 && t[65*x+y-65] >= -25){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100, 255, 0), stop: 0.8 rgb(255,50,0)); border:0px solid black;");
             }
                else if(number < -225 && number >= -250 && t[65*x+y-65] < 25 && t[65*x+y-65] >= 0){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 255, 50), stop: 0.8 rgb(255,50,0)); border:0px solid black;");
             }
                else if(number < -225 && number >= -250 && t[65*x+y-65] < 50 && t[65*x+y-65] >= 25){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 225, 50), stop: 0.8 rgb(255,50,0)); border:0px solid black;");
             }
                else if(number < -225 && number >= -250 && t[65*x+y-65] < 75 && t[65*x+y-65] >= 50){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 200, 75), stop: 0.8 rgb(255,50,0)); border:0px solid black;");
             }
                else if(number < -225 && number >= -250 && t[65*x+y-65] < 100 && t[65*x+y-65] >= 75){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 175, 100), stop: 0.8 rgb(255,50,0)); border:0px solid black;");
             }
                else if(number < -225 && number >= -250 && t[65*x+y-65] < 125 && t[65*x+y-65] >= 100){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 150, 125), stop: 0.8 rgb(255,50,0)); border:0px solid black;");
             }
                else if(number < -225 && number >= -250 && t[65*x+y-65] < 150 && t[65*x+y-65] >= 125){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 125, 150), stop: 0.8 rgb(255,50,0)); border:0px solid black;");
             }
                else if(number < -225 && number >= -250 && t[65*x+y-65] < 175 && t[65*x+y-65] >= 150){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 100, 175), stop: 0.8 rgb(255,50,0)); border:0px solid black;");
             }
                else if(number < -225 && number >= -250 && t[65*x+y-65] < 200 && t[65*x+y-65] >= 175){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 75, 200), stop: 0.8 rgb(255,50,0)); border:0px solid black;");
             }
                else if(number < -225 && number >= -250 && t[65*x+y-65] < 225 && t[65*x+y-65] >= 200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 50, 225), stop: 0.8 rgb(255,50,0)); border:0px solid black;");
             }
                else if(number < -225 && number >= -250 && t[65*x+y-65] < 250 && t[65*x+y-65] >= 225){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 50, 255), stop: 0.8 rgb(255,50,0)); border:0px solid black;");
             }
                else if(number < -225 && number >= -250 && t[65*x+y-65] >= 250){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 0, 255), stop: 0.8 rgb(255,50,0)); border:0px solid black;");
             }

             //<-200 && >=-225
                else if(number < -200 && number >= -225 && t[65*x+y-65] < -250){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255, 0, 0), stop: 0.8 rgb(225,50,0)); border:0px solid black;");
            }
                else if(number < -200 && number >= -225 && t[65*x+y-65] < -225 && t[65*x+y-65] >= -250){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255, 50, 0), stop: 0.8 rgb(225,50,0)); border:0px solid black;");
             }
                else if(number < -200 && number >= -225 && t[65*x+y-65] < -200 && t[65*x+y-65] >= -225){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(225, 50, 0), stop: 0.8 rgb(225,50,0)); border:0px solid black;");
             }
                else if(number < -200 && number >= -225 && t[65*x+y-65] < -175 && t[65*x+y-65] >= -200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200, 50, 0), stop: 0.8 rgb(225,50,0)); border:0px solid black;");
             }
                else if(number < -200 && number >= -225 && t[65*x+y-65] < -150 && t[65*x+y-65] >= -175){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200, 75, 0), stop: 0.8 rgb(225,50,0)); border:0px solid black;");
             }
                else if(number < -200 && number >= -225 && t[65*x+y-65] < -125 && t[65*x+y-65] >= -150){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(175, 100, 0), stop: 0.8 rgb(225,50,0)); border:0px solid black;");
             }
                else if(number < -200 && number >= -225 && t[65*x+y-65] < -100 && t[65*x+y-65] >= -125){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(150, 125, 0), stop: 0.8 rgb(225,50,0)); border:0px solid black;");
             }
                else if(number < -200 && number >= -225 && t[65*x+y-65] < -75 && t[65*x+y-65] >= -100){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125, 150, 0), stop: 0.8 rgb(225,50,0)); border:0px solid black;");
             }
                else if(number < -200 && number >= -225 && t[65*x+y-65] < -50 && t[65*x+y-65] >= -75){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125, 175, 0), stop: 0.8 rgb(225,50,0)); border:0px solid black;");
             }
                else if(number < -200 && number >= -225 && t[65*x+y-65] < -25 && t[65*x+y-65] >= -50){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100, 200, 0), stop: 0.8 rgb(225,50,0)); border:0px solid black;");
             }
                else if(number < -200 && number >= -225 && t[65*x+y-65] < 0 && t[65*x+y-65] >= -25){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100, 255, 0), stop: 0.8 rgb(225,50,0)); border:0px solid black;");
             }
                else if(number < -200 && number >= -225 && t[65*x+y-65] < 25 && t[65*x+y-65] >= 0){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 255, 50), stop: 0.8 rgb(225,50,0)); border:0px solid black;");
             }
                else if(number < -200 && number >= -225 && t[65*x+y-65] < 50 && t[65*x+y-65] >= 25){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 225, 50), stop: 0.8 rgb(225,50,0)); border:0px solid black;");
             }
                else if(number < -200 && number >= -225 && t[65*x+y-65] < 75 && t[65*x+y-65] >= 50){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 200, 75), stop: 0.8 rgb(225,50,0)); border:0px solid black;");
             }
                else if(number < -200 && number >= -225 && t[65*x+y-65] < 100 && t[65*x+y-65] >= 75){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 175, 100), stop: 0.8 rgb(225,50,0)); border:0px solid black;");
             }
                else if(number < -200 && number >= -225 && t[65*x+y-65] < 125 && t[65*x+y-65] >= 100){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 150, 125), stop: 0.8 rgb(225,50,0)); border:0px solid black;");
             }
                else if(number < -200 && number >= -225 && t[65*x+y-65] < 150 && t[65*x+y-65] >= 125){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 125, 150), stop: 0.8 rgb(225,50,0)); border:0px solid black;");
             }
                else if(number < -200 && number >= -225 && t[65*x+y-65] < 175 && t[65*x+y-65] >= 150){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 100, 175), stop: 0.8 rgb(225,50,0)); border:0px solid black;");
             }
                else if(number < -200 && number >= -225 && t[65*x+y-65] < 200 && t[65*x+y-65] >= 175){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 75, 200), stop: 0.8 rgb(225,50,0)); border:0px solid black;");
             }
                else if(number < -200 && number >= -225 && t[65*x+y-65] < 225 && t[65*x+y-65] >= 200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 50, 225), stop: 0.8 rgb(225,50,0)); border:0px solid black;");
             }
                else if(number < -200 && number >= -225 && t[65*x+y-65] < 250 && t[65*x+y-65] >= 225){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 50, 255), stop: 0.8 rgb(225,50,0)); border:0px solid black;");
             }
                else if(number < -200 && number >= -225 && t[65*x+y-65] >= 250){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 0, 255), stop: 0.8 rgb(225,50,0)); border:0px solid black;");
             }


                //<-175 && >= -200
                else if(number < -175 && number >= -200 && t[65*x+y-65] < -250){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255, 0, 0), stop: 0.8 rgb(200,50,0)); border:0px solid black;");
            }
                else if(number < -175 && number >= -200 && t[65*x+y-65] < -225 && t[65*x+y-65] >= -250){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255, 50, 0), stop: 0.8 rgb(200,50,0)); border:0px solid black;");
             }
                else if(number < -175 && number >= -200 && t[65*x+y-65] < -200 && t[65*x+y-65] >= -225){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(225,50,0), stop: 0.8 rgb(200,50,0)); border:0px solid black;");
             }
                else if(number < -175 && number >= -200 && t[65*x+y-65] < -175 && t[65*x+y-65] >= -200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,50,0), stop: 0.8 rgb(200,50,0)); border:0px solid black;");
             }
                else if(number < -175 && number >= -200 && t[65*x+y-65] < -150 && t[65*x+y-65] >= -175){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,75,0), stop: 0.8 rgb(200,50,0)); border:0px solid black;");
             }
                else if(number < -175 && number >= -200 && t[65*x+y-65] < -125 && t[65*x+y-65] >= -150){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(175,100,0), stop: 0.8 rgb(200,50,0)); border:0px solid black;");
             }
                else if(number < -175 && number >= -200 && t[65*x+y-65] < -100 && t[65*x+y-65] >= -125){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(150,125,0), stop: 0.8 rgb(200,50,0)); border:0px solid black;");
             }
                else if(number < -175 && number >= -200 && t[65*x+y-65] < -75 && t[65*x+y-65] >= -100){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,150,0), stop: 0.8 rgb(200,50,0)); border:0px solid black;");
             }
                else if(number < -175 && number >= -200 && t[65*x+y-65] < -50 && t[65*x+y-65] >= -75){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,175,0), stop: 0.8 rgb(200,50,0)); border:0px solid black;");
             }
                else if(number < -175 && number >= -200 && t[65*x+y-65] < -25 && t[65*x+y-65] >= -50){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,200,0), stop: 0.8 rgb(200,50,0)); border:0px solid black;");
             }
                else if(number < -175 && number >= -200 && t[65*x+y-65] < 0 && t[65*x+y-65] >= -25){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,255,50), stop: 0.8 rgb(200,50,0)); border:0px solid black;");
             }
                else if(number < -175 && number >= -200 && t[65*x+y-65] < 25 && t[65*x+y-65] >= 0){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,255,50), stop: 0.8 rgb(200,50,0)); border:0px solid black;");
             }
                else if(number < -175 && number >= -200 && t[65*x+y-65] < 50 && t[65*x+y-65] >= 25){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,225,50), stop: 0.8 rgb(200,50,0)); border:0px solid black;");
             }
                else if(number < -175 && number >= -200 && t[65*x+y-65] < 75 && t[65*x+y-65] >= 50){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,200,75), stop: 0.8 rgb(200,50,0)); border:0px solid black;");
             }
                else if(number < -175 && number >= -200 && t[65*x+y-65] < 100 && t[65*x+y-65] >= 75){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,175,100), stop: 0.8 rgb(200,50,0)); border:0px solid black;");
             }
                else if(number < -175 && number >= -200 && t[65*x+y-65] < 125 && t[65*x+y-65] >= 100){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,150,125), stop: 0.8 rgb(200,50,0)); border:0px solid black;");
             }
                else if(number < -175 && number >= -200 && t[65*x+y-65] < 150 && t[65*x+y-65] >= 125){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,125,150), stop: 0.8 rgb(200,50,0)); border:0px solid black;");
             }
                else if(number < -175 && number >= -200 && t[65*x+y-65] < 175 && t[65*x+y-65] >= 150){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,100,175), stop: 0.8 rgb(200,50,0)); border:0px solid black;");
             }
                else if(number < -175 && number >= -200 && t[65*x+y-65] < 200 && t[65*x+y-65] >= 175){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,75,200), stop: 0.8 rgb(200,50,0)); border:0px solid black;");
             }
                else if(number < -175 && number >= -200 && t[65*x+y-65] < 225 && t[65*x+y-65] >= 200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,225), stop: 0.8 rgb(200,50,0)); border:0px solid black;");
             }
                else if(number < -175 && number >= -200 && t[65*x+y-65] < 250 && t[65*x+y-65] >= 225){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,255), stop: 0.8 rgb(200,50,0)); border:0px solid black;");
             }
                else if(number < -175 && number >= -200 && t[65*x+y-65] >= 250){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 0, 255), stop: 0.8 rgb(200,50,0)); border:0px solid black;");
             }



             //<-150 && >=-175
                else if(number < -150 && number >= -175 && t[65*x+y-65] < -250){
                 btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255, 0, 0), stop: 0.8 rgb(200,75,0)); border:0px solid black;");
            }
                else if(number < -150 && number >= -175 && t[65*x+y-65] < -225 && t[65*x+y-65] >= -250){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255, 50, 0), stop: 0.8 rgb(200,75,0)); border:0px solid black;");
             }
                else if(number < -150 && number >= -175 && t[65*x+y-65] < -200 && t[65*x+y-65] >= -225){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(225, 50, 0), stop: 0.8 rgb(200,75,0)); border:0px solid black;");
             }
                else if(number < -150 && number >= -175 && t[65*x+y-65] < -175 && t[65*x+y-65] >= -200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200, 50, 0), stop: 0.8 rgb(200,75,0)); border:0px solid black;");
             }
                else if(number < -150 && number >= -175 && t[65*x+y-65] < -150 && t[65*x+y-65] >= -175){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200, 75, 0), stop: 0.8 rgb(200,75,0)); border:0px solid black;");
             }
                else if(number < -150 && number >= -175 && t[65*x+y-65] < -125 && t[65*x+y-65] >= -150){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(175, 100, 0), stop: 0.8 rgb(200,75,0)); border:0px solid black;");
             }
                else if(number < -150 && number >= -175 && t[65*x+y-65] < -100 && t[65*x+y-65] >= -125){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(150, 125, 0), stop: 0.8 rgb(200,75,0)); border:0px solid black;");
             }
                else if(number < -150 && number >= -175 && t[65*x+y-65] < -75 && t[65*x+y-65] >= -100){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125, 150, 0), stop: 0.8 rgb(200,75,0)); border:0px solid black;");
             }
                else if(number < -150 && number >= -175 && t[65*x+y-65] < -50 && t[65*x+y-65] >= -75){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125, 175, 0), stop: 0.8 rgb(200,75,0)); border:0px solid black;");
             }
                else if(number < -150 && number >= -175 && t[65*x+y-65] < -25 && t[65*x+y-65] >= -50){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,200,0), stop: 0.8 rgb(200,75,0)); border:0px solid black;");
             }
                else if(number < -150 && number >= -175 && t[65*x+y-65] < 0 && t[65*x+y-65] >= -25){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,255,0), stop: 0.8 rgb(200,75,0)); border:0px solid black;");
             }
                else if(number < -150 && number >= -175 && t[65*x+y-65] < 25 && t[65*x+y-65] >= 0){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,255,50), stop: 0.8 rgb(200,75,0)); border:0px solid black;");
             }
                else if(number < -150 && number >= -175 && t[65*x+y-65] < 50 && t[65*x+y-65] >= 25){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,225,50), stop: 0.8 rgb(200,75,0)); border:0px solid black;");
             }
                else if(number < -150 && number >= -175 && t[65*x+y-65] < 75 && t[65*x+y-65] >= 50){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,200,75), stop: 0.8 rgb(200,75,0)); border:0px solid black;");
             }
             else if(number < -150 && number >= -175 && t[65*x+y-65] < 100 && t[65*x+y-65] >= 75){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,175,100), stop: 0.8 rgb(200,75,0)); border:0px solid black;");
             }
                else if(number < -150 && number >= -175 && t[65*x+y-65] < 125 && t[65*x+y-65] >= 100){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,150,125), stop: 0.8 rgb(200,75,0)); border:0px solid black;");
             }
                else if(number < -150 && number >= -175 && t[65*x+y-65] < 150 && t[65*x+y-65] >= 125){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,125,150), stop: 0.8 rgb(200,75,0)); border:0px solid black;");
             }
                else if(number < -150 && number >= -175 && t[65*x+y-65] < 175 && t[65*x+y-65] >= 150){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,100,175), stop: 0.8 rgb(200,75,0)); border:0px solid black;");
             }
                else if(number < -150 && number >= -175 && t[65*x+y-65] < 200 && t[65*x+y-65] >= 175){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,75,200), stop: 0.8 rgb(200,75,0)); border:0px solid black;");
             }
                else if(number < -150 && number >= -175 && t[65*x+y-65] < 225 && t[65*x+y-65] >= 200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,225), stop: 0.8 rgb(200,75,0)); border:0px solid black;");
             }
                else if(number < -150 && number >= -175 && t[65*x+y-65] < 250 && t[65*x+y-65] >= 225){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,255), stop: 0.8 rgb(200,75,0)); border:0px solid black;");
             }
              else if(number < -150 && number >= -175 && t[65*x+y-65] >= 250){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 0, 255), stop: 0.8 rgb(200,75,0)); border:0px solid black;");
             }


             //<-125 && >=-150
                else if(number < -125 && number >= -150 && t[65*x+y-65] < -250){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,0 0), stop: 0.8 rgb(175,100,0)); border:0px solid black;");
            }
                else if(number < -125 && number >= -150 && t[65*x+y-65] < -225 && t[65*x+y-65] >= -250){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,50, 0), stop: 0.8 rgb(175,100,0)); border:0px solid black;");
             }
                else if(number < -125 && number >= -150 && t[65*x+y-65] < -200 && t[65*x+y-65] >= -225){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(225,50, 0), stop: 0.8 rgb(175,100,0)); border:0px solid black;");
             }
                else if(number < -125 && number >= -150 && t[65*x+y-65] < -175 && t[65*x+y-65] >= -200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,50, 0), stop: 0.8 rgb(175,100,0)); border:0px solid black;");
             }
                else if(number < -125 && number >= -150 && t[65*x+y-65] < -150 && t[65*x+y-65] >= -175){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,75, 0), stop: 0.8 rgb(175,100,0)); border:0px solid black;");
             }
                else if(number < -125 && number >= -150 && t[65*x+y-65] < -125 && t[65*x+y-65] >= -150){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(175,100, 0), stop: 0.8 rgb(175,100,0)); border:0px solid black;");
             }
                else if(number < -125 && number >= -150 && t[65*x+y-65] < -100 && t[65*x+y-65] >= -125){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(150,125, 0), stop: 0.8 rgb(175,100,0)); border:0px solid black;");
             }
                else if(number < -125 && number >= -150 && t[65*x+y-65] < -75 && t[65*x+y-65] >= -100){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,150, 0), stop: 0.8 rgb(175,100,0)); border:0px solid black;");
             }
                else if(number < -125 && number >= -150 && t[65*x+y-65] < -50 && t[65*x+y-65] >= -75){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,175, 0), stop: 0.8 rgb(175,100,0)); border:0px solid black;");
             }
                else if(number < -125 && number >= -150 && t[65*x+y-65] < -25 && t[65*x+y-65] >= -50){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,200, 0), stop: 0.8 rgb(175,100,0)); border:0px solid black;");
             }
                else if(number < -125 && number >= -150 && t[65*x+y-65] < 0 && t[65*x+y-65] >= -25){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,255, 0), stop: 0.8 rgb(175,100,0)); border:0px solid black;");
             }
                else if(number < -125 && number >= -150 && t[65*x+y-65] < 25 && t[65*x+y-65] >= 0){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,255,50), stop: 0.8 rgb(175,100,0)); border:0px solid black;");
             }
                else if(number < -125 && number >= -150 && t[65*x+y-65] < 50 && t[65*x+y-65] >= 25){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,225,50), stop: 0.8 rgb(175,100,0)); border:0px solid black;");
             }
                else if(number < -125 && number >= -150 && t[65*x+y-65] < 75 && t[65*x+y-65] >= 50){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,200,75), stop: 0.8 rgb(175,100,0)); border:0px solid black;");
             }
             else if(number < -125 && number >= -150 && t[65*x+y-65] < 100 && t[65*x+y-65] >= 75){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,175,100), stop: 0.8 rgb(175,100,0)); border:0px solid black;");
             }
                else if(number < -125 && number >= -150 && t[65*x+y-65] < 125 && t[65*x+y-65] >= 100){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,150,125), stop: 0.8 rgb(175,100,0)); border:0px solid black;");
             }
                else if(number < -125 && number >= -150 && t[65*x+y-65] < 150 && t[65*x+y-65] >= 125){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,125,150), stop: 0.8 rgb(175,100,0)); border:0px solid black;");
             }
                else if(number < -125 && number >= -150 && t[65*x+y-65] < 175 && t[65*x+y-65] >= 150){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,100,175), stop: 0.8 rgb(175,100,0)); border:0px solid black;");
             }
                else if(number < -125 && number >= -150 && t[65*x+y-65] < 200 && t[65*x+y-65] >= 175){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,75,200), stop: 0.8 rgb(175,100,0)); border:0px solid black;");
             }
                else if(number < -125 && number >= -150 && t[65*x+y-65] < 225 && t[65*x+y-65] >= 200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,225), stop: 0.8 rgb(175,100,0)); border:0px solid black;");
             }
                else if(number < -125 && number >= -150 && t[65*x+y-65] < 250 && t[65*x+y-65] >= 225){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,255), stop: 0.8 rgb(175,100,0)); border:0px solid black;");
             }
              else if(number < -125 && number >= -150 && t[65*x+y-65] >= 250){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 0, 255), stop: 0.8 rgb(175,100,0)); border:0px solid black;");
             }


                //<-100 && >=-125
                else if(number < -100 && number >= -125 && t[65*x+y-65] < -250){
                 btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,0,0), stop: 0.8 rgb(150,125,0)); border:0px solid black;");
            }
                else if(number < -100 && number >= -125 && t[65*x+y-65] < -225 && t[65*x+y-65] >= -250){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,50,0), stop: 0.8 rgb(150,125,0)); border:0px solid black;");
             }
                else if(number < -100 && number >= -125 && t[65*x+y-65] < -200 && t[65*x+y-65] >= -225){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(225,50,0), stop: 0.8 rgb(150,125,0)); border:0px solid black;");
             }
                else if(number < -100 && number >= -125 && t[65*x+y-65] < -175 && t[65*x+y-65] >= -200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,50,0), stop: 0.8 rgb(150,125,0)); border:0px solid black;");
             }
                else if(number < -100 && number >= -125 && t[65*x+y-65] < -150 && t[65*x+y-65] >= -175){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,75,0), stop: 0.8 rgb(150,125,0)); border:0px solid black;");
             }
                else if(number < -100 && number >= -125 && t[65*x+y-65] < -125 && t[65*x+y-65] >= -150){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(175,100,0), stop: 0.8 rgb(150,125,0)); border:0px solid black;");
             }
                else if(number < -100 && number >= -125 && t[65*x+y-65] < -100 && t[65*x+y-65] >= -125){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(150,125,0), stop: 0.8 rgb(150,125,0)); border:0px solid black;");
             }
                else if(number < -100 && number >= -125 && t[65*x+y-65] < -75 && t[65*x+y-65] >= -100){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,150,0), stop: 0.8 rgb(150,125,0)); border:0px solid black;");
             }
                else if(number < -100 && number >= -125 && t[65*x+y-65] < -50 && t[65*x+y-65] >= -75){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,175,0), stop: 0.8 rgb(150,125,0)); border:0px solid black;");
             }
                else if(number < -100 && number >= -125 && t[65*x+y-65] < -25 && t[65*x+y-65] >= -50){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,200,0), stop: 0.8 rgb(150,125,0)); border:0px solid black;");
             }
                else if(number < -100 && number >= -125 && t[65*x+y-65] < 0 && t[65*x+y-65] >= -25){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,255,0), stop: 0.8 rgb(150,125,0)); border:0px solid black;");
             }
                else if(number < -100 && number >= -125 && t[65*x+y-65] < 25 && t[65*x+y-65] >= 0){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,255,50), stop: 0.8 rgb(150,125,0)); border:0px solid black;");
             }
                else if(number < -100 && number >= -125 && t[65*x+y-65] < 50 && t[65*x+y-65] >= 25){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,225,50), stop: 0.8 rgb(150,125,0)); border:0px solid black;");
             }
                else if(number < -100 && number >= -125 && t[65*x+y-65] < 75 && t[65*x+y-65] >= 50){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,200,75), stop: 0.8 rgb(150,125,0)); border:0px solid black;");
             }
             else if(number < -100 && number >= -125 && t[65*x+y-65] < 100 && t[65*x+y-65] >= 75){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,175,100), stop: 0.8 rgb(150,125,0)); border:0px solid black;");
             }
                else if(number < -100 && number >= -125 && t[65*x+y-65] < 125 && t[65*x+y-65] >= 100){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,150,125), stop: 0.8 rgb(150,125,0)); border:0px solid black;");
             }
                else if(number < -100 && number >= -125 && t[65*x+y-65] < 150 && t[65*x+y-65] >= 125){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,125,150), stop: 0.8 rgb(150,125,0)); border:0px solid black;");
             }
                else if(number < -100 && number >= -125 && t[65*x+y-65] < 175 && t[65*x+y-65] >= 150){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,100,175), stop: 0.8 rgb(150,125,0)); border:0px solid black;");
             }
                else if(number < -100 && number >= -125 && t[65*x+y-65] < 200 && t[65*x+y-65] >= 175){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,75,200), stop: 0.8 rgb(150,125,0)); border:0px solid black;");
             }
                else if(number < -100 && number >= -125 && t[65*x+y-65] < 225 && t[65*x+y-65] >= 200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,225), stop: 0.8 rgb(150,125,0)); border:0px solid black;");
             }
                else if(number < -100 && number >= -125 && t[65*x+y-65] < 250 && t[65*x+y-65] >= 225){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,255), stop: 0.8 rgb(150,125,0)); border:0px solid black;");
             }
              else if(number < -100 && number >= -125 && t[65*x+y-65] >= 250){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 0, 255), stop: 0.8 rgb(150,125,0)); border:0px solid black;");
             }

                //<-75 && >=-100
                else if(number < -75 && number >= -100 && t[65*x+y-65] < -250){
                 btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,0,0), stop: 0.8 rgb(125,150,0)); border:0px solid black;");
            }
                else if(number < -75 && number >= -100 && t[65*x+y-65] < -225 && t[65*x+y-65] >= -250){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,50,0), stop: 0.8 rgb(125,150,0)); border:0px solid black;");
             }
                else if(number < -75 && number >= -100 && t[65*x+y-65] < -200 && t[65*x+y-65] >= -225){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(225,50,0), stop: 0.8 rgb(125,150,0)); border:0px solid black;");
             }
                else if(number < -75 && number >= -100 && t[65*x+y-65] < -175 && t[65*x+y-65] >= -200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,50,0), stop: 0.8 rgb(125,150,0)); border:0px solid black;");
             }
                else if(number < -75 && number >= -100 && t[65*x+y-65] < -150 && t[65*x+y-65] >= -175){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,75,0), stop: 0.8 rgb(125,150,0)); border:0px solid black;");
             }
                else if(number < -75 && number >= -100 && t[65*x+y-65] < -125 && t[65*x+y-65] >= -150){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(175,100,0), stop: 0.8 rgb(125,150,0)); border:0px solid black;");
             }
                else if(number < -75 && number >= -100 && t[65*x+y-65] < -100 && t[65*x+y-65] >= -125){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(150,125,0), stop: 0.8 rgb(125,150,0)); border:0px solid black;");
             }
                else if(number < -75 && number >= -100 && t[65*x+y-65] < -75 && t[65*x+y-65] >= -100){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,150,0), stop: 0.8 rgb(125,150,0)); border:0px solid black;");
             }
                else if(number < -75 && number >= -100 && t[65*x+y-65] < -50 && t[65*x+y-65] >= -75){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,175,0), stop: 0.8 rgb(125,150,0)); border:0px solid black;");
             }
                else if(number < -75 && number >= -100 && t[65*x+y-65] < -25 && t[65*x+y-65] >= -50){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,200,0), stop: 0.8 rgb(125,150,0)); border:0px solid black;");
             }
                else if(number < -75 && number >= -100 && t[65*x+y-65] < 0 && t[65*x+y-65] >= -25){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,255,0), stop: 0.8 rgb(125,150,0)); border:0px solid black;");
             }
                else if(number < -75 && number >= -100 && t[65*x+y-65] < 25 && t[65*x+y-65] >= 0){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,255,50), stop: 0.8 rgb(125,150,0)); border:0px solid black;");
             }
                else if(number < -75 && number >= -100 && t[65*x+y-65] < 50 && t[65*x+y-65] >= 25){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,225,50), stop: 0.8 rgb(125,150,0)); border:0px solid black;");
             }
                else if(number < -75 && number >= -100 && t[65*x+y-65] < 75 && t[65*x+y-65] >= 50){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,200,75), stop: 0.8 rgb(125,150,0)); border:0px solid black;");
             }
             else if(number < -75 && number >= -100 && t[65*x+y-65] < 100 && t[65*x+y-65] >= 75){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,175,100), stop: 0.8 rgb(125,150,0)); border:0px solid black;");
             }
                else if(number < -75 && number >= -100 && t[65*x+y-65] < 125 && t[65*x+y-65] >= 100){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,150,125), stop: 0.8 rgb(125,150,0)); border:0px solid black;");
             }
                else if(number < -75 && number >= -100 && t[65*x+y-65] < 150 && t[65*x+y-65] >= 125){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,125,150), stop: 0.8 rgb(125,150,0)); border:0px solid black;");
             }
                else if(number < -75 && number >= -100 && t[65*x+y-65] < 175 && t[65*x+y-65] >= 150){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,100,175), stop: 0.8 rgb(125,150,0)); border:0px solid black;");
             }
                else if(number < -75 && number >= -100 && t[65*x+y-65] < 200 && t[65*x+y-65] >= 175){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,75,200), stop: 0.8 rgb(125,150,0)); border:0px solid black;");
             }
                else if(number < -75 && number >= -100 && t[65*x+y-65] < 225 && t[65*x+y-65] >= 200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,225), stop: 0.8 rgb(125,150,0)); border:0px solid black;");
             }
                else if(number < -75 && number >= -100 && t[65*x+y-65] < 250 && t[65*x+y-65] >= 225){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,255), stop: 0.8 rgb(125,150,0)); border:0px solid black;");
             }
              else if(number < -75 && number >= -100 && t[65*x+y-65] >= 250){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 0, 255), stop: 0.8 rgb(125,150,0)); border:0px solid black;");
             }


             //<-50 &&>=-75
              else  if(number < -50 && number >= -75 && t[65*x+y-65] < -250){
                 btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,0,0), stop: 0.8 rgb(125,175,0)); border:0px solid black;");
            }
                else if(number < -50 && number >= -75 && t[65*x+y-65] < -225 && t[65*x+y-65] >= -250){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,50,0), stop: 0.8 rgb(125,175,0)); border:0px solid black;");
             }
                else if(number < -50 && number >= -75 && t[65*x+y-65] < -200 && t[65*x+y-65] >= -225){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(225,50,0), stop: 0.8 rgb(125,175,0)); border:0px solid black;");
             }
                else if(number < -50 && number >= -75 && t[65*x+y-65] < -175 && t[65*x+y-65] >= -200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,50,0), stop: 0.8 rgb(125,175,0)); border:0px solid black;");
             }
                else if(number < -50 && number >= -75 && t[65*x+y-65] < -150 && t[65*x+y-65] >= -175){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,75,0), stop: 0.8 rgb(125,175,0)); border:0px solid black;");
             }
                else if(number < -50 && number >= -75 && t[65*x+y-65] < -125 && t[65*x+y-65] >= -150){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(175,100,0), stop: 0.8 rgb(125,175,0)); border:0px solid black;");
             }
                else if(number < -50 && number >= -75 && t[65*x+y-65] < -100 && t[65*x+y-65] >= -125){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(150,125,0), stop: 0.8 rgb(125,175,0)); border:0px solid black;");
             }
                else if(number < -50 && number >= -75 && t[65*x+y-65] < -75 && t[65*x+y-65] >= -100){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,150,0), stop: 0.8 rgb(125,175,0)); border:0px solid black;");
             }
                else if(number < -50 && number >= -75 && t[65*x+y-65] < -50 && t[65*x+y-65] >= -75){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,175,0), stop: 0.8 rgb(125,175,0)); border:0px solid black;");
             }
                else if(number < -50 && number >= -75 && t[65*x+y-65] < -25 && t[65*x+y-65] >= -50){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,200,0), stop: 0.8 rgb(125,175,0)); border:0px solid black;");
             }
                else if(number < -50 && number >= -75 && t[65*x+y-65] < 0 && t[65*x+y-65] >= -25){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,255,0), stop: 0.8 rgb(125,175,0)); border:0px solid black;");
             }
                else if(number < -50 && number >= -75 && t[65*x+y-65] < 25 && t[65*x+y-65] >= 0){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,255,50), stop: 0.8 rgb(125,175,0)); border:0px solid black;");
             }
                else if(number < -50 && number >= -75 && t[65*x+y-65] < 50 && t[65*x+y-65] >= 25){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,225,50), stop: 0.8 rgb(125,175,0)); border:0px solid black;");
             }
                else if(number < -50 && number >= -75 && t[65*x+y-65] < 75 && t[65*x+y-65] >= 50){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,200,75), stop: 0.8 rgb(125,175,0)); border:0px solid black;");
             }
             else if(number < -50 && number >= -75 && t[65*x+y-65] < 100 && t[65*x+y-65] >= 75){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,175,100), stop: 0.8 rgb(125,175,0)); border:0px solid black;");
             }
                else if(number < -50 && number >= -75 && t[65*x+y-65] < 125 && t[65*x+y-65] >= 100){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,150,125), stop: 0.8 rgb(125,175,0)); border:0px solid black;");
             }
                else if(number < -50 && number >= -75 && t[65*x+y-65] < 150 && t[65*x+y-65] >= 125){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,125,150), stop: 0.8 rgb(125,175,0)); border:0px solid black;");
             }
                else if(number < -50 && number >= -75 && t[65*x+y-65] < 175 && t[65*x+y-65] >= 150){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,100,175), stop: 0.8 rgb(125,175,0)); border:0px solid black;");
             }
                else if(number < -50 && number >= -75 && t[65*x+y-65] < 200 && t[65*x+y-65] >= 175){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,75,200), stop: 0.8 rgb(125,175,0)); border:0px solid black;");
             }
                else if(number < -50 && number >= -75 && t[65*x+y-65] < 225 && t[65*x+y-65] >= 200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,225), stop: 0.8 rgb(125,175,0)); border:0px solid black;");
             }
                else if(number < -50 && number >= -75 && t[65*x+y-65] < 250 && t[65*x+y-65] >= 225){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 50, 255), stop: 0.8 rgb(125,175,0)); border:0px solid black;");
             }
              else if(number < -50 && number >= -75 && t[65*x+y-65] >= 250){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 0, 255), stop: 0.8 rgb(125,175,0)); border:0px solid black;");
             }


                 //<-25 && >=-50
                 else  if(number < -25 && number >= -50 && t[65*x+y-65] < -250){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,0,0), stop: 0.8 rgb(100,200,0)); border:0px solid black;");
               }
                   else if(number < -25 && number >= -50 && t[65*x+y-65] < -225 && t[65*x+y-65] >= -250){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,50,0), stop: 0.8 rgb(100,200,0)); border:0px solid black;");
                }
                   else if(number < -25 && number >= -50 && t[65*x+y-65] < -200 && t[65*x+y-65] >= -225){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(225,50,0), stop: 0.8 rgb(100,200,0)); border:0px solid black;");
                }
                   else if(number < -25 && number >= -50 && t[65*x+y-65] < -175 && t[65*x+y-65] >= -200){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,50,0), stop: 0.8 rgb(100,200,0)); border:0px solid black;");
                }
                   else if(number < -25 && number >= -50 && t[65*x+y-65] < -150 && t[65*x+y-65] >= -175){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,75,0), stop: 0.8 rgb(100,200,0)); border:0px solid black;");
                }
                   else if(number < -25 && number >= -50 && t[65*x+y-65] < -125 && t[65*x+y-65] >= -150){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(175,100,0), stop: 0.8 rgb(100,200,0)); border:0px solid black;");
                }
                   else if(number < -25 && number >= -50 && t[65*x+y-65] < -100 && t[65*x+y-65] >= -125){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(150,125,0), stop: 0.8 rgb(100,200,0)); border:0px solid black;");
                }
                   else if(number < -25 && number >= -50 && t[65*x+y-65] < -75 && t[65*x+y-65] >= -100){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,150,0), stop: 0.8 rgb(100,200,0)); border:0px solid black;");
                }
                   else if(number < -25 && number >= -50 && t[65*x+y-65] < -50 && t[65*x+y-65] >= -75){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,175,0), stop: 0.8 rgb(100,200,0)); border:0px solid black;");
                }
                   else if(number < -25 && number >= -50 && t[65*x+y-65] < -25 && t[65*x+y-65] >= -50){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,200,0), stop: 0.8 rgb(100,200,0)); border:0px solid black;");
                }
                   else if(number < -25 && number >= -50 && t[65*x+y-65] < 0 && t[65*x+y-65] >= -25){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,255,0), stop: 0.8 rgb(100,200,0)); border:0px solid black;");
                }
                   else if(number < -25 && number >= -50 && t[65*x+y-65] < 25 && t[65*x+y-65] >= 0){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,255,50), stop: 0.8 rgb(100,200,0)); border:0px solid black;");
                }
                   else if(number < -25 && number >= -50 && t[65*x+y-65] < 50 && t[65*x+y-65] >= 25){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,225,50), stop: 0.8 rgb(100,200,0)); border:0px solid black;");
                }
                   else if(number < -25 && number >= -50 && t[65*x+y-65] < 75 && t[65*x+y-65] >= 50){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,200,75), stop: 0.8 rgb(100,200,0)); border:0px solid black;");
                }
                else if(number < -25 && number >= -50 && t[65*x+y-65] < 100 && t[65*x+y-65] >= 75){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,175,100), stop: 0.8 rgb(100,200,0)); border:0px solid black;");
                }
                   else if(number < -25 && number >= -50 && t[65*x+y-65] < 125 && t[65*x+y-65] >= 100){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,150,125), stop: 0.8 rgb(100,200,0)); border:0px solid black;");
                }
                   else if(number < -25 && number >= -50 && t[65*x+y-65] < 150 && t[65*x+y-65] >= 125){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,125,150), stop: 0.8 rgb(100,200,0)); border:0px solid black;");
                }
                   else if(number < -25 && number >= -50 && t[65*x+y-65] < 175 && t[65*x+y-65] >= 150){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,100,175), stop: 0.8 rgb(100,200,0)); border:0px solid black;");
                }
                   else if(number < -25 && number >= -50 && t[65*x+y-65] < 200 && t[65*x+y-65] >= 175){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,75,200), stop: 0.8 rgb(100,200,0)); border:0px solid black;");
                }
                   else if(number < -25 && number >= -50 && t[65*x+y-65] < 225 && t[65*x+y-65] >= 200){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,225), stop: 0.8 rgb(100,200,0)); border:0px solid black;");
                }
                   else if(number < -25 && number >= -50 && t[65*x+y-65] < 250 && t[65*x+y-65] >= 225){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,255), stop: 0.8 rgb(100,200,0)); border:0px solid black;");
                }
                 else if(number < -25 && number >= -50 && t[65*x+y-65] >= 250){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 0, 255), stop: 0.8 rgb(100,200,0)); border:0px solid black;");
                }




                 //<0 && >=-25

                 else  if(number < 0 && number >= -25 && t[65*x+y-65] < -250){
                    btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,0,0), stop: 0.8 rgb(100,255,0)); border:0px solid black;");
               }
                   else if(number < 0 && number >= -25 && t[65*x+y-65] < -225 && t[65*x+y-65] >= -250){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,50,0), stop: 0.8 rgb(100,255,0)); border:0px solid black;");
                }
                   else if(number < 0 && number >= -25 && t[65*x+y-65] < -200 && t[65*x+y-65] >= -225){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(225,50,0), stop: 0.8 rgb(100,255,0)); border:0px solid black;");
                }
                   else if(number < 0 && number >= -25 && t[65*x+y-65] < -175 && t[65*x+y-65] >= -200){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,50,0), stop: 0.8 rgb(100,255,0)); border:0px solid black;");
                }
                   else if(number < 0 && number >= -25 && t[65*x+y-65] < -150 && t[65*x+y-65] >= -175){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,75,0), stop: 0.8 rgb(100,255,0)); border:0px solid black;");
                }
                   else if(number < 0 && number >= -25 && t[65*x+y-65] < -125 && t[65*x+y-65] >= -150){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(175,100,0), stop: 0.8 rgb(100,255,0)); border:0px solid black;");
                }
                   else if(number < 0 && number >= -25 && t[65*x+y-65] < -100 && t[65*x+y-65] >= -125){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(150,125,0), stop: 0.8 rgb(100,255,0)); border:0px solid black;");
                }
                   else if(number < 0 && number >= -25 && t[65*x+y-65] < -75 && t[65*x+y-65] >= -100){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,150,0), stop: 0.8 rgb(100,255,0)); border:0px solid black;");
                }
                   else if(number < 0 && number >= -25 && t[65*x+y-65] < -50 && t[65*x+y-65] >= -75){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,175,0), stop: 0.8 rgb(100,255,0)); border:0px solid black;");
                }
                   else if(number < 0 && number >= -25 && t[65*x+y-65] < -25 && t[65*x+y-65] >= -50){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,200,0), stop: 0.8 rgb(100,255,0)); border:0px solid black;");
                }
                   else if(number < 0 && number >= -25 && t[65*x+y-65] < 0 && t[65*x+y-65] >= -25){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,255,0), stop: 0.8 rgb(100,255,0)); border:0px solid black;");
                }
                   else if(number < 0 && number >= -25 && t[65*x+y-65] < 25 && t[65*x+y-65] >= 0){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,255,50), stop: 0.8 rgb(100,255,0)); border:0px solid black;");
                }
                   else if(number < 0 && number >= -25 && t[65*x+y-65] < 50 && t[65*x+y-65] >= 25){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,225,50), stop: 0.8 rgb(100,255,0)); border:0px solid black;");
                }
                   else if(number < 0 && number >= -25 && t[65*x+y-65] < 75 && t[65*x+y-65] >= 50){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,200,75), stop: 0.8 rgb(100,255,0)); border:0px solid black;");
                }
                else if(number <0 && number >= -25 && t[65*x+y-65] < 100 && t[65*x+y-65] >= 75){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,175,100), stop: 0.8 rgb(100,255,0)); border:0px solid black;");
                }
                   else if(number < 0 && number >= -25 && t[65*x+y-65] < 125 && t[65*x+y-65] >= 100){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,150,125), stop: 0.8 rgb(100,255,0)); border:0px solid black;");
                }
                   else if(number < 0 && number >= -25 && t[65*x+y-65] < 150 && t[65*x+y-65] >= 125){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,125,150), stop: 0.8 rgb(100,255,0)); border:0px solid black;");
                }
                   else if(number < 0 && number >= -25 && t[65*x+y-65] < 175 && t[65*x+y-65] >= 150){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,100,175), stop: 0.8 rgb(100,255,0)); border:0px solid black;");
                }
                   else if(number < 0 && number >= -25 && t[65*x+y-65] < 200 && t[65*x+y-65] >= 175){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,75,200), stop: 0.8 rgb(100,255,0)); border:0px solid black;");
                }
                   else if(number < 0 && number >= -25 && t[65*x+y-65] < 225 && t[65*x+y-65] >= 200){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,225), stop: 0.8 rgb(100,255,0)); border:0px solid black;");
                }
                   else if(number < 0 && number >= -25 && t[65*x+y-65] < 250 && t[65*x+y-65] >= 225){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,255), stop: 0.8 rgb(100,255,0)); border:0px solid black;");
                }
                 else if(number < 0 && number >= -25 && t[65*x+y-65] >= 250){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 0, 255), stop: 0.8 rgb(100,255,0)); border:0px solid black;");
                }

                 //<25 && >=0
                 else  if(number < 25 && number >= 0 && t[65*x+y-65] < -250){
                    btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,0,0), stop: 0.8 rgb(0,255,50)); border:0px solid black;");
               }
                   else if(number < 25 && number >= 0 && t[65*x+y-65] < -225 && t[65*x+y-65] >= -250){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,50,0), stop: 0.8 rgb(0,255,50)); border:0px solid black;");
                }
                   else if(number < 25 && number >= 0 && t[65*x+y-65] < -200 && t[65*x+y-65] >= -225){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(225,50,0), stop: 0.8 rgb(0,255,50)); border:0px solid black;");
                }
                   else if(number < 25 && number >= 0 && t[65*x+y-65] < -175 && t[65*x+y-65] >= -200){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,50,0), stop: 0.8 rgb(0,255,50)); border:0px solid black;");
                }
                   else if(number < 25 && number >= 0 && t[65*x+y-65] < -150 && t[65*x+y-65] >= -175){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,75,0), stop: 0.8 rgb(0,255,50)); border:0px solid black;");
                }
                   else if(number < 25 && number >= 0 && t[65*x+y-65] < -125 && t[65*x+y-65] >= -150){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(175,100,0), stop: 0.8 rgb(0,255,50)); border:0px solid black;");
                }
                   else if(number < 25 && number >= 0 && t[65*x+y-65] < -100 && t[65*x+y-65] >= -125){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(150,125,0), stop: 0.8 rgb(0,255,50)); border:0px solid black;");
                }
                   else if(number < 25 && number >= 0 && t[65*x+y-65] < -75 && t[65*x+y-65] >= -100){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,150,0), stop: 0.8 rgb(0,255,50)); border:0px solid black;");
                }
                   else if(number < 25 && number >= 0 && t[65*x+y-65] < -50 && t[65*x+y-65] >= -75){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,175,0), stop: 0.8 rgb(0,255,50)); border:0px solid black;");
                }
                   else if(number < 25 && number >= 0 && t[65*x+y-65] < -25 && t[65*x+y-65] >= -50){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,200,0), stop: 0.8 rgb(0,255,50)); border:0px solid black;");
                }
                   else if(number < 25 && number >= 0 && t[65*x+y-65] < 0 && t[65*x+y-65] >= -25){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,255,0), stop: 0.8 rgb(0,255,50)); border:0px solid black;");
                }
                   else if(number < 25 && number >= 0 && t[65*x+y-65] < 25 && t[65*x+y-65] >= 0){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,255,50), stop: 0.8 rgb(0,255,50)); border:0px solid black;");
                }
                   else if(number < 25 && number >= 0 && t[65*x+y-65] < 50 && t[65*x+y-65] >= 25){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,225,50), stop: 0.8 rgb(0,255,50)); border:0px solid black;");
                }
                   else if(number < 25 && number >= 0 && t[65*x+y-65] < 75 && t[65*x+y-65] >= 50){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,200,75), stop: 0.8 rgb(0,255,50)); border:0px solid black;");
                }
                else if(number < 25 && number >= 0 && t[65*x+y-65] < 100 && t[65*x+y-65] >= 75){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,175,100), stop: 0.8 rgb(0,255,50)); border:0px solid black;");
                }
                   else if(number < 25 && number >= 0 && t[65*x+y-65] < 125 && t[65*x+y-65] >= 100){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,150,125), stop: 0.8 rgb(0,255,50)); border:0px solid black;");
                }
                   else if(number < 25 && number >= 0 && t[65*x+y-65] < 150 && t[65*x+y-65] >= 125){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,125,150), stop: 0.8 rgb(0,255,50)); border:0px solid black;");
                }
                   else if(number < 25 && number >= 0 && t[65*x+y-65] < 175 && t[65*x+y-65] >= 150){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,100,175), stop: 0.8 rgb(0,255,50)); border:0px solid black;");
                }
                   else if(number < 25 && number >= 0 && t[65*x+y-65] < 200 && t[65*x+y-65] >= 175){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,75,200), stop: 0.8 rgb(0,255,50)); border:0px solid black;");
                }
                   else if(number < 25 && number >= 0 && t[65*x+y-65] < 225 && t[65*x+y-65] >= 200){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,225), stop: 0.8 rgb(0,255,50)); border:0px solid black;");
                }
                   else if(number < 25 && number >= 0 && t[65*x+y-65] < 250 && t[65*x+y-65] >= 225){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,255), stop: 0.8 rgb(0,255,50)); border:0px solid black;");
                }
                 else if(number < 25 && number >= 0 && t[65*x+y-65] >= 250){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,0,255), stop: 0.8 rgb(0,255,50)); border:0px solid black;");
                }

                 //<50 && >=25
                 else  if(number < 50 && number >= 25 && t[65*x+y-65] < -250){
                    btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,0,0), stop: 0.8 rgb(0,225,50)); border:0px solid black;");
               }
                   else if(number < 50 && number >= 25 && t[65*x+y-65] < -225 && t[65*x+y-65] >= -250){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,50,0), stop: 0.8 rgb(0,225,50)); border:0px solid black;");
                }
                   else if(number < 50 && number >= 25 && t[65*x+y-65] < -200 && t[65*x+y-65] >= -225){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(225,50,0), stop: 0.8 rgb(0,225,50)); border:0px solid black;");
                }
                   else if(number < 50 && number >= 25 && t[65*x+y-65] < -175 && t[65*x+y-65] >= -200){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,50,0), stop: 0.8 rgb(0,225,50)); border:0px solid black;");
                }
                   else if(number < 50 && number >= 25 && t[65*x+y-65] < -150 && t[65*x+y-65] >= -175){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,75,0), stop: 0.8 rgb(0,225,50)); border:0px solid black;");
                }
                   else if(number < 50 && number >= 25 && t[65*x+y-65] < -125 && t[65*x+y-65] >= -150){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(175,100,0), stop: 0.8 rgb(0,225,50)); border:0px solid black;");
                }
                   else if(number < 50 && number >= 25 && t[65*x+y-65] < -100 && t[65*x+y-65] >= -125){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(150,125,0), stop: 0.8 rgb(0,225,50)); border:0px solid black;");
                }
                   else if(number < 50 && number >= 25 && t[65*x+y-65] < -75 && t[65*x+y-65] >= -100){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,150,0), stop: 0.8 rgb(0,225,50)); border:0px solid black;");
                }
                   else if(number < 50 && number >= 25 && t[65*x+y-65] < -50 && t[65*x+y-65] >= -75){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,175,0), stop: 0.8 rgb(0,225,50)); border:0px solid black;");
                }
                   else if(number < 50 && number >= 25 && t[65*x+y-65] < -25 && t[65*x+y-65] >= -50){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,200,0), stop: 0.8 rgb(0,225,50)); border:0px solid black;");
                }
                   else if(number < 50 && number >= 25 && t[65*x+y-65] < 0 && t[65*x+y-65] >= -25){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,255,0), stop: 0.8 rgb(0,225,50)); border:0px solid black;");
                }
                   else if(number < 50 && number >= 25 && t[65*x+y-65] < 25 && t[65*x+y-65] >= 0){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,255,50), stop: 0.8 rgb(0,225,50)); border:0px solid black;");
                }
                   else if(number < 50 && number >= 25 && t[65*x+y-65] < 50 && t[65*x+y-65] >= 25){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,225,50), stop: 0.8 rgb(0,225,50)); border:0px solid black;");
                }
                   else if(number < 50 && number >= 25 && t[65*x+y-65] < 75 && t[65*x+y-65] >= 50){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,200,75), stop: 0.8 rgb(0,225,50)); border:0px solid black;");
                }
                else if(number < 50 && number >= 25 && t[65*x+y-65] < 100 && t[65*x+y-65] >= 75){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,175,100), stop: 0.8 rgb(0,225,50)); border:0px solid black;");
                }
                   else if(number < 50 && number >= 25 && t[65*x+y-65] < 125 && t[65*x+y-65] >= 100){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,150,125), stop: 0.8 rgb(0,225,50)); border:0px solid black;");
                }
                   else if(number < 50 && number >= 25 && t[65*x+y-65] < 150 && t[65*x+y-65] >= 125){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,125,150), stop: 0.8 rgb(0,225,50)); border:0px solid black;");
                }
                   else if(number < 50 && number >= 25 && t[65*x+y-65] < 175 && t[65*x+y-65] >= 150){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,100,175), stop: 0.8 rgb(0,225,50)); border:0px solid black;");
                }
                   else if(number < 50 && number >= 25 && t[65*x+y-65] < 200 && t[65*x+y-65] >= 175){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,75,200), stop: 0.8 rgb(0,225,50)); border:0px solid black;");
                }
                   else if(number < 50 && number >= 25 && t[65*x+y-65] < 225 && t[65*x+y-65] >= 200){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,225), stop: 0.8 rgb(0,225,50)); border:0px solid black;");
                }
                   else if(number < 50 && number >= 25 && t[65*x+y-65] < 250 && t[65*x+y-65] >= 225){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 50, 255), stop: 0.8 rgb(0,225,50)); border:0px solid black;");
                }
                 else if(number < 50 && number >= 25 && t[65*x+y-65] >= 250){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 0, 255), stop: 0.8 rgb(0,225,50)); border:0px solid black;");
                }

                 //<75 && >= 50

                 else  if(number < 75 && number >= 50 && t[65*x+y-65] < -250){
                    btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,0,0), stop: 0.8 rgb(0,200,75)); border:0px solid black;");
               }
                   else if(number < 75 && number >= 50 && t[65*x+y-65] < -225 && t[65*x+y-65] >= -250){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,50,0), stop: 0.8 rgb(0,200,75)); border:0px solid black;");
                }
                   else if(number < 75 && number >= 50 && t[65*x+y-65] < -200 && t[65*x+y-65] >= -225){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(225,50,0), stop: 0.8 rgb(0,200,75)); border:0px solid black;");
                }
                   else if(number < 75 && number >= 50 && t[65*x+y-65] < -175 && t[65*x+y-65] >= -200){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,50,0), stop: 0.8 rgb(0,200,75)); border:0px solid black;");
                }
                   else if(number < 75 && number >= 50 && t[65*x+y-65] < -150 && t[65*x+y-65] >= -175){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,75,0), stop: 0.8 rgb(0,200,75)); border:0px solid black;");
                }
                   else if(number < 75 && number >= 50 && t[65*x+y-65] < -125 && t[65*x+y-65] >= -150){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(175,100,0), stop: 0.8 rgb(0,200,75)); border:0px solid black;");
                }
                   else if(number < 75 && number >= 50 && t[65*x+y-65] < -100 && t[65*x+y-65] >= -125){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(150,125,0), stop: 0.8 rgb(0,200,75)); border:0px solid black;");
                }
                   else if(number < 75 && number >= 50 && t[65*x+y-65] < -75 && t[65*x+y-65] >= -100){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,150,0), stop: 0.8 rgb(0,200,75)); border:0px solid black;");
                }
                   else if(number < 75 && number >= 50 && t[65*x+y-65] < -50 && t[65*x+y-65] >= -75){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,175,0), stop: 0.8 rgb(0,200,75)); border:0px solid black;");
                }
                   else if(number < 75 && number >= 50 && t[65*x+y-65] < -25 && t[65*x+y-65] >= -50){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,200,0), stop: 0.8 rgb(0,200,75)); border:0px solid black;");
                }
                   else if(number < 75 && number >= 50  && t[65*x+y-65] < 0 && t[65*x+y-65] >= -25){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,255,0), stop: 0.8 rgb(0,200,75)); border:0px solid black;");
                }
                   else if(number < 75 && number >= 50 && t[65*x+y-65] < 25 && t[65*x+y-65] >= 0){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,255,50), stop: 0.8 rgb(0,200,75)); border:0px solid black;");
                }
                   else if(number < 75 && number >= 50 && t[65*x+y-65] < 50 && t[65*x+y-65] >= 25){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,225,50), stop: 0.8 rgb(0,200,75)); border:0px solid black;");
                }
                   else if(number < 75 && number >= 50 && t[65*x+y-65] < 75 && t[65*x+y-65] >= 50){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,200,75), stop: 0.8 rgb(0,200,75)); border:0px solid black;");
                }
                else if(number < 75 && number >= 50 && t[65*x+y-65] < 100 && t[65*x+y-65] >= 75){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,175,100), stop: 0.8 rgb(0,200,75)); border:0px solid black;");
                }
                   else if(number < 75 && number >= 50 && t[65*x+y-65] < 125 && t[65*x+y-65] >= 100){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,150,125), stop: 0.8 rgb(0,200,75)); border:0px solid black;");
                }
                   else if(number < 75 && number >= 50 && t[65*x+y-65] < 150 && t[65*x+y-65] >= 125){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,125,150), stop: 0.8 rgb(0,200,75)); border:0px solid black;");
                }
                   else if(number < 75 && number >= 50 && t[65*x+y-65] < 175 && t[65*x+y-65] >= 150){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,100,175), stop: 0.8 rgb(0,200,75)); border:0px solid black;");
                }
                   else if(number < 75 && number >= 50 && t[65*x+y-65] < 200 && t[65*x+y-65] >= 175){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,75,200), stop: 0.8 rgb(0,200,75)); border:0px solid black;");
                }
                   else if(number < 75 && number >= 50 && t[65*x+y-65] < 225 && t[65*x+y-65] >= 200){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,225), stop: 0.8 rgb(0,200,75)); border:0px solid black;");
                }
                   else if(number < 75 && number >= 50 && t[65*x+y-65] < 250 && t[65*x+y-65] >= 225){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,255), stop: 0.8 rgb(0,200,75)); border:0px solid black;");
                }
                 else if(number < 75 && number >= 50 && t[65*x+y-65] >= 250){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 0, 255), stop: 0.8 rgb(0,200,75)); border:0px solid black;");
                }

                 //<100 && >=75
                 else  if(number < 100 && number >= 75 && t[65*x+y-65] < -250){
                    btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,0,0), stop: 0.8 rgb(0,175,100)); border:0px solid black;");
               }
                   else if(number < 100 && number >= 75 && t[65*x+y-65] < -225 && t[65*x+y-65] >= -250){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,50,0), stop: 0.8 rgb(0,175,100)); border:0px solid black;");
                }
                   else if(number < 100 && number >= 75 && t[65*x+y-65] < -200 && t[65*x+y-65] >= -225){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(225,50,0), stop: 0.8 rgb(0,175,100)); border:0px solid black;");
                }
                   else if(number < 100 && number >= 75 && t[65*x+y-65] < -175 && t[65*x+y-65] >= -200){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,50,0), stop: 0.8 rgb(0,175,100)); border:0px solid black;");
                }
                   else if(number < 100 && number >= 75 && t[65*x+y-65] < -150 && t[65*x+y-65] >= -175){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,75,0), stop: 0.8 rgb(0,175,100)); border:0px solid black;");
                }
                   else if(number < 100 && number >= 75 && t[65*x+y-65] < -125 && t[65*x+y-65] >= -150){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(175,100,0), stop: 0.8 rgb(0,175,100)); border:0px solid black;");
                }
                   else if(number < 100 && number >= 75 && t[65*x+y-65] < -100 && t[65*x+y-65] >= -125){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(150,125,0), stop: 0.8 rgb(0,175,100)); border:0px solid black;");
                }
                   else if(number < 100 && number >= 75 && t[65*x+y-65] < -75 && t[65*x+y-65] >= -100){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,150,0), stop: 0.8 rgb(0,175,100)); border:0px solid black;");
                }
                   else if(number < 100 && number >= 75 && t[65*x+y-65] < -50 && t[65*x+y-65] >= -75){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,175,0), stop: 0.8 rgb(0,175,100)); border:0px solid black;");
                }
                   else if(number < 100 && number >= 75 && t[65*x+y-65] < -25 && t[65*x+y-65] >= -50){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,200,0), stop: 0.8 rgb(0,175,100)); border:0px solid black;");
                }
                   else if(number < 100 && number >= 75 && t[65*x+y-65] < 0 && t[65*x+y-65] >= -25){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,255,0), stop: 0.8 rgb(0,175,100)); border:0px solid black;");
                }
                   else if(number < 100 && number >= 75 && t[65*x+y-65] < 25 && t[65*x+y-65] >= 0){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,255,50), stop: 0.8 rgb(0,175,100)); border:0px solid black;");
                }
                   else if(number < 100 && number >= 75 && t[65*x+y-65] < 50 && t[65*x+y-65] >= 25){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,225,50), stop: 0.8 rgb(0,175,100)); border:0px solid black;");
                }
                   else if(number < 100 && number >= 75 && t[65*x+y-65] < 75 && t[65*x+y-65] >= 50){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,200,75), stop: 0.8 rgb(0,175,100)); border:0px solid black;");
                }
                   else if(number < 100 && number >= 75 && t[65*x+y-65] < 100 && t[65*x+y-65] >= 75){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,175,100), stop: 0.8 rgb(0,175,100)); border:0px solid black;");
                }
                   else if(number < 100 && number >= 75 && t[65*x+y-65] < 125 && t[65*x+y-65] >= 100){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,150,125), stop: 0.8 rgb(0,175,100)); border:0px solid black;");
                }
                   else if(number < 100 && number >= 75 && t[65*x+y-65] < 150 && t[65*x+y-65] >= 125){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,125,150), stop: 0.8 rgb(0,175,100)); border:0px solid black;");
                }
                   else if(number < 100 && number >= 75 && t[65*x+y-65] < 175 && t[65*x+y-65] >= 150){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,100,175), stop: 0.8 rgb(0,175,100)); border:0px solid black;");
                }
                   else if(number < 100 && number >= 75 && t[65*x+y-65] < 200 && t[65*x+y-65] >= 175){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,75,200), stop: 0.8 rgb(0,175,100)); border:0px solid black;");
                }
                   else if(number < 100 && number >= 75 && t[65*x+y-65] < 225 && t[65*x+y-65] >= 200){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,225), stop: 0.8 rgb(0,175,100)); border:0px solid black;");
                }
                   else if(number < 100 && number >= 75 && t[65*x+y-65] < 250 && t[65*x+y-65] >= 225){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 50, 255), stop: 0.8 rgb(0,175,100)); border:0px solid black;");
                }
                   else if(number < 100 && number >= 75 && t[65*x+y-65] >= 250){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 0, 255), stop: 0.8 rgb(0,175,100)); border:0px solid black;");
                }

                 //<125 && >=100
                 else  if(number < 125 && number >= 100 && t[65*x+y-65] < -250){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,0,0), stop: 0.8 rgb(0,150,125)); border:0px solid black;");
               }
                   else if(number < 125 && number >= 100 && t[65*x+y-65] < -225 && t[65*x+y-65] >= -250){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,50,0), stop: 0.8 rgb(0,150,125)); border:0px solid black;");
                }
                   else if(number < 125 && number >= 100 && t[65*x+y-65] < -200 && t[65*x+y-65] >= -225){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(225,50,0), stop: 0.8 rgb(0,150,125)); border:0px solid black;");
                }
                   else if(number < 125 && number >= 100 && t[65*x+y-65] < -175 && t[65*x+y-65] >= -200){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,50,0), stop: 0.8 rgb(0,150,125)); border:0px solid black;");
                }
                   else if(number < 125 && number >= 100 && t[65*x+y-65] < -150 && t[65*x+y-65] >= -175){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,75,0), stop: 0.8 rgb(0,150,125)); border:0px solid black;");
                }
                   else if(number < 125 && number >= 100 && t[65*x+y-65] < -125 && t[65*x+y-65] >= -150){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(175,100,0), stop: 0.8 rgb(0,150,125)); border:0px solid black;");
                }
                   else if(number < 125 && number >= 100 && t[65*x+y-65] < -100 && t[65*x+y-65] >= -125){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(150,125,0), stop: 0.8 rgb(0,150,125)); border:0px solid black;");
                }
                   else if(number < 125 && number >= 100 && t[65*x+y-65] < -75 && t[65*x+y-65] >= -100){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,150,0), stop: 0.8 rgb(0,150,125)); border:0px solid black;");
                }
                   else if(number < 125 && number >= 100 && t[65*x+y-65] < -50 && t[65*x+y-65] >= -75){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,175,0), stop: 0.8 rgb(0,150,125)); border:0px solid black;");
                }
                   else if(number < 125 && number >= 100 && t[65*x+y-65] < -25 && t[65*x+y-65] >= -50){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,225,0), stop: 0.8 rgb(0,150,125)); border:0px solid black;");
                }
                   else if(number < 125 && number >= 100 && t[65*x+y-65] < 0 && t[65*x+y-65] >= -25){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,255,0), stop: 0.8 rgb(0,150,125)); border:0px solid black;");
                }
                   else if(number < 125 && number >= 100 && t[65*x+y-65] < 25 && t[65*x+y-65] >= 0){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,255,50), stop: 0.8 rgb(0,150,125)); border:0px solid black;");
                }
                   else if(number < 125 && number >= 100 && t[65*x+y-65] < 50 && t[65*x+y-65] >= 25){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,225,50), stop: 0.8 rgb(0,150,125)); border:0px solid black;");
                }
                   else if(number < 125 && number >= 100 && t[65*x+y-65] < 75 && t[65*x+y-65] >= 50){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,200,175), stop: 0.8 rgb(0,150,125)); border:0px solid black;");
                }
                   else if(number < 125 && number >= 100 && t[65*x+y-65] < 100 && t[65*x+y-65] >= 75){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,175,150), stop: 0.8 rgb(0,150,125)); border:0px solid black;");
                }
                   else if(number < 125 && number >= 100 && t[65*x+y-65] < 125 && t[65*x+y-65] >= 100){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,150,125), stop: 0.8 rgb(0,150,125)); border:0px solid black;");
                }
                   else if(number < 125 && number >= 100 && t[65*x+y-65] < 150 && t[65*x+y-65] >= 125){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,125,150), stop: 0.8 rgb(0,150,125)); border:0px solid black;");
                }
                   else if(number < 125 && number >= 100 && t[65*x+y-65] < 175 && t[65*x+y-65] >= 150){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,100,175), stop: 0.8 rgb(0,150,125)); border:0px solid black;");
                }
                   else if(number < 125 && number >= 100 && t[65*x+y-65] < 200 && t[65*x+y-65] >= 175){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,75,200), stop: 0.8 rgb(0,150,125)); border:0px solid black;");
                }
                   else if(number < 125 && number >= 100 && t[65*x+y-65] < 225 && t[65*x+y-65] >= 200){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,225), stop: 0.8 rgb(0,150,125)); border:0px solid black;");
                }
                   else if(number < 125 && number >= 100 && t[65*x+y-65] < 250 && t[65*x+y-65] >= 225){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 50, 255), stop: 0.8 rgb(0,150,125)); border:0px solid black;");
                }
                   else if(number < 125 && number >= 100 && t[65*x+y-65] >= 250){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 0, 255), stop: 0.8 rgb(0,150,125)); border:0px solid black;");
                }


                 //<150 && >=125
                 else  if(number < 150 && number >= 125 && t[65*x+y-65] < -250){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,0,0), stop: 0.8 rgb(0,125,150)); border:0px solid black;");
               }
                   else if(number < 150 && number >= 125 && t[65*x+y-65] < -225 && t[65*x+y-65] >= -250){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,50,0), stop: 0.8 rgb(0,125,150)); border:0px solid black;");
                }
                   else if(number < 150 && number >= 125 && t[65*x+y-65] < -200 && t[65*x+y-65] >= -225){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(225,50,0), stop: 0.8 rgb(0,125,150)); border:0px solid black;");
                }
                   else if(number < 150 && number >= 125 && t[65*x+y-65] < -175 && t[65*x+y-65] >= -200){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,50,0), stop: 0.8 rgb(0,125,150)); border:0px solid black;");
                }
                   else if(number < 150 && number >= 125 && t[65*x+y-65] < -150 && t[65*x+y-65] >= -175){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,75,0), stop: 0.8 rgb(0,125,150)); border:0px solid black;");
                }
                   else if(number < 150 && number >= 125 && t[65*x+y-65] < -125 && t[65*x+y-65] >= -150){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(175,100,0), stop: 0.8 rgb(0,125,150)); border:0px solid black;");
                }
                   else if(number < 150 && number >= 125 && t[65*x+y-65] < -100 && t[65*x+y-65] >= -125){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(150,125,0), stop: 0.8 rgb(0,125,150)); border:0px solid black;");
                }
                   else if(number < 150 && number >= 125 && t[65*x+y-65] < -75 && t[65*x+y-65] >= -100){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,150,0), stop: 0.8 rgb(0,125,150)); border:0px solid black;");
                }
                   else if(number < 150 && number >= 125 && t[65*x+y-65] < -50 && t[65*x+y-65] >= -75){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,175,0), stop: 0.8 rgb(0,125,150)); border:0px solid black;");
                }
                   else if(number < 150 && number >= 125 && t[65*x+y-65] < -25 && t[65*x+y-65] >= -50){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,200,0), stop: 0.8 rgb(0,125,150)); border:0px solid black;");
                }
                   else if(number < 150 && number >= 125 && t[65*x+y-65] < 0 && t[65*x+y-65] >= -25){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,255,0), stop: 0.8 rgb(0,125,150)); border:0px solid black;");
                }
                   else if(number < 150 && number >= 125 && t[65*x+y-65] < 25 && t[65*x+y-65] >= 0){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,255,50), stop: 0.8 rgb(0,125,150)); border:0px solid black;");
                }
                   else if(number < 150 && number >= 125 && t[65*x+y-65] < 50 && t[65*x+y-65] >= 25){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,225,50), stop: 0.8 rgb(0,125,150)); border:0px solid black;");
                }
                   else if(number < 150 && number >= 125 && t[65*x+y-65] < 75 && t[65*x+y-65] >= 50){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,200,75), stop: 0.8 rgb(0,125,150)); border:0px solid black;");
                }
                   else if(number < 150 && number >= 125 && t[65*x+y-65] < 100 && t[65*x+y-65] >= 75){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,175,100), stop: 0.8 rgb(0,125,150)); border:0px solid black;");
                }
                   else if(number < 150 && number >= 125 && t[65*x+y-65] < 125 && t[65*x+y-65] >= 100){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,150,125), stop: 0.8 rgb(0,125,150)); border:0px solid black;");
                }
                   else if(number < 150 && number >= 125 && t[65*x+y-65] < 150 && t[65*x+y-65] >= 125){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,125,150), stop: 0.8 rgb(0,125,150)); border:0px solid black;");
                }
                   else if(number < 150 && number >= 125 && t[65*x+y-65] < 175 && t[65*x+y-65] >= 150){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,100,175), stop: 0.8 rgb(0,125,150)); border:0px solid black;");
                }
                   else if(number < 150 && number >= 125 && t[65*x+y-65] < 200 && t[65*x+y-65] >= 175){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,75,200), stop: 0.8 rgb(0,125,150)); border:0px solid black;");
                }
                   else if(number < 150 && number >= 125 && t[65*x+y-65] < 225 && t[65*x+y-65] >= 200){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,225), stop: 0.8 rgb(0,125,150)); border:0px solid black;");
                }
                   else if(number < 150 && number >= 125 && t[65*x+y-65] < 250 && t[65*x+y-65] >= 225){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,255), stop: 0.8 rgb(0,125,150)); border:0px solid black;");
                }
                   else if(number < 150 && number >= 125 && t[65*x+y-65] >= 250){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 0, 255), stop: 0.8 rgb(0,125,150)); border:0px solid black;");
                }

                 //<175 && >=150
                 else  if(number < 175 && number >= 150 && t[65*x+y-65] < -250){
                    btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,0,0), stop: 0.8 rgb(0,100,175)); border:0px solid black;");
               }
                   else if(number < 175 && number >= 150 && t[65*x+y-65] < -225 && t[65*x+y-65] >= -250){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,50,0), stop: 0.8 rgb(0,100,175)); border:0px solid black;");
                }
                   else if(number < 175 && number >= 150 && t[65*x+y-65] < -200 && t[65*x+y-65] >= -225){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(225,50,0), stop: 0.8 rgb(0,100,175)); border:0px solid black;");
                }
                   else if(number < 175 && number >= 150 && t[65*x+y-65] < -175 && t[65*x+y-65] >= -200){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,50,0), stop: 0.8 rgb(0,100,175)); border:0px solid black;");
                }
                   else if(number < 175 && number >= 150 && t[65*x+y-65] < -150 && t[65*x+y-65] >= -175){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,75,0), stop: 0.8 rgb(0,100,175)); border:0px solid black;");
                }
                   else if(number < 175 && number >= 150 && t[65*x+y-65] < -125 && t[65*x+y-65] >= -150){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(175,100,0), stop: 0.8 rgb(0,100,175)); border:0px solid black;");
                }
                   else if(number < 175 && number >= 150 && t[65*x+y-65] < -100 && t[65*x+y-65] >= -125){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(150,125,0), stop: 0.8 rgb(0,100,175)); border:0px solid black;");
                }
                   else if(number < 175 && number >= 150 && t[65*x+y-65] < -75 && t[65*x+y-65] >= -100){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,150,0), stop: 0.8 rgb(0,100,175)); border:0px solid black;");
                }
                   else if(number < 175 && number >= 150 && t[65*x+y-65] < -50 && t[65*x+y-65] >= -75){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,175,0), stop: 0.8 rgb(0,100,175)); border:0px solid black;");
                }
                   else if(number < 175 && number >= 150 && t[65*x+y-65] < -25 && t[65*x+y-65] >= -50){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,200,0), stop: 0.8 rgb(0,100,175)); border:0px solid black;");
                }
                   else if(number < 175 && number >= 150 && t[65*x+y-65] < 0 && t[65*x+y-65] >= -25){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,255,0), stop: 0.8 rgb(0,100,175)); border:0px solid black;");
                }
                   else if(number < 175 && number >= 150 && t[65*x+y-65] < 25 && t[65*x+y-65] >= 0){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,255,50), stop: 0.8 rgb(0,100,175)); border:0px solid black;");
                }
                   else if(number < 175 && number >= 150 && t[65*x+y-65] < 50 && t[65*x+y-65] >= 25){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,225,50), stop: 0.8 rgb(0,100,175)); border:0px solid black;");
                }
                   else if(number < 175 && number >= 150 && t[65*x+y-65] < 75 && t[65*x+y-65] >= 50){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,200,75), stop: 0.8 rgb(0,100,175)); border:0px solid black;");
                }
                   else if(number < 175 && number >= 150 && t[65*x+y-65] < 100 && t[65*x+y-65] >= 75){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,175,100), stop: 0.8 rgb(0,100,175)); border:0px solid black;");
                }
                   else if(number < 175 && number >= 150 && t[65*x+y-65] < 125 && t[65*x+y-65] >= 100){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,150,125), stop: 0.8 rgb(0,100,175)); border:0px solid black;");
                }
                   else if(number < 175 && number >= 150 && t[65*x+y-65] < 150 && t[65*x+y-65] >= 125){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,125,150), stop: 0.8 rgb(0,100,175)); border:0px solid black;");
                }
                   else if(number < 175 && number >= 150 && t[65*x+y-65] < 175 && t[65*x+y-65] >= 150){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,100,175), stop: 0.8 rgb(0,100,175)); border:0px solid black;");
                }
                   else if(number < 175 && number >= 150 && t[65*x+y-65] < 200 && t[65*x+y-65] >= 175){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,75,200), stop: 0.8 rgb(0,100,175)); border:0px solid black;");
                }
                   else if(number < 175 && number >= 150 && t[65*x+y-65] < 225 && t[65*x+y-65] >= 200){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,225), stop: 0.8 rgb(0,100,175)); border:0px solid black;");
                }
                   else if(number < 175 && number >= 150 && t[65*x+y-65] < 250 && t[65*x+y-65] >= 225){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,255), stop: 0.8 rgb(0,100,175)); border:0px solid black;");
                }
                   else if(number < 175 && number >= 150 && t[65*x+y-65] >= 250){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 0, 255), stop: 0.8 rgb(0,100,175)); border:0px solid black;");
                }

                 //<200 && >=175
                 else  if(number < 200 && number >= 175 && t[65*x+y-65] < -250){
                    btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,0,0), stop: 0.8 rgb(0,75,200)); border:0px solid black;");
               }
                   else if(number < 200 && number >= 175 && t[65*x+y-65] < -225 && t[65*x+y-65] >= -250){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,50,0), stop: 0.8 rgb(0,75,200)); border:0px solid black;");
                }
                   else if(number < 200 && number >= 175 && t[65*x+y-65] < -200 && t[65*x+y-65] >= -225){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(225,50,0), stop: 0.8 rgb(0,75,200)); border:0px solid black;");
                }
                   else if(number < 200 && number >= 175 && t[65*x+y-65] < -175 && t[65*x+y-65] >= -200){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,50,0), stop: 0.8 rgb(0,75,200)); border:0px solid black;");
                }
                   else if(number < 200 && number >= 175 && t[65*x+y-65] < -150 && t[65*x+y-65] >= -175){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,75,0), stop: 0.8 rgb(0,75,200)); border:0px solid black;");
                }
                   else if(number < 200 && number >= 175 && t[65*x+y-65] < -125 && t[65*x+y-65] >= -150){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(175,100,0), stop: 0.8 rgb(0,75,200)); border:0px solid black;");
                }
                   else if(number < 200 && number >= 175 && t[65*x+y-65] < -100 && t[65*x+y-65] >= -125){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(150,125,0), stop: 0.8 rgb(0,75,200)); border:0px solid black;");
                }
                   else if(number < 200 && number >= 175 && t[65*x+y-65] < -75 && t[65*x+y-65] >= -100){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,150,0), stop: 0.8 rgb(0,75,200)); border:0px solid black;");
                }
                   else if(number < 200 && number >= 175 && t[65*x+y-65] < -50 && t[65*x+y-65] >= -75){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,175,0), stop: 0.8 rgb(0,75,200)); border:0px solid black;");
                }
                   else if(number < 200 && number >= 175 && t[65*x+y-65] < -25 && t[65*x+y-65] >= -50){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,200,0), stop: 0.8 rgb(0,75,200)); border:0px solid black;");
                }
                   else if(number < 200 && number >= 175 && t[65*x+y-65] < 0 && t[65*x+y-65] >= -25){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,255,0), stop: 0.8 rgb(0,75,200)); border:0px solid black;");
                }
                   else if(number < 200 && number >= 175 && t[65*x+y-65] < 25 && t[65*x+y-65] >= 0){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,255,50), stop: 0.8 rgb(0,75,200)); border:0px solid black;");
                }
                   else if(number < 200 && number >= 175 && t[65*x+y-65] < 50 && t[65*x+y-65] >= 25){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,225,50), stop: 0.8 rgb(0,75,200)); border:0px solid black;");
                }
                   else if(number < 200 && number >= 175 && t[65*x+y-65] < 75 && t[65*x+y-65] >= 50){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,200,75), stop: 0.8 rgb(0,75,200)); border:0px solid black;");
                }
                   else if(number < 200 && number >= 175 && t[65*x+y-65] < 100 && t[65*x+y-65] >= 75){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,175,100), stop: 0.8 rgb(0,75,200)); border:0px solid black;");
                }
                   else if(number < 200 && number >= 175 && t[65*x+y-65] < 125 && t[65*x+y-65] >= 100){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,150,125), stop: 0.8 rgb(0,75,200)); border:0px solid black;");
                }
                   else if(number < 200 && number >= 175 && t[65*x+y-65] < 150 && t[65*x+y-65] >= 125){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,125,150), stop: 0.8 rgb(0,75,200)); border:0px solid black;");
                }
                   else if(number < 200 && number >= 175 && t[65*x+y-65] < 175 && t[65*x+y-65] >= 150){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,100,175), stop: 0.8 rgb(0,75,200)); border:0px solid black;");
                }
                   else if(number < 200 && number >= 175 && t[65*x+y-65] < 200 && t[65*x+y-65] >= 175){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,75,200), stop: 0.8 rgb(0,75,200)); border:0px solid black;");
                }
                   else if(number < 200 && number >= 175 && t[65*x+y-65] < 225 && t[65*x+y-65] >= 200){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,225), stop: 0.8 rgb(0,75,200)); border:0px solid black;");
                }
                   else if(number < 200 && number >= 175 && t[65*x+y-65] < 250 && t[65*x+y-65] >= 225){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,255), stop: 0.8 rgb(0,75,200)); border:0px solid black;");
                }
                   else if(number < 200 && number >= 175 && t[65*x+y-65] >= 250){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 0, 255), stop: 0.8 rgb(0,75,200)); border:0px solid black;");
                }

                 //<225 && >=200
                 else  if(number < 225 && number >= 200 && t[65*x+y-65] < -250){
                    btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,0,0), stop: 0.8 rgb(0,50,225)); border:0px solid black;");
               }
                   else if(number < 225 && number >= 200 && t[65*x+y-65] < -225 && t[65*x+y-65] >= -250){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,50,0), stop: 0.8 rgb(0,50,225)); border:0px solid black;");
                }
                   else if(number < 225 && number >= 200 && t[65*x+y-65] < -200 && t[65*x+y-65] >= -225){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(225,50,0), stop: 0.8 rgb(0,50,225)); border:0px solid black;");
                }
                   else if(number < 225 && number >= 200 && t[65*x+y-65] < -175 && t[65*x+y-65] >= -200){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,50,0), stop: 0.8 rgb(0,50,225)); border:0px solid black;");
                }
                   else if(number < 225 && number >= 200 && t[65*x+y-65] < -150 && t[65*x+y-65] >= -175){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,75,0), stop: 0.8 rgb(0,50,225)); border:0px solid black;");
                }
                   else if(number < 225 && number >= 200 && t[65*x+y-65] < -125 && t[65*x+y-65] >= -150){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(175,100,0), stop: 0.8 rgb(0,50,225)); border:0px solid black;");
                }
                   else if(number < 225 && number >= 200 && t[65*x+y-65] < -100 && t[65*x+y-65] >= -125){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(150,125,0), stop: 0.8 rgb(0,50,225)); border:0px solid black;");
                }
                   else if(number < 225 && number >= 200 && t[65*x+y-65] < -75 && t[65*x+y-65] >= -100){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,150,0), stop: 0.8 rgb(0,50,225)); border:0px solid black;");
                }
                   else if(number < 225 && number >= 200 && t[65*x+y-65] < -50 && t[65*x+y-65] >= -75){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,175,0), stop: 0.8 rgb(0,50,225)); border:0px solid black;");
                }
                   else if(number < 225 && number >= 200 && t[65*x+y-65] < -25 && t[65*x+y-65] >= -50){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,200,0), stop: 0.8 rgb(0,50,225)); border:0px solid black;");
                }
                   else if(number < 225 && number >= 200 && t[65*x+y-65] < 0 && t[65*x+y-65] >= -25){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,255,0), stop: 0.8 rgb(0,50,225)); border:0px solid black;");
                }
                   else if(number < 225 && number >= 200 && t[65*x+y-65] < 25 && t[65*x+y-65] >= 0){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,255,50), stop: 0.8 rgb(0,50,225)); border:0px solid black;");
                }
                   else if(number < 225 && number >= 200 && t[65*x+y-65] < 50 && t[65*x+y-65] >= 25){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,225,50), stop: 0.8 rgb(0,50,225)); border:0px solid black;");
                }
                   else if(number < 225 && number >= 200 && t[65*x+y-65] < 75 && t[65*x+y-65] >= 50){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,200,75), stop: 0.8 rgb(0,50,225)); border:0px solid black;");
                }
                   else if(number < 225 && number >= 200 && t[65*x+y-65] < 100 && t[65*x+y-65] >= 75){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,175,100), stop: 0.8 rgb(0,50,225)); border:0px solid black;");
                }
                   else if(number < 225 && number >= 200 && t[65*x+y-65] < 125 && t[65*x+y-65] >= 100){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,150,125), stop: 0.8 rgb(0,50,225)); border:0px solid black;");
                }
                   else if(number < 225 && number >= 200 && t[65*x+y-65] < 150 && t[65*x+y-65] >= 125){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,125,150), stop: 0.8 rgb(0,50,225)); border:0px solid black;");
                }
                   else if(number < 225 && number >= 200 && t[65*x+y-65] < 175 && t[65*x+y-65] >= 150){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,100,175), stop: 0.8 rgb(0,50,225)); border:0px solid black;");
                }
                   else if(number < 225 && number >= 200 && t[65*x+y-65] < 200 && t[65*x+y-65] >= 175){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,75,200), stop: 0.8 rgb(0,50,225)); border:0px solid black;");
                }
                   else if(number < 225 && number >= 200 && t[65*x+y-65] < 225 && t[65*x+y-65] >= 200){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,225), stop: 0.8 rgb(0,50,225)); border:0px solid black;");
                }
                   else if(number < 225 && number >= 200 && t[65*x+y-65] < 250 && t[65*x+y-65] >= 225){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 50, 255), stop: 0.8 rgb(0,50,225)); border:0px solid black;");
                }
                   else if(number < 225 && number >= 200 && t[65*x+y-65] >= 250){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 0, 255), stop: 0.8 rgb(0,50,225)); border:0px solid black;");
                }


                 //<250 && >=225
                 else  if(number < 250 && number >= 225 && t[65*x+y-65] < -250){
                    btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,0,0), stop: 0.8 rgb(0,50,255)); border:0px solid black;");
               }
                   else if(number < 250 && number >= 225 && t[65*x+y-65] < -225 && t[65*x+y-65] >= -250){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,50,0), stop: 0.8 rgb(0,50,255)); border:0px solid black;");
                }
                   else if(number < 250 && number >= 225 && t[65*x+y-65] < -200 && t[65*x+y-65] >= -225){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(225,50,0), stop: 0.8 rgb(0,50,255)); border:0px solid black;");
                }
                   else if(number < 250 && number >= 225 && t[65*x+y-65] < -175 && t[65*x+y-65] >= -200){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,50,0), stop: 0.8 rgb(0,50,255)); border:0px solid black;");
                }
                   else if(number < 250 && number >= 225 && t[65*x+y-65] < -150 && t[65*x+y-65] >= -175){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,75,0), stop: 0.8 rgb(0,50,255)); border:0px solid black;");
                }
                   else if(number < 250 && number >= 225 && t[65*x+y-65] < -125 && t[65*x+y-65] >= -150){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(175,100,0), stop: 0.8 rgb(0,50,255)); border:0px solid black;");
                }
                   else if(number < 250 && number >= 225 && t[65*x+y-65] < -100 && t[65*x+y-65] >= -125){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(150,125,0), stop: 0.8 rgb(0,50,255)); border:0px solid black;");
                }
                   else if(number < 250 && number >= 225 && t[65*x+y-65] < -75 && t[65*x+y-65] >= -100){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,150,0), stop: 0.8 rgb(0,50,255)); border:0px solid black;");
                }
                   else if(number < 250 && number >= 225 && t[65*x+y-65] < -50 && t[65*x+y-65] >= -75){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,175,0), stop: 0.8 rgb(0,50,255)); border:0px solid black;");
                }
                   else if(number < 250 && number >= 225 && t[65*x+y-65] < -25 && t[65*x+y-65] >= -50){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,200,0), stop: 0.8 rgb(0,50,255)); border:0px solid black;");
                }
                   else if(number < 250 && number >= 225 && t[65*x+y-65] < 0 && t[65*x+y-65] >= -25){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,255,0), stop: 0.8 rgb(0,50,255)); border:0px solid black;");
                }
                   else if(number < 250 && number >= 225 && t[65*x+y-65] < 25 && t[65*x+y-65] >= 0){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,255,50), stop: 0.8 rgb(0,50,255)); border:0px solid black;");
                }
                   else if(number < 250 && number >= 225 && t[65*x+y-65] < 50 && t[65*x+y-65] >= 25){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,225,50), stop: 0.8 rgb(0,50,255)); border:0px solid black;");
                }
                   else if(number < 250 && number >= 225 && t[65*x+y-65] < 75 && t[65*x+y-65] >= 50){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,200,75), stop: 0.8 rgb(0,50,255)); border:0px solid black;");
                }
                   else if(number < 250 && number >= 225 && t[65*x+y-65] < 100 && t[65*x+y-65] >= 75){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,175,100), stop: 0.8 rgb(0,50,255)); border:0px solid black;");
                }
                   else if(number < 250 && number >= 225 && t[65*x+y-65] < 125 && t[65*x+y-65] >= 100){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,150,125), stop: 0.8 rgb(0,50,255)); border:0px solid black;");
                }
                   else if(number < 250 && number >= 225 && t[65*x+y-65] < 150 && t[65*x+y-65] >= 125){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,125,150), stop: 0.8 rgb(0,50,255)); border:0px solid black;");
                }
                   else if(number < 250 && number >= 225 && t[65*x+y-65] < 175 && t[65*x+y-65] >= 150){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,100,175), stop: 0.8 rgb(0,50,255)); border:0px solid black;");
                }
                   else if(number < 250 && number >= 225 && t[65*x+y-65] < 200 && t[65*x+y-65] >= 175){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,75,200), stop: 0.8 rgb(0,50,255)); border:0px solid black;");
                }
                   else if(number < 250 && number >= 225 && t[65*x+y-65] < 225 && t[65*x+y-65] >= 200){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,225), stop: 0.8 rgb(0,50,255)); border:0px solid black;");
                }
                   else if(number < 250 && number >= 225 && t[65*x+y-65] < 250 && t[65*x+y-65] >= 225){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,255), stop: 0.8 rgb(0,50,255)); border:0px solid black;");
                }
                   else if(number < 250 && number >= 225 && t[65*x+y-65] >= 250){
                   btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 0, 255), stop: 0.8 rgb(0,50,255)); border:0px solid black;");
                }

               //>=250
                else if(number >= 250 && t[65*x+y-65] < -250){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,0,0), stop: 0.8 rgb(0,0,255)); border:0px solid black;");
            }
                else if(number >= 250 && t[65*x+y-65] < -225 && t[65*x+y-65] >= -250){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(255,50,0), stop: 0.8 rgb(0,0,255)); border:0px solid black;");
             }
                else if(number >= 250 && t[65*x+y-65] < -200 && t[65*x+y-65] >= -225){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(225,50,0), stop: 0.8 rgb(0,0,255)); border:0px solid black;");
             }
                else if(number >= 250 && t[65*x+y-65] < -175 && t[65*x+y-65] >= -200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,50,0), stop: 0.8 rgb(0,0,255)); border:0px solid black;");
             }
                else if(number >= 250 && t[65*x+y-65] < -150 && t[65*x+y-65] >= -175){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(200,75,0), stop: 0.8 rgb(0,0,255)); border:0px solid black;");
             }
                else if(number >= 250 && t[65*x+y-65] < -125 && t[65*x+y-65] >= -150){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(175,100,0), stop: 0.8 rgb(0,0,255)); border:0px solid black;");
             }
                else if(number >= 250 && t[65*x+y-65] < -100 && t[65*x+y-65] >= -125){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(150,125,0), stop: 0.8 rgb(0,0,255)); border:0px solid black;");
             }
                else if(number >= 250 && t[65*x+y-65] < -75 && t[65*x+y-65] >= -100){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,150,0), stop: 0.8 rgb(0,0,255)); border:0px solid black;");
             }
                else if(number >= 250 && t[65*x+y-65] < -50 && t[65*x+y-65] >= -75){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(125,175,0), stop: 0.8 rgb(0,0,255)); border:0px solid black;");
             }
                else if(number >= 250 && t[65*x+y-65] < -25 && t[65*x+y-65] >= -50){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,200,0), stop: 0.8 rgb(0,0,255)); border:0px solid black;");
             }
                else if(number >= 250 && t[65*x+y-65] < 0 && t[65*x+y-65] >= -25){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(100,255,0), stop: 0.8 rgb(0,0,255)); border:0px solid black;");
             }
                else if(number >= 250 && t[65*x+y-65] < 25 && t[65*x+y-65] >= 0){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,255,50), stop: 0.8 rgb(0,0,255)); border:0px solid black;");
             }
                else if(number >= 250 && t[65*x+y-65] < 50 && t[65*x+y-65] >= 25){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,225,50), stop: 0.8 rgb(0,0,255)); border:0px solid black;");
             }
                else if(number >= 250 && t[65*x+y-65] < 75 && t[65*x+y-65] >= 50){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,200,75), stop: 0.8 rgb(0,0,255)); border:0px solid black;");
             }
             else if(number >= 250 && t[65*x+y-65] < 100 && t[65*x+y-65] >= 75){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,175,100), stop: 0.8 rgb(0,0,255)); border:0px solid black;");
             }
                else if(number >= 250 && t[65*x+y-65] < 125 && t[65*x+y-65] >= 100){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,150,125), stop: 0.8 rgb(0,0,255)); border:0px solid black;");
             }
                else if(number >= 250 && t[65*x+y-65] < 150 && t[65*x+y-65] >= 125){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,125,150), stop: 0.8 rgb(0,0,255)); border:0px solid black;");
             }
                else if(number >= 250 && t[65*x+y-65] < 175 && t[65*x+y-65] >= 150){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,100,175), stop: 0.8 rgb(0,0,255)); border:0px solid black;");
             }
                else if(number >= 250 && t[65*x+y-65] < 200 && t[65*x+y-65] >= 175){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,75,200), stop: 0.8 rgb(0,0,255)); border:0px solid black;");
             }
                else if(number >= 250 && t[65*x+y-65] < 225 && t[65*x+y-65] >= 200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,225), stop: 0.8 rgb(0,0,255)); border:0px solid black;");
             }
                else if(number >= 250 && t[65*x+y-65] < 250 && t[65*x+y-65] >= 225){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,50,255), stop: 0.8 rgb(0,0,255)); border:0px solid black;");
             }
              else if(number >= 250 && t[65*x+y-65] >= 250){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0, 0, 255), stop: 0.8 rgb(0,0,255)); border:0px solid black;");
             }

           }





            btn->setDisabled(true);
            ui->gridLayout->addWidget(btn, x, y);
        }
    }


    file->close();
}

void ColorDiagram::on_horizontalSlider_sliderMoved(int position)
{
    QLayoutItem *child;
    QWidget *w;
    while((child = ui->gridLayout->takeAt(0)) != 0){
        w = child->widget();
        ui->gridLayout->removeItem(child);
        delete child;
        delete w;
   }
   if(position   % 21 == 0 ){
       fillGridLayoutTest(QString("C:\\msiu-master\\last_modification_look_this\\logs\\log3000"));
    }
   else if(position % 21 == 1) {
        fillGridLayoutTest(QString("C:\\msiu-master\\last_modification_look_this\\logs\\log1000"));
    }
   else if(position % 21 == 2){
        fillGridLayoutTest(QString("C:\\msiu-master\\last_modification_look_this\\logs\\log1100"));
   }
   else if(position % 21 == 3) {
        fillGridLayoutTest(QString("C:\\msiu-master\\last_modification_look_this\\logs\\log1200"));
    }
   else if(position % 21 == 4){
        fillGridLayoutTest(QString("C:\\msiu-master\\last_modification_look_this\\logs\\log1300"));
   } else if(position % 21 == 5) {
       fillGridLayoutTest(QString("C:\\msiu-master\\last_modification_look_this\\logs\\log1400"));
   }
  else if(position % 21 == 6){
       fillGridLayoutTest(QString("C:\\msiu-master\\last_modification_look_this\\logs\\log1500"));
  }
  else if(position % 21 == 7) {
       fillGridLayoutTest(QString("C:\\msiu-master\\last_modification_look_this\\logs\\log1600"));
   }
  else if(position % 21 == 8){
       fillGridLayoutTest(QString("C:\\msiu-master\\last_modification_look_this\\logs\\log1700"));
  }
   else if(position % 21 == 9){
        fillGridLayoutTest(QString("C:\\msiu-master\\last_modification_look_this\\logs\\log1800"));
   }
   else if(position % 21 == 10){
        fillGridLayoutTest(QString("C:\\msiu-master\\last_modification_look_this\\logs\\log1900"));
   }
   else if(position % 21 == 11) {
        fillGridLayoutTest(QString("C:\\msiu-master\\last_modification_look_this\\logs\\log2000"));
    }
   else if(position % 21 == 12){
        fillGridLayoutTest(QString("C:\\msiu-master\\last_modification_look_this\\logs\\log2100"));
   }
   else if(position % 21 == 13) {
        fillGridLayoutTest(QString("C:\\msiu-master\\last_modification_look_this\\logs\\log2200"));
    }
   else if(position% 21 == 14){
        fillGridLayoutTest(QString("C:\\msiu-master\\last_modification_look_this\\logs\\log2300"));
   } else if(position % 21 == 15) {
       fillGridLayoutTest(QString("C:\\msiu-master\\last_modification_look_this\\logs\\log2400"));
   }
  else if(position % 21 == 16){
       fillGridLayoutTest(QString("C:\\msiu-master\\last_modification_look_this\\logs\\log2500"));
  }
  else if(position % 21 == 17) {
       fillGridLayoutTest(QString("C:\\msiu-master\\last_modification_look_this\\logs\\log2600"));
   }
  else if(position % 21 == 18){
       fillGridLayoutTest(QString("C:\\msiu-master\\last_modification_look_this\\logs\\log2700"));
  }
   else if(position % 21 == 19){
        fillGridLayoutTest(QString("C:\\msiu-master\\last_modification_look_this\\logs\\log2800"));
   }
   else if(position % 21 == 20){
        fillGridLayoutTest(QString("C:\\msiu-master\\last_modification_look_this\\logs\\log2900"));
   }
    ui->label->setText(QString::number(position).append(" секунда просмотра"));
    ui->label->setStyleSheet("color: rgb(0,0,255)");
}

void ColorDiagram::nextStep()
{
  int pos = ui->horizontalSlider->sliderPosition();
  ui->horizontalSlider->setValue(pos+1);
  this->on_horizontalSlider_sliderMoved(pos+1);
}




void ColorDiagram::on_playBtn_clicked()
{
    int posi = ui->horizontalSlider->sliderPosition();
    if(!autoPlayTimer->isActive()){
        autoPlayTimer->start();
        ui->playBtn->setText(QString("Пауза"));
        ui->playBtn->setStyleSheet("background-color: #EEE8AA; border:0px solid black;");
    } else if(autoPlayTimer->isActive() && posi != 0) {
        autoPlayTimer->stop();
        ui->playBtn->setText(QString("Продолжить"));
        ui->playBtn->setStyleSheet("background-color: #ADD8E6; border:0px solid black;");
    } else{
        autoPlayTimer->stop();
        ui->playBtn->setText(QString("Старт"));
        ui->playBtn->setStyleSheet("background-color: rgb(255,0,0); border:0px solid black;");
    }
}



void ColorDiagram::on_scalaBtn_pressed()
{
    ui->scalaBtn->setDisabled(true);
    ui->scalaBtn->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(0,0,255),stop: 0.2 rgb(0,100,200), stop: 0.4 rgb(0, 200, 100), stop: 0.6 rgb(100,200, 0), stop: 0.8 rgb(200,100, 0), stop: 1 rgb(255,0,0)); border:0px solid black;");
}


void ColorDiagram::on_sbrosBtn_clicked()
{
    ui->horizontalSlider->setValue(0);
    ui->label->setText(QString("Вы прервали показ!!!"));
    ui->label->setStyleSheet("color: rgb(255, 0, 0)");
    autoPlayTimer->stop();
    fillGridLayoutTest(QString("C:\\msiu-master\\last_modification_look_this\\logs\\log300"));
    ui->playBtn->setText(QString("Старт"));
    ui->playBtn->setStyleSheet("background-color: rgb(0,255,0); border:0px solid black;");
}
