#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    qMessageBox(new QMessageBox(parent)),
    qFileDialog(new QFileDialog(parent)),
    formDialog(new Dialog(parent))
{
    ui->setupUi(this);
    //qMessageBox->setText(QString("This is QMessageBox"));
    //QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //QString dbFilePath = QDir::currentPath();
    //dbFilePath.append("/development.sqlite3");
    //qDebug() << dbFilePath;
    //db.setDatabaseName(dbFilePath);
    //db.open();
    //if (db.isOpen()){
      //  qDebug() << "база данных открыта";
    //}
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::on_createWindowBtn_clicked()
//{
  //  qMessageBox->show();
//}

//void MainWindow::on_loadFileBtn_clicked()
//{
  //  qFileDialog->show();
    //connect(qFileDialog, SIGNAL(fileSelected(QString)), this, SLOT(qFileDialogFileSelected(QString)));
//}
// "загрузить файл" - значит скопировать файл в папку с программой
// позже можно будет сделать какие-то настройки
// куда будем копировать файл
// если одноимённый файл в этой папке уже существует
// тихо, без вопросов, заменяем
//void MainWindow::qFileDialogFileSelected(QString filePath)
//{
  //  qDebug() << QString("Копируем отсюда: ").append(filePath);
    //qDebug() << QString("Сюда: ").append(QDir::currentPath());
    //QFile f(filePath);

    //QFileInfo fileInfo(f.fileName());
    //QString newFilePath(fileInfo.fileName());
    //newFilePath.prepend("/").prepend(QDir::currentPath());
    //QFile::copy(filePath, newFilePath);
//}

void MainWindow::on_createFormBtn_clicked()
{
    formDialog->show();
}

//void MainWindow::on_sqlLiteBtn_clicked()
//{

//    QSqlQuery query(db);
  //  query.exec("select * from products");

    //while (query.next()) {
      //  qDebug() << query.value(3).toString();
    //}

//}
