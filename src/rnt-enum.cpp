#include "rnt-enum.hpp"



std::string rnt::option(_option s) {
    switch(s){
        case _option::Identifier: return "Identifier";
        case _option::Screen: return "Screen";
        case _option::InputDevice: return "InputDevice";
        case _option::ModulePath: return "ModulePath";
        case _option::FontPath: return "FontPath";
        case _option::Load: return "Load";
        case _option::Driver: return "Driver";
        case _option::VendorName: return "Option";
        case _option::ModelName: return "VendorName";
        case _option::BusID: return "BusID";
        case _option::Viewport: return "Viewport";
        case _option::Depth: return "Depth";
        case _option::NOWAY: return "<empty>";
        default: return "invalid option";
        //default: throw std::invalid_argument("Unimpliment item");
    }
}

std::string rnt::tag(_tag s) {
    switch(s){
        case _tag::Section: return "Section";
        case _tag::EndSection: return "EndSection";
        case _tag::SubSection: return "SubSection";
        case _tag::EndSubSection: return "EndSubSection";
        case _tag::NOWAY: return "<empty>";
        default: return "invalid tag";
        //default: throw std::invalid_argument("Unimpliment item");
    }
}

std::string rnt::section(_section s) {
    switch(s){
        case _section::ServerLayout: return "\"ServerLayout\"";
        case _section::Module: return "\"Module\"";
        case _section::Files: return "\"Files\"";
        case _section::InputDevice: return "\"InputDevice\"";
        case _section::Monitor: return "\"Monitor\"";
        case _section::Device: return "\"Device\"";
        case _section::Screen: return "\"Screen\"";
        case _section::NOWAY: return "<empty>";
        default: return "invalid section";
        // default: throw std::invalid_argument("Unimpliment item");
    }
}
std::string rnt::vendor(_vendor s){
    switch(s){
        case _vendor::Amd: return "AMD";
        case _vendor::Nvidia: return "NVIDEA";
        case _vendor::Intel:return "Intel";
        case _vendor::NOWAY: return "<empty>";
        default: return "invalid section";
    }
}


rnt::_section rnt::check_sec(std::string& word)
{
    for(size_t i = 0; i < static_cast<int>(_section::NOWAY); ++i){
        std::string _buff = section(static_cast<_section>(i));
        if(word == _buff){
            return static_cast<_section>(i);
        }
    }
    
    return _section::NOWAY;
}

rnt::_option rnt::check_opt(std::string& word)
{
    for(size_t i = 0; i < static_cast<int>(_option::NOWAY); ++i){
        std::string _buff = option(static_cast<_option>(i));
        if(word == _buff){
            return static_cast<_option>(i);
        }
    }
    return _option::NOWAY;
}

rnt::_tag rnt::check_tag(std::string& word){
    for(size_t i = 0; i < static_cast<int>(_tag::NOWAY); ++i){
        std::string _buff = tag(static_cast<_tag>(i));
        if(word == _buff){
            return static_cast<_tag>(i);
        }
    }
    return _tag::NOWAY;
}
rnt::_vendor rnt::check_vend_t(std::string& word){
    for(size_t i = 0; i < static_cast<int>(_vendor::NOWAY); ++i){
        std::string _buff = vendor(static_cast<_vendor>(i));
        if(word == _buff){
            return static_cast<_vendor>(i);
        }
    }
    return _vendor::NOWAY;
}