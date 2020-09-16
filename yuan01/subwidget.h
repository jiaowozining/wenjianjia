#ifndef SUBWIDGET_H
#define SUBWIDGET_H
#include"mainwindow.h"
#include <QWidget>
#include <QPushButton>

class subwidget : public QWidget
{
    Q_OBJECT
public:

    explicit subwidget(QWidget *parent = nullptr);

    void changewin();//窗口显示调换函数

    void paintEvent(QPaintEvent *);//用于绘图

signals:

public slots:

private:
        QPushButton b;
        MainWindow w;

};

#endif // SUBWIDGET_H
