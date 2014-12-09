#ifndef COLORDIAGRAM_H
#define COLORDIAGRAM_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>

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

private:
    Ui::ColorDiagram *ui;
    void fillGridLayoutTest(QString);
};

#endif // COLORDIAGRAM_H
