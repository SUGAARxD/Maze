#include "UIClass.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UIClass w;
    w.show();
    return a.exec();
}
