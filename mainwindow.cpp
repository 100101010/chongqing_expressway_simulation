//
// Created by 帆桥 on 2019/6/19.
//

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "Utils/otherUsefulUtility.hpp"
#include "algorithms/binarySearch.hpp"
#include <iostream>
#include "initData.hpp"
#include "algorithms/dijkstra.hpp"
#include "Utils/drawImagePy.hpp"
#include "algorithms/dijkstraByMinHeap.hpp"
#include "algorithms/dijkstraByQuickSort.hpp"
#include "algorithms/dijkstraByAVL.hpp"

extern const int INFF = 0x3c3c3c3c - 1;

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString filename("F:\\ClionCode\\images\\abc.jpg");
    QImage* img=new QImage;
    if(! ( img->load(filename) ) ) //加载图像
    {
        QMessageBox::information(this,
                                 tr("打开图像失败"),
                                 tr("打开图像失败!"));
        delete img;
        return;
    }
    ui->label->setPixmap(QPixmap::fromImage(*img));
    ui->label->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CountShow() {
    dlg = new Dialog();
    connect(dlg,SIGNAL(dialog_send_a_signal(QString)),this,SLOT(mainwindow_receive_a_signal(QString)));
    dlg->exec();
}

void MainWindow::RandomShow() {
    dlg2 = new Dialog2();
    connect(dlg2,SIGNAL(dialog_send_a_signal2(QString)),this,SLOT(mainwindow_receive_a_signal2(QString)));
    dlg2->randomGenerateNode();
    dlg2->exec();
}

// 接受子窗口2传回来的数据
void MainWindow::mainwindow_receive_a_signal2(QString dia_to_main_msg)
{
    handleInfo(dia_to_main_msg);
}

// 接受子窗口1传回来的数据
void MainWindow::mainwindow_receive_a_signal(QString dia_to_main_msg)
{
    handleInfo(dia_to_main_msg);
}

void MainWindow::handleInfo(QString dia_to_main_msg) {
    std::string str = dia_to_main_msg.toStdString();
    Util::Vector<std::string> temp = split(str, ":");
    std::string name = UTF8ToGBK(temp[0].c_str());

    int num = std::atoi(temp[1].c_str());
    int num1 = binarySearch(nodesMap, name, 0, countNodes);

//    无任何优化
//    dijkstra(num1);

//    最小堆优化
//    dijkstraByMinHeap(num1);

//    快排优化
//    dijkstraByQuickSort(num1);

//    二叉搜索树优化
    dijkstraByAVL(num1);

//    输出选定结点
//    std::cout<<num1<<std::endl;

//    找到最近救援结点
    int minx = INFF, index = 0;
    for (int i = 0; i < rescueNodes.size(); ++i) {
        if (dist[rescueNodes[i]]<minx){
            minx = dist[rescueNodes[i]];
            index = rescueNodes[i];
        }
    }
//    输出最近结点标号
//    std::cout<<index<<std::endl;

//     输出结点路径（通过编号代替）
//    for (int i = 0; i < Path[index-1].size(); ++i) {
//        std::cout<<Path[index-1][i]<<" ";
//    }
//    std::cout<<std::endl;

    generate(Path[index-1]);
}