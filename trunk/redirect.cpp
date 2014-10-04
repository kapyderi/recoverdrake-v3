#include "redirect.h"
#include "drakesistema.h"

CRedirect::CRedirect()
{
    drakeSistema drake;
    User = drake.getUser();
    Hostname = drake.getHostname();
}

CRedirect::~CRedirect()
{}

bool CRedirect::StartChildProcess(bool bShowChildWindow)
{
    Q_UNUSED(bShowChildWindow);
    process = new QProcess();
    process->setProcessChannelMode(QProcess::MergedChannels);
    connect(process, SIGNAL(readyReadStandardError()), this, SLOT(readyReadStandardError()));
    connect(process, SIGNAL(readyReadStandardOutput()), this, SLOT(readyReadStandardOutput()));
    //process->start("");//sh");
    //process->write(User+"@"+Hostname+">\n");
    return true;
}

bool CRedirect::IsChildRunning() const
{
    return true;
}

int CRedirect::ProcessThread()
{
    return 0;
}

void CRedirect::WriteChildStdIn(QString szInput)
{    
    process->start(szInput);
    //process->write(szInput.toLatin1());
    //process->write(User+"@"+Hostname+">\n");
}

void CRedirect::readyReadStandardOutput()
{
    QString str = process->readAllStandardOutput();
    emit OnChildStdOutWrite(str);
}

void CRedirect::readyReadStandardError()
{
    emit OnChildStdErrWrite(QString(process->readAllStandardError()));
}
