#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_rejected()
{
    this->hide();
}
// записываем всё в файлик
void Dialog::on_buttonBox_accepted()
{
    QString filePath(QDir::currentPath());
    filePath.append("/dialog_file.txt");

    QString newString = ui->rest_begin->toPlainText();
    newString.append(";");
    newString.append(ui->rest_end->toPlainText());
    newString.append(";");
    newString.append(ui->top_begin->toPlainText());
    newString.append(";");
    newString.append(ui->top_end->toPlainText());
    newString.append(";");
    newString.append(ui->first_minute_begin->toPlainText());
    newString.append(";");
    newString.append(ui->first_minute_end->toPlainText());
    newString.append(";");
    newString.append(ui->third_minute_begin->toPlainText());
    newString.append(";");
    newString.append(ui->third_minute_end->toPlainText());
    newString.append(";");
    newString.append(ui->fifth_minute_begin->toPlainText());
    newString.append(";");
    newString.append(ui->seventh_minute_begin->toPlainText());
    newString.append(";");
    newString.append(ui->seventh_minute_end->toPlainText());


    QFile file(filePath);

    if(!file.open(QFile::Append)){
        qDebug() << "Не смог открыть файл =)";
        return;
    }

    QTextStream out(&file);
    out << newString;
    out << "\n";
    out.flush();
    file.close();
}
