#ifndef _RNT_ENUM_HPP
#define _RNT_ENUM_HPP
#include "rnt.hpp"
namespace rnt {

//====================================//
//          enum declarations         //
//====================================//
    
    enum _vendor{
        Nvidia,
        Amd,
        Intel,
        NOWAY
    };

    enum class _option{
        Identifier,
        Screen,
        ModulePath,
        InputDevice,
        FontPath,
        Load,
        Driver,
        Option,
        VendorName,
        ModelName,
        BusID,
        Viewport,
        Depth,
        TearFree,
        NOWAY
    };

    enum class _tag{
        Section,
        EndSection,
        SubSection,
        EndSubSection,
        NOWAY
    };

    enum class _section{
        ServerLayout,
        Module,
        Files,
        InputDevice,
        Monitor,
        Device,
        Screen,
        NOWAY
    };  

    
    std::string     option(_option);
    std::string     tag(_tag);
    std::string     section(_section);
    std::string     vendor(_vendor);

    _section        check_sec(std::string&);
    _option         check_opt(std::string&);
    _tag            check_tag(std::string&);
    _vendor         check_vend_t(std::string&);
    

}

#endif