#include "rnt-configurator.hpp"

int rnt::Configurator::configure_screen_setup(std::string scr_name)
{
    return 0;
}

int rnt::Configurator::configure_driver_setup()
{
    return 0;
}

std::vector<std::vector<std::string>> rnt::Configurator::generate_section_device(std::string, _vendor, std::string, std::string)
{
    return std::vector<std::vector<std::string>>();
}
