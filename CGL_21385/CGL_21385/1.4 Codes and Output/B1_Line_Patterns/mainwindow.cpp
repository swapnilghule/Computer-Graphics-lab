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
        if(i%2==0)
        {
            img.setPixel(a,b,qRgb(255,255,255));
        }
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
    DDALine1(x1,y1,x2,y2);
    ui->label->setPixmap(QPixmap::fromImage(img));
}
void MainWindow::DDALine1(int x1, int y1, int x2, int y2)
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
        if(i%10!=0)
        {
            img.setPixel(a,b,qRgb(255,255,255));
        }
        a=a+x;
        b=b+y;
        i=i+1;
    }
}
void MainWindow::on_pushButton_5_clicked()
{
    int x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    DDALine2(x1,y1,x2,y2);
    ui->label->setPixmap(QPixmap::fromImage(img));
}
void MainWindow::DDALine2(int x1, int y1, int x2, int y2)
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
void MainWindow::on_pushButton_3_clicked()
{
    int x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    DDALine3(x1,y1,x2,y2);
    ui->label->setPixmap(QPixmap::fromImage(img));
}
void MainWindow::DDALine3(int x1, int y1, int x2, int y2)
{


    float dx,dy,x,y;
    float lengh;

    if(abs(x2-x1) >=abs(y2-y1))
            lengh=abs(x2-x1);
    else
        lengh=abs(y2-y1);

    dx=(x2-x1)/lengh;
    dy=(y2-y1)/lengh;

    x=x1+0.5*sign(x2-x1);
    y=y1+0.5*sign(y2-y1);

    int i=1;int n=20;
    while(i<=lengh)
    {
        if(i%n!=0 && i%n!=1 && i%n!=2 && i%n!=3&& i%n!=4 && i%n!=5 &&i%n!=6)
        {
        img.setPixel(x,y,qRgb(25,250,140));
        }else if(i%n==3)
        {
          img.setPixel(x,y,qRgb(200,200,20));
        }
        x=x+dx;
        y=y+dy;
        i=i+1;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
    }


int MainWindow::sign(float d)
{
    if(d==0)
        return 0;
    else if(d>0)
        return 1;
    else return -1;
}

void MainWindow::on_pushButton_4_clicked()
{
    int x1,y1,x2,y2,w,wx,wy,y,x,m1,m2,m3,m4,abs1;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    w=ui->textEdit_5->toPlainText().toInt();
    if((y2-y1)<(x2-x1))
    {
        y=(w-1)/2;
        m1=y2-y1;
        m2=m1*m1;
        m3=(x2-x1);
        m4=m3*m3;
        abs1=abs(x2-x1);
        wy=y*sqrt(m2+m4)/abs1;
        for(int i=0;i<wy;i++)
        {
            DDALine2(x1,y1+i,x2,y2+i);
            DDALine2(x1,y1-i,x2,y2-i);
        }
    }
    else
    {
        x=(w-1)/2;
        m1=x2-x1;
        m2=m1*m1;
        m3=y2-y1;
        m4=m3*m3;
        abs1=abs(y2-y1);
        wx=x*sqrt(m2+m4)/abs1;
        for(int i=0;i<wx;i++)
        {
            DDALine2(x1+i,y1,x2+i,y2);
            DDALine2(x1-i,y1,x2+i,y2);
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}
