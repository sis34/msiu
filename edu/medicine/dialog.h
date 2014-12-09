#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>
#include <QFile>
#include <QDir>
#include <QTextEdit>
#include <QDebug>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    
private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
