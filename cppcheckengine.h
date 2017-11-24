#ifndef CPPCHECKENGINE_H
#define CPPCHECKENGINE_H

#include "basesaengine.h"

namespace QtCreatorStaticAnalysisPlugin {
namespace Internal {
class CPPCheckEngine : public BaseSAEngine
{
public:
    CPPCheckEngine(QObject *parent = nullptr):BaseSAEngine("CPPCheck",parent)
    {
        QString programname="cppcheck";
        setProgramName(programname);
        QStringList args;
        args<<"--enable=all";
    }
};
}
}
#endif // CPPCHECKENGINE_H
