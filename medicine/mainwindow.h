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
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDriver>
#include <QSqlDriverCreator>


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


   // void on_loadFileBtn_clicked();
    //void qFileDialogFileSelected(QString filePath);

    void on_createFormBtn_clicked();

    //void on_sqlLiteBtn_clicked();

private:
    Ui::MainWindow *ui;
    QMessageBox *qMessageBox;
    QFileDialog *qFileDialog;
    Dialog *formDialog;
    QSqlDatabase db;
};

#endif // MAINWINDOW_H
