//
// Created by 帆桥 on 2019/6/24.
//

#ifndef CLIONCODE_COUNTSELECT_H
#define CLIONCODE_COUNTSELECT_H
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;

signals:
    void dialog_send_a_signal(QString dia_to_main_msg);//定义子窗口向主窗口发送数据的信号

public slots:
    void sendInfo();
};

#endif // DIALOG_H

#endif //CLIONCODE_COUNTSELECT_H
