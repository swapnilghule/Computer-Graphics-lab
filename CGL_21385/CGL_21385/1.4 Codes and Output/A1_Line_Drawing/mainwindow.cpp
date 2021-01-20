#include "mainwindow.h"
#include "ui_mainwindow.h"
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
   //img.setPixel(50,150,qRgb(255,255,255));
    int x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    DDALine(x1,y1,x2,y2);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::DDALine(int x1, int y1, int x2, int y2)
{
    int length;
    if(abs(x2-x1)>abs(y2-y1))
        length=abs(x2-x1);
    else
        length=abs(y2-y1);

    float x,y;
    x=(x2-x1)/length;
    y=(y2-y1)/length;

    float a,b;
    a=x1;
    b=y1;

    int i=1;

    while(i<=length)
    {
        img.setPixel(a,b,qRgb(255,255,255));
        a=a+x;
        b=b+y;
        i=i+1;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    int x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    Bresenhams(x1,y1,x2,y2);
    ui->label->setPixmap(QPixmap::fromImage(img));
}
void MainWindow::Bresenhams(int x1, int y1, int x2, int y2)
{
    int x,y,s1,s2;
    float dx,dy,e;
    x=x1;
    y=y1;
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    s1=sign(x2-x1);
    s2=sign(y2-y1);
    int temp,flag;
    if(dy>dx)
    {
        temp=dx;
        dx=dy;
        dy=temp;
        flag=1;
    }
    else
    {
        flag=0;
    }
    e=2*dx-dy;
    for(int i=1;i<=dx;i++)
    {
        img.setPixel(x,y,qRgb(0,255,0));
        while(e>0)
        {
            if(flag==1)
            {
                x=x+s1;
            }
            else
            {
                y=y+s2;
            }
            e=e-2*dx;
        }
        if(flag==1)
        {
            y=y+s2;
        }
        else
        {
            x=x+s1;
        }
        e=e+2*dy;
    }

}

int MainWindow::sign(int x)
{
    if(x<0)
    {
        return -1;
    }
    else if(x==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    Bresenhams(100,100,300,100);
    Bresenhams(100,100,100,300);
    Bresenhams(100,300,300,300);
    Bresenhams(300,100,300,300);
    Bresenhams(150,150,250,150);
    Bresenhams(150,150,150,250);
    Bresenhams(150,250,250,250);
    Bresenhams(250,150,250,250);
    DDALine(200,100,100,200);
    DDALine(200,100,300,200);
    DDALine(100,200,200,300);
    DDALine(300,200,200,300);
    ui->label->setPixmap(QPixmap::fromImage(img));
}
