//
// Created by slbtty on 12/26/20.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "./ui_rimebrew.h"

class mainwindow: public QMainWindow, private Ui::rimebrew_main
{
    Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow();

public slots:
    void save_settings();

//signals:
//    void want_new_schema();



};
#endif // MAINWINDOW_H
