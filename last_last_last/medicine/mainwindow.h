#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QString>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QDialog>
#include "dialog.h"
#include "colordiagram.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_createFormBtn_clicked();


    void on_colorDiagramBtnOpen_clicked();

   // void on_openglBtn_clicked();

private:
    Ui::MainWindow *ui;
    Dialog *formDialog;
    ColorDiagram *colorDiagram;
};

#endif // MAINWINDOW_H
