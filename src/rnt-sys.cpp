#include "rnt-sys.hpp"

rnt::PciData::PciData(){
    parce_pci_table();
}

int rnt::PciData::parce_pci_table()
{
    this->pci_table.clear();
    TextMatrix call_data = sys_call("lspci -k | grep -A 2 -E \"(VGA|3D)\""); 
    DataField buff_field;
    for(auto& line : call_data){
        for (auto& word : line){
            if(word == "--"){this->pci_table.push_back(buff_field);} else { 
                if(std::regex_match(word, bus_id_pattern)){
                    buff_field.id_bus = word;
                }
                if(word == vendor(check_vend_t(word))){
                    buff_field.vendor_type = word;
                }
                if(word == driver(check_driver(word))){
                    buff_field.kernel_driver = word;
                }
            }
        }
    }
    this->pci_table.push_back(buff_field);
    


    return 0;
}

int rnt::PciData::show_table(){
    std::cout << "List short vidoadapters: \n"
        << "Bus Id\tVendor\tDriver\n";    
    for(const auto& line : this->pci_table){
        std::cout << line.id_bus << "\t" << line.vendor_type << "\t" << line.kernel_driver  << "\n";
        //std::cout << line.kernel_driver << " " << line.vendor_type << "\n";
    }
    return 0;
}
