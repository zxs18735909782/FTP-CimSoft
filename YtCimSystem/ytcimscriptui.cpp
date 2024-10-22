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


    /**********************FTP操作函数****************************************/
    if(str == u8"FTP上传文件")
    {
        AppendTxt = u8"//FTP上传文件 参数1:产品ID 参数2:路径是否大写 参数3:FTP上传路径 参数4:上传文件的名字 参数5:变化的路径 参数6:传文件的内容  参数7:文件后缀  参数8:文件类型(image/ascii)  \n"
                      "var bool = Yt.toUploadFile('panelID', 0,'ftpUploadPath', 'fileName', '变化的路径' ,'UploadContent', 'txt','image');";
    }

    if(str == u8"FTP下载文件")
    {
        AppendTxt = u8"//FTP文件下载 参数1:FTP文件路径 参数2:本地保存路径 参数3:文件类型  返回值:是否下载 \n"
                    "var isDownLoad = Yt.toDownLoadFile('panelID','ftpfilePath' , 'localfilepath', 'txt');";
    }

    /*************************共享文件夹操作函数********************************/
    if(str == u8"标题内容")
    {
        AppendTxt = u8"//共享文件夹标题内容 \n"
                    "Yt.toShareFolderTitle();";
    }

    if(str == u8"上传内容")
    {
        AppendTxt = u8"//共享文件夹上传内容 \n"
                    "Yt.toSFUploadContent();";
    }

    /*************************基础操作函数*****************************************/
    if(str == u8"获取客户端缺陷信息")
    {
        AppendTxt = u8"//读取缺陷信息 参数1:产品ID 参数2:厂别名称(BOE,TM)  参数3:TM填充字符  参数4:时间戳 参数5:玻璃的面数 参数6:玻璃短边比例尺 参数7:玻璃长边比例尺 \n"
                       "var defectInfo = Yt.toGetDefectInfo('PanelID', 'TM', 'A1000', 'time' , 2 ,0.025, 0.025);";
    }

    if(str == u8"获取大图缺陷信息")
    {
        AppendTxt = u8"//读取缺陷信息 参数1:产品ID 参数2:厂别名称(BOE,TM)  参数3:TM填充字符  参数4:时间戳 参数5:玻璃的面数 参数6:玻璃短边比例尺 参数7:玻璃长边比例尺 \n"
                       "var defectInfo = Yt.toGetBigImDefectInfo('PanelID', 'TM', 'A1000', 'time' , 2 ,0.025, 0.025);";
    }

    if(str == u8"添加日志")
    {
        AppendTxt = u8"Yt.toPrintlog('------------日志内容----------', 'red');";
    }

    if(str == u8"添加延时")
    {
        AppendTxt = u8"Yt.toSleep(1000);";
    }

    if(str == u8"获取产品ID")
    {
        AppendTxt = u8"var PanelID = Yt.toGetPanelID();";
    }

    if(str == u8"生成空内容")
    {
        AppendTxt = u8"//标题内容 参数1:上传标题部分  参数2:标题的分割符号 参数3:上传内容填充字符 参数4:上传内容分割符   返回值:全为填充字符的字符串\n"
                    "var upContent = Yt.toCombinaFtpContent('title' , ',' , '****' , ',');";
    }

    if(str == u8"设置指定内容")
    {
        AppendTxt = u8"//上传内容 参数1:需要更新的字符串 参数2:参数1的分隔符  参数3:填充字符串 参数4:参数3的分隔符  参数5:参数4的分隔符 返回值:更新后的字符串\n"
                    "var updateContent = Yt.toFillSpecialSig('upConten', ',' , 'owner_code:10#own_type:15#cassetID:18', '#' , ':');";
    }

    if(str == u8"获取时间戳")
    {
        AppendTxt = u8"//获取事件戳 参数1: 获取时间字符串的几位\n"
                      "var time = Yt.toGetTimepoint(8);";
    }

    if(str == u8"获取文件内容")
    {
        AppendTxt = u8"//获取文件内容 参数1:产品ID 参数2:读取文件的路径 参数3:读取文本类型  参数4:匹配内容 参数5:是否删除文件\n"
                      "var str = Yt.toGetTextContent('PanelID', 'filePath', 'txt', 'MatchContent', 0);";
    }

    if(str == u8"查询数据")
    {
        AppendTxt =u8"//查询数据库 参数1:查询内容  参数2:查询数据表  参数3:刷新时间 \n"
                     "var isSuccess = Yt.QueryProductInfo('FrameID,ClientIndex', '`ag01-100`.conclusion', 10);";
    }

    if(str == u8"获取单条数据")
    {
        AppendTxt = u8"//获取数据库单条记录 \n"
                     "var sigelInfo = Yt.ParseSigleInfo();";
    }

    if(str == u8"解析单条数据")
    {
        AppendTxt = u8"//解析单条记录 参数1:查询内容  参数2:获取的单条记录  参数3:比例尺  \n"
                        "var defectInfo = Yt.ParseProductDefectInfo('FrameID,ClientIndex', 'sigelInfo', 0.025);";
    }

    if(str == u8"上传第三方文件")
    {
        AppendTxt = u8"//上传第三方文件  参数1:本地文件路径  参数2:文件类型(例: *.jpg;*.png/*.csv;*.txt )  参数3:ftp固定路径  参数4:变化的路径 \n"
                      "var isSuccess = Yt.toParseFileAndPut('localFilePath', '*.jpg;', 'ftpUploadPath', 'unControlPath')";
    }

    if(str == u8"获取文件信息列表")
    {
        AppendTxt = u8"//获取文件信息列表  参数1:文件夹路径  参数2:获取类型\n"
                        "var fileList = Yt.toGetFileList('filePath', '*.jpg;');";
    }

    if(str == u8"获取文件夹列表")
    {
        AppendTxt = u8"//获取文件夹的列表  参数1:扫描的文件夹路径 参数2:扫描周期 \n"
                      " var folderList = Yt.getOtherFile('folderPath', 5);";
    }

    if(str == u8"写入字符串")
    {
        AppendTxt = u8"//将字符串写入PLC \n"
                    "Yt.toWriteQString('D0', 'str');";
    }

    if(str == u8"读取字符串")
    {
        AppendTxt = u8"//从PLC读取字符串 \n"
                    "var str = Yt.toReadQString('D0', 20);";
    }

    if(str == u8"获取检测参数")
    {
        AppendTxt = u8"//从算法文件读取检测规格 参数1:算法文件读取路径  参数2:当前配方及配方名称(1_TEST) \n"
                    "var detectRule = Yt.toReadIni('D:/GSI_Client_V4/PluginModels', '1_TEST');";
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
