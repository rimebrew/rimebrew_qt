//
// Created by slbtty on 12/26/20.
//


#ifndef RIMEBREW_FIRST_RUN_H
#define RIMEBREW_FIRST_RUN_H

#include <QWidget>

#include "./ui_first_run.h"


// 1. Set up usr_data_dir
// 2. Save it to a config file under usr_data_dir

class FirstRun: public QWidget, private Ui::FirstRun
{
    Q_OBJECT

public:
    explicit FirstRun(QWidget *parent = nullptr);
    ~FirstRun();

public slots:
    static void printhello();
};


#endif //RIMEBREW_FIRST_RUN_H
