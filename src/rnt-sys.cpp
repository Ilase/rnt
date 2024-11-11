#include "rnt-sys.hpp"

rnt::PciData::PciData(){
    parce_pci_table();
}

int rnt::PciData::parce_pci_table()
{
    this->pci_table.clear();
    std::vector<std::vector<std::string>> call_data = sys_call("lspci -k | grep -A 2 -E \"(VGA)\"");
// #ifdef DEBUG
//     for(const auto& line : call_data){
//         std::cout << DEBUG;
//         for(const auto& word : line){
//             std::cout << word << " ";
//         }
//         std::cout << "\n";
//     }
// #endif // DEBUG    
    std::string _bus_id_f;
    std::string _vendor_f;
    std::string _driver_f;
    for(const auto& line : call_data){  
        for(const auto& word : line){
            if(std::regex_match(word, bus_id_pattern)){
                _bus_id_f = word;
            }
            if(word == "NVIDIA"){
                _vendor_f = word;
            }
            if(word == "noveau"){
                _driver_f = word;
            }
        }
    }
    this->pci_table.push_back({_bus_id_f, check_vend_t(_vendor_f),_driver_f });

    return 0;
}

int rnt::PciData::show_table(){
    for(const auto& line : this->pci_table){
        std::cout << line.id_bus << "\t" << line.vendor_type << "\t" << line.kernel_driver  << "\n";
        //std::cout << line.kernel_driver << " " << line.vendor_type << "\n";
    }
    return 0;
}
