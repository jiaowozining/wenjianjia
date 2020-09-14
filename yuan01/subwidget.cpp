#include "subwidget.h"
#include <QPixmap>
#include <QPaintEvent>
subwidget::subwidget(QWidget *parent) : QWidget(parent)
{
    resize(500,500);

    this->setWindowTitle("六子棋");//更改窗口名字

    b.setParent(this);//指向当前窗口

    b.setText("开始游戏");//更改按钮名字

    b.move(200,450);

     b.show();//显示按钮

    connect(&b,&QPushButton::clicked,this,&subwidget::changewin);//鼠标点击按钮则跳转窗口

}

void subwidget::paintEvent(QPaintEvent *)//绘图函数
{
    QPainter d(this);//设一个参数p

    d.begin(this);//指定当前窗口为绘图设备

    d.drawPixmap(0,0,width(),height(),QPixmap("://qi.jpg.png"));//设置背景图片

}

void subwidget::changewin(){

     w.show();//显示游戏窗口
    this->hide();//隐藏当前窗口
}
