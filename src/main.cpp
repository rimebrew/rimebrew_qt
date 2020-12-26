#include <iostream>
#include <QtCore>
#include <QtDebug>
#include <cstdlib>
#include <filesystem>

/* TODO:
 *  Windows -> Dialog to insert a path
 *  Fcitx -> A choice dialog for 4 or 5
*/

std::filesystem::path get_user_data_dir(){

    std::filesystem::path user_data_dir;
#ifdef __linux__

    std::filesystem::path Home = std::filesystem::path(std::getenv("HOME"));
    if (strcmp(std::getenv("INPUT_METHOD"),"ibus") == 0){
        return Home.concat("/.config/ibus/rime/");
    }

#elif defined(__APPLE__)
    std::filesystem::path Home = std::filesystem::path(std::getenv("HOME"));
        return Home.concat("/Library/Rime/");
    #elif defined(__WIN32__)

    #else
        #error Cannot detect complier.
#endif
    return user_data_dir;
}

bool first_run(){
    return std::filesystem::exists(get_user_data_dir());
}


int main(int argc, char *argv[])
{

    return 0;
}
