#ifndef _RNT_CONFIGURATOR_HPP
#define _RNT_CONFIGURATOR_HPP
#include "rnt.hpp"
#include "rnt-sys.hpp"
#include "rnt-enum.hpp"
#include "rnt-texteditor.hpp"

namespace rnt
{
    /// @brief Provides main changes in textEditor::text and or make opposite files in xorg.conf.d/
    class Configurator : public textEditor
    {

    public:
        Configurator();
        int configure_screen_setup(std::string scr_name);
        int configure_driver_setup();

        /// @brief Generate std::vector with data from lspci and return it
        /// @param  identifier videoadaptor name
        /// @param  vendor vendor name
        /// @param  driver driver name
        /// @param  busid bus_id
        /// @return vector of data
        TextMatrix generate_section_device(std::string, _vendor, std::string, std::string);
    };
}
#endif
