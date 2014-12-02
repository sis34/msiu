#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setTabOrderEditText();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setTabOrderEditText()
{
    QWidget::setTabOrder(ui->start_rest, ui->end_rest);
    QWidget::setTabOrder(ui->end_rest, ui->start_top);
    QWidget::setTabOrder(ui->start_top, ui->end_top);
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

    QString newString = ui->start_rest->toPlainText();
    newString.append(";");
    newString.append(ui->end_rest->toPlainText());
    newString.append(";");
    newString.append(ui->start_top->toPlainText());
    newString.append(";");
    newString.append(ui->end_top->toPlainText());
    newString.append(";");
    newString.append(ui->start_first_minute->toPlainText());
    newString.append(";");
    newString.append(ui->end_first_minute->toPlainText());
    newString.append(";");
    newString.append(ui->start_third_minute->toPlainText());
    newString.append(";");
    newString.append(ui->end_third_minute->toPlainText());
    newString.append(";");
    newString.append(ui->start_fifth_minute->toPlainText());
    newString.append(";");
    newString.append(ui->end_fifth_minute->toPlainText());
    newString.append(";");
    newString.append(ui->start_seventh_minute->toPlainText());
    newString.append(";");
    newString.append(ui->end_seventh_minute->toPlainText());

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
