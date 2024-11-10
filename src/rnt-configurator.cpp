#include "rnt-configurator.hpp"

int rnt::Configurator::configure_screen_setup(std::string scr_name)
{
    return 0;
}

int rnt::Configurator::configure_driver_setup()
{
    return 0;
}

TextMatrix rnt::Configurator::generate_section_device(std::string identifier, _vendor vendor /* = _vendor::NOWAY*/, std::string driver, std::string bus_id /*= "0"*/)
{   
    TextMatrix result;
    result.push_back({tag(_tag::Section), section(_section::Device)});
    result.push_back({option(_option::Identifier), add_dc(identifier)});
    result.push_back({option(_option::BusID), add_dc(bus_id)});
    result.push_back({option(_option::Driver), add_dc(driver)});
    result.push_back({tag(_tag::EndSection)});
    return result;
}
