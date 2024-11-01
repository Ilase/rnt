#ifndef _RNT_ENUM_HPP
#define _RNT_ENUM_HPP
#include "rnt.hpp"
namespace rnt {

   enum _type{
        NVIDIA,
        AMD,
        INTEL
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

    
    /// @brief Enum converts to c string 
    /// @param  std::sting s 
    /// @return string equvalent 
    std::string option(_option s);
    std::string tag(_tag s);
    std::string section(_section s);

    _section check_sec(std::string&);
    _option check_opt(std::string&);
    _tag check_tag(std::string&);
    //int reload_config();

}

#endif