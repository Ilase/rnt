#include "rnt-sys.hpp"

int rnt::PciData::parce_pci_table()
{
    std::vector<std::vector<std::string>> call_data = sys_call("lspci -n");
    for(const auto& line : call_data){
        this->pci_table.push_back(DataField({line[0], line[1], line[3], line[4]}));
        
    }
    return 0;
}

int rnt::PciData::show_table(){
    for(const auto& line : this->pci_table){
        std::cout << line.id_bus << "\t" << line.id_vendor << "\t" << line.pci_id  << "\n";
    }
    return 0;
}
