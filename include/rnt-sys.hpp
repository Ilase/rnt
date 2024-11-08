#ifndef _RNT_SYS_HPP
#define _RNT_SYS_HPP
#include "rnt.hpp"
#include "rnt-enum.hpp"


namespace rnt{


    struct DataField{
        // std::string id_bus;
        // std::string id_vendor;
        // std::string pci_id;
        // std::string revision_id;
        _vendor vendor_type;
        std::string kernel_driver;
    };
    class PciData{
            std::vector<DataField> pci_table;
        public:
            //PciData();
            int parce_pci_table();
            int show_table();            
            


        friend class Configurator;
    };

}

#endif