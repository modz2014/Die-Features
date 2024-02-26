#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include "../pluginexample1/plugininterface.h"
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QLibrary>
#include <QDebug>
#include <QMainWindow> 

class PluginManager : public QMainWindow
{
    Q_OBJECT

public:
    explicit PluginManager(QWidget *parent = nullptr);

signals:
   void pluginLoaded(PluginInterface *plugin);
private slots:
    void browsePlugins();
    void loadPlugins();
private:
    QMainWindow *m_mainWindow;
    QVBoxLayout *m_layout;
    QPushButton *m_browseButton;
    QPushButton *m_loadButton;
    QString m_selectedPluginPath;
    QList<PluginInterface *> m_plugins;
};

#endif // PLUGINMANAGER_H
