#include "mainwindow.h"
#include "ui_mainwindow.h"
static QImage img(600,600,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dist0=512;x=0;y=0;
    dist=dist0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int level;
    level=ui->textEdit->toPlainText().toInt();
    for (int i=level;i>0;i--)
        dist /= 2;
    goToXY ( dist/2, dist/2 );
    HilbertA(level);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::goToXY(int x, int y)
{
   this->x = x;
    this->y = y;
}

void MainWindow::HilbertA(int level)
{
    if (level > 0)
    {
      HilbertB(level-1);
      lineRel(0,dist);
      HilbertA(level-1);
      lineRel(dist,0);
      HilbertA(level-1);
      lineRel(0,-dist);
      HilbertC(level-1);
    }
}

void MainWindow::HilbertB(int level)
{
    if (level > 0) {
                HilbertA(level-1);
                lineRel(dist,0);
                HilbertB(level-1);
                lineRel(0,dist);
                HilbertB(level-1);
                lineRel(-dist,0);
                HilbertD(level-1);
            }
}

void MainWindow::HilbertC(int level)
{
    if (level > 0) {
                HilbertD(level-1);
                lineRel(-dist,0);
                HilbertC(level-1);
                lineRel(0,-dist);
                HilbertC(level-1);
                lineRel(dist,0);
                HilbertA(level-1);
            }

}

void MainWindow::HilbertD(int level)
{
    if (level > 0) {
        HilbertC(level-1);
        lineRel(0,-dist);
        HilbertD(level-1);
        lineRel(-dist,0);
        HilbertD(level-1);
        lineRel(0,dist);
        HilbertB(level-1);
    }
}

void MainWindow::display(int x1,int y1,int x2,int y2)
{

    float x,y,dx,dy,l,i=0;
    QRgb value;
    value=qRgb(0,255,0);

    l=std::abs(x2-x1)>std::abs(y2-y1)?std::abs(x2-x1):std::abs(y2-y1);
    dx=(x2-x1)/l;
    dy=(y2-y1)/l;

    x=x1;
    y=y1;

    while(i < l)
    {
        // qDebug()<<static_cast<int>(x)<<" y value:"<<static_cast<int>(y);
       img.setPixel(static_cast<int>(x),static_cast<int>(y),value);
       x = x + dx;
       y = y + dy;
       // delay(50);
        ui->label->setPixmap(QPixmap::fromImage(img));
         i++;
      }
}

void MainWindow::lineRel(int deltaX, int deltaY)
{
    display(x, y, x+deltaX, y+deltaY);
    x += deltaX;
    y += deltaY;
}
