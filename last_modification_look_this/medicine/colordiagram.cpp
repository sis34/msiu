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
    ui(new Ui::ColorDiagram)
{
    ui->setupUi(this);
    fillGridLayoutTest(QString("/mnt/storage1/users/s/si/sis34/Desktop/edu/test1_1.txt"));
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
    int t[66177];
    for(int x = 0; x <= 129; x++){
        for(int y = 0; y <= 513; y++){
            QString line = in.readLine();
            int number = line.toInt();
            t[129*x+y] = number;
        }
    }

    QImage* inputImg = new QImage(513, 129,QImage::Format_RGB32);
                for(int i = 0; i< 129; i++){
                    for(int j = 0; j < 513; j++){
                        if (t[j*i+i] < -200){
                        inputImg->setPixel(j, i, qRgb(255, 0 , 0));
                        }else if(t[i*129+j] >= -200 && t[i*129+j] < -100){
                          inputImg->setPixel(i, j, qRgb(125, 255 , 125));
                        }
                    else if(t[i*129+j] >= -100 && t[i*129+j] < 0){
                      inputImg->setPixel(i, j, qRgb(0, 255 , 125));

                    }
                    else if(t[i*129+j] >= 0 && t[i*129+j] < 100){
                     inputImg->setPixel(i, j, qRgb(0, 255 , 0));
                  }
                    else if(t[i*129+j] >= 100 && t[i*129+j] < 200){
                     inputImg->setPixel(i, j, qRgb(0, 125 , 255));
                  }
                    else if(t[i*129+j] >= 200){
                     inputImg->setPixel(i, j, qRgb(0, 0 , 255));
                  }
                }}
                QLabel* imgDisplayLabel = new QLabel("");
                imgDisplayLabel->setPixmap(QPixmap::fromImage(*inputImg));
                imgDisplayLabel->adjustSize();
                QScrollArea* scrollArea = new QScrollArea();
                scrollArea->setWidget(imgDisplayLabel);
                scrollArea->setMinimumSize(640,640);
                ui->gridLayout->addWidget(scrollArea,100,100);


    /*int  t[4257];
    for(int x = 0; x <= 33; x++){
        for(int y = 0; y <= 129; y++){
            QString line = in.readLine();
            int number = line.toInt();
            t[33*x+y] = number;

            qDebug() << t[1];
            //qDebug() << t[29];

            QPushButton *btn = new QPushButton(this);
            btn->setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);
            if(number < -200 ){
                btn->setStyleSheet("background-color: #0000ff); border:0px solid black;");
            }
            else if(number >= -200 && number < -100 ){
                btn->setStyleSheet("background-color: #0088ff); border:0px solid black;");
            }
            else if(number >= -100 && number < 0 ){
                btn->setStyleSheet("background-color: #00ff00); border:0px solid black;");
            }
            else if(number >= 0 && number < 100 ){
                btn->setStyleSheet("background-color: #88ff88); border:0px solid black;");
            }else if(number >= 100 && number < 200 ){
                btn->setStyleSheet("background-color: #ff8800); border:0px solid black;");
            }else if(number >200){
                btn->setStyleSheet("background-color: #ff0000); border:0px solid black;");
            }
            //первая строка, если текущий зеленый и нижний зеленый
            //else if(number <= 200 && number >= 100 && x < 1 && t[16+y] >= 100 && t[16+y] <= 200){
              //  btn->setStyleSheet("background-color: qlineargradient(x1: 0.3, y1: 0, x2: 0.3, y2: 1, stop: 0 #00ff00, stop: 0.5 #00ff00, stop: 1 #00ff00); border:0px solid black;");
            //}
            /*///первая строка, если текущий красный и нижний красный
           /* if(number < 100 && x < 1 && t[16+y] < 100){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0.3, y1: 0, x2: 0.3, y2: 1, stop: 0 #ff0000, stop: 0.5 #ff0000, stop: 1 #ff0000); border:0px solid black;");
            }
            //первая строка, если текущий зеленый и нижний зеленый
            else if(number <= 200 && number >= 100 && x < 1 && t[16+y] >= 100 && t[16+y] <= 200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0.3, y1: 0, x2: 0.3, y2: 1, stop: 0 #00ff00, stop: 0.5 #00ff00, stop: 1 #00ff00); border:0px solid black;");
            }
            //первая строка, если текущий синий и нижний синий
            else if(number > 200 && x < 1 && t[16+y] > 200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0.3, y1: 0, x2: 0.3, y2: 1, stop: 0 #0000ff, stop: 0.5 #0000ff, stop: 1 #0000ff); border:0px solid black;");
            }*/
            /*
            //первая строка, если текущий зеленый и нижний красный
            else if(number <= 200 && number >= 100 && x < 1 && t[16+y] < 100){
               btn->setStyleSheet("background-color: qlineargradient(x1: 0.3, y1: 0, x2: 0.3, y2: 1, stop: 0 #00ff00, stop: 0.5 #00ff00, stop: 1 #ff0000); border:0px solid black;");
            }
            //первая строка, если текущий зеленый и нижний синий
            else if(number <= 200 && number >= 100 && x < 1 && t[16+y] > 200 ){
              btn->setStyleSheet("background-color: qlineargradient(x1: 0.3, y1: 0, x2: 0.3, y2: 1, stop: 0 #00ff00, stop: 0.5 #00ff00, stop: 1 #0000ff); border:0px solid black;");
            }
            //первая строка, если текущий красный и нижний зеленый
            else if(number < 100  && x < 1 && t[16+y] >= 100 && t[16+y] <= 200){
               btn->setStyleSheet("background-color: qlineargradient(x1: 0.3, y1: 0, x2: 0.3, y2: 1, stop: 0 #ff0000, stop: 0.5 #ff0000, stop: 1 #00ff00); border:0px solid black;");
            }

            //первая строка, если текущий красный и нижний синий
            else if(number < 100 && x < 1 && t[16+y] > 200){
              btn->setStyleSheet("background-color: qlineargradient(x1: 0.3, y1: 0, x2: 0.3, y2: 1, stop: 0 #ff0000, stop: 0.5 #ff0000, stop: 1 #0000ff); border:0px solid black;");
            }
            //первая строка, если текущий синий и нижний красный
            else if(number > 200  && x < 1 && t[16+y] < 100){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0.3, y1: 0, x2: 0.3, y2: 1, stop: 0 #0000ff, stop: 0.5 #0000ff, stop: 1 #ff0000); border:0px solid black;");
            }
            //первая строка, если текущий синий и нижний зеленый
            else if(number > 200 && x < 1 && t[16+y] >= 100 && t[16+y] <= 200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0.3, y1: 0, x2: 0.3, y2: 1, stop: 0 #0000ff, stop: 0.5 #0000ff, stop: 1 #00ff00); border:0px solid black;");
            }



            //последующие строки
            //верхний красный, текущий красный
            else if(t[x*16+y-16] < 100  && x >= 1 &&  number < 100){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0.3, y1: 0, x2: 0.3, y2: 1, stop: 0 #ff0000, stop: 0.5 #ff0000, stop: 1 #ff0000); border:0px solid black;");
            }
            //верхний зеленый, текущий зеленый
            else if(t[x*16+y-16] >= 100 && t[x*16+y-16] <= 200 && x >= 1 && number >= 100 && number <= 200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0.3, y1: 0, x2: 0.3, y2: 1, stop: 0 #00ff00, stop: 0.5 #00ff00, stop: 1 #00ff00); border:0px solid black;");
            }
            //верхний синий, текущий синий
            else if(t[x*16+y-16] > 200 && x >= 1 && number > 200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0.3, y1: 0, x2: 0.3, y2: 1, stop: 0 #0000ff, stop: 0.5 #0000ff, stop: 1 #0000ff); border:0px solid black;");
            }
            //верхний красный, текущий зеленый
            else if(t[x*16+y-16] < 100 && x >= 1 && number >= 100 && number <= 200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0.3, y1: 0, x2: 0.3, y2: 1, stop: 0 #ff0000, stop: 0.5 #00ff00, stop: 1 #00ff00); border:0px solid black;");
            }
            //верхний красный, текущий синий
            else if(t[x*16+y-16] < 100 && x >= 1 && number > 200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0.3, y1: 0, x2: 0.3, y2: 1, stop: 0 #ff0000, stop: 0.5 #0000ff, stop: 1 #0000ff); border:0px solid black;");
            }
            //верхний зеленый, текущий красный
            else if(t[x*16+y-16] <= 200 && t[x*16+y-16] >= 100 &&  x >= 1 && number < 100){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0.3, y1: 0, x2: 0.3, y2: 1, stop: 0 #00ff00, stop: 0.5 #ff0000, stop: 1 #ff0000); border:0px solid black;");
            }
            //верхний зеленый, текущий синий
            else if(t[x*16+y-16] <= 200 && t[x*16+y-16] >= 100 &&  x >= 1 && number > 200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0.3, y1: 0, x2: 0.3, y2: 1, stop: 0 #00ff00, stop: 0.5 #0000ff, stop: 1 #0000ff); border:0px solid black;");
            }
            //верхний синий, текущий красный
            else if(t[x*16+y-16] > 200  &&  x >= 1 && number < 100){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0.3, y1: 0, x2: 0.3, y2: 1, stop: 0 #0000ff, stop: 0.5 #ff0000, stop: 1 #ff0000); border:0px solid black;");
            }
            //верхний синий, текущий зеленый
            else if(t[x*16+y-16] > 200  &&  x >= 1 && number >= 100 && number <= 200){
                btn->setStyleSheet("background-color: qlineargradient(x1: 0.3, y1: 0, x2: 0.3, y2: 1, stop: 0 #0000ff, stop: 0.5 #ff0000, stop: 1 #ff0000); border:0px solid black;");
            }

            btn->setDisabled(true);
            ui->gridLayout->addWidget(btn, x, y);
        }
    }*/

    file->close();
}

void ColorDiagram::on_horizontalSlider_sliderMoved(int position)
{
    //qDebug() << position;
    QLayoutItem *child;
    QWidget *w;
    while((child = ui->gridLayout->takeAt(0)) != 0){
        w = child->widget();
        ui->gridLayout->removeItem(child);
        delete child;
        delete w;
   }
   if(position >= 0 && position < 10 ){
       fillGridLayoutTest(QString("/mnt/storage1/users/s/si/sis34/Desktop/edu/test1_1.txt"));
    }
    /*else if(position >=10 && position < 20) {
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
*/
    ui->label->setText(QString::number(position).append(" Секунда"));
}


