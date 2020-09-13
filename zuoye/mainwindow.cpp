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
}
