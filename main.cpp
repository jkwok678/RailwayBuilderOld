#include "window.h"
#include "map.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
    Map currentLayout = new Map;

    w.show();

    return a.exec();
}
