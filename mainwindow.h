//
// Created by 帆桥 on 2019/6/19.
//

#ifndef CLIONCODE_MAINWINDOW_H
#define CLIONCODE_MAINWINDOW_H

#include <QMainWindow>
#include "CountSelect.h"
#include "randomSelect.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Dialog *dlg;
    Dialog2 *dlg2;

public slots:
    void CountShow(); // 弹出选择结点以及预警级别对话框
    void RandomShow(); // 弹出随机选择结点和预警级别对话框
    void mainwindow_receive_a_signal(QString dia_to_main_msg);//定义接收Dialog窗口发来信号的槽函数
    void mainwindow_receive_a_signal2(QString dia_to_main_msg);//定义接收Dialog2窗口发来信号的槽函数
    void handleInfo(QString dia_to_main_msg);
};
#endif //CLIONCODE_MAINWINDOW_H
