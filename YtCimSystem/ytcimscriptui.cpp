#include "ytcimscriptui.h"
#include "ui_ytcimscriptui.h"

YtCimScriptUI::YtCimScriptUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::YtCimScriptUI)
{
    ui->setupUi(this);
    m_YtCimScriptThread = new YtCimScriptThread;
    m_YtCimScriptThread->toLoadModel();
    ui->ytEditTool->toSetData(m_YtCimScriptThread->m_RunScript);
    m_YtCimScriptThread->toInitThread();
}

YtCimScriptUI::~YtCimScriptUI()
{
    if(m_YtCimScriptThread != nullptr)
    {
        delete m_YtCimScriptThread;
        m_YtCimScriptThread = nullptr;
    }
    delete ui;
}


void YtCimScriptUI::toInsertScript(QString str)
{
    QString AppendTxt = "";


    /**********************FTP��������****************************************/
    if(str == u8"FTP�ϴ��ļ�")
    {
        AppendTxt = u8"//FTP�ϴ��ļ� ����1:��ƷID ����2:·���Ƿ��д ����3:FTP�ϴ�·�� ����4:�ϴ��ļ������� ����5:�仯��·�� ����6:���ļ�������  ����7:�ļ���׺  ����8:�ļ�����(image/ascii)  \n"
                      "var bool = Yt.toUploadFile('panelID', 0,'ftpUploadPath', 'fileName', '�仯��·��' ,'UploadContent', 'txt','image');";
    }

    if(str == u8"FTP�����ļ�")
    {
        AppendTxt = u8"//FTP�ļ����� ����1:FTP�ļ�·�� ����2:���ر���·�� ����3:�ļ�����  ����ֵ:�Ƿ����� \n"
                    "var isDownLoad = Yt.toDownLoadFile('panelID','ftpfilePath' , 'localfilepath', 'txt');";
    }

    /*************************�����ļ��в�������********************************/
    if(str == u8"��������")
    {
        AppendTxt = u8"//�����ļ��б������� \n"
                    "Yt.toShareFolderTitle();";
    }

    if(str == u8"�ϴ�����")
    {
        AppendTxt = u8"//�����ļ����ϴ����� \n"
                    "Yt.toSFUploadContent();";
    }

    /*************************������������*****************************************/
    if(str == u8"��ȡ�ͻ���ȱ����Ϣ")
    {
        AppendTxt = u8"//��ȡȱ����Ϣ ����1:��ƷID ����2:��������(BOE,TM)  ����3:TM����ַ�  ����4:ʱ��� ����5:���������� ����6:�����̱߱����� ����7:�������߱����� \n"
                       "var defectInfo = Yt.toGetDefectInfo('PanelID', 'TM', 'A1000', 'time' , 2 ,0.025, 0.025);";
    }

    if(str == u8"��ȡ��ͼȱ����Ϣ")
    {
        AppendTxt = u8"//��ȡȱ����Ϣ ����1:��ƷID ����2:��������(BOE,TM)  ����3:TM����ַ�  ����4:ʱ��� ����5:���������� ����6:�����̱߱����� ����7:�������߱����� \n"
                       "var defectInfo = Yt.toGetBigImDefectInfo('PanelID', 'TM', 'A1000', 'time' , 2 ,0.025, 0.025);";
    }

    if(str == u8"������־")
    {
        AppendTxt = u8"Yt.toPrintlog('------------��־����----------', 'red');";
    }

    if(str == u8"������ʱ")
    {
        AppendTxt = u8"Yt.toSleep(1000);";
    }

    if(str == u8"��ȡ��ƷID")
    {
        AppendTxt = u8"var PanelID = Yt.toGetPanelID();";
    }

    if(str == u8"���ɿ�����")
    {
        AppendTxt = u8"//�������� ����1:�ϴ����ⲿ��  ����2:����ķָ���� ����3:�ϴ���������ַ� ����4:�ϴ����ݷָ��   ����ֵ:ȫΪ����ַ����ַ���\n"
                    "var upContent = Yt.toCombinaFtpContent('title' , ',' , '****' , ',');";
    }

    if(str == u8"����ָ������")
    {
        AppendTxt = u8"//�ϴ����� ����1:��Ҫ���µ��ַ��� ����2:����1�ķָ���  ����3:����ַ��� ����4:����3�ķָ���  ����5:����4�ķָ��� ����ֵ:���º���ַ���\n"
                    "var updateContent = Yt.toFillSpecialSig('upConten', ',' , 'owner_code:10#own_type:15#cassetID:18', '#' , ':');";
    }

    if(str == u8"��ȡʱ���")
    {
        AppendTxt = u8"//��ȡ�¼��� ����1: ��ȡʱ���ַ����ļ�λ\n"
                      "var time = Yt.toGetTimepoint(8);";
    }

    if(str == u8"��ȡ�ļ�����")
    {
        AppendTxt = u8"//��ȡ�ļ����� ����1:��ƷID ����2:��ȡ�ļ���·�� ����3:��ȡ�ı�����  ����4:ƥ������ ����5:�Ƿ�ɾ���ļ�\n"
                      "var str = Yt.toGetTextContent('PanelID', 'filePath', 'txt', 'MatchContent', 0);";
    }

    if(str == u8"��ѯ����")
    {
        AppendTxt =u8"//��ѯ���ݿ� ����1:��ѯ����  ����2:��ѯ���ݱ�  ����3:ˢ��ʱ�� \n"
                     "var isSuccess = Yt.QueryProductInfo('FrameID,ClientIndex', '`ag01-100`.conclusion', 10);";
    }

    if(str == u8"��ȡ��������")
    {
        AppendTxt = u8"//��ȡ���ݿⵥ����¼ \n"
                     "var sigelInfo = Yt.ParseSigleInfo();";
    }

    if(str == u8"������������")
    {
        AppendTxt = u8"//����������¼ ����1:��ѯ����  ����2:��ȡ�ĵ�����¼  ����3:������  \n"
                        "var defectInfo = Yt.ParseProductDefectInfo('FrameID,ClientIndex', 'sigelInfo', 0.025);";
    }

    if(str == u8"�ϴ��������ļ�")
    {
        AppendTxt = u8"//�ϴ��������ļ�  ����1:�����ļ�·��  ����2:�ļ�����(��: *.jpg;*.png/*.csv;*.txt )  ����3:ftp�̶�·��  ����4:�仯��·�� \n"
                      "var isSuccess = Yt.toParseFileAndPut('localFilePath', '*.jpg;', 'ftpUploadPath', 'unControlPath')";
    }

    if(str == u8"��ȡ�ļ���Ϣ�б�")
    {
        AppendTxt = u8"//��ȡ�ļ���Ϣ�б�  ����1:�ļ���·��  ����2:��ȡ����\n"
                        "var fileList = Yt.toGetFileList('filePath', '*.jpg;');";
    }

    if(str == u8"��ȡ�ļ����б�")
    {
        AppendTxt = u8"//��ȡ�ļ��е��б�  ����1:ɨ����ļ���·�� ����2:ɨ������ \n"
                      " var folderList = Yt.getOtherFile('folderPath', 5);";
    }

    if(str == u8"д���ַ���")
    {
        AppendTxt = u8"//���ַ���д��PLC \n"
                    "Yt.toWriteQString('D0', 'str');";
    }

    if(str == u8"��ȡ�ַ���")
    {
        AppendTxt = u8"//��PLC��ȡ�ַ��� \n"
                    "var str = Yt.toReadQString('D0', 20);";
    }


    ui->ytEditTool->toAppendData(AppendTxt);

}

void YtCimScriptUI::toStart(bool isOnce)
{
    m_YtCimScriptThread->toStart(isOnce);
}

void YtCimScriptUI::toSetObject(YtNetWorkDo *tYtNetWork, int flag)
{
    if(tYtNetWork == nullptr)
    {
        return ;
    }

    m_YtCimScriptThread->toSetObject(tYtNetWork, flag);
}

void YtCimScriptUI::toInitPlc()
{

    m_YtCimScriptThread->toInitPLC();
}

void YtCimScriptUI::toStop()
{
    m_YtCimScriptThread->toStop();
}

void YtCimScriptUI::toSaveScript()
{
    ui->ytEditTool->toGetData(m_YtCimScriptThread->m_RunScript);
    m_YtCimScriptThread->toSaveModel();
}

void YtCimScriptUI::toSetTime(QString tTime)
{
    m_YtCimScriptThread->toSetRecordTime(tTime);
}