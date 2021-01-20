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

    void mousePressEvent(QMouseEvent *);

    void bresenham(float x1, float y1, float x2, float y2);

    int sign(int n);

    void mouseDoubleClickEvent(QMouseEvent *);

    void seedFill(int x, int y, QRgb bg);

private:
    Ui::MainWindow *ui;
    int a[10], b[10], i;
    bool start;
};

#endif // MAINWINDOW_H
