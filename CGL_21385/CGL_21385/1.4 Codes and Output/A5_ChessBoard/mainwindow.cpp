#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include "math.h"
#include "QColorDialog"
QImage img(400,400,QImage::Format_RGB888);
QColor color;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::bres(int x1, int y1, int x2, int y2)
{
    float x,y,dx,dy,p,i;
    float s1,s2;
            x=x1;
            y=y1;
            dx=abs(x2-x1);
            dy=abs(y2-y1);
            s1=sign(x2-x1);
            s2=sign(y2-y1);

            i=0;
            if(dx>=dy)
            {
                p=2*dy-dx;
                while(i<=dx)
                {
                    img.setPixel(x,y,qRgb(255,255,255));
                    if(p<0)
                    {
                        p=p+2*dy;
                    }
                    else
                    {
                        p=p+2*(dy-dx);
                        y=y+s2;
                    }
                    x=x+s1;
                    i++;
                }
            }
            else
            {
                p=2*dx-dy;
                while(i<=dy)
                {
                    img.setPixel(x,y,qRgb(255,255,255));
                    if(p<0)
                    {
                        p=p+2*dx;
                    }
                    else
                    {
                        p=p+2*(dx-dy);
                        x=x+s1;
                    }
                    y=y+s2;
                    i++;
                }
            }

}

int MainWindow::sign(int x)
{
    if(x==0)
        return 0;
    else if(x<0)
        return -1;
    else
        return 1;
}

void MainWindow::rotation(int x1, int y1, int x2, int y2, float a)
{
    double r1[2][3],r2[2][3],r3[2][3];
    double t1[2][3]={{x1,y1,1},{x2,y2,1}};
    double t2[3][3]={{1,0,0},{0,1,0},{-200,-200,1}};
    double t3[3][3]={{cos(a),sin(a),0},{-sin(a),cos(a),0},{0,0,1}};
    double t4[3][3]={{1,0,0},{0,1,0},{200,200,1}};
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            r1[i][j]=0;
            for(int k=0;k<3;k++)
            {
                r1[i][j]+=t1[i][k]*t2[k][j];
            }
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            r2[i][j]=0;
            for(int k=0;k<3;k++)
            {
                r2[i][j]+=r1[i][k]*t3[k][j];
            }
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            r3[i][j]=0;
            for(int k=0;k<3;k++)
            {
                r3[i][j]+=r2[i][k]*t4[k][j];
            }
        }
    }
    bres(r3[0][0],r3[0][1],r3[1][0],r3[1][1]);

}

void MainWindow::mouseDoubleClickEvent(QMouseEvent * ev)
{
    QRgb bg= qRgb(0,0,0);
    int p=ev->pos().x();
    int q=ev->pos().y();
    seedFill(p,q,bg);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::seedFill(int x, int y, QRgb bg)
{
    QRgb curr=img.pixel(x,y);
    if(bg==curr)
    {
        img.setPixel(x,y,qRgb(255,255,255));
        seedFill(x+1,y,bg);
         seedFill(x-1,y,bg);
          seedFill(x,y+1,bg);
           seedFill(x,y-1,bg);
    }
}


void MainWindow::on_pushButton_clicked()
{
    bres(150,100,150,300);
    bres(100,100,100,300);
    bres(200,100,200,300);
    bres(250,100,250,300);
    bres(300,100,300,300);

    bres(100,100,300,100);
    bres(100,150,300,150);
    bres(100,200,300,200);
    bres(100,250,300,250);
    bres(100,300,300,300);
}

void MainWindow::on_pushButton_2_clicked()
{
    for(int i=0;i<400;i++)
    {
        for(int j=0;j<400;j++)
        {
            img.setPixel(i,j,qRgb(0,0,0));
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_3_clicked()
{
    float r;
    r=45*(3.14/180);
    rotation(150,100,150,300,r);
   rotation(100,100,100,300,r);
   rotation(200,100,200,300,r);
   rotation(250,100,250,300,r);
   rotation(300,100,300,300,r);

    rotation(100,100,300,100,r);
    rotation(100,150,300,150,r);
    rotation(100,200,300,200,r);
   rotation(100,250,300,250,r);
 rotation(100,300,300,300,r);
 ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_4_clicked()
{
    color=QColorDialog::getColor();
}
