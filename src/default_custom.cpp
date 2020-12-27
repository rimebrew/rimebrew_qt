#include "default_custom.h"
#include <QSettings>
#include <QDebug>
#include <QtCore>
#include <QFileInfo>
#include <filesystem>
#include <string>
#include <iostream>
#include <fstream>

#include <yaml-cpp/yaml.h>

default_custom::default_custom()
{

    QCoreApplication::setOrganizationName("rimebrew");
    QCoreApplication::setOrganizationDomain("org.slbtty");
    QCoreApplication::setApplicationName("rimebrew");

    QSettings g_settings;
    QString default_yaml_dir=g_settings.value("global/usrdatadir")
                                       .toString()
                                       .append("default.custom.yaml");

}
