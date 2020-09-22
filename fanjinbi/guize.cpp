#include <QPixmap>
#include <QPaintEvent>
#include <QWidget>
#include "guize.h"
#include <QPainter>

guize::guize(QWidget * parent) : QWidget(parent)
{
    resize(320,588);

    this->setWindowTitle("规则");//更改窗口名字

}

void guize::paintEvent(QPaintEvent *)//绘图函数
{
    QPainter d(this);//设一个参数p

    d.begin(this);//指定当前窗口为绘图设备

    d.drawPixmap(0,0,width(),height(),QPixmap("://res/guizebj.jpg"));//设置背景图片

}
