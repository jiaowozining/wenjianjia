#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    }

    update();

}
