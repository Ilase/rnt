#include "rnt-sys.hpp"

int rnt::PciData::parce_pci_table()
{
    std::vector<std::vector<std::string>> call_data = sys_call("lspci -k | grep -A 2 -E \"(VGA|3D)\"");
    for(const auto& line : call_data){  
        _vendor vnd_b;
        std::string drv_b;
        for(const auto& word : line){
            std::string buff_v = word;
            if(buff_v == vendor(check_vend_t(buff_v))){
                vnd_b = check_vend_t(buff_v);
            }
            if(buff_v == "amdgpu" || buff_v == "nouveau" || buff_v == "i915"){
                drv_b = buff_v;
            }
            if(word == "--") this->pci_table.push_back({vnd_b, drv_b});
        }
    }
    return 0;
}

int rnt::PciData::show_table(){
    for(const auto& line : this->pci_table){
        //std::cout << line.id_bus << "\t" << line.id_vendor << "\t" << line.pci_id  << "\n";
        std::cout << line.kernel_driver << " " << line.vendor_type << "\n";
    }
    return 0;
}
