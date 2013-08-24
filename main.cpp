#include "wordlistmaker.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WordListMaker w;
    w.show();
    
    return a.exec();
}
