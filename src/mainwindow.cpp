#include "mainwindow.h"
#include<QMainWindow>
#include<QDebug>
#include<QPushButton>
mainwindow::mainwindow(QWidget *parent)
    :QMainWindow(parent)
{
    setupUi(this);
    connect(this->apply_btn,&QPushButton::clicked,this,&mainwindow::save_settings);
}


mainwindow::~mainwindow()
{
    delete this;
}


void mainwindow::save_settings(){
    qDebug()<<this->radio_horizontal->isChecked();

}
