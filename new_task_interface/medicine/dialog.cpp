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

    QString newString = ui->height->toPlainText();
    newString.append(";");
    newString.append(ui->weight->toPlainText());


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
