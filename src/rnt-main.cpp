#include "rnt.hpp"

int main(){
    rnt::textEditor test("/root/xorg.conf.new");
    test.load();
    test.show();
    test.show_tag_table();

    return 0;
}