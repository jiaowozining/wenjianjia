#ifndef DATACONFIG_H
#define DATACONFIG_H

#include<QMap>
#include <QObject>
#include<QVector>

class dataConfig : public QObject
{
    Q_OBJECT

public:
   explicit dataConfig(QObject *parent = 0);

public:

    //int储存关卡的数目
    //用两个QVector来存储二维数组
    QMap<int, QVector< QVector<int> > >mData;

signals:

public slots:
};

#endif // DATACONFIG_H
