//
// Created by slb on 2020-12-18.
//

#include <iostream>
#include <yaml-cpp/yaml.h>

int main (int argc, char *argv[])
{
  //load
  YAML::Node root = YAML::LoadFile ("zhuyin.yaml");
  std::cout << root["display_name"] << std::endl;

  // Navigation
  YAML::Node provides = root["provides"];
  std::cout << provides["zhuyin"]["display_name"] << std::endl;

  // Iteratioon
  for (YAML::const_iterator x = provides.begin (); x != provides.end (); ++x)
    {
      std::cout << x->first << " \n " << x->second << " |||||\n " << x->second["files"] << "\n\n";
    };

  YAML::Node builder;
  builder["map_root"] = "value";
  builder["sequence"].push_back ("a element");
  builder["sequence"].push_back ("another elemtn");

  std::cout << builder << std::endl;;

  //YAML emitter

  YAML::Emitter myEmt;
  myEmt << YAML::BeginDoc;
  myEmt << YAML::BeginMap;
  myEmt << YAML::Key << "name";
  myEmt << YAML::Value << "Ryan Braun";
  myEmt << YAML::Key << "position";
  myEmt << YAML::Value << "LF";
  myEmt << YAML::EndMap;
  myEmt << YAML::EndDoc;;

  std::cout << ">>>>>>>>>>>\nEmitter: \n" << myEmt.c_str () << std::endl;

  return 0;
}