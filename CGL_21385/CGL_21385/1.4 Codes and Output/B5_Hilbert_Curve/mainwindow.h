#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void goToXY(int x, int y);
    void HilbertA (int level);
    void HilbertB (int level);
    void HilbertC (int level);
    void HilbertD (int level);
    void lineRel(int deltaX, int deltaY);
    void display(int x1,int y1,int x2,int y2);
private:
    Ui::MainWindow *ui;
   int dist0,dist,x,y,deltaX,deltaY;

};

#endif // MAINWINDOW_H
