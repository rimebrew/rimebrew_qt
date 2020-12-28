#ifndef DEFAULT_CUSTOM_H
#define DEFAULT_CUSTOM_H

#include <yaml-cpp/yaml.h>
#include <QSettings>
#include <QDebug>
#include <QtCore>
#include <QFileInfo>
#include <filesystem>
#include <string>
#include <iostream>
#include <fstream>


class default_custom
{
public:
    explicit default_custom();
    void dump_default_custom();

    YAML::Node page_size;
    YAML::Node schema_list;

    void update_page_size(int n);

    void insert_schema(std::string name);
    void remove_schema(std::string name);



private:
    QString default_yaml_dir;
    YAML::Node config;
};

#endif // DEFAULT_CUSTOM_H
