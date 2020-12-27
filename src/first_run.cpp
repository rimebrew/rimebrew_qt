//
// Created by slbtty on 12/26/20.
//

#include <iostream>
#include <QRadioButton>
#include <QtCore>
#include <QLineEdit>
#include <QFileDialog>
#include <QDir>
#include <QPushButton>
#include <QSettings>

#include "first_run.h"

FirstRun::FirstRun(QWidget *parent)
    :QWidget(parent)
{
    setupUi(this);
    this->setWindowFlag(Qt::Dialog);

    connect(this->radio_fcitx4,&QRadioButton::clicked,this,&FirstRun::fcitx4_selected);
    connect(this->radio_fcitx5,&QRadioButton::clicked,this,&FirstRun::fcitx5_selected);
    connect(this->radio_ibus,&QRadioButton::clicked,this,&FirstRun::ibus_selected);
    connect(this->radio_squ,&QRadioButton::clicked,this,&FirstRun::mac_selected);

    connect(this->custom_path_btn,&QRadioButton::clicked,this,&FirstRun::custom_rime_dir);
    connect(this->ok_btn,&QPushButton::clicked,this,&FirstRun::confirm_usr_dir);
}

FirstRun::~FirstRun()
{
    delete this;
}

void FirstRun::custom_rime_dir(){
    QDir custom_path;
    custom_path.setPath( QFileDialog::getExistingDirectory(this,
        "选择 RIME 配置文件目录"));
    this->path_edit->setText(custom_path.absolutePath());
}

void FirstRun::confirm_usr_dir(){

       QSettings g_settings;
       g_settings.setValue("global/usrdatadir",this->path_edit->text());
       g_settings.setValue("global/configured",1);
       this->hide();
}

void FirstRun::fcitx4_selected()
{
    this->path_edit->setText("~/.config/fcitx/rime/");
}

void FirstRun::fcitx5_selected()
{
    this->path_edit->setText("~/.local/share/fcitx5/rime/");
}

void FirstRun::ibus_selected()
{
    this->path_edit->setText("~/.config/ibus/rime/");
}

void FirstRun::mac_selected()
{
    this->path_edit->setText("~/Library/Rime/");
}

//void FirstRun::win_selected()
//{
//    this->path_edit->setText("~/.config/fcitx/rime/");
//}

