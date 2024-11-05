#ifndef _RNT_CONFIGURATOR_HPP
#define _RNT_CONFIGURATOR_HPP
#include "rnt.hpp"
#include "rnt-sys.hpp"
#include "rnt-enum.hpp"
namespace rnt{
    class Configurator{
        _vendor vendor;

        public:
            Configurator();
            int configure_screen_setup(std::string scr_name); 
            int configure_driver_setup();
    };
}
#endif
