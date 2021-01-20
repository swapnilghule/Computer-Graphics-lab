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
     void DDALine(int x1,int y1,int x2,int y2);
      void DDALine1(int x1,int y1,int x2,int y2);
      void DDALine2(int x1,int y1,int x2,int y2);
       void DDALine3(int x1,int y1,int x2,int y2);
       int sign(float d);
     void on_pushButton_2_clicked();

     void on_pushButton_5_clicked();

     void on_pushButton_3_clicked();

     void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
