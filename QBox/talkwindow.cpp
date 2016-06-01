#include "talkwindow.h"
#include "ui_talkwindow.h"
TalkWindow*  TalkWindow::myTalkWindow=NULL;
TalkWindow::TalkWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TalkWindow)
{
    ui->setupUi(this);
    ui->textEditMessage->setFocus();
    ui->textEditMessage->setFontPointSize(20.0);
    //第一个参数是设置无边框。第二个参数是允许最小化与还原。
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    fullWidget = new fullScreenWidget();
    //绑定截图的信号
    connect(this,SIGNAL(setPixmap(QPixmap)),fullWidget,SLOT(loadBackgroundPixmap(QPixmap)));

}

void TalkWindow::init(QString userid, QString name, quint8 status, QString photo, QString info)
{
    //设置单聊属性
    this->type=1;

    //先把它进行数据的复制
    this->userid=userid;
    this->name=name;
    this->status=status;
    this->photo=photo;
    this->info=info;
    //将这些东西显示在界面上
    ui->label_name->setText(QString("<html><head/><body><p><span style='font-size:20pt ;font-weight:600; color:#55ff00;'>%1</span></p></body></html>").arg(name));
    ui->label_PeopleStatus->setText(QString("状态：%1").arg(Tools::getStatus(status)));
    ui->UserPS_label->setText(info);
    QFile pic(photo);
    if(pic.exists())
    {
        ui->labelPic->setPixmap(QPixmap(photo));
    }
    qDebug()<<userid<<name<<status<<photo<<info;
}

void TalkWindow::init_Group(QString groupID, QString name, QString info, QString admin, QMap<QString, QString> *userList)
{

    //设置群聊属性
    this->type=2;
    //先把它进行数据的复制
    this->groupID=groupID;
    this->Groupname=name;
    this->Groupinfo=info;
    this->admin=admin;
    this->userList=userList;
    //将这些东西显示在界面上
    ui->label_name->setText(QString("<html><head/><body><p><span style='font-size:20pt ;font-weight:600; color:#55ff00;'>群组：%1</span></p></body></html>").arg(name));
    ui->label_PeopleStatus->setText(QString("群主：%1").arg(admin));
    ui->UserPS_label->setText(info);

    QString photo=":/resource/image/talkwindow/resource/image/talkwindow/group.png";
    QFile pic(photo);
    qDebug()/*<<photo*/<<admin;
    //      qDebug()<<*userList;
    ui->textEditMessage->setFontPointSize(10);
    if(pic.exists())
    {
        qDebug()<<photo;
        ui->labelPic->setPixmap(QPixmap(photo));
    }
}

TalkWindow::~TalkWindow()
{
    delete ui;
    qDebug()<<QObject::tr("析构函数被执行");
}

void TalkWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - this->dPos);
}

void TalkWindow::mousePressEvent(QMouseEvent *event)
{
    this->windowPos = this->pos();
    this->mousePos = event->globalPos();
    this->dPos = mousePos - windowPos;
}

void TalkWindow::on_btnClose_clicked()
{
    qDebug()<<"关闭！";
    this->hide();
    //    this->close();
}

void TalkWindow::on_btnClear_clicked()
{
    ui->textEditMessage->clear();
}

void TalkWindow::on_btnSend_clicked()
{
    static bool i=false;
    message=ui->textEditMessage->toHtml();
    i!=i;
    qDebug()<<message;

    //    if(i==true)
    //    {
    //        ui->MessageBrowser->setAlignment(Qt::AlignRight);
    //    }
    //    else
    //    {
    //        ui->MessageBrowser->setAlignment(Qt::AlignLeft);

    //    }
    ui->MessageBrowser->append(message);
    ui->textEditMessage->clear();
}

void TalkWindow::on_tbCutPic_clicked()
{
    //    qDebug()<<"进行截图";

    //hide();
    QPixmap pixmap = fullWidget->getFullScreenPixmap();
    fullWidget->show();

    emit setPixmap(pixmap); //发送信号，使用当前的屏幕的图片作背景图片
}

void TalkWindow::on_tbSpTxt_clicked(bool checked)
{
    if(checked)
    {
        qDebug()<<"使用加粗";
        ui->textEditMessage->setFontPointSize(20);
        ui->textEditMessage->setFontWeight(QFont::Bold);
        ui->textEditMessage->setTextColor(QColor(255, 0, 0));
        ui->textEditMessage->setFocus();
    }
    else
    {
        qDebug()<<"取消加粗";
        ui->textEditMessage->setFontPointSize(10);
        ui->textEditMessage->setFontWeight(QFont::Normal);
        ui->textEditMessage->setTextColor(QColor(0, 0, 0));
        ui->textEditMessage->setFocus();
    }
}

void TalkWindow::on_cbFont_currentFontChanged(const QFont &f)
{
    ui->textEditMessage->setCurrentFont(f);
    ui->textEditMessage->setFocus();
}

void TalkWindow::on_cbNum_currentIndexChanged(const QString &arg1)
{
    ui->textEditMessage->setFontPointSize(arg1.toDouble());
    ui->textEditMessage->setFocus();
}

void TalkWindow::on_tbVoice_clicked(bool checked)
{
    if(checked)
    {
        qDebug()<<"录音开始";
        ui->tbVoice->setText("录音结束");
        //-------------------------------------------------------------------------------
        file=new QFile();
        QString filename=QString("E:\\录音文件_%1.wav").arg( QDateTime::currentMSecsSinceEpoch());
        qDebug()<<filename;
        file->setFileName(filename);

        bool is_open =file->open(QIODevice::WriteOnly | QIODevice::Truncate);
        if(!is_open)
        {
            qDebug()<<"打开失败！"<<endl;
            exit(1);
        }

        QAudioFormat format;
        format.setSampleRate(8000);
        format.setChannelCount(1);
        format.setSampleSize(8);
        format.setCodec("audio/wav");
        format.setByteOrder(QAudioFormat::LittleEndian);
        format.setSampleType(QAudioFormat::UnSignedInt);

        QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
        QString str=info.deviceName();
        qDebug()<<"使用的录音设备是:"<<str<<endl;
        if(!info.isFormatSupported(format))
        {
            format = info.nearestFormat(format);
        }
        input = new QAudioInput(format, this);
        input->start(file);
        //-------------------------------------------------------------------------------

    }
    else
    {
        qDebug()<<"录音结束";
        ui->tbVoice->setText("语音");
        input->stop();
        file->close();
    }
}

void TalkWindow::on_tbPlay_clicked()
{
    QString  fileName = QFileDialog::getOpenFileName(this,
                 tr("打开音频文件"), "E:", tr("wav Files (*.wav)"));
    qDebug()<<fileName;
    file->setFileName(fileName);

    file->open(QIODevice::ReadOnly);

    QAudioFormat format;
    format.setSampleRate(8000);
    format.setChannelCount(1);
    format.setSampleSize(8);
    format.setCodec("audio/wav");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    output = new QAudioOutput(format);
    output->start(file);
}
