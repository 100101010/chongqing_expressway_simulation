//
// Created by 帆桥 on 2019/6/24.
//

#include "ui_CountSelect.h"
#include "CountSelect.h"
#include <QMessageBox>
#include "initData.hpp"
#include "Utils/otherUsefulUtility.hpp"

Dialog::Dialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::Dialog)
{
    ui->setupUi(this);
    for(auto item:Nodes)
        ui->comboBox->addItem(GBKToUTF8(item.c_str()).c_str());
    this->setWindowTitle("选择预警信息");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::sendInfo() {
    if (ui->comboBox->currentText()=="请选择结点")
        QMessageBox::warning(this,"warning","请选择结点！",QMessageBox::Ok | QMessageBox::Cancel,QMessageBox::Cancel);
    else if (ui->comboBox_2->currentText()=="请选择预警级别")
        QMessageBox::warning(this,"warning","请选择预警级别!",QMessageBox::Ok | QMessageBox::Cancel,QMessageBox::Cancel);
    else{
        emit dialog_send_a_signal(ui->comboBox->currentText()+":"+ui->comboBox_2->currentText());
        close();
    }
}
