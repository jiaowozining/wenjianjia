#include "subwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    subwidget w;
    w.show();

    return a.exec();
}
