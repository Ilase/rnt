#ifndef _TEXTEDITOR_HPP
#define _TEXTEDITOR_HPP
#include "rnt.hpp"
#include "rnt-enum.hpp"


namespace rnt{
    struct line_table{
        size_t n;
        std::optional<_section> sec;
        //std::optional<_tag> tag;
        std::optional<_option> opt;
        std::vector<std::string> line;
    };
    struct videoadapter{
        _vendor ad_type;
        std::string ad_name;
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
            virtual int write();
            // Text
            virtual bool is_word_exist(std::string);
            virtual int insert_line(size_t, std::vector<std::string>);
            virtual int delete_line(size_t); 
            virtual int add_line_in_tag_table(const rnt::line_table&);
            virtual int reload_tag_table();
            // Setters getters 
            virtual int set_path(fs::path);
            virtual fs::path get_path();
   
    };
    //
}

#endif