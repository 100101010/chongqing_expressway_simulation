//
// Created by 帆桥 on 2019/6/26.
//

#include "ui_randomSelect.h"
#include "randomSelect.h"
#include "initData.hpp"
#include "Utils/otherUsefulUtility.hpp"
#include <string>
#include <random>
#include <memory>
#include <time.h>
#include <iostream>
#include <QTextCodec>

Dialog2::Dialog2(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::Dialog2)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    ui->setupUi(this);
    ui->lineEdit->setEnabled(false);
    ui->lineEdit_2->setEnabled(false);
    this->setWindowTitle("随机预警生成");
    randomGenerateNode();
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::randomGenerateNode() {
    std::default_random_engine engine(time(nullptr));
    std::uniform_int_distribution<unsigned> u(1, 100000);
    int randomNumber1;
    do{
        randomNumber1 = u(engine)%countNodes+1;
    }while (!judge(randomNumber1) && !judgePre(randomNumber1));
    int randomNumber2 = u(engine)%2+1;
    std::string tem = GBKToUTF8(Nodes[randomNumber1].c_str());
    ui->lineEdit->setText(tem.c_str());
    ui->lineEdit_2->setText(std::to_string(randomNumber2).c_str());
}

void Dialog2::sendInfo2() {
    emit dialog_send_a_signal2(ui->lineEdit->text()+":"+ui->lineEdit_2->text());
    close();
}

void Dialog2::changeNode() {
    randomGenerateNode();
}