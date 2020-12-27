#include "mainwindow.h"
#include<QMainWindow>

mainwindow::mainwindow(QWidget *parent)
    :QMainWindow(parent)
{
    setupUi(this);
}



mainwindow::~mainwindow()
{
    delete this;
}
