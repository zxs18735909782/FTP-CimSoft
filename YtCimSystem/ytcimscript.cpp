#include "ytcimscript.h"

#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QApplication>
#include <QSettings>


YtCimScript::YtCimScript(QObject *parent)
{
    connect(this, &YtCimScript::onSignalSendIndexOut, this, &YtCimScript::getSignalOut);
}

YtCimScript::~YtCimScript()
{

}

void YtCimScript::toPrintlog(QString logContent, QString color)
{
    if(color == "green")
    {
        toPrintLog(logContent, Qt::green);
    }

    else if(color == "red")
    {
        toPrintLog(logContent, Qt::red);
    }

    else if(color == "yellow")
    {
        toPrintLog(logContent, Qt::yellow);
    }
    else
    {
        toPrintLog(logContent, color);
    }
}

QString YtCimScript::toGetPanelID()
{
    QString PanelID = "";

    if(m_PanelIDList.size() != 0)
    {
        PanelID = m_PanelIDList.first();
        m_PanelIDList.pop_front();
        return PanelID;
    }


    QString ReadPath = QApplication::applicationDirPath() + "/CIM_Manger";

    QDir dir(ReadPath);
    if(!dir.exists())
    {
        dir.mkpath(dir.path());
    }

    QFile file(dir.path() + "/fileInfoList.txt");
    if(!file.exists())
    {
        return PanelID;
    }

    QString content = "";
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        content = file.readAll();

    }
    file.close();
    file.setFileName(dir.path() + "/fileInfoList_over.txt");
    if(file.exists())
    {
        file.remove();
    }

    file.rename(dir.path() + "/fileInfoList.txt", dir.path() + "/fileInfoList_over.txt");

    if(content.isEmpty())
    {
        return PanelID;
    }

    QStringList contentList = content.split("\n");
    for(int i = 0; i < contentList.size(); i++)
    {
        if(contentList.at(i) != "")
        {
            m_PanelIDList.push_back((contentList.at(i).split("/").last()).trimmed());
            m_BlobFileList.push_back(contentList.at(i));
        }
    }

    PanelID = m_PanelIDList.first();
    m_PanelIDList.pop_front();

    toPrintlog(QString(u8"CIM_SCRIPT:--------ʣ��ID����---------%1------blob�ļ�����-----%2").arg(m_PanelIDList.size()).arg(m_BlobFileList.size()), "green");
    return PanelID;
}

QStringList YtCimScript::toGetDefectInfo(QString PanelID, QString Factory, QString fillContent, QString time,int face_num, double scale_x,double scale_y)
{
    QStringList DefectInfoList;
    DefectInfoList.clear();
    if(PanelID.isEmpty())
    {
        return DefectInfoList;
    }

    QString blobPath = m_BlobFileList.first();
    m_BlobFileList.pop_front();

    if(blobPath.contains("\n"))
    {
        blobPath = blobPath.split("\n").first();
    }

    blobPath = blobPath.trimmed();

    QDir dir(blobPath);
    dir.setFilter(QDir::Files);
    dir.setSorting(QDir::Time);
    QStringList ytblobImList = {"*.ytblob"};
    QStringList ytblobNameList = dir.entryList(ytblobImList);

    YtAllBlob  tAllBlobInfo;
    //��ȡ����Сͼ
    QVector<QImage> OutImList;

    QString file1 = "", file2 = "";
    int i = 0;
    foreach(QString fileInfo , ytblobNameList)
    {
        if(fileInfo.contains("CA_"))
        {
            file1 = fileInfo;

            //�жϱ�־�ļ��Ƿ���ڣ��������ظ�¼��
            QFile file(dir.path() + "/" + file1 + ".txt");
            if(file.exists())
            {   i++;
                toPrintlog(QString(u8"CIM_SCRIPT:------------��־�ļ�����-------------%1")
                           .arg(dir.path() + "/" + file1 + ".txt") , "white");
                continue ;
            }

            break;
        }
    }

    if(face_num <= 0 || i == ytblobNameList.size() / face_num)
    {
        return DefectInfoList;
    }

    QDir imageDir(QApplication::applicationDirPath() + "/CIM_Manger/PARAM/FTP/FTP_UPLOAD_FILE/Image/" + PanelID);
    if(!imageDir.exists())
    {
        imageDir.mkpath(imageDir.path());
    }

    int C_Size = 5;
    if(file1 != "")
    {
        YTLoadBlobFile(tAllBlobInfo,dir.path() + "/" + file1);
        if(tAllBlobInfo.GetBlob.size() < 5)
        {
            C_Size = tAllBlobInfo.GetBlob.size();
        }


        toLoadSmallBlobIm(OutImList, dir.path() + "/" + file1.replace(".ytblob", ".ytblobim"));
        file1 = file1.replace(".ytblobim", ".ytblob");

        qDebug() << u8"CIM_SCRIPT:---------C��ȱ������----------" << C_Size << OutImList.size();
        toPrintlog(QString(u8"CIM_SCRIPT:------------C�����������ȱ��ͼ������-------------%1------ȱ������------%2")
                   .arg(OutImList.size()).arg(C_Size) , "white");
        for(int i = 0; i < C_Size; i++)
        {

            double width = tAllBlobInfo.GetBlob.at(i).Len1 * 2;             //������ *2 �ָ�Ϊԭ�еĳ���
            double height= tAllBlobInfo.GetBlob.at(i).Len2 * 2;
            double area  = width * height;
            double x_pos = abs(tAllBlobInfo.GetBlob.at(i).Pos.Center.x - tAllBlobInfo.m_GetPos[0].x) * scale_x;
            double y_pos = abs(tAllBlobInfo.GetBlob.at(i).Pos.Center.y - tAllBlobInfo.m_GetPos[0].y) * scale_y;

            QString ImageName;
            if(Factory.toLower() == u8"boe")
            {
                ImageName = QString("%1_%2_%3_C_%4.jpg").arg(PanelID).arg(QDateTime::currentDateTime().toString("yyyyMMdd"))
                        .arg(QDateTime::currentDateTime().toString("hhmmss")).arg(i);
            }
            else if(Factory.toLower() == u8"tm")
            {
                QString temTime = QDateTime::fromString(time, "yyyyMMddhhmmss").toString("yyyyMMdd_hhmmss");
                ImageName = QString("%1_%2_%3_%4_%5_%6_%7_%8_%9_%10_%11_%12.jpg").arg(PanelID).arg(fillContent).arg(i + 1)
                        .arg("DFT").arg("Main").arg("1").arg("@").arg("@").arg(x_pos).arg(y_pos).arg("@")
                        .arg(temTime);
            }


            if(i < OutImList.size())
            {
                OutImList.at(i).save(imageDir.path() + "/" + ImageName, "jpg");
            }
            DefectInfoList.append(QString("%1,%2,%3,%4,%5,%6,%7,%8").arg("CF").arg(i + 1).arg(width).arg(height).arg(area)
                                  .arg(x_pos).arg(y_pos).arg(ImageName));
        }

        //���ɱ�־�ļ�
        QFile file(dir.path() + "/" + file1 + ".txt");
        if(file.open(QIODevice::WriteOnly))
        {
            toPrintlog(QString(u8"CIM_SCRIPT:------------���ɱ�־�ļ�-------------%1").arg(dir.path() + "/" + file1 + ".txt") , "white");
            file.close();
        }
    }

    file2 = file1;
    file2 = file2.replace("CA_", "TA_");

    YTLoadBlobFile(tAllBlobInfo,dir.path() + "/" + file2);

    int T_Size = 5;
    if(file2 != "")
    {
        if(tAllBlobInfo.GetBlob.size() < 5)
        {
            T_Size = tAllBlobInfo.GetBlob.size();
        }

        OutImList.clear();
        QString FilePath = dir.path() + "/" + file2.replace(".ytblob", ".ytblobim");
        file2 = file2.replace(".ytblobim", ".ytblob");
        toLoadSmallBlobIm(OutImList, FilePath);
        toPrintlog(QString(u8"CIM_SCRIPT:�������ļ�·��-----------%1").arg(FilePath), "white");
        qDebug() << u8"CIM_SCRIPT:---------T��ȱ������----------" << T_Size << OutImList.size();
        toPrintlog(QString(u8"CIM_SCRIPT:------------T�����������ȱ��ͼ������-------------%1------ȱ������------%2")
                   .arg(OutImList.size()).arg(T_Size) , "white");
        for(int j = 0; j < T_Size; j++)
        {
            double width = tAllBlobInfo.GetBlob.at(j).Len1 * 2;             //������ *2 �ָ�Ϊԭ�еĳ���
            double height= tAllBlobInfo.GetBlob.at(j).Len2 * 2;
            double area  = width * height;
            double x_pos = abs(tAllBlobInfo.GetBlob.at(j).Pos.Center.x - tAllBlobInfo.m_GetPos[0].x) * scale_x;
            double y_pos = abs(tAllBlobInfo.GetBlob.at(j).Pos.Center.y - tAllBlobInfo.m_GetPos[0].y) * scale_y;

            //ͼ��洢���ļ�����
            QString ImageName;
            if(Factory.toLower() == u8"boe")
            {
                ImageName = QString("%1_%2_%3_TFT_%4.jpg").arg(PanelID).arg(QDateTime::currentDateTime().toString("yyyyMMdd"))
                        .arg(QDateTime::currentDateTime().toString("hhmmss")).arg(j);
            }
            else if(Factory.toLower() == u8"tm")
            {
                QString temTime = QDateTime::fromString(time, "yyyyMMddhhmmss").toString("yyyyMMdd_hhmmss");
                ImageName = QString("%1_%2_%3_%4_%5_%6_%7_%8_%9_%10_%11_%12.jpg").arg(PanelID).arg(fillContent).arg(C_Size + 1 + j)
                        .arg("DFT").arg("Sub").arg("1").arg("@").arg("@").arg(x_pos).arg(y_pos).arg("@")
                        .arg(temTime);
            }


            if(j < OutImList.size())
            {
                OutImList.at(j).save(imageDir.path() + "/" + ImageName, "jpg");
            }

            DefectInfoList.append(QString("%1,%2,%3,%4,%5,%6,%7,%8").arg("TFT").arg(C_Size + 1 + j).arg(width).arg(height)
                                  .arg(area).arg(x_pos).arg(y_pos).arg(ImageName));

        }

        //���ɱ�־�ļ�
        QFile file(dir.path() + "/" + file2 + ".txt");
        if(file.open(QIODevice::WriteOnly))
        {
            file.close();
        }
    }

    //�ָ�ʱ��
    QString fileTime  = (file1.split(".").first()).split("_").last();
    QString startTime = QDateTime::fromString(fileTime, "yyyyMMddhhmmss").addSecs(-5).toString("yyyyMMdd_hhmmss");
    QString endTime   = QDateTime::fromString(fileTime, "yyyyMMddhhmmss").toString("yyyyMMdd_hhmmss");

    DefectInfoList.append(startTime);
    DefectInfoList.append(endTime);

    if(C_Size == 0 && T_Size == 0)
    {
        DefectInfoList.append("OK");
    }
    else
    {
        DefectInfoList.append("NG");
    }

    DefectInfoList.append(imageDir.path());

    DefectInfoList.append(blobPath.split("/").at(3));

    return DefectInfoList;
}

QStringList YtCimScript::toGetBigImDefectInfo(QString PanelID, QString Factory, QString fillContent, QString time,int face_num, double scale_x, double scale_y)
{
    QStringList DefectInfoList;
    DefectInfoList.clear();
    if(PanelID.isEmpty())
    {
        return DefectInfoList;
    }

    QString blobPath = m_BlobFileList.first();
    m_BlobFileList.pop_front();

    if(blobPath.contains("\n"))
    {
        blobPath = blobPath.split("\n").first();
    }
    blobPath = blobPath.trimmed();

    QDir dir(blobPath);
    dir.setFilter(QDir::Files);
    dir.setSorting(QDir::Time);
    QStringList ytblobImList = {"*.ytblob"};
    QStringList ytblobNameList = dir.entryList(ytblobImList);


    YtAllBlob  tAllBlobInfo;
    QImage     cImage;
    //��ȡ����Сͼ
    //    QVector<QImage> OutImList;
    QString file1 = "", file2 = "";
    int i = 0;
    foreach(QString fileInfo , ytblobNameList)
    {
        if(fileInfo.contains("C0_"))
        {
            file1 = fileInfo;

            //�жϱ�־�ļ��Ƿ���ڣ��������ظ�¼��
            QFile file(dir.path() + "/" + file1 + ".txt");
            if(file.exists())
            {   i++;
                toPrintlog(QString(u8"CIM_SCRIPT:------------��־�ļ�����-------------%1")
                           .arg(dir.path() + "/" + file1 + ".txt") , "white");
                continue ;
            }

            break;
        }
    }

    if(face_num <= 0 || i == ytblobNameList.size() / face_num)
    {
        return DefectInfoList;
    }


    QDir imageDir(QApplication::applicationDirPath() + "/CIM_Manger/PARAM/FTP/FTP_UPLOAD_FILE/Image/" + PanelID);
    if(!imageDir.exists())
    {
        imageDir.mkpath(imageDir.path());
    }

    int C_Size = 5;

    if(file1 != "")
    {

//        YTLoadBlobFile(tAllBlobInfo,dir.path() + "/" + file1);
//        toPrintlog(QString(u8"CIM_SCRIPT:------------C��ȱ������111------%1").arg(tAllBlobInfo.GetBlob.size()) , "white");

        YtLoadYtImageH(cImage, tAllBlobInfo,dir.path() + "/" + file1.replace(".ytblob", ".ytimage"));
        file1 = file1.replace(".ytimage", ".ytblob");
        toPrintlog(QString(u8"CIM_SCRIPT:------------C��ȱ������------%1").arg(tAllBlobInfo.GetBlob.size()) , "white");

        if(tAllBlobInfo.GetBlob.size() < 5)
        {
            C_Size = tAllBlobInfo.GetBlob.size();
        }

        for(int i = 0; i < C_Size; i++)
        {
            double width = tAllBlobInfo.GetBlob.at(i).Len1 * 2;             //������ *2 �ָ�Ϊԭ�еĳ���
            double height= tAllBlobInfo.GetBlob.at(i).Len1 * 2;
            double area  = width * height;
            double x_pos = abs(tAllBlobInfo.GetBlob.at(i).Pos.Center.x - tAllBlobInfo.m_GetPos[0].x) * scale_x * 4;
            double y_pos = abs(tAllBlobInfo.GetBlob.at(i).Pos.Center.y - tAllBlobInfo.m_GetPos[0].y) * scale_y * 4;

            QString ImageName ;
            if(Factory.toLower() == u8"boe")
            {
                ImageName = QString("%1_%2_%3_C_%4.jpg").arg(PanelID).arg(QDateTime::currentDateTime().toString("yyyyMMdd"))
                        .arg(QDateTime::currentDateTime().toString("hhmmss")).arg(i);
            }
            else if(Factory.toLower() == u8"tm")
            {
                QString temTime = QDateTime::fromString(time, "yyyyMMddhhmmss").toString("yyyyMMdd_hhmmss");
                ImageName = QString("%1_%2_%3_%4_%5_%6_%7_%8_%9_%10_%11_%12.jpg").arg(PanelID).arg(fillContent).arg(i + 1)
                        .arg("DFT").arg("Main").arg("1").arg("1").arg("White").arg(x_pos).arg(y_pos).arg("A35")
                        .arg(temTime);
            }

            QImage cutImage = cImage.copy(tAllBlobInfo.GetBlob.at(i).Pos.Center.x - 100, tAllBlobInfo.GetBlob.at(i).Pos.Center.y - 100,
                                          200, 200);
            cutImage.save(imageDir.path() + "/" + ImageName, "jpg");

            DefectInfoList.append(QString("%1,%2,%3,%4,%5,%6,%7,%8").arg("CF").arg(i + 1).arg(width).arg(height).arg(area)
                                  .arg(x_pos).arg(y_pos).arg(ImageName));

            //B10 CIM ͼ����벿��
            //            QString type = QString::fromLocal8Bit(tAllBlobInfo.GetBlob.at(i).Type);
            //            toPrintlog(QString(u8"CIM_SCRIPT:---------C_ȱ������---------%1").arg(type), "white");

            //            if(type == u8"����")
            //            {
            //                DefectInfoList.append(QString("%1,%2,%3,%4,%5,%6,%7,%8,Black").arg("CF").arg(i + 1).arg(width).arg(height).arg(area)
            //                                      .arg(x_pos).arg(y_pos).arg(ImageName));
            //            }
            //            else if(type == u8"����")
            //            {
            //                DefectInfoList.append(QString("%1,%2,%3,%4,%5,%6,%7,%8,Crack").arg("CF").arg(i + 1).arg(width).arg(height).arg(area)
            //                                      .arg(x_pos).arg(y_pos).arg(ImageName));
            //            }
        }

        //���ɱ�־�ļ�
        QFile file(dir.path() + "/" + file1 + ".txt");
        if(file.open(QIODevice::WriteOnly))
        {
            toPrintlog(QString(u8"CIM_SCRIPT:------------���ɱ�־�ļ�-------------%1").arg(dir.path() + "/" + file1 + ".txt") , "white");
            file.close();
        }
    }

    QImage tImage;
    file2 = file1;
    file2 = file2.replace("C0_", "T0_");
//    YTLoadBlobFile(tAllBlobInfo,dir.path() + "/" + file2);
    int T_Size = 5;

    if(file2 != "")
    {


        QString FilePath = file2.replace(".ytblob", ".ytimage");
        YtLoadYtImageH(tImage, tAllBlobInfo,dir.path() + "/" + FilePath);
        file2 = file2.replace(".ytimage", ".ytblob");

        toPrintlog(QString(u8"CIM_SCRIPT:�������ļ�·��-----------%1").arg(FilePath), "white");
        toPrintlog(QString(u8"CIM_SCRIPT:------------T��ȱ������------%1").arg(T_Size) , "white");

        if(tAllBlobInfo.GetBlob.size() < 5)
        {
            T_Size = tAllBlobInfo.GetBlob.size();
        }

        for(int j = 0;j < T_Size; j++)
        {
            double width = tAllBlobInfo.GetBlob.at(j).Len1 * 2;             //������ *2 �ָ�Ϊԭ�еĳ���
            double height= tAllBlobInfo.GetBlob.at(j).Len1 * 2;
            double area  = width * height;
            double x_pos = abs(tAllBlobInfo.GetBlob.at(j).Pos.Center.x - tAllBlobInfo.m_GetPos[0].x) * scale_x * 4;
            double y_pos = abs(tAllBlobInfo.GetBlob.at(j).Pos.Center.y - tAllBlobInfo.m_GetPos[0].y) * scale_y * 4;

            //ͼ��洢���ļ�����
            QString ImageName;
            if(Factory.toLower() == u8"boe")
            {
                ImageName = QString("%1_%2_%3_TFT_%4.jpg").arg(PanelID).arg(QDateTime::currentDateTime().toString("yyyyMMdd"))
                        .arg(QDateTime::currentDateTime().toString("hhmmss")).arg(j);
            }
            else if(Factory.toLower() == u8"tm")
            {
                QString temTime = QDateTime::fromString(time, "yyyyMMddhhmmss").toString("yyyyMMdd_hhmmss");
                ImageName = QString("%1_%2_%3_%4_%5_%6_%7_%8_%9_%10_%11_%12.jpg").arg(PanelID).arg(fillContent).arg(C_Size + 1 + j)
                        .arg("DFT").arg("Sub").arg("1").arg("1").arg("White").arg(x_pos).arg(y_pos).arg("A35")
                        .arg(temTime);
            }

            QImage cutImage = tImage.copy(tAllBlobInfo.GetBlob.at(j).Pos.Center.x - 100, tAllBlobInfo.GetBlob.at(j).Pos.Center.y - 100,
                                          200 ,200);

            cutImage.save(imageDir.path() + "/" + ImageName, "jpg");


            DefectInfoList.append(QString("%1,%2,%3,%4,%5,%6,%7,%8").arg("TFT").arg(C_Size + 1 + j).arg(width).arg(height)
                                  .arg(area).arg(x_pos).arg(y_pos).arg(ImageName));

            //B10 CIMͼ���ϴ�����


            //            QString type = QString::fromLocal8Bit(tAllBlobInfo.GetBlob.at(j).Type);
            //            toPrintlog(QString(u8"CIM_SCRIPT:---------T _ȱ������---------%1").arg(type), "white");

            //            if(type == u8"����")
            //            {
            //                DefectInfoList.append(QString("%1,%2,%3,%4,%5,%6,%7,%8,Black").arg("TFT").arg(C_Size + 1 + j).arg(width).arg(height)
            //                                      .arg(area).arg(x_pos).arg(y_pos).arg(ImageName));
            //            }
            //            else if(type == u8"����")
            //            {
            //                DefectInfoList.append(QString("%1,%2,%3,%4,%5,%6,%7,%8,Crack").arg("TFT").arg(C_Size + 1 + j).arg(width).arg(height)
            //                                      .arg(area).arg(x_pos).arg(y_pos).arg(ImageName));
            //            }
        }
        //���ɱ�־�ļ�
        QFile file(dir.path() + "/" + file2 + ".txt");
        if(file.open(QIODevice::WriteOnly))
        {
            file.close();
        }
    }

    //�ָ�ʱ��
    QString fileTime  = (file1.split(".").first()).split("_").last();
    QString startTime = QDateTime::fromString(fileTime, "yyyyMMddhhmmss").addSecs(-5).toString("yyyyMMdd_hhmmss");
    QString endTime   = QDateTime::fromString(fileTime, "yyyyMMddhhmmss").toString("yyyyMMdd_hhmmss");

    DefectInfoList.append(startTime);
    DefectInfoList.append(endTime);

    if(C_Size == 0 && T_Size == 0)
    {
        DefectInfoList.append("OK");
        //        imageDir.removeRecursively();
    }
    else
    {
        DefectInfoList.append("NG");
    }

    DefectInfoList.append(imageDir.path());
    DefectInfoList.append(blobPath.split("/").at(3));

    return DefectInfoList;
}


void YtCimScript::toSleep(int msec)
{
    QTime ttimer;
    ttimer.start();
    while(ttimer.elapsed() < msec)
    {
        if(!m_RunState)
        {
            toPrintlog(u8"CIM_SCRIPT:------CIM������ֹ-----", "red");
            break;
        }
        QCoreApplication::processEvents();
    }
}

QString YtCimScript::toCombinaFtpContent(QString titleContent, QString splitSig1, QString FillSig, QString splitSig2)
{
    int len = titleContent.split(splitSig1).size();

    QString str = "";
    for(int i = 0; i < len; i++)
    {
        str += FillSig;
        if(i < len - 1)
        {
            str += splitSig2;
        }
    }

    return str;
}


QString YtCimScript::toFillSpecialSig(QString FillContent, QString splitSig1, QString fillSig, QString splitSig2, QString splitSig3)
{
    QString temStr = "";
    //�ȴ������ַ���
    QStringList stringList1 = FillContent.split(splitSig1);

    //����ַ���
    QStringList stringList2 = fillSig.split(splitSig2);

    foreach (QString fill_content, stringList2) {
        QString content = fill_content.split(splitSig3).first();
        int index = (fill_content.split(splitSig3).last()).toInt() - 1;

        if(index >= stringList1.size() || index < 0)
        {
            emit onSignalSendIndexOut(index + 1, content);
            return temStr;
        }
        stringList1[index] = content;
    }

    for(int i = 0; i < stringList1.size(); i++)
    {
        temStr += stringList1[i];
        if(i < stringList1.size() - 1)
        {
            temStr += splitSig1;
        }

    }

    return temStr;
}

QString YtCimScript::toGetTimepoint(int length)
{
    QString time = QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz");
    if(length >= time.size())
    {
        toPrintlog(u8"�������ȳ���", "red");
    }

    return time.mid(0,length);
}

QString YtCimScript::toGetTextContent(QString PanelID, QString filePath, QString fileType,QString MatchContent, bool isDel)
{
    QString retStr = "";
    if(PanelID.isEmpty())
    {
        return retStr;
    }

    QString fileInfo = QString("%1/%2.%3").arg(filePath).arg(PanelID).arg(fileType);
    toPrintlog(u8"CIM_SCRIPT:-------��ȡ�ļ�·��-------" + fileInfo, "yellow");
    QFile file(fileInfo);

    if(!file.exists())
    {
        return "null";
    }

    if(file.open(QIODevice::ReadOnly))
    {
        while(!file.atEnd())
        {
            QString readLine = file.readLine();
            if(readLine.contains(MatchContent))
            {
                retStr = readLine.split("=").last();
                retStr = retStr.replace("\n","");
                retStr = retStr.trimmed();
            }
        }
    }
    file.close();

    if(file.open(QIODevice::WriteOnly))
    {
        file.close();
    }

    if(isDel)
    {
        file.remove();
    }

    return retStr;
}

bool YtCimScript::toParseFileAndPut(QString filePath, QString fileType, QString FtpFilePath, QString unControlPath)
{
    QDir dir(filePath);
    if(!dir.exists())
    {
        toPrintlog(QString(u8"CIM_SCRIPT:---------�����ļ��в�����---------%1").arg(filePath), "red" );
        return false;
    }

    QFile file,file1,file2;
    file.setFileName(filePath + "/file.txt");
    file1.setFileName(filePath + "/imagefile.txt");
    file2.setFileName(filePath + "/dmy.txt");

    if(file.exists() && file1.exists() && file2.exists())
    {
            toPrintlog(QString(u8"CIM_SCRIPT:---------�ļ����ϴ�---------"), "yellow" );
            return true;

    }


    dir.setFilter(QDir::Files);
    QStringList filterList = fileType.split(";");
    QStringList fileNameList = dir.entryList(filterList);

    //����ϴ���·��
    QString upLoadPath = FtpFilePath + "@/" + unControlPath;

    int FileFlag = 0;           //�ļ����ͱ�־
    for(int i = 0; i < fileNameList.size(); i++)
    {
        QString var = fileNameList.at(i);
        //���������·��
        QString fileInfo = filePath + "/" + var;
        //�������˵��
        QString cmd;
        if(var.toLower().contains(".jpg") || var.toLower().contains(".png") || var.toLower().contains(".jpeg"))
        {
            FileFlag = 1;
            cmd = QString("PUT::%1#%2#%3#%4").arg(upLoadPath).arg(var).arg(fileInfo).arg("image");
        }
        else
        {
            FileFlag = 2;
            if(var.toLower().contains(".dmy"))
            {
                FileFlag = 3;
            }
            cmd = QString("PUT::%1#%2#%3#%4").arg(upLoadPath).arg(var).arg(fileInfo).arg("ascii");
        }

        if(!m_YtFTPNetWorkDo->CmdPro(cmd))
        {
            toPrintlog(QString(u8"CIM_SCRIPT:----------�ϴ��������ļ�ʧ��----------%1").arg(cmd), "red");
            return false;
        }

        toPrintlog(QString(u8"CIM_SCRIPT:----------�ϴ��������ļ��ɹ�----------%1").arg(cmd), "white");
    }

    //����ͼƬ�ϴ���ı�־
    if(FileFlag == 1)
    {
        file.setFileName(filePath + "/imagefile.txt");
        if(file.exists())
        {
            return true;
        }
        else
        {
            if(file.open(QIODevice::ReadWrite))
            {
                file.close();
            }
        }
    }

    //�����ļ��ϴ���ı�־
    if(FileFlag == 2)
    {
        file.setFileName(filePath + "/file.txt");
        if(file.exists())
        {
            return true;
        }
        else
        {
            if(file.open(QIODevice::ReadWrite))
            {
                file.close();
            }
        }
    }

    if(FileFlag == 3)
    {
        file.setFileName(filePath + "/dmy.txt");
        if(file.exists())
        {
            return true;
        }
        else
        {
            if(file.open(QIODevice::ReadWrite))
            {
                file.close();
            }
        }
    }

    return true;
}

QStringList YtCimScript::toGetFileList(QString filePath, QString FileType)
{
    QStringList tFileList;

    QDir dir(filePath);
    if(!dir.exists())
    {
        return tFileList;
    }

    QStringList filter;
    filter << FileType;
    dir.setFilter(QDir::Files | QDir::NoDotAndDotDot);
    dir.setSorting(QDir::Time);

    tFileList = dir.entryList(filter);
    return tFileList;
}


bool YtCimScript::toDownLoadFile(QString Panel_ID,QString FtpFilePath, QString SavePath, QString FileType)
{
    bool isConnect = m_YtFTPNetWorkDo->IsConnnect();

    QString SaveFile = QString("%1/%2.%3").arg(SavePath).arg(Panel_ID).arg(FileType);

    if(!isConnect)
    {
        if(!m_YtFTPNetWorkDo->ReConnect())
        {
            toPrintlog(u8"CIM_SCRIPT:-----FTP���������ӶϿ�,����-----", "red");
            return false;
        }
    }

    QFile file(SaveFile);
    if(file.exists())
    {
        file.remove();
        toPrintlog(u8"CIM_SCRIPT:-----�����ļ������ļ������-----", "yellow");
    }

    //�������  ����1:FTP����·��   ����2:���浽���ص�·��
    QString Cmd = QString("GET::%1#%2").arg(FtpFilePath).arg(SaveFile);
    toPrintlog(u8"FTP_SCRIPT:---------����ָ��--------------" + Cmd, "yellow");
    if(!m_YtFTPNetWorkDo->CmdPro(Cmd))
    {
        toPrintlog(u8"FTP_SCRIPT:---------�ļ�����ʧ��----------" + FtpFilePath, "red");
        return false;
    }

    return true;
}


bool YtCimScript::toUploadFile(QString PanelID, bool isUpper,QString FtpFilePath, QString FileName, QString unControlPath,QString UploadContent,QString FileLastName, QString FileType)
{
    bool isConnect = m_YtFTPNetWorkDo->IsConnnect();

    if(!isConnect)
    {
        if(!m_YtFTPNetWorkDo->ReConnect())
        {
            toPrintlog(u8"CIM_SCRIPT:---------FTP����������ʧ��!!!---------", "red");
            return false;
        }
    }

    QDir dir(QApplication::applicationDirPath() + "/CIM_Manger/PARAM/FTP/FTP_UPLOAD_FILE");
    if(!dir.exists())
    {
        dir.mkpath(dir.path());
    }

    QString filename = "";
    QString Cmd = "";

    toPrintlog(u8"CIM_SCRIPT:-----FTP�������׼���ϴ�-----", "green");
    if(FileType.toLower() != u8"image")
    {
        if(isUpper)
        {
            PanelID = PanelID.toUpper();
        }
        else
        {
            PanelID = PanelID.toLower();
        }

        filename = QString("%1.%2").arg(FileName).arg(FileLastName);
        QFile file(dir.path() + "/" + filename);
        if(file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            file.write(UploadContent.toLatin1().data());
        }
        file.close();


        QString upLoadPath = FtpFilePath;

        if(!unControlPath.isEmpty())
        {
            upLoadPath = upLoadPath + "@/" + unControlPath;
        }
        else
        {
            upLoadPath = upLoadPath + "@";
        }

        qDebug() << u8"CIM_SCRIPT:----------ƴ�Ӻ��·��---------" << upLoadPath;
        //�������  ����1:FTP�ϴ�·�� ����2:FTP�ϴ����ļ����� ����3:�ϴ������ļ������� ����4�ļ�����
        Cmd = QString("PUT::%1#%2#%3#%4").arg(upLoadPath).arg(filename).arg(dir.path() + "/" + filename).arg(FileType);
        if(!m_YtFTPNetWorkDo->CmdPro(Cmd))
        {
            return false;
        }
        return true;
    }
    else
    {
        toPrintlog(u8"CIM_SCRIPT:-----����ͼ���������-----", "green");
        QStringList imageList = UploadContent.split(".");
        //�����·��,�����ͼ��
        if(imageList.size() == 1)
        {
            toPrintlog(u8"CIM_SCRIPT:-----׼���ϴ�ͼ��-----" + imageList.first(), "green");

            QString upLoadPath = FtpFilePath;
            if(isUpper)
            {
                PanelID = PanelID.toUpper();
            }
            else
            {
                PanelID = PanelID.toLower();
            }

            if(!unControlPath.isEmpty())
            {
                upLoadPath = upLoadPath + "@/" + unControlPath;
            }
            else
            {
                upLoadPath = upLoadPath + "@";
            }

            QDir readImage(imageList.first());
            qDebug() << u8"CIM_SCRIPT:����ͼ��·��----------" << imageList.first();
            if(!readImage.exists())
            {
                return false;
            }

            readImage.setFilter(QDir::Files);
            QStringList imageList = {"*.jpg"};
            QStringList ImageNameList = readImage.entryList(imageList);

            foreach(QString ImageName, ImageNameList)
            {
                Cmd = QString("PUT::%1#%2#%3#%4").arg(upLoadPath).arg(ImageName).arg(readImage.path() + "/" + ImageName).arg(FileType);
                qDebug() << u8"CIM_SCRIPT:ͼ���ϴ�·��----------" << upLoadPath << ImageName;
                if(!m_YtFTPNetWorkDo->CmdPro(Cmd))
                {
                    return false;
                }

                //                QFile file(readImage.path() + "/" + ImageName);
                //                if(!file.remove())
                //                {
                //                   toPrintlog(u8"CIM_SCRIPT:--------�Ƴ�ͼ��ʧ��,ͼ������----------" + ImageName, "red");
                //                }
            }
            return true;
        }
    }
}

bool YtCimScript::QueryProductInfo(QString QueryContent, QString QueryTable, int queryTime)
{
    qDebug() << u8"CIM_SCRIPT:------ ׼����ѯ���� -------";

    if(QDateTime::currentDateTime() < m_dateTime.addSecs(60 * queryTime) && m_flag)
    {
        return false;
    }

    m_dateTime = QDateTime::currentDateTime();
    m_flag = true;


    //��ȡ�ϴ��ļ���¼��ʱ��
    QString SelectCmd;
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm");
    if(QueryContent.isEmpty())
    {
        toPrintlog(u8"CIM_SCRIPT:��ѯ����Ϊ��------------", "red");
        return false;
    }
    else
    {
        SelectCmd = QString(u8"select %1 from %2 where  ErrCount > 0 and RecordTime between '%3' and '%4' order by RecordTime desc;")
                .arg(QueryContent).arg(QueryTable).arg(m_recordTime).arg(currentTime);
        toPrintlog(u8"���ݿ��ѯ���---------" + SelectCmd,"green");
    }

    //����1:ִ�е�select���  ����2:��ѯ���ݵĸ���  ����3:��ѯ������
    QString cmd = QString(u8"SELECT::%1#%2").arg(SelectCmd).arg(QueryContent);
    if(!m_YtSQLNetWork->CmdPro(cmd))
    {
        toPrintlog(u8"CIM_SCRIPT:��ѯִ��ʧ��------------", "red");
        return false;
    }

    return true;

}

QString YtCimScript::ParseSigleInfo()
{
    QString sigelInfo = "";
    toPrintlog(QString(u8"------ʣ����Ϣ����------%1").arg(m_SigelInfo.size()), "green");
    if(m_SigelInfo.size() > 0)
    {
        sigelInfo = m_SigelInfo.first();
        m_SigelInfo.pop_front();
        return sigelInfo;
    }

    QFile file1(QApplication::applicationDirPath() + "/SQLFile/sqlfile_over.txt");
    if(file1.exists())
    {
        file1.remove();
    }

    QString filePath = QApplication::applicationDirPath() + "/SQLFile/sqlfile.txt";
    QFile file(filePath);

    if(!file.exists())
    {
        return sigelInfo;
    }

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString content = file.readAll();

        if(content.isEmpty())
        {
            file.close();
            return sigelInfo;
        }

        foreach (QString var, content.split("\n")) {
            m_SigelInfo.push_back(var);
        }
    }
    file.close();
    file.rename(QApplication::applicationDirPath() + "/SQLFile/sqlfile.txt" , QApplication::applicationDirPath() + "/SQLFile/sqlfile_over.txt");

    sigelInfo = m_SigelInfo.first();
    m_SigelInfo.pop_front();
    return sigelInfo;
}

QStringList YtCimScript::ParseProductDefectInfo( QString QueryContent, QString sigleInfo, double scale_x, double scale_y)
{

    QStringList defectInfo;

    QStringList sigleInfoList = sigleInfo.split("\t");
    QStringList queryContentList = QueryContent.split(",");

    if(sigleInfoList.size() != queryContentList.size())
    {
        toPrintlog(QString(u8"CIM_SCRIPT:---------�������ݳ��ȺͲ�ѯ���ݳ��Ȳ�ƥ��---------%1   %2").arg(sigleInfoList.size())
                   .arg(queryContentList.size()), "red");

        return defectInfo;
    }

    //�������е�ȱ����Ϣ
    QString frameid = "", clientIndex, recordTime, imagePath;
    QStringList errInfo, posInfo;
    int errCount;
    for(int i = 0; i < queryContentList.size(); i++)
    {
        QString matchTitle = queryContentList.at(i).toLower().trimmed();
        QString matchContent = sigleInfoList.at(i);
        if(matchTitle == u8"frameid")
        {
            frameid = matchContent;
        }

        if(matchTitle == u8"clientindex")
        {
            clientIndex = matchContent.split("-").last();
        }

        if(matchTitle == u8"errcount")
        {
            errCount = matchContent.toInt();
        }

        if(matchTitle == u8"posinfo")
        {
            posInfo = matchContent.split(";");
        }

        if(matchTitle == u8"errinfo")
        {
            errInfo = matchContent.split(";");
        }

        if(matchTitle == u8"recordtime")
        {
            recordTime = matchContent.replace("T", " ");
        }

        if(matchTitle == u8"imagepath")
        {
            imagePath = matchContent.split(";").last();
        }
    }


    QDir imageDir(QApplication::applicationDirPath() + "/CIM_Manger/PARAM/FTP/FTP_UPLOAD_FILE/Image/" + frameid);
    if(!imageDir.exists())
    {
        imageDir.mkpath(imageDir.path());
    }


    for(int j = 0 ; j < errCount; j++)
    {
        QStringList sigelDefectInfo = errInfo.at(j).split(",");
        double width = sigelDefectInfo.at(4).toDouble();
        double height = sigelDefectInfo.at(5).toDouble();
        double area = width * height;

        double left_x = sigelDefectInfo.at(0).toDouble() ;
        double left_y = sigelDefectInfo.at(1).toDouble() ;
        double right_x = sigelDefectInfo.at(2).toDouble();
        double right_y = sigelDefectInfo.at(3).toDouble();

        QImage image(imagePath);
        QString ImageName = "";

        if(!image.isNull())
        {
            ImageName = QString("%1_%2_%3_%4.jpg").arg(frameid).arg(QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss"))
                    .arg(clientIndex).arg(j);

            //0.25Ϊͼ������ű�����V2��V3Ϊ�̶�ֵ
            QImage timage = image.copy(left_x * 0.25 - 50, left_y * 0.25 - 50, 100, 100);
            timage.save(imageDir.path() + "/" + ImageName, "jpg");
        }

        //x,y���껻�㵽���Ͻ�Ϊԭ���λ��
        defectInfo.append(QString("%1,%2,%3,%4,%5,%6,%7,%8").arg(clientIndex).arg(j).arg(width).arg(height)
                          .arg(area).arg( ((left_x + right_x) / 2 - posInfo.at(2).toDouble())  * scale_x)
                          .arg( ((left_y + right_y) / 2 - posInfo.at(3).toDouble()) * scale_y).arg(ImageName));
    }

    QString startTime = QDateTime::fromString(recordTime, "yyyy-MM-dd hh:mm:ss.zzz").addSecs(-5).toString("yyyyMMdd_hhmmss");
    QString endTime   = QDateTime::fromString(recordTime, "yyyy-MM-dd hh:mm:ss.zzz").toString("yyyyMMdd_hhmmss");
    qDebug() << u8"CIM_SCRIPT:-------ʱ���¼-------" << startTime << endTime;

    defectInfo.append(startTime);
    defectInfo.append(endTime);

    defectInfo.append("NG");

    defectInfo.append(imageDir.path());
    defectInfo.append(frameid);

    return defectInfo;
}

QStringList YtCimScript::getOtherFile(QString filePath, int Sec)
{
    qDebug() << u8"CIM_SCRIPT:---------ɨ���·��-------" << filePath;
    QStringList PanelIDList;
    PanelIDList.clear();
    QDir dir(filePath);
    if(!dir.exists())
    {
        return PanelIDList;
    }

    if(QDateTime::currentDateTime() < m_dateTime.addSecs(Sec))
    {
        qDebug() << u8"CIM_SCRIPT:---------ɨ��������,ֱ�ӷ���-------";
        return PanelIDList;
    }


    //��ȡʱ���
    QString recordTime = "";
    QFile file(QApplication::applicationDirPath() + "/CIM_Manger/othertimerecord.txt");
    if(!file.exists())
    {
        if(file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            recordTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm");
            file.write(recordTime.toLatin1().data());
        }
        file.close();
    }
    else
    {
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            recordTime = file.readLine();
            if(recordTime.isEmpty())
            {
                recordTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm");
            }
        }
        file.close();

        if(file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
        {
            file.write(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm").toLatin1().data());
        }
        file.close();
    }


    QStringList tttFolderList;
    tttFolderList.clear();
    dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
    dir.setSorting(QDir::Time);

    QFileInfoList tttfileInfoList = dir.entryInfoList();
    foreach (QFileInfo fileInfo, tttfileInfoList) {
        QString date = QDateTime::fromString(recordTime,"yyyy-MM-dd hh:mm").toString("yyyy-MM-dd");
        if(fileInfo.lastModified() >= QDateTime::fromString(date,"yyyy-MM-dd")
                && fileInfo.lastModified() <= QDateTime::currentDateTime())
        {
//            toPrintLog(QString(u8"CIM_SCRIPT:------�������ļ�����·��-----%1--------�ļ�����޸�ʱ��------%2").arg(fileInfo.filePath())
//                       .arg(fileInfo.lastModified().toString("yyyy-MM-dd hh:mm:ss")), Qt::white);
            tttFolderList.append(fileInfo.filePath());
        }
    }

    for(int i = 0; i < tttFolderList.size();i++)
    {
        qDebug() << u8"CIM_SCRIPT:---------��ȡ�ļ�������-------" << tttFolderList.at(i);
//        toPrintLog(QString(u8"CIM_SCRIPT:------��ȡ�����ļ�������-----%1").arg(tttFolderList.at(i)), Qt::white);
        QFile file(tttFolderList.at(i) + "/file.txt");
        if(file.exists())
        {
            continue;
        }

        QFileInfo fileInfo = QFileInfo(tttFolderList.at(i));
        if(fileInfo.lastModified() >= QDateTime::fromString(recordTime,"yyyy-MM-dd hh:mm")
                && fileInfo.lastModified() <= QDateTime::currentDateTime())
        {
            toPrintLog(QString(u8"CIM_SCRIPT:------��ȡ���ĵ������ļ�-----%1").arg(fileInfo.absoluteFilePath()), Qt::white);
            qDebug() << u8"CIM_SCRIPT:��ȡ�����ļ�--------------" << fileInfo.fileName();
            PanelIDList.append(fileInfo.absoluteFilePath());
        }
    }

    return PanelIDList;
}

void YtCimScript::toWriteQString(QString WritAdr, QString val)
{

    if (m_YtPlcDo) {
        m_YtPlcDo->WriteString(WritAdr, val);
    }
}

QString YtCimScript::toReadQString(QString ReadAdr, int len)
{
    if (m_YtPlcDo) {
        return m_YtPlcDo->ReadString(ReadAdr,len).trimmed();
    }
    return "ERRR";
}

QString YtCimScript::toReadIni(QString filePath, QString productName)
{
    QString CfFilePath = QString(u8"%1/%2/�ɼ���Ԫ/CA0/BasePar.ini").arg(filePath).arg(productName);
    QSettings m_Setting(CfFilePath, QSettings::IniFormat);
    m_Setting.setIniCodec("GB2312");

    double cfWid  = m_Setting.value("m_NewSurFacePar/UBlobFilter.dLSize","3").toDouble();
    double cfHigh = m_Setting.value("m_NewSurFacePar/UBlobFilter.dWSize","3").toDouble();

    QString TftFilePath = CfFilePath;
    TftFilePath = TftFilePath.replace("CA0", "TA0");

    double tftWid  = m_Setting.value("m_NewSurFacePar/UBlobFilter.dLSize","3").toDouble();
    double tfthigh = m_Setting.value("m_NewSurFacePar/UBlobFilter.dWSize","3").toDouble();

    return QString("%1,%2,%3,%4").arg(cfWid).arg(cfHigh).arg(tftWid).arg(tfthigh);

}

void YtCimScript::toLoadSmallBlobIm(QVector<QImage> &OutImList, QString filename)
{
    OutImList.clear();
    QFile datafile(filename);
    if(!datafile.exists()) {
        return;
    }

    datafile.open(QIODevice::ReadOnly);
    QDataStream out(&datafile);    // read the data serialized from the file
    //////////
    int ttsize = 0;
    CMvRect temretc;
    QByteArray temarry;

    out >> ttsize ;
    for(int i = 0; i < ttsize; i++) {

        out >> temarry >> temretc.LeftTop.x >> temretc.LeftTop.y >> temretc.cx >> temretc.cy;
        QImage tempim;

        tempim.loadFromData(temarry, "jpg");
        OutImList.append(tempim);
    }
    ////////////
    datafile.close();
}

bool YtCimScript::YTLoadBlobFile(YtAllBlob &blobfile, QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
    {
        return false;
    }
    int SetSize=0;
    blobfile.GetBlob.clear();
    QDataStream out(&file);
    out >> blobfile.Xscal>>blobfile.yscal>>blobfile.OutTypeDefine>>blobfile.GetImInfo>>SetSize;
    qDebug()<<filename<< blobfile.Xscal<<blobfile.yscal<<blobfile.OutTypeDefine<<blobfile.GetImInfo<<SetSize;

    QByteArray temByteData;
    YtBlobDefine temsetdata;
    for(int i=0;i<SetSize;i++)
    {
        out>>temByteData;
        memcpy(&temsetdata,temByteData.data(),temByteData.size());
        blobfile.GetBlob.append(temsetdata);
    }
    out >> blobfile.m_GetPos[0].x >> blobfile.m_GetPos[0].y;
    out >> blobfile.m_GetPos[1].x >> blobfile.m_GetPos[1].y;
    out >> blobfile.m_GetPos[2].x >> blobfile.m_GetPos[2].y;
    out >> blobfile.m_GetPos[3].x >> blobfile.m_GetPos[3].y;
    file.close();
    return true;
}

void YtCimScript::getSignalOut(int index, QString content)
{
    QMessageBox::warning(nullptr, u8"���ݴ�����ʾ", QString(u8"%1 ��Ӧ���� %2 ����ȷ,����!!!").arg(content).arg(index));
}


