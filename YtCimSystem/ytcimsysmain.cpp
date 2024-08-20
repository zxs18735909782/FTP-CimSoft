#include "ytcimsysmain.h"
#include "ui_ytcimsysmain.h"
#include "ytlogprolib.h"

#include <QDir>
#include <QFileDialog>
#include <QFile>
#include <QDataStream>
#include <QScroller>
#include <QPushButton>
#include <QMessageBox>

YtCimSysMain::YtCimSysMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::YtCimSysMain)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/Images/image/DataChange.png"));

    ui->log->addWidget(toGetLogoWindow(QColor(56, 62, 73), YtRight));
    toInitLogoProcDo(kLogShowAndSave, 1);
    m_YtCimParamSet = new YtCimParamSet();

    toLoadParam();
    toGetFileInfoList();

    connect(&m_timer, &QTimer::timeout, this, &YtCimSysMain::toCollectFile);
    m_timer.start(1000 * 5);

    ui->reFreash->setIcon(QIcon(":/Images/image/refresh.png"));
    connect(this, &YtCimSysMain::onSignalSend, this, &YtCimSysMain::toShowFile);
    toRefreshFileList();


    QFile file(QApplication::applicationDirPath() + "/CIM_Manger/isrun.txt");
    if(file.exists())
    {
        on_Start_CIM_clicked();
    }

}

YtCimSysMain::~YtCimSysMain()
{
    toSaveParam();

    if(m_YtCimParamSet != nullptr)
    {
        delete m_YtCimParamSet;
        m_YtCimParamSet = nullptr;
    }

    QDir dir(QApplication::applicationDirPath() + "/temFile");
    if(dir.exists())
    {
        dir.removeRecursively();
    }

    delete ui;
}

void YtCimSysMain::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton button = QMessageBox::question(nullptr, u8"�رմ���", u8"ȷ���Ƿ�رմ���?", QMessageBox::Yes | QMessageBox::No);
    if(button != QMessageBox::Yes)
    {
        qDebug() << u8"CIM_Main:-------ȡ���رմ���------";
        event->ignore();
        return ;
    }

    qDebug() << u8"CIM_Main:-------�رմ���------";
    event->accept();


}

void YtCimSysMain::on_ParamSet_clicked()
{
    m_YtCimParamSet->exec();
}

void YtCimSysMain::on_Start_CIM_clicked()
{
    if(ui->Start_CIM->text() == u8"����CIM")
    {
        ui->Start_CIM->setText(u8"ֹͣCIM");
        ui->ParamSet->setVisible(false);
        m_YtCimParamSet->on_ExecCycle_clicked();
    }
    else if(ui->Start_CIM->text() == u8"ֹͣCIM")
    {
        ui->Start_CIM->setText(u8"����CIM");
        ui->ParamSet->setVisible(true);
        m_YtCimParamSet->on_Stop_clicked();
    }

}

bool YtCimSysMain::toGetFileInfoList()
{
    toPrintLog(u8"CIM_Main:------�����ļ���Ϣ�ռ�����--------", Qt::green);

    QString SavePath = QApplication::applicationDirPath() + "/CIM_Manger";

    QDir dir(SavePath);
    if(!dir.exists())
    {
        dir.mkpath(dir.path());
    }



    //��ȡ�ϴ��ļ���¼��ʱ��
    QString recordTime = "";
    QFile file(SavePath + "/timerecord.txt");
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

    toPrintLog(u8"CIM_Main:---------�ļ��б�ˢ��ʱ���--------" + recordTime, "yellow");
    //���ļ���Ϣ������ű���������ѯ
    m_YtCimParamSet->toSetRecrdTime(recordTime);

    QFile fileInit(SavePath + "/fileInfoList.txt");
    if(fileInit.exists())
    {
        if(QFile::remove(SavePath + "/fileInfoList.txt"))
        {
            toPrintLog(u8"CIM_Main:---------fileInfoList.txt--------" + recordTime, "yellow");
        }
    }

    QString filePath = ui->filePath->text();

    if(filePath.isEmpty())
    {
        return false;
    }

    toPrintLog(u8"CIM_Main:------��ʼ�����ļ���Ϣ--------" + filePath, Qt::white);
    //��ʼ�����ļ�����Ϣ
    QString SaveFilePath = filePath;
    QDir fileDir(SaveFilePath);
    if(!fileDir.exists())
    {
        toPrintLog(u8"CIM_Main:---�ļ�·��������----" + fileDir.path(), Qt::red);
        return false;
    }

    QStringList folderList;
    fileDir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
    fileDir.setSorting(QDir::Time);
    QFileInfoList fileInfoList = fileDir.entryInfoList();
    //�����������ļ���
    foreach (QFileInfo fileInfo, fileInfoList) {

        QDir dir(fileInfo.absolutePath());
        dir.refresh();

        QString date = QDateTime::fromString(recordTime,"yyyy-MM-dd hh:mm").toString("yyyy-MM-dd");
        if(fileInfo.lastModified() >= QDateTime::fromString(date,"yyyy-MM-dd")
                && fileInfo.lastModified() <= QDateTime::currentDateTime())
        {
            toPrintLog(QString(u8"CIM_Main:------����·��-----%1--------�ļ�����޸�ʱ��------%2").arg(fileInfo.filePath())
                       .arg(fileInfo.lastModified().toString("yyyy-MM-dd hh:mm:ss")), Qt::white);
            folderList.append(fileInfo.filePath());
        }
    }

    toPrintLog(u8"CIM_Main:------���ڱ����ļ���Ϣ--------", Qt::white);
    //��ʼ�����ļ���Ϣ
    for(int i = 0;i < folderList.size(); i++)
    {
        QDir dir(folderList.at(i));
        dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
        QStringList fileList;
        foreach(QFileInfo fileInfo, dir.entryInfoList())
        {
            if(fileInfo.lastModified() >= QDateTime::fromString(recordTime,"yyyy-MM-dd hh:mm")
                    && fileInfo.lastModified() <= QDateTime::currentDateTime())
            {
                fileList.append(fileInfo.fileName());
            }
        }

        QFile file(SavePath + "/fileInfoList.txt");
        if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        {
            foreach (QString var, fileList) {
                QString writeInfo = QString("%1/%2 \n").arg(folderList.at(i)).arg(var);
                file.write(writeInfo.toLatin1().data());
            }
        }
        file.close();
    }
    toPrintLog(u8"CIM_Main:------�ļ���Ϣ�������--------", Qt::green);

    return true;
}

void YtCimSysMain::toCollectFile()
{
    toPrintLog(u8"CIM_Main:-----CIM�ϴ���Ϣ�б���ʱˢ��-----", "green");
    QFile file(QApplication::applicationDirPath() + "/CIM_Manger/fileInfoList_over.txt");
    if(file.exists())
    {
        if(!file.remove())
        {
            toPrintLog(u8"CIM_Main:------fileInfoList_over.txt �ļ��Ƴ�ʧ��--------", Qt::red);
        }
        else
        {
            toPrintLog(u8"CIM_Main:------fileInfoList_over.txt �ļ��Ƴ��ɹ�--------", Qt::green);
        }
    }

    toGetFileInfoList();
}

void YtCimSysMain::toShowFile(QString filePath)
{
    if(!filePath.contains("."))
    {
        return ;
    }

    QDir dir(QApplication::applicationDirPath() + "/temFile");
    if(!dir.exists())
    {
        dir.mkpath(dir.path());
    }

    QString fileName = filePath.split("/").last();
    QFile file(dir.path() + "/" + fileName);
    if(!file.exists())
    {
        YtNetWorkDo *tYtNetWorkDo = m_YtCimParamSet->toGetObject();
        QString Cmd = QString("GET-%1#%2").arg(filePath).arg(dir.path() + "/" + fileName);
        if(tYtNetWorkDo->CmdPro(Cmd))
        {
            toPrintLog(u8"CIM_Main:��ʱ�ļ����سɹ�-----------" + dir.path() + "/" + fileName, Qt::green);
        }
    }

    if(filePath.contains(".jpg") || filePath.contains(".bmp") || filePath.contains(".png"))
    {
        QString imagePath = dir.path() + "/" + fileName;
        QImage image(imagePath);
        image=image.scaled(ui->showFileInfo->width() * 0.8, ui->showFileInfo->height() * 0.8,
                           Qt::KeepAspectRatio, Qt::SmoothTransformation);

        image.save(imagePath.split(".").first() + ".jpg", "jpg");
        ui->showFileInfo->setHtml(QString("<img src=\"%1\" />").arg(imagePath.split(".").first() + ".jpg"));
        ui->showFileInfo->setAlignment(Qt::AlignCenter);
    }
    else
    {
        QFile file(dir.path() + "/" + fileName);
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QString fileContent = file.readAll();
            ui->showFileInfo->setText(fileContent);
        }
    }
}


void YtCimSysMain::on_ChoseFilePath_clicked()
{
    QString filePath = QFileDialog::getExistingDirectory();
    if(filePath.isEmpty())
    {
        return ;
    }

    ui->filePath->setText(filePath);
}

void YtCimSysMain::on_SavePath_clicked()
{
    toSaveParam();
}

void YtCimSysMain::toSaveParam()
{
    QString ParamPath = QApplication::applicationDirPath() + "/CIM_Manger";

    QDir dir(ParamPath);
    if(!dir.exists())
    {
        dir.mkpath(dir.path());
    }

    QFile file(ParamPath + "/MAIN.dat");
    if(file.open(QIODevice::WriteOnly))
    {
        QDataStream in(&file);
        in << ui->filePath->text() << ui->FTP_Refresh_Path->text();
    }
    file.close();
}

void YtCimSysMain::toLoadParam()
{
    QString ParamPath = QApplication::applicationDirPath() + "/CIM_Manger";

    QDir dir(ParamPath);
    if(!dir.exists())
    {
        dir.mkpath(dir.path());
    }

    QFile file(ParamPath + "/MAIN.dat");
    if(file.open(QIODevice::ReadOnly))
    {
        QString path = "", ftp_Path = "";
        QDataStream out(&file);
        out >> path >> ftp_Path;
        ui->filePath->setText(path);
        ui->FTP_Refresh_Path->setText(ftp_Path);
    }
    file.close();
}

void YtCimSysMain::toRefreshFileList()
{
    YtNetWorkDo *tYtNetWorkDo = m_YtCimParamSet->toGetObject();
    QDir dir(QApplication::applicationDirPath() + "/CIM_Manger/FILE_SHOW");
    if(!dir.exists())
    {
        dir.mkpath(dir.path());
    }

    QFile file(dir.path() + "/folderlist.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        file.close();
    }

    ui->treeWidget->header()->setSectionResizeMode(0, QHeaderView::ResizeMode::ResizeToContents);
    ui->treeWidget->header()->setStretchLastSection(false);

    QTreeWidgetItem *rootItem = new QTreeWidgetItem(ui->treeWidget);
    rootItem->setText(0, u8"/");
    rootItem->setIcon(0, QIcon(":/Images/image/folder.png"));

    if(!ui->FTP_Refresh_Path->text().isEmpty())
    {
        toGetFileTree(tYtNetWorkDo, rootItem, dir.path() + "/folderlist.txt", ui->FTP_Refresh_Path->text());
    }
}

void YtCimSysMain::toGetFileTree(YtNetWorkDo *tYtNetWorkDo, QTreeWidgetItem *treeRoot ,QString infoSavePath, QString SearchPath)
{
    //ָ�����1: �ļ��б���Ϣ�ı����ļ�·��   ����2:����һ��Ŀ¼�¿�ʼ�����ļ��б�
    QString Cmd = QString("LIST-%1#%2").arg(infoSavePath).arg(SearchPath);
    if(tYtNetWorkDo->CmdPro(Cmd))
    {
        QStringList fileList;
        QList<QTreeWidgetItem *> itemList;
        itemList.clear();

        QFile file(infoSavePath);
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            while(!file.atEnd())
            {
                QString fileContent = file.readLine();
                fileList << fileContent;
                //ȡ���һ��,ȥ�����з���ȥ���ո�
                fileContent = fileContent.split("/").last();
                fileContent = fileContent.replace("\n" ,"");
                fileContent = fileContent.trimmed();

                if(fileContent.contains("."))
                {
                    QTreeWidgetItem *item = new QTreeWidgetItem(treeRoot, QStringList(fileContent));
                    if(fileContent.contains(".jpg") || fileContent.contains(".png") || fileContent.contains(".bmp"))
                    {
                        item->setIcon(0,QIcon(":/Images/image/Image.png"));
                    }
                    else
                    {
                        item->setIcon(0, QIcon(":/Images/image/file.png"));
                    }
                }
                else
                {
                    QTreeWidgetItem *item = new QTreeWidgetItem(treeRoot, QStringList(fileContent));
                    item->setIcon(0, QIcon(":/Images/image/folder.png"));
                    itemList.push_back(item);
                }

            }
        }
        file.close();

        for(int i = 0; i < fileList.size(); i++)
        {
            if(!fileList.at(i).contains("."))
            {
                QString fileInfo = fileList.at(i);
                toGetFileTree(tYtNetWorkDo, itemList.first() ,infoSavePath, fileInfo.replace("\n", ""));
                itemList.pop_front();
            }
        }
    }
}

void YtCimSysMain::toGetFileInfo(QTreeWidgetItem *item,QStringList &filePathList)
{
    //����Ϊ�շ��� ���ַ���
    if(item == nullptr)
    {
        return ;
    }

    //ͷ�巨
    filePathList.insert(0, item->text(0));
    toGetFileInfo(item->parent(), filePathList);
}

void YtCimSysMain::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    m_filePathList.clear();

    toGetFileInfo(item, m_filePathList);

    QString filePath = m_filePathList.first();
    for(int i = 1; i < m_filePathList.size();i++)
    {
        filePath += m_filePathList.at(i);
        if(i != m_filePathList.size() - 1)
        {
            filePath += "/";
        }
    }

    qDebug() << u8"CIM_Main:---------�����ļ�·��----------" << ui->filePath->text() + "/" +filePath;
    emit onSignalSend(ui->FTP_Refresh_Path->text() + filePath);

}

void YtCimSysMain::on_reFreash_clicked()
{
    ui->treeWidget->clear();
    toRefreshFileList();
}