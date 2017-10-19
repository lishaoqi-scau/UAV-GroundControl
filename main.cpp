#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK")); //路径名支持中文
//        QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK")); //QString支持中文
//        QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK")); //string支持中文
    a.setWindowIcon(QIcon("://new/GCSProcess/png/GCS.png"));
    MainWindow w;
//    w.show();

    return a.exec();
}
