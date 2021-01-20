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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void dda_line(int x1,int x2,int y1,int y2);
    void dda_circle(int xc,int yc,int r);
    void bresenham_circle(int xc,int yc,int r);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
