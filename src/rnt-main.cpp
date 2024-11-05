#include "rnt.hpp"
#include "rnt-sys.hpp"
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
    rnt::PciData data;

    data.parce_pci_table();
    data.show_table();

    // std::vector<std::vector<std::string>>pars(rnt::sys_call("lspci -k | grep -A 2 -E \"(VGA|3D)\""));
    // std::cout << std::endl;
    // for(const auto& line : pars){
    //     for(const auto& word : line){
    //         std::cout << word << " "; 
    //     }
    //     std::cout << "\n";
    // }
    
    
    
    return 0;
}