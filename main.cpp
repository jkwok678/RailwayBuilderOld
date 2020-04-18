#include "window.h"
#include "map.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Map *currentLayout = new Map;
    Window w;

    w.show();

    return a.exec();
}
