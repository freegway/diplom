#include "cmdgui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CmdGUI w;
    w.show();
    return a.exec();
}
