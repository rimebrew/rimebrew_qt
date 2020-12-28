#include "default_custom.h"


static std::string filr_form_home(QString s) {
    if ((s == "~") || (s.startsWith("~/"))) {
        s.replace (0, 1, QDir::homePath());
    }
    return s.toStdString();
}

default_custom::default_custom()
{

    QCoreApplication::setOrganizationName("rimebrew");
    QCoreApplication::setOrganizationDomain("org.slbtty");
    QCoreApplication::setApplicationName("rimebrew");

    QSettings g_settings;

    default_yaml_dir=g_settings.value("global/usrdatadir")
                                       .toString()
                                       .append("default.custom.yaml");

    config = YAML::LoadFile(filr_form_home(default_yaml_dir));

    // Check this if  you feels the code below is werid.
    // https://github.com/rime/librime/blob/4e518b96a381c5ee2e82d43247d9f49886af8b75/tools/rime_deployer.cc

    page_size=config["patch"]["menu"]["page_size"];
    schema_list=config["patch"]["schema_list"];
    std::cout<<config<<std::endl;
//    std::cout<<"nice"<<std::endl;


////  std::cout<<schema_list.size()<< schema_list.IsMap();
//    std::cout<<schema_list[2]["schema"]<<std::endl;
//    schema_list[3]["schema"]="nice";

//    std::cout<<config<<std::endl;
//    schema_list.remove(3);
//    std::cout<<config<<std::endl;

}


void default_custom::insert_schema(std::string name){
    schema_list[schema_list.size()]["schema"]=name;
};

void default_custom::remove_schema(std::string name){
    for (std::size_t i=0;i<schema_list.size();i++) {
      std::string cur=schema_list[i]["schema"].as<std::string>();

      if(cur.compare(name) != 0){
          schema_list.remove(i);
      }
    }
};

void default_custom::update_page_size(int n){
    page_size=n;
}

void default_custom::dump_default_custom(){
    std::ofstream yaml_out(filr_form_home(default_yaml_dir));
    yaml_out<<config;

}
