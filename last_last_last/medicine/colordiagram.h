#ifndef COLORDIAGRAM_H
#define COLORDIAGRAM_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QTimer>

namespace Ui {
class ColorDiagram;
}

class ColorDiagram : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ColorDiagram(QWidget *parent = 0);
    ~ColorDiagram();
    



private slots:
    void on_horizontalSlider_sliderMoved(int position);
    void nextStep();



    void on_playBtn_clicked();



    void on_scalaBtn_pressed();



    void on_sbrosBtn_clicked();

private:
    Ui::ColorDiagram *ui;
    void fillGridLayoutTest(QString);
    QTimer* autoPlayTimer;
};

#endif // COLORDIAGRAM_H
