//
// Created by slbtty on 12/26/20.
//

#ifndef FIRST_RUN_H
#define FIRST_RUN_H

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

private:
private slots:
    void fcitx4_selected();
    void fcitx5_selected();
    void ibus_selected();
//  void win_selected();
    void mac_selected();
    void custom_rime_dir();
    void confirm_usr_dir();
};

#endif //RIMEBREW_FIRST_RUN_H
