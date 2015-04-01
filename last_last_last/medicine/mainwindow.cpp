#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    formDialog(new Dialog(parent)),
    colorDiagram(new ColorDiagram(parent))
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_createFormBtn_clicked()
{
    formDialog->show();
}


void MainWindow::on_colorDiagramBtnOpen_clicked()
{
    colorDiagram->show();
}


