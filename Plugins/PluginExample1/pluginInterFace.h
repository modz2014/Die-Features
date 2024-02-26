#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H

#include <QCheckBox>
#include <QObject>

class PluginInterface : public QObject
{
    Q_OBJECT

public:
    explicit PluginInterface(QObject *parent = nullptr) : QObject(parent) {}

    virtual void initialize() = 0;
    virtual void execute() = 0;
    virtual void setParentWidget(QWidget* parent) = 0;

signals:
    void pluginInitialized();
    void pluginExecuted();
};


#endif // PLUGININTERFACE_H
