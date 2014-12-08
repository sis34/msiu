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
    fillGridLayoutTest(QString("/mnt/storage1/users/s/si/sis34/Desktop/edu/build-medicine-Desktop_Qt_5_0_2_GCC_32bit-Release/test1.txt"));
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
            if(number > 100){
                btn->setStyleSheet("background-color: yellow;border:1px solid black;");
            } else if(number < 100 && number > 50){
                btn->setStyleSheet("background-color: red;border:1px solid black;");
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
    QLayoutItem *child;
    QWidget *w;
    while((child = ui->gridLayout->takeAt(0)) != 0){
        w = child->widget();
        ui->gridLayout->removeItem(child);
        delete child;
        delete w;
   }
    if(position > 50){
        fillGridLayoutTest(QString("/mnt/storage1/users/s/si/sis34/Desktop/edu/build-medicine-Desktop_Qt_5_0_2_GCC_32bit-Release/test2.txt"));

    } else {
       fillGridLayoutTest(QString("/mnt/storage1/users/s/si/sis34/Desktop/edu/build-medicine-Desktop_Qt_5_0_2_GCC_32bit-Release/test1.txt"));

    }

}
