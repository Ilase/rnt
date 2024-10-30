#include "rnt.hpp"

int main(){
    rnt::textEditor test("/root/xorg.conf.new");
    test.load();
    test.show();

    return 0;
}