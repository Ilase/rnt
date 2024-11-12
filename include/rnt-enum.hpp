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
    enum class _driver{
        // nvidia
        noveau,
        nvidia,
        nvidia_drm,
        nv,
        // amd
        amdgpu,
        ati,
        radeon,
        // intel
        intel,
        modesetting,
        i915,
        intel_drv,
        // other
        NOWAY
    };
//========================================================//
//--------------------------------------------------------//
//========================================================//

    std::string     option(_option);
    std::string     tag(_tag);
    std::string     section(_section);
    std::string     vendor(_vendor);
    std::string     driver(_driver);

    _section        check_sec(std::string&);
    _option         check_opt(std::string&);
    _tag            check_tag(std::string&);
    _vendor         check_vend_t(std::string&);
    _driver         check_driver(std::string&);
//========================================================//
//--------------------------------------------------------//
//========================================================//
    bool            operator==(std::string, const _vendor&);
    bool            operator==(std::string, const _option&);
    bool            operator==(std::string, const _section&);
    bool            operator==(std::string, const _tag&);
    bool            operator==(std::string, const _driver&);
}

#endif