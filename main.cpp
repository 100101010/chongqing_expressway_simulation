#include "mainwindow.h"
#include <QApplication>
#include "initData.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    init();// 初始化数据和结点

    // 运行主程序
    QApplication a(argc, argv);
    MainWindow w;
    w.setMinimumSize(200,200);
    w.showMaximized();

    return a.exec();
}