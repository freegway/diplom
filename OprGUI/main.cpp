#include "oprgui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OprGUI w;
    w.show();
    return a.exec();
}
