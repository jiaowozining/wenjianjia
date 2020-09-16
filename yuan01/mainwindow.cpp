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

    this->setWindowTitle("游戏界面");

    resize(880, 880);//构建一个大小为880的窗口

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

    p.begin(this);//指定当前窗口为绘图设备

    p.drawPixmap(0,0,width(),height(),QPixmap("://muban.png.jpg"));//设置背景图片

    p.setRenderHint(QPainter::Antialiasing, true);//反走样设置，防止图像边缘锯齿明显

    int i, j;

    for (i = 0; i < 21; i++)//绘制棋盘横竖线

    {

        p.drawLine(40, 40 + i * 40, 840, 40 + i * 40);//横线

        p.drawLine(40 + i * 40, 40, 40 + i * 40, 840);//竖线

    }

    QBrush brush;

    brush.setStyle(Qt::SolidPattern);//用笔刷画圆作为子

    for (i = 0; i < 20; i++)

    {

        for (j = 0; j < 20; j++)

        {

            if (a[i][j] == 1)

            {

                brush.setColor(Qt::black);//设置笔刷颜色为黑色

                p.setBrush(brush);

                p.drawEllipse(QPoint((i + 1) * 40, (j + 1) * 40), 15, 15);//黑子落子

            }

            else if (a[i][j] == 2)

            {

                brush.setColor(Qt::white);//设置笔刷颜色为白色

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

            a[x][y] = player++ % 2 +1;//设置棋盘数组数据，记录黑白子落子情况

        }

        if(isWin(x, y))

        {

            update();

            setEnabled(false);//下过子的地方无法再次下子，不能被更改



            if(player%2)

                QMessageBox::information(this, "result", "Black Win", QMessageBox::Ok);//下棋者轮到白子但游戏已结束则黑子胜利

            else
                QMessageBox::information(this, "result", "White Win", QMessageBox::Ok);//下棋者轮到黑子但游戏已结束则白子胜利


        }
        else  if(player==400)

            QMessageBox::information(this, "result", "board games", QMessageBox::Ok);//棋盘四百格，若下满则和棋

    }

    update();

}



int MainWindow::isWin(int x, int y)//判断是否胜利

{

     return f1(x, y) || f2(x, y) || f3(x, y) || f4(x ,y);

}



int MainWindow::f1(int x, int y)//判断横线是否连成六子

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



int MainWindow::f2(int x, int y)//判断竖线是否连成六子

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



int MainWindow::f3(int x, int y)//x负方向判断斜线是否连成六子

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



int MainWindow::f4(int x, int y)//x正方向判断斜线是否连成六子

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
