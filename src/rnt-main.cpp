#include "rnt.hpp"
/// @brief Main function zalupa polnaya
/// @param argc 
/// @param argv 
/// @return status code
int main(int argc, char const *argv[]){
    // rnt::textEditor test("/root/xorg.conf.new");
    // test.load();
    // test.show();
    // test.reload_tag_table();
    // test.show_tag_table();
    rnt::Configurator app("/etc/X11/xorg.conf");
    app.load();
    app.reload_tag_table();
    app.show();
    
    return 0;
}