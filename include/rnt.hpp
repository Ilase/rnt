
#include <vector>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <string>
#include <algorithm>
#include <optional>
#include <unordered_map>

#define XDR_PREF "[RNT] "

namespace fs = std::filesystem;

namespace rnt{

    enum _type{
        NVIDIA,
        AMD,
        INTEL
    };

    enum class _option{
        Identifier,
        Screen,
        InputDevice,
        ModulePath,
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
            



            //std::vector<std::vector<std::string>> generate_driver_section(_section, _type);
            //std::vector<std::vector<std::string>> generate_screen_section(_section);
            //bool is_word_exist(std::string);

            //
            // int load();
            // //void show();
            // void show(std::vector<std::vector<std::string>>);
            // std::vector<std::vector<std::string>> 
            //     find_option(_option);
            // void change_param(std::string, std::string, _option, _section);
            // int save_conf();
            // int insert_line(size_t, std::vector<std::string>);    
            // int delete_line(int);
            // //
            // int change_tearing(size_t, bool);
            // //
            // std::vector<std::string> generate_option(_option,std::vector<std::string>);
    
    };


    class xConf : public textEditor{
        public: 
        
    };

    _section check_sec(std::string&);
    _option check_opt(std::string&);
    int reload_config();
}