#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
QImage img(400,400,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    int x1,x2,y1,y2;

    x1=ui->plainTextEdit->toPlainText().toInt();
    y1=ui->plainTextEdit_2->toPlainText().toInt();
    x2=ui->plainTextEdit_3->toPlainText().toInt();
    y2=ui->plainTextEdit_4->toPlainText().toInt();
    dda_line(200,100,290,250);
     dda_line(200,100,110,250);
     dda_line(110,250,290,250);
    bresenham_circle(200,200,100);
    dda_circle(200,200,50);
    ui->label->setPixmap(QPixmap::fromImage(img));
}
void MainWindow::dda_line(int x1, int y1, int x2, int y2)
{
 float length,x,y,xx,yy,i;
 if(abs(x2-x1)>abs(y2-y1))
     length=abs(x2-x1);
 else
     length=abs(y2-y1);

 xx=(x2-x1)/length;
 yy=(y2-y1)/length;
x=x1+0.5;
y=y1+0.5;
i=1;
       while(i<=length)
     {
         img.setPixel(x,y,qRgb(205,155,0));
         x=x+xx;
         y=y+yy;
         i=i+1;
     }

}

void MainWindow::dda_circle(int xc, int yc, int r)
{
float a=r,b=0,e,sx=a,sy=b,x1=sx,y1=sy,x2,y2;
float i=0,val;
do
{
    val=pow(2,i);
    i++;
}while(val<r);
e=1/pow(2,i-1);
do
{
    x2=x1+e*y1;
    y2=y1-e*x2;
    img.setPixel((xc+x2),(yc-y2),qRgb(50,155,0));
    x1=x2;
    y1=y2;
}while((y1-sy)<e || (sx-x1)>e);
}

void MainWindow::bresenham_circle(int xc,int yc,int r)
{
    int p=3-2*r;
    int x=0,y=r;
    while(x<=y)
    {
        img.setPixel(xc+x,yc+y,qRgb(205,155,0));
        img.setPixel(xc+x,yc-y,qRgb(205,155,0));
        img.setPixel(xc-x,yc-y,qRgb(205,155,0));
        img.setPixel(xc-x,yc+y,qRgb(205,155,0));
        img.setPixel(xc+y,yc+x,qRgb(205,155,0));
        img.setPixel(xc+y,yc-x,qRgb(205,155,0));
        img.setPixel(xc-y,yc-x,qRgb(205,155,0));
        img.setPixel(xc-y,yc+x,qRgb(205,155,0));

   if(p<0)
       p=p+4*x+6;
   else
   {
       p=p+4*(x-y)+10;
       y=y-1;
   }
   x=x+1;
    }
}
