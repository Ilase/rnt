#ifndef _RNT_HPP
#define _RNT_HPP

#include <vector>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <string>
#include <algorithm>
#include <optional>
#include <unordered_map>
#include <exception>
#include <functional>
#include <map>
#include <variant>
#include <filesystem>

#define RNT_PR "[RNT] "
#define RNT_ERR "[RNT-ERR] "



namespace fs = std::filesystem;

namespace rnt{
    /// @brief Handler for my poops
    /// @param  
    /// @param  
    void rnt_handler(std::exception&, std::string);
    //================================================
    /// @brief DO NOT TOUCH THIS SHIIT
    const std::map<
        std::string,
        std::variant<
            std::function<void()>
        >
    > comand_map = {
        {
            "--show",
            []() -> void {

            }
        }
    };
    //================================================
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

    //
    struct line_table{
        size_t n;
        std::optional<_section> sec;
        //std::optional<_tag> tag;
        std::optional<_option> opt;
        std::vector<std::string> line;
    };
    //
    class textEditor{
        public:
            std::vector<std::vector<std::string>> text;
            /// @brief thiss sheet is cumming up and blow my jobS
            std::vector<rnt::line_table> tag_table;
            fs::path path = "/etc/X11/xorg.conf.d/100-xutils-xorg.conf";
            //std::vector<size_t> device_pos;
        
            //----------------------------------------------------
            textEditor();    
            textEditor(fs::path);
            //----------------------------------------------------
            // File 
        
            virtual int create();
            virtual int show();
            virtual int show_tag_table();
            virtual int load();
            // Text
            virtual bool is_word_exist(std::string);
            virtual int insert_line(size_t, std::vector<std::string>);
            virtual int delete_line(size_t); 
            virtual int add_line_in_tag_table(const rnt::line_table&);
            virtual int reload_tag_table();
   
    };


    class Configurator : public textEditor{
            textEditor process;
            std::vector<_type> adaptors;
        public: 
            Configurator(fs::path);
            int change_tearing(bool, size_t);
            int change_vsync(bool, size_t);
            
    };

    _section check_sec(std::string&);
    _option check_opt(std::string&);
    _tag check_tag(std::string&);
    //int reload_config();


    class MainApp{
        Configurator app;
        std::vector<std::string> arguments;
        fs::path path_to_conf;
        public:
            MainApp();
            
    };
}
#endif