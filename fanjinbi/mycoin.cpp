#include "mycoin.h"
#include <QDebug>
#include <QPixmap>
#include <QTimer>

MyCoin::MyCoin(QWidget *parent) : QPushButton(parent)
{

}

MyCoin::MyCoin(QString btnImg)
{
    //加载金币/银币的图片到pixmap中
    QPixmap pixmap;
    bool ret=pixmap.load(btnImg);
    if(!ret)
    {
//        QString str=QString("图片 %1 加载失败").arg(btnImg);
//        qDebug()<<str;
        qDebug()<<"加载金币对象图片失败";
        return;
    }
    //设置金币大小
    this->setFixedSize(pixmap.width(),pixmap.height());
    //将金币的边框设为零像素
    this->setStyleSheet("QPushButton(border:0px)");
    //将金币/银币的图片放到MyCoin中
    this->setIcon(pixmap);
    //设置MyCoin中金币/银币的大小
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));

    //初始化定时器
    timer1=new QTimer(this);
    timer2=new QTimer(this);

    isWin=false;
    //点击金币，实现翻转
    //定时器启动30s后会发送timeout信号
    connect(timer1,&QTimer::timeout,[=]()
    {
        QPixmap pixmap;
        QString str=QString(":/image/coin%1.png").arg(this->min++);
        bool ret=pixmap.load(str);
        if(!ret)
        {
            qDebug()<<"金币翻转失败";
            return;
        }

        //设置金币大小
        this->setFixedSize(pixmap.width(),pixmap.height());
        //将金币的边框设为零像素
        this->setStyleSheet("QPushButton(border:0px)");
        //将金币/银币的图片放到MyCoin中
        this->setIcon(pixmap);
        //设置MyCoin中金币/银币的大小
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));

        //翻完后，重置min
        if(this->min>this->max)
        {
            this->min=1;
            isAnimation=false;
            timer1->stop();
        }
    });

    //反面翻到正面
    connect(timer2,&QTimer::timeout,[=]()
    {
        QPixmap pixmap;
        QString str=QString("://image/coin%1.png").arg(this->max--);
        bool ret=pixmap.load(str);
        if(!ret)
        {
            qDebug()<<"银币翻转失败";
            return;
        }

        //设置金币大小
        this->setFixedSize(pixmap.width(),pixmap.height());
        //将金币的边框设为零像素
        this->setStyleSheet("QPushButton(border:0px)");
        //将金币/银币的图片放到MyCoin中
        this->setIcon(pixmap);
        //设置MyCoin中金币/银币的大小
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));

        //翻完后，重置min
        if(this->max<this->min)
        {
            this->max=8;
            isAnimation=false;
            timer2->stop();
        }
    });

}

//点击金币后，改变币的正反面标志
void MyCoin::changeFlag()
{
    //如果是正面
    if(this->flag)
    {
        //定时器开始作用
        timer1->start(30);
        //开始执行翻转动画
        isAnimation=true;
        this->flag=false;
    }
    //如果是反面
    else
    {
        timer2->start(30);
        //开始执行翻转动画
        isAnimation=true;
        this->flag=true;
    }
}

void MyCoin::mousePressEvent(QMouseEvent *e)
{
    //如果正在执行翻转动画，就锁定金币按钮，使得点击金币，不会翻转
    if(this->isAnimation||this->isWin)
    {
        return ;
    }
    else
    {
        return QPushButton::mousePressEvent(e);
    }
}
