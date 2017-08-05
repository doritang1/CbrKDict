#include "MainForm.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainForm w;
    w.showMaximized(); //최대화 상태로 실행

    return a.exec();
}
