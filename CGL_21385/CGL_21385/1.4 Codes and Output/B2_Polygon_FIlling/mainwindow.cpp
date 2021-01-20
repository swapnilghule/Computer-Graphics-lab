#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
#include "QMouseEvent"
#include "QColorDialog"

QImage img(400,400,QImage::Format_RGB888);
QColor color;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start = true;
    i = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::sign(int n)
{
    if(n < 0)
        return -1;
    if(n == 0)
        return 0;
    if(n > 0)
        return 1;
}

void MainWindow::bresenham(float x1, float y1, float x2, float y2)
{
        int x,y,dx,dy,p,i;
        x=x1;
        y=y1;
        dx=abs(x2-x1);
        dy=abs(y2-y1);
        i=0;
        if(dx>=dy)
        {
            p=2*dy-dx;
            while(i<=dx)
            {
                img.setPixel(floor(x),floor(y),color.rgb());
                if(p<0)
                {
                    p=p+2*dy;
                }
                else
                {
                    p=p+2*(dy-dx);
                    y=y+1*sign(y2-y1);
                }
                x=x+1*sign(x2-x1);
                i++;
            }
        }
        else
        {
            p=2*dx-dy;
            while(i<=dy)
            {
                img.setPixel(floor(x),floor(y),color.rgb());
                if(p<0)
                {
                    p=p+2*dx;
                }
                else
                {
                    p=p+2*(dx-dy);
                    x=x+1*sign(x2-x1);
                }
                y=y+1*sign(y2-y1);
                i++;
            }
        }
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(start)
    {
        int p = ev->pos().x();
        int q = ev->pos().y();
        a[i] = p;
        b[i] = q;

        if(ev->button() == Qt::RightButton)
        {
           bresenham(a[i-1], b[i-1], a[0],b[0]);
           start = false;
        }
        else
        {
            if(i>0)
            {
                bresenham(a[i], b[i], a[i-1], b[i-1]);
            }
        }
        i++;
    }

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_clicked()
{
     color = QColorDialog::getColor();
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *ev)
{
    QRgb bg = qRgb(0,0,0);
    int p = ev->pos().x();
    int q = ev->pos().y();
    seedFill(p,q,bg);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::seedFill(int x, int y, QRgb bg)
{
    QRgb curr = img.pixel(x,y);
    if(curr == bg)
    {
        img.setPixel(x, y, color.rgb());
        seedFill(x+1, y, bg);
        seedFill(x-1, y, bg);
        seedFill(x, y+1, bg);
        seedFill(x, y-1, bg);
    }
}
