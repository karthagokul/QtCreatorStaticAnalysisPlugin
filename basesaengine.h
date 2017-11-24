#ifndef BASESAENGINE_H
#define BASESAENGINE_H

#include <QObject>
#include <QDebug>
#include <QProcess>
#include <coreplugin/messagemanager.h>
#include <QMessageBox>
#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>

namespace QtCreatorStaticAnalysisPlugin {
namespace Internal {
class BaseSAEngine : public QObject
{
    Q_OBJECT
public:
    explicit BaseSAEngine(QString aName,QObject *parent = nullptr):QObject(parent),
        mName(aName)
    {
        mProcess.setParent(parent);
    }
    virtual void run()
    {
        /*Experiments*/
        QStringList args=mProcess.arguments();
        args<<mFilePath;
       // mProcess.setArguments(args);
       // mProcess.execute("cppcheck",args);
        QMessageBox::information(Core::ICore::mainWindow(),
                                 tr("Action Triggered"),
                                 mProcess.program());
    }

    virtual bool setProgramName(const QString &aProgramName)
    {
        mProcess.setProgram(aProgramName);
        return true;
    }
    virtual bool setArguments(const QStringList &aArgs)
    {
        mProcess.setArguments(aArgs);
        return true;
    }
    virtual bool setCurrentFileName(const QString &aFilePath)
    {
        mFilePath=aFilePath;
        return true;
    }

signals:

public slots:

private:
    QProcess mProcess;
    QString mName;
    QString mFilePath;
};
}
}

#endif // BASESAENGINE_H
