# Plugin Manager

The Plugin Manager is a component of the application responsible for browsing and loading plugins dynamically.

Features

- Browse for plugin files on the file system.
- Load selected plugin files dynamically.
- Provide a mechanism for plugins to initialize and integrate with the application.

## Usage

- **Browse for Plugins**: Click on the "Browse" button to select plugin files. Only files with the .dll extension are recognized as plugins.
- **Load Plugins**: After selecting plugin files, click on the "Load" button to load them into the application. Loaded plugins will be initialized and integrated with the main application.

## How to Use

- **Integration with the Application**: The PluginManager class can be integrated into the main application window or used as a standalone component.
- **Signal Handling**: Connect to the pluginLoaded signal to receive notifications when plugins are successfully loaded. This signal provides a pointer to the loaded plugin.

## Prerequisites

- Qt framework installed on your machine.
- Basic understanding of Qt signals and slots mechanism.

## Example

```cpp
// Example usage of the PluginManager class

#include "PluginManager.h"

// Create an instance of the PluginManager
PluginManager pluginManager;

// Connect to the pluginLoaded signal
QObject::connect(&pluginManager, &PluginManager::pluginLoaded,  {
    // Handle loaded plugin
    qDebug() << "Plugin loaded:" << plugin->name();
});

// Run the application event loop

## License

This project is licensed under the MIT License - see the LICENSE file for details.
