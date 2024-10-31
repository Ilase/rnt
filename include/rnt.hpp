
#include <vector>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <string>
#include <algorithm>
#include <optional>
#include <unordered_map>
#include <exception>

#define RNT_PR "[RNT] "
#define RNT_ERR "[RNT-ERR] "

namespace fs = std::filesystem;

namespace rnt{
    /// @brief Handler for my poops
    /// @param  
    /// @param  
    void rnt_handler(std::exception&, std::string);


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
            std::vector<std::vector<std::string>> text;
            /// @brief thiss sheet is cumming up and blow my jobS
            std::vector<rnt::line_table> tag_table;
            fs::path path = "/etc/X11/xorg.conf.d/100-xutils-xorg.conf";
            //std::vector<size_t> device_pos;
        public:
            //----------------------------------------------------
            //textEditor();    
            textEditor(fs::path);
            //----------------------------------------------------
            // File 
        
            int create();
            int show();
            int show_tag_table();
            int load();
            // Text
            bool is_word_exist(std::string);
            int insert_line(size_t, std::vector<std::string>);
            int delete_line(size_t); 
            int add_line_in_tag_table(const rnt::line_table&);
            int reload_tag_table();
            



   
    };


    class xConf : public textEditor{
        public: 
        
    };

    _section check_sec(std::string&);
    _option check_opt(std::string&);
    _tag check_tag(std::string&);
    int reload_config();
}