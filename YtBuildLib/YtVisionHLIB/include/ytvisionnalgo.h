#ifndef YTVISIONNALGO_H
#define YTVISIONNALGO_H
#include "ythandqalgo.h"
//根据输入图形以及搜索卡尺位置确定满足条件的点
int YtSAPI  YtCaliberRulePointS(HObject &inim,CMvRotatedRect Seacerect,QVector<CMvPoint> &OutPoints,QVector<double> &OutGradient,int thVal=20,double sigma=1.0);
//根据先计算
int YtSAPI YtCalclRotaRect(CMvLineSeg insegLine,QVector<CMvRotatedRect> &OutRectc,int tSpitNumbe=10);

int YtSAPI YtGetLineRst(QVector<QVector<CMvPoint>> &inPoints,QVector<QVector<double>> &inGradient,QVector<CMvPoint> &RestGetPoints,QString tran,QString Sel);

int YtSAPI YtFitLine(QVector<CMvPoint> &RestGetPoints,CMvLineSeg &restline,double xiangailv);

int YtSAPI YtCalCleLineRest(QVector<QVector<CMvPoint>> &inPoints,QVector<QVector<double>> &inGradient,QString tranfirst,QString transec,double diflenmin,double diflenmax,QVector<CMvPoint> &outSectPoints,QVector<CMvPoint> &outSecPoints);

//计算点集到一条线的距离
int YtSAPI YtCalcLinewidth(CMvLineSeg &infirstLine, QVector<CMvPoint> &inSecPoints, double &twidth);
//根据旋转矩形完成点集的二次映射




#endif // YTVISIONNALGO_H
