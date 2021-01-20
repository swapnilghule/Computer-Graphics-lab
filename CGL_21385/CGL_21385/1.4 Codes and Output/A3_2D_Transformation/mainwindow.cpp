#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
QImage img(400,400,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DDALine(0,199,399,199);
    DDALine(199,0,199,399);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() //translation
{
    int x1,y1,x2,y2,tx,ty;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    tx=ui->textEdit_5->toPlainText().toInt();
    ty=ui->textEdit_6->toPlainText().toInt();
    DDALine(199+x1,199+y1,199+x2,199+y2);

    int arr1[3][3]={{1,0,0},{0,1,0},{tx,ty,1}};
    int arr[2][3]={{x1,y1,1},{x2,y2,1}};

    multiplication(arr,arr1);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::DDALine(int x1, int y1, int x2, int y2)
{
    float length;
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

void MainWindow::multiplication(int arr[][3],int arr1[][3])
{
    int result[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            result[i][j]=0;
            for(int k=0;k<3;k++)
            {
                result[i][j]+=arr[i][k]*arr1[k][j];
            }
        }
    }
    DDALine(199+result[0][0],199+result[0][1],199+result[1][0],199+result[1][1]);
}



void MainWindow::on_pushButton_2_clicked() //scaling
{
    int x1,y1,x2,y2,tx,ty;

    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    tx=ui->textEdit_5->toPlainText().toInt();
    ty=ui->textEdit_6->toPlainText().toInt();
    DDALine(199+x1,199+y1,199+x2,199+y2);

    int arr[2][3]={{x1,y1,1},{x2,y2,1}};
    int arr2[3][3]={{tx,0,0},{0,ty,0},{0,0,1}};

    multiplication(arr,arr2);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_3_clicked() //rotation
{
    int x1,y1,x2,y2,d;
    float r;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    d=ui->textEdit_7->toPlainText().toInt();
    DDALine(199+x1,199+y1,199+x2,199+y2);

    r=d*(3.14/180);

    int arr[2][3]={{x1,y1,1},{x2,y2,1}};
    double arr3[3][3]={{cos(r),sin(r),0},{-sin(r),cos(r),0},{0,0,1}};
    mult(arr,arr3);
    ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::mult(int arr[][3], double arr3[][3])
{
    double result[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            result[i][j]=0;
            for(int k=0;k<3;k++)
            {
                result[i][j]+=arr[i][k]*arr3[k][j];
            }
        }
    }
    DDALine(199+result[0][0],199+result[0][1],199+result[1][0],199+result[1][1]);
}

void MainWindow::on_pushButton_4_clicked()
{
    int x1,y1,x2,y2;

    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    DDALine(199+x1,199+y1,199+x2,199+y2);
    ui->label->setPixmap(QPixmap::fromImage(img));
}
