#include "dataconfig.h"
#include <QDebug>
#include "dataconfig.h"

dataConfig::dataConfig(QObject *parent)
    : QObject(parent)
{
    //第一关卡
    //1代表金币，0代表银币
    //用s1储存第一关卡的金银币分布情况

     int s1[4][4];
     for(int i=0;i<4;i++){
         for(int j=0;j<4;j++){
             if((j==2&&i==0)||((j==3)&&(i==0||i==1)))
                 s1[i][j]=0;
             else  s1[i][j]=1;
         }
     }

    QVector<QVector<int>> w;
    int k;
    int h;
    for(k=0;k<4;k++)
    {
        //先用w1来存储一维数组
        QVector<int> w1;
        for(h=0;h<4;h++)
        {
            //s1插入QVector中
            w1.push_back(s1[k][h]);
        }
        //将一维数组w1插入w中
        w.push_back(w1);
    }

    //插入数组
    mData.insert(1,w);

    //第二关

    int s2[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if((i==1&&j==1)||((i==2)&&(j==1||j==2))||(i==3&&j==0))
                s2[i][j]=0;
            else s2[i][j]=1;
        }
    }

      //vector储存的是指向对象的指针，不会调用析构函数，对值进行清空
    w.clear();

    for(k=0;k<4;k++)
    {
        QVector<int> w1;
        for(h=0;h<4;h++)
        {
            w1.push_back(s2[k][h]);
        }
        w.push_back(w1);
    }

    mData.insert(2,w);

    //第三关

     int  s3[4][4];
     for(int i=0;i<4;i++){
         for(int j=0;j<4;j++){
             if(i==0||i==3||j==0||j==3)
                 s3[i][j]=0;
             else s3[i][j]=1;
         }
     }

      //vector储存的是指向对象的指针，不会调用析构函数，对值进行清空
    w.clear();

    for(k=0;k<4;k++)
    {
        QVector<int> w1;
        for(h=0;h<4;h++)
        {
            w1.push_back(s3[k][h]);
        }
        w.push_back(w1);
    }

    mData.insert(3,w);

    //第四关

   int  s4[4][4];
   for(int i=0;i<4;i++){
       for(int j=0;j<4;j++){
           if((i==0&&j==2)||((i==1)&&(j==2||j==3))||((i==2)&&(j==0||j==1))||(i==3&&j==1))
               s4[i][j]=0;
           else s4[i][j]=1;
       }
   }

    w.clear();

    for(k=0;k<4;k++)
    {
        QVector<int> w1;
        for(h=0;h<4;h++)
        {
            w1.push_back(s4[k][h]);
        }
        w.push_back(w1);
    }

    mData.insert(4,w);


    //第五关

   int  s5[4][4];
   for(int i=0;i<4;i++){
       for(int j=0;j<4;j++){
           if(((i==0)&&(j==0||j==3))||((i==3)&&(j==0||j==3)))
               s5[i][j]=1;
           else s5[i][j]=0;
       }
   }

    //vector储存的是指向对象的指针，不会调用析构函数，对值进行清空
  w.clear();

  for(k=0;k<4;k++)
  {
      QVector<int> w1;
      for(h=0;h<4;h++)
      {
          w1.push_back(s5[k][h]);
      }
      w.push_back(w1);
  }

  mData.insert(5,w);

        //第六关


 int s6[4][4];
 for(int i=0;i<4;i++){
     for(int j=0;j<4;j++){
         if(((i==0)&&(j==0||j==3))||((i==3)&&(j==0||j==3))||((i==1)&&(j==1||j==2))||((i==2)&&(j==1||j==2)))
             s6[i][j]=1;
         else s6[i][j]=0;
     }
 }

    //vector储存的是指向对象的指针，不会调用析构函数，对值进行清空
  w.clear();

  for(k=0;k<4;k++)
  {
      QVector<int> w1;
      for(h=0;h<4;h++)
      {
          w1.push_back(s6[k][h]);
      }
      w.push_back(w1);
  }

  mData.insert(6,w);


       //第七关


  int s7[4][4];
  for(int i=0;i<4;i++){
          for(int j=0;j<4;j++){
      if((i==0&&j==3)||(i==1&&j==2)||(i==2&&j==1)||(i==3&&j==0))
          s7[i][j]=0;
      else s7[i][j]=1;
  }
  }

    //vector储存的是指向对象的指针，不会调用析构函数，对值进行清空
  w.clear();

  for(k=0;k<4;k++)
  {
      QVector<int> w1;
      for(h=0;h<4;h++)
      {
          w1.push_back(s7[k][h]);
      }
      w.push_back(w1);
  }

  mData.insert(7,w);

  //第八关

   int s8[4][4];
   for(int i=0;i<4;i++){
       for(int j=0;j<4;j++){
           if(((i==0)&&(j==0||j==2))||(i==1&&j==3)||(i==2&&j==0)||((i==3)&&(j==1||j==3)))
               s8[i][j]=1;
           else s8[i][j]=0;
       }
   }

    //vector储存的是指向对象的指针，不会调用析构函数，对值进行清空
  w.clear();

  for(k=0;k<4;k++)
  {
      QVector<int> w1;
      for(h=0;h<4;h++)
      {
          w1.push_back(s8[k][h]);
      }
      w.push_back(w1);
  }

  mData.insert(8,w);

  //第九关

  int s9[4][4];
  for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
          if(((j==0)&&(i==0||i==3))||(j==1&&i==1)||((j==2)&&(i==1||i==3))||((j==3)&&(i==1||i==3)))
              s9[i][j]=1;
          else s9[i][j]=0;
      }
  }
    //vector储存的是指向对象的指针，不会调用析构函数，对值进行清空
  w.clear();

  for(k=0;k<4;k++)
  {
      QVector<int> w1;
      for(h=0;h<4;h++)
      {
          w1.push_back(s9[k][h]);
      }
      w.push_back(w1);
  }

  mData.insert(9,w);

  //第十关

  int s10[4][4];
  for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
          if((j==0&&i==2)||((j==1)&&(i==0||i==1))||((j==2)&&(i==2||i==3))||(j==3&&i==1))
              s10[i][j]=0;
          else s10[i][j]=1;
      }
  }

    //vector储存的是指向对象的指针，不会调用析构函数，对值进行清空
  w.clear();

  for(k=0;k<4;k++)
  {
      QVector<int> w1;
      for(h=0;h<4;h++)
      {
          w1.push_back(s10[k][h]);
      }
      w.push_back(w1);
  }

  mData.insert(10,w);

  //第十一关
 int  s11[4][4];
 for(int i=0;i<4;i++){
     for(int j=0;j<4;j++){
         if(((i==0)&&(j==0||j==3))||((i==3)&&(j==0||j==3))||((i==1)&&(j==1||j==2))||((i==2)&&(j==1||j==2)))
             s11[i][j]=0;
         else s11[i][j]=1;
     }
 }

    //vector储存的是指向对象的指针，不会调用析构函数，对值进行清空
  w.clear();

  for(k=0;k<4;k++)
  {
      QVector<int> w1;
      for(h=0;h<4;h++)
      {
          w1.push_back(s11[k][h]);
      }
      w.push_back(w1);
  }

  mData.insert(11,w);

  //第十二关


 int s12[4][4];
 for(int i=0;i<4;i++){
     for(int j=0;j<4;j++){
         if(j==2||((j==0)&&(i==1||i==2)))
             s12[i][j]=1;
         else s12[i][j]=0;
     }
 }

    //vector储存的是指向对象的指针，不会调用析构函数，对值进行清空
  w.clear();

  for(k=0;k<4;k++)
  {
      QVector<int> w1;
      for(h=0;h<4;h++)
      {
          w1.push_back(s12[k][h]);
      }
      w.push_back(w1);
  }

  mData.insert(12,w);

  //第十三关

 int s13[4][4];
 for(int i=0;i<4;i++){
     for(int j=0;j<4;j++){
         if(((i==0)&&(j==1||j==2))||((i==3)&&(j==1||j==2)))
             s13[i][j]=1;
         else s13[i][j]=0;
     }
 }

    //vector储存的是指向对象的指针，不会调用析构函数，对值进行清空
  w.clear();

  for(k=0;k<4;k++)
  {
      QVector<int> w1;
      for(h=0;h<4;h++)
      {
          w1.push_back(s13[k][h]);
      }
      w.push_back(w1);
  }

  mData.insert(13,w);

  //第十四关
 int s14[4][4];
 for(int i=0;i<4;i++){
     for(int j=0;j<4;j++){
         if((j==0&&i==1)||((j==1)&&(i==0||i==2))||(j==3&&i==2)||((j==2)&&(i==1||i==3)))
             s14[i][j]=0;
         else s14[i][j]=1;
     }
 }

    //vector储存的是指向对象的指针，不会调用析构函数，对值进行清空
  w.clear();

  for(k=0;k<4;k++)
  {
      QVector<int> w1;
      for(h=0;h<4;h++)
      {
          w1.push_back(s14[k][h]);
      }
      w.push_back(w1);
  }

  mData.insert(14,w);

  //第十五关


 int s15[4][4];
 for(int i=0;i<4;i++){
     for(int j=0;j<4;j++){
         if(((j==0)&&(i==1||i==2))||(j==1&&i==0)||(j==2&&i==0)||((j==3)&&(i==0||i==2)))
             s15[i][j]=1;
         else s15[i][j]=0;
     }
 }

    //vector储存的是指向对象的指针，不会调用析构函数，对值进行清空
  w.clear();

  for(k=0;k<4;k++)
  {
      QVector<int> w1;
      for(h=0;h<4;h++)
      {
          w1.push_back(s15[k][h]);
      }
      w.push_back(w1);
  }

  mData.insert(15,w);

  //第十六关
  int s16[4][4]={{0,1,1,0},
             {1,1,1,1},
             {1,1,1,1},
             {0,1,1,0}};

    //vector储存的是指向对象的指针，不会调用析构函数，对值进行清空
  w.clear();

  for(k=0;k<4;k++)
  {
      QVector<int> w1;
      for(h=0;h<4;h++)
      {
          w1.push_back(s16[k][h]);
      }
      w.push_back(w1);
  }

  mData.insert(16,w);

  //第十七关


 int s17[4][4]={{1,1,1,0},
             {0,0,1,0},
             {0,1,0,0},
             {0,1,1,1}};

    //vector储存的是指向对象的指针，不会调用析构函数，对值进行清空
  w.clear();

  for(k=0;k<4;k++)
  {
      QVector<int> w1;
      for(h=0;h<4;h++)
      {
          w1.push_back(s17[k][h]);
      }
      w.push_back(w1);
  }

  mData.insert(17,w);

  //第十八关


 int s18[4][4]={{1,0,0,0},
             {0,1,0,0},
             {0,0,1,0},
             {0,0,0,1}};

    //vector储存的是指向对象的指针，不会调用析构函数，对值进行清空
  w.clear();

  for(k=0;k<4;k++)
  {
      QVector<int> w1;
      for(h=0;h<4;h++)
      {
          w1.push_back(s18[k][h]);
      }
      w.push_back(w1);
  }

  mData.insert(18,w);

  //第十九关
  int s19[4][4]={{0,1,0,1},
                 {1,0,1,0},
                 {0,1,0,1},
                 {1,0,1,0}};




    //vector储存的是指向对象的指针，不会调用析构函数，对值进行清空
  w.clear();

  for(k=0;k<4;k++)
  {
      QVector<int> w1;
      for(h=0;h<4;h++)
      {
          w1.push_back(s19[k][h]);
      }
      w.push_back(w1);
  }

  mData.insert(19,w);

  //第二十关
  int s20[4][4];
  for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
          if(((j==1)&&(i==0||i==1))||((j==2)&&(i==1||i==2))||(j==3&&i==2))
              s20[i][j]=1;
          else s20[i][j]=0;
      }
  }

    //vector储存的是指向对象的指针，不会调用析构函数，对值进行清空
  w.clear();

  for(k=0;k<4;k++)
  {
      QVector<int> w1;
      for(h=0;h<4;h++)
      {
          w1.push_back(s20[k][h]);
      }
      w.push_back(w1);
  }

  mData.insert(20,w);


}

