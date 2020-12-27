//
// Created by slbtty on 12/26/20.
//

#include "first_run.h"
#include <iostream>
#include <QRadioButton>
#include <QtCore>

FirstRun::FirstRun(QWidget *parent)
    :QWidget(parent)
{
    setupUi(this);

    connect(this->radio_fcitx4,&QRadioButton::clicked,this,&FirstRun::printhello);

}

FirstRun::~FirstRun()
{
    delete this;
}

void FirstRun::printhello()
{
    qDebug() << "Hallo";

}
