//
// Created by 帆桥 on 2019/6/26.
//

#ifndef CLIONCODE_RANDOMSELECT_H
#define CLIONCODE_RANDOMSELECT_H
#include <QDialog>

namespace Ui {
    class Dialog2;
}

class Dialog2 : public QDialog
{
Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = 0);
    ~Dialog2();
    void randomGenerateNode();

private:
    Ui::Dialog2 *ui;

signals:
    void dialog_send_a_signal2(QString dia_to_main_msg);//定义子窗口向主窗口发送数据的信号

public slots:
    void sendInfo2();
    void changeNode();
};
#endif //CLIONCODE_RANDOMSELECT_H
