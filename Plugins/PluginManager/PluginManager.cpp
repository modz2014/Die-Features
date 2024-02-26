#include "PluginManager.h"
#include <QFileDialog>

PluginManager::PluginManager(QWidget *parent)
    : QMainWindow(parent)
{
    // Set the initial window size
    resize(400, 200); // Adjust the dimensions as needed

    // Create a central widget
    QWidget *centralWidget = new QWidget(this);

    m_layout = new QVBoxLayout(centralWidget);

    m_browseButton = new QPushButton(this);
    m_browseButton->setIcon(QIcon(":/icons/open.png")); // Set icon
    m_browseButton->setText("Browse");
    connect(m_browseButton, &QPushButton::clicked, this, &PluginManager::browsePlugins);
    m_layout->addWidget(m_browseButton);

    m_loadButton = new QPushButton(this);
    m_loadButton->setIcon(QIcon(":/icons/load.png")); // Set icon
    m_loadButton->setText("Load");
    m_loadButton->setEnabled(false);
    connect(m_loadButton, &QPushButton::clicked, this, &PluginManager::loadPlugins);
    m_layout->addWidget(m_loadButton);

    // Set the central widget
    setCentralWidget(centralWidget);
}


void PluginManager::browsePlugins()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Select Plugin", "", "Plugin Files (*.dll)");
    if (!filePath.isEmpty())
    {
        m_selectedPluginPath = filePath;
        m_loadButton->setEnabled(true);
    }
}

void PluginManager::loadPlugins()
{
    QDir dir(QFileInfo(m_selectedPluginPath).path()); // Get the directory of the selected plugin
    QStringList filters;
    filters << "*.dll"; // Assuming plugins are dynamic libraries (.dll on Windows)
    dir.setNameFilters(filters);

    qDebug() << "Loading plugins from directory:" << dir.path(); // Debug output

    foreach (const QString &fileName, dir.entryList(QDir::Files)) {
        qDebug() << "Loading plugin:" << fileName; // Debug output

        QLibrary library(dir.absoluteFilePath(fileName));
        if (library.load()) {
            qDebug() << "Plugin loaded successfully:" << fileName; // Debug output

            typedef PluginInterface* (*CreatePlugin)();
            CreatePlugin createPlugin = reinterpret_cast<CreatePlugin>(library.resolve("createPlugin"));
            if (createPlugin) {
                PluginInterface *plugin = createPlugin();
                if (plugin) {
                    // Pass the main window to the plugin's initialize function
                    plugin->setParentWidget(this);  // Add this line
                    plugin->initialize();
                    m_plugins.append(plugin); // Use append for QList
                    emit pluginLoaded(plugin); // Emit signal with loaded plugin
                } else {
                    qWarning() << "Failed to create plugin object:" << fileName;
                }
            } else {
                qWarning() << "Failed to resolve createPlugin function:" << fileName;
            }
        } else {
            qWarning() << "Failed to load plugin:" << fileName << "-" << library.errorString();
        }
    }
}

