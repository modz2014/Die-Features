#ifndef PLUGINEXAMPLE_H
#define PLUGINEXAMPLE_H

#include "pluginexample_global.h"
#include "plugininterface.h"
#include <QObject>

class PLUGINEXAMPLE_EXPORT PluginExample : public PluginInterface
{
    Q_OBJECT

public:
    explicit PluginExample(QObject *parent = nullptr)
        : PluginInterface(parent) {}

    void setParentWidget(QWidget* parent) override;
    void initialize() override;
    void execute() override;
signals:

    void pluginLoadedWithButton();
    void pluginInitialized();
    void pluginExecuted();
};


#endif // PLUGINEXAMPLE_H
