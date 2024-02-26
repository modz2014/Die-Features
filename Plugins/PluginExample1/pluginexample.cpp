#include "pluginexample.h"
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>
#include <QLayout>

// Implementation of PluginExample member functions
void PluginExample::initialize()
{
    qDebug() << "Entering initialize function";

    qDebug() << "PluginExample initialized";
    emit pluginInitialized();

    // Use the PluginManager (main window) as the parent widget
    QWidget *parentWidget = qobject_cast<QWidget*>(this->parent());

    if (!parentWidget) {
        qWarning() << "Failed to add button to layout: parent is not a QWidget";
        qDebug() << "Exiting initialize function due to no parent widget";
        return;
    }

    qDebug() << "Parent widget:" << parentWidget;
    qDebug() << "Parent widget object name:" << parentWidget->objectName();
    qDebug() << "Parent widget class name:" << parentWidget->metaObject()->className();

    // Create a button
    QPushButton *button = new QPushButton("Test Button", parentWidget);

    // Connect the button click signal to a slot
    QObject::connect(button, &QPushButton::clicked, this, []{
            QMessageBox::information(nullptr, "Button Clicked", "Button clicked");
        });

    // Get the layout of the parent widget
    QLayout *layout = parentWidget->layout();

    if (!layout) {
        qWarning() << "Failed to add button to layout: parent widget has no layout";
        qDebug() << "Exiting initialize function due to no layout";
        return;
    }

    qDebug() << "Layout object name:" << layout->objectName();
    qDebug() << "Layout class name:" << layout->metaObject()->className();

    // Add the button to the layout
    layout->addWidget(button);

    // Emit the signal
    emit pluginLoadedWithButton();

    qDebug() << "Exiting initialize function successfully";
}

void PluginExample::setParentWidget(QWidget* parent)
{
    this->setParent(parent);
}

void PluginExample::execute()
{
    qDebug() << "PluginExample executed";
    emit pluginExecuted();

    // Display a message box
    QMessageBox::information(nullptr, "Plugin Example", "PluginExample executed");
}

// Implementation of createPlugin function
extern "C" PLUGINEXAMPLE_EXPORT PluginInterface* createPlugin()
{
    PluginExample *plugin = new PluginExample();
    plugin->initialize(); // Emit signal when plugin is initialized
    return plugin;
}
