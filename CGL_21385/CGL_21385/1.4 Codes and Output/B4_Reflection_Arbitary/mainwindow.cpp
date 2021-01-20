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

void MainWindow::on_pushButton_3_clicked()
{
    int x1,y1,x2,y2;
       x1=ui->textEdit->toPlainText().toInt();
       y1=ui->textEdit_2->toPlainText().toInt();
       x2=ui->textEdit_3->toPlainText().toInt();
       y2=ui->textEdit_4->toPlainText().toInt();
       DDALine(199+x1,199+y1,199+x2,199+y2);
       int arr[2][3]={{x1,y1,1},{x2,y2,1}};
       int arr1[3][3]={{0,1,0},{1,0,0},{0,0,1}};
       multiplication(arr,arr1);
    //   ui->label->setPixmap(QPixmap::fromImage(img));

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
    ui->label->setPixmap(QPixmap::fromImage(img));
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
void MainWindow::on_pushButton_clicked()
{
    int x1,y1,x2,y2;
       x1=ui->textEdit->toPlainText().toInt();
       y1=ui->textEdit_2->toPlainText().toInt();
       x2=ui->textEdit_3->toPlainText().toInt();
       y2=ui->textEdit_4->toPlainText().toInt();
       DDALine(199+x1,199+y1,199+x2,199+y2);
       int arr[2][3]={{x1,y1,1},{x2,y2,1}};
       int arr1[3][3]={{1,0,0},{0,-1,0},{0,0,1}};
       multiplication(arr,arr1);
      // ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::on_pushButton_2_clicked()
{
    int x1,y1,x2,y2;
       x1=ui->textEdit->toPlainText().toInt();
       y1=ui->textEdit_2->toPlainText().toInt();
       x2=ui->textEdit_3->toPlainText().toInt();
       y2=ui->textEdit_4->toPlainText().toInt();
       DDALine(199+x1,199+y1,199+x2,199+y2);
       int arr[2][3]={{x1,y1,1},{x2,y2,1}};
       int arr1[3][3]={{-1,0,0},{0,1,0},{0,0,1}};
       multiplication(arr,arr1);
     //  ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::on_pushButton_4_clicked()
{
       int x1,y1,x2,y2;
       float r;
       double res1[2][3],res2[2][3],res3[2][3];

       x1=ui->textEdit->toPlainText().toInt();
       y1=ui->textEdit_2->toPlainText().toInt();
       x2=ui->textEdit_3->toPlainText().toInt();
       y2=ui->textEdit_4->toPlainText().toInt();
       r=ui->textEdit_5->toPlainText().toInt();

       r=r*(3.14/180.0);

       double arr[2][3]={{x1,y1,1},{x2,y2,1}};
       double arr1[3][3]={{1,0,0},{0,1,0},{-x1,-y1,1}};

       double a1[3][3]={{cos(r),sin(r),0},{-sin(r),cos(r),0},{0,0,1}};
       double a2[3][3]={{1,0,0},{0,1,0},{x1,y1,1}};

        DDALine(199+x1,199+y1,199+x2,199+y2);
       for(int i=0;i<2;i++)
       {
           for(int j=0;j<3;j++)
           {
               res1[i][j]=0;
               for(int k=0;k<3;k++)
               {
                   res1[i][j]+=arr[i][k]*arr1[k][j];
               }
           }
       }

       for(int i=0;i<2;i++)
       {
           for(int j=0;j<3;j++)
           {
               res2[i][j]=0;
               for(int k=0;k<3;k++)
               {
                   res2[i][j]+=res1[i][k]*a1[k][j];
               }
           }
       }

       for(int i=0;i<2;i++)
       {
           for(int j=0;j<3;j++)
           {
               res3[i][j]=0;
               for(int k=0;k<3;k++)
               {
                   res3[i][j]+=res2[i][k]*a2[k][j];
               }
           }
       }
      DDALine(199+res3[0][0],199+res3[0][1],199+res3[1][0],199+res3[1][1]);

}

void MainWindow::on_pushButton_5_clicked()
{
    int x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    DDALine(199+x1,199+y1,199+x2,199+y2);
   //  ui->label->setPixmap(QPixmap::fromImage(img));
}
