#include <QApplication>
#include "PluginManager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PluginManager manager;
    manager.show();

    return a.exec();
}
