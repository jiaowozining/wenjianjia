#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include <QPixmap>
#include <QPaintEvent>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(840, 840);//构建一个大小为840的窗口

       memset(a, 0, 20 * 20 * sizeof(int));//分配内存

       player = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)//绘图函数

{

    QPainter p(this);//设一个参数p

    p.setRenderHint(QPainter::Antialiasing, true);//反走样设置，防止图像边缘锯齿明显

    int i, j;

    for (i = 0; i < 21; i++)//绘制棋盘横竖线

    {

        p.drawLine(20, 20 + i * 40, 820, 20 + i * 40);//横线

        p.drawLine(20 + i * 40, 20, 20 + i * 40, 820);//竖线

    }



    QBrush brush;

    brush.setStyle(Qt::SolidPattern);//用笔刷画圆作为子

    for (i = 0; i < 20; i++)

    {

        for (j = 0; j < 20; j++)

        {

            if (a[i][j] == 1)

            {

                brush.setColor(Qt::black);

                p.setBrush(brush);

                p.drawEllipse(QPoint((i + 1) * 40, (j + 1) * 40), 15, 15);//黑子落子

            }

            else if (a[i][j] == 2)

            {

                brush.setColor(Qt::white);

                p.setBrush(brush);

                p.drawEllipse(QPoint((i + 1) * 40, (j + 1) * 40), 15, 15);//白子落子

            }

        }

    }

}



void MainWindow::mouseReleaseEvent(QMouseEvent *e)

{

    int x, y;

    if(e->x() >= 20 && e->x() < 820 && e->y() >= 20 && e->y() < 820)//落点在棋盘内

    {

        x = (e->x() - 20) / 40;

        y = (e->y() - 20) / 40;

        if (!a[x][y])

        {

            a[x][y] = player++ % 2 +1;

        }

        if(isWin(x, y))

        {

            update();

            setEnabled(false);

            QMessageBox::information(this, "Win", "Win", QMessageBox::Ok);

        }

    }

    update();

}



int MainWindow::isWin(int x, int y)

{

     return f1(x, y) || f2(x, y) || f3(x, y) || f4(x ,y);

}



int MainWindow::f1(int x, int y)//判断横线

{

    int i;

    for (i = 0; i < 6; i++)

    {

        if(y - i >= 0 &&

           y + 5 - i <= 0xF &&

           a[x][y - i] == a[x][y + 1 - i] &&

           a[x][y - i] == a[x][y + 2 - i] &&

           a[x][y - i] == a[x][y + 3 - i] &&

           a[x][y - i] == a[x][y + 4 - i] &&

           a[x][y - i] == a[x][y + 5 - i])

        return 1;

    }

    return 0;

}



int MainWindow::f2(int x, int y)//判断竖线

{

    int i;

    for (i = 0; i < 6; i++)

    {

        if(x - i >= 0 &&

           x + 5 - i <= 0xF &&

           a[x - i][y] == a[x + 1 - i][y] &&

           a[x - i][y] == a[x + 2 - i][y] &&

           a[x - i][y] == a[x + 3 - i][y] &&

           a[x - i][y] == a[x + 4 - i][y] &&

           a[x - i][y] == a[x + 5 - i][y])

           return 1;

    }

    return 0;

}



int MainWindow::f3(int x, int y)//x负方向判断斜线

{

    int i;

    for (i = 0; i < 6; i++)

    {

        if(x - i >= 0 &&

           y - i >= 0 &&

           x + 5 - i <= 0xF &&

           y + 5 - i <= 0xF &&

           a[x - i][y - i] == a[x + 1 - i][y + 1 - i] &&

           a[x - i][y - i] == a[x + 2 - i][y + 2 - i] &&

           a[x - i][y - i] == a[x + 3 - i][y + 3 - i] &&

           a[x - i][y - i] == a[x + 4 - i][y + 4 - i] &&

           a[x - i][y - i] == a[x + 5 - i][y + 5 - i])

           return 1;

    }

    return 0;

}



int MainWindow::f4(int x, int y)//x正方向判断斜线

{

    int i;

    for (i = 0; i < 6; i++)

    {

        if(x + i <= 0xF &&

           y - i >= 0 &&

           x - 5 + i >= 0 &&

           y + 5 - i <= 0xF &&

           a[x + i][y - i] == a[x - 1 + i][y + 1 - i] &&

           a[x + i][y - i] == a[x - 2 + i][y + 2 - i] &&

           a[x + i][y - i] == a[x - 3 + i][y + 3 - i] &&

           a[x + i][y - i] == a[x - 4 + i][y + 4 - i] &&

           a[x + i][y - i] == a[x - 5 + i][y + 5 - i])

           return 1;

    }

    return 0;

}
