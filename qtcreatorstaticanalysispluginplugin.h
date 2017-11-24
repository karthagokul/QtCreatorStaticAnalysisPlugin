#pragma once

#include "qtcreatorstaticanalysisplugin_global.h"

#include <extensionsystem/iplugin.h>

namespace QtCreatorStaticAnalysisPlugin {
namespace Internal {

class QtCreatorStaticAnalysisPluginPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "QtCreatorStaticAnalysisPlugin.json")

public:
    QtCreatorStaticAnalysisPluginPlugin();
    ~QtCreatorStaticAnalysisPluginPlugin();

    bool initialize(const QStringList &arguments, QString *errorString);
    void extensionsInitialized();
    ShutdownFlag aboutToShutdown();

private:
    void triggerAction();
};

} // namespace Internal
} // namespace QtCreatorStaticAnalysisPlugin
