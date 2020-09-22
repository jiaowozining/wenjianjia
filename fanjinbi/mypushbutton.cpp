#include "mypushbutton.h"
#include <QPropertyAnimation>   //qt动态属性
#include<QDebug>

MyPushButton::MyPushButton(QString zc,QString anxia)
{
    //保存正常显示路径和选中后的显示路径
    this->zcl = zc;
    this->anxial = anxia;

    QPixmap q;
     //加载图片
    bool r = q.load(zc);
    if(!r)
    {
       qDebug() << "图片加载失败";
       return;
       /*打印出出错的位置
        * QString str=QString ("%1 图片加载失败").arg(this->normalImg);
        * qDebug()<<str;
        * return;
        * */
    }

    //设置图片固定大小
    this->setFixedSize( q.width(),q.height());

    //设置不规则图片样式实现透明贴图，不加会有小框
    this->setStyleSheet("QPushButton{border:0px;}");

    //设置图标
    this->setIcon(q);

    //设置图标大小
    this->setIconSize(QSize(q.width(),q.height()));
}

  //先设置向上弹跳
void MyPushButton::jumpdow(){

    //创建动态对象
    QPropertyAnimation *action= new QPropertyAnimation(this,"geometry");

    //设置动画时间间隔
    action->setDuration(150);

    //开始位置
    action->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //结束位置
    action->setEndValue(QRect(this->x(),this->y()+15,this->width(),this->height()));

    //设置弹跳曲线
    action->setEasingCurve(QEasingCurve::OutBounce);//弹跳效果

    //执行动画
    action->start();
}

//设置向上弹跳
void MyPushButton::jumpup(){

    //创建动态对象
    QPropertyAnimation *action= new QPropertyAnimation(this,"geometry");

    //设置动画时间间隔
    action->setDuration(150);

    //开始位置
    action->setStartValue(QRect(this->x(),this->y()+15,this->width(),this->height()));
    //结束位置
    action->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));

    //设置弹跳曲线
    action->setEasingCurve(QEasingCurve::OutBounce);//弹跳效果

    //执行动画
    action->start();
}

//鼠标按下按钮
void MyPushButton::mousePressEvent(QMouseEvent *event)
{
    if(this->anxial != "") //传入的按下图片不为空 说明需要有按下状态，切换图片
    {
        QPixmap q1;
        bool r1 = q1.load(this->anxial);
        if(!r1)
        {
           qDebug() << "图片加载失败";
           return;
           /*打印出出错的位置
            * QString str=QString ("%1 图片加载失败").arg(this->normalImg);
            * qDebug()<<str;
            * return;
            * */
        }

        //设置图片固定大小
        this->setFixedSize( q1.width(),q1.height());

        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px;}");

        //设置不规则透明贴图，否则图片会带有小框
        this->setIcon(q1);

        //设置图标大小
        this->setIconSize(QSize(q1.width(),q1.height()));

    }

    //让父类执行其他内容
    return QPushButton::mousePressEvent(event);

}

void MyPushButton::mouseReleaseEvent(QMouseEvent *event)
{
    if(this->anxial != "") //传入的按下图片不为空 说明需要有按下状态，切换成初始图片
    {
        QPixmap q1;
        bool e1 = q1.load(this->zcl);
        if(!e1)
        {
           qDebug() << "图片加载失败";
           return;
           /*打印出出错的位置
            * QString str=QString ("%1 图片加载失败").arg(this->normalImg);
            * qDebug()<<str;
            * return;
            * */
        }

        //设置图片固定大小
        this->setFixedSize( q1.width(),q1.height());

        //设置不规则透明贴图，否则图片会带有小框
        this->setStyleSheet("QPushButton{border:0px;}");

        //设置图标
        this->setIcon(q1);

        //设置图标大小
        this->setIconSize(QSize(q1.width(),q1.height()));

    }

    //让父类执行其他内容
    return QPushButton::mouseReleaseEvent(event);

}
