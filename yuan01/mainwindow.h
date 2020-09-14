#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtGui>//需要使用gui中的内容，必须增加
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);//用于绘图

    void mouseReleaseEvent(QMouseEvent *);//用于检测鼠标的信号

private:
    Ui::MainWindow *ui;
    int a[20][20];//棋盘数组

        int isWin(int, int);

        int f1(int, int);

        int f2(int, int);

        int f3(int, int);

        int f4(int, int);

        int player;//记录下棋步数以便计算黑白子
};

#endif // MAINWINDOW_H
