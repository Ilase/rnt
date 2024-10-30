#include "rnt.hpp"


std::string rnt::option(_option s) {
    switch(s){
        case _option::Identifier: return "ServerLayout";
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
        default: throw std::invalid_argument("Unimpliment item");
    }
}

std::string rnt::tag(_tag s) {
    switch(s){
        case _tag::Section: return "\"Section\"";
        case _tag::EndSection: return "\"EndSection\"";
        case _tag::SubSection: return "\"SubSection\"";
        case _tag::EndSubSection: return "\"EndSubSection\"";
        case _tag::NOWAY: return "<empty>";
        default: throw std::invalid_argument("Unimpliment item");
    }
}

std::string rnt::section(_section s) {
    switch(s){
        case _section::ServerLayout: return "\"ServerLayout\"";
        case _section::Module: return "\"Module\"";
        case _section::Files: return "\"Module\"";
        case _section::InputDevice: return "\"InputDevice\"";
        case _section::Monitor: return "\"Monitor\"";
        case _section::Device: return "\"Device\"";
        case _section::Screen: return "\"Screen\"";
        case _section::NOWAY: return "<empty>";
        default: throw std::invalid_argument("Unimpliment item");
    }
}





// int rnt::reload_config()
// {
    
//     return 0;
// }

// rnt::xConfigurator::xConfigurator(fs::path xorgcp)
// {
//     if(xorgcp != this->conf_path){
//         if(!fs::exists(xorgcp)){
//             std::cerr << XDR_PREF << "Xorg path doesn't exists\n";
//         }
//         this->conf_path = xorgcp;
//     }
// }

// std::vector<std::vector<std::string>> rnt::xConfigurator::generate_driver_section(_section, _type)
// {
//     std::vector<std::vector<std::string>> result;

//     return result;
// }

// bool rnt::xConfigurator::is_word_exist(std::string querry)
// {
//     for(auto const& line : this->conf){
//         for(const auto& word : line){
//             if(word == querry){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// int rnt::xConfigurator::load()
// {
//     std::ifstream input(this->conf_path);
//     if(!input.is_open()){
//         std::cerr << XDR_PREF << "Unable to open file for read\n";
//         return 1;
//     }
//     int line_num;
//     std::string line;
//     bool is_device;
//     while(std::getline(input,line)){
//         line_num++;
//         std::istringstream iss(line);
//         std::vector<std::string> line_words;
//         std::string word;
//         while(iss >> word){
//             line_words.push_back(word);
            
//         }
//         this->conf.push_back(line_words);
//     }

//     return 0;
// }

// void rnt::xConfigurator::show()
// {
    
//     for(size_t l = 0; l < this->conf.size(); ++l){
//         // for(const auto& word : line.second()){
//         //     std::cout << word << " ";
//         // }
        
        
//         for(size_t w = 0; w < this->conf[l].size(); ++w){
//             std::cout << this->conf[l][w] << " ";
//         }

//         std::cout << "\n";
//     }
// }

// void rnt::xConfigurator::show(std::vector<std::vector<std::string>> _ivec)
// {
//     for(const auto& line : _ivec){
//         for(const auto& word : line){
//             std::cout << word << " ";
//         }
//         std::cout << "\n";
//     }    
// }

// std::vector<std::vector<std::string>>
//     rnt::xConfigurator::find_option(_option opt)
// {
//     std::vector<std::vector<std::string>> result;
//     std::string opt_str = rnt::option(opt);
//     for(const auto& line : this->conf){
//         for(const auto& word : line){
//             if(word == opt_str){
//                 result.push_back(line); 
//             }
//         }
//         // if(!result.empty()){
//         //     break;
//         // }
//     }    
//     return result;
// }



// int rnt::xConfigurator::save_conf()
// {
//     if(fs::exists(this->conf_path)){
//         std::cout << XDR_PREF << "Updating xorg.conf. Removing/n";
//         fs::remove(this->conf_path);
//     }
//     //!!!!! 
//     std::ofstream output(this->conf_path);

//     if(!output.is_open()){
//         std::cerr << XDR_PREF << "Unable open output path/";
//     } else {
//         for(const auto& line : this->conf){
//             for(const auto& word : line){
//                 output << word << " ";
//             }
//             output << "\n";
//         }
//     }


//     return 0;
// }

// int rnt::xConfigurator::insert_line(size_t pos, std::vector<std::string> line)
// {   
//     auto it = this->conf.begin();
//     std::advance(it, pos);
//     this->conf.insert(it, line);
//     return 0;
// }

// int rnt::xConfigurator::delete_line(int pos)
// {
//     this->conf.erase(this->conf.begin() + pos);
//     return 0;
// }

// int rnt::xConfigurator::change_tearing(size_t device, bool state)
// {
//     std::vector<std::vector<std::string>> conf_buff;
//     auto it = this->conf.begin();
//     std::advance(it, device + 1 );
    
//     for(const auto it : this->conf){
        
//         if(it[0] != "EndSection"){
//             conf_buff.push_back(it);
//         }
//     }
//     it = conf_buff.end();
//     std::advance(it, conf_buff.end() - 1);
    
    
//     {
//         if(state){
//             conf_buff.insert(conf_buff.end() - 1 ,generate_option(_option::Option, {"\"TearFree\"", "\"true\""}));
//         } else {
//             conf_buff.insert(conf_buff.end() - 1 ,generate_option(_option::Option, {"\"TearFree\"", "\"true\""}));
//         }
//     }
//     return 0;
// }

// std::vector<std::string> rnt::xConfigurator::generate_option(_option opt, std::vector<std::string> params)
// {
//     std::vector<std::string> result;
//     result.push_back("Option");
//     auto it = params.begin();
//     std::advance(it, 1);
//     for(const auto& it : params){
//         result.push_back(it);
//     }

//     return result;
// }

int rnt::textEditor::create()
{
    std::ofstream buff_file(this->path);
    if(buff_file.is_open()){
        buff_file.close();
        std::cout << XDR_PREF << "File " << this->path.filename() << " created succsessfuly";
        return 0;
    } else {
        std::cerr << XDR_PREF << "Can't create file!\n";
        return 1;
    }
}

int rnt::textEditor::show()
{
    for(const auto& line : this->text){
        for(const auto& word : line){
            std::cout << word << " ";
        }
        std::cout << "\n";
    }
    return 0;
}

int rnt::textEditor::show_tag_table()
{
    
    for(const auto& line : this->tag_table){
        const _section& section_inline = line.sec.value();
        const _option& option_inline = line.opt.value();
        std::cout << XDR_PREF << line.n << " | " << section(section_inline) << " | " << option(option_inline) << " :: ";
        for(const auto& _word : line.line){
            std::cout << _word << " ";
        }
        std::cout << "\n";
    }
    return 0;
}

int rnt::textEditor::load()
{   
    std::ifstream input(this->path);
    if(!input.is_open()){
        std::cerr << XDR_PREF << "Unable open file for reading.\n"; 
        return 1;
    }

    size_t line_pos = 0;
    std::string buff_line;
    //
    _section curr_sec;
    _option opt_var;
    //
    while (std::getline(input, buff_line))
    {
        std::istringstream iss(buff_line);
        std::vector<std::string> word_line;
        std::string word;
        //check this out nigga
        while(iss >> word){
            word_line.push_back(word);
            //

            //
        }
        this->text.push_back(word_line);
        //this->tag_table.push_back({line_pos, check_sec(word), check_sec(word), word_line});
        add_line_in_tag_table({line_pos, check_sec(word), check_opt(word), word_line});
        line_pos++;
    }
    
    
    return 0;
}

bool rnt::textEditor::is_word_exist(std::string querry)
{
    for(const auto& line : this->text){
        for(const auto& word : line) { 
            if(word == querry){
                return true;
            }
        }
    }
    return false;
}

int rnt::textEditor::insert_line(size_t pos, std::vector<std::string> line)
{
    auto it = this->text.begin();
    std::advance(it, pos);
    this->text.insert(it,line);
    return 0;
}

int rnt::textEditor::delete_line(size_t pos)
{   
    this->text.erase(this->text.begin() + pos);
    return 0;
}

int rnt::textEditor::add_line_in_tag_table(const rnt::line_table & line)
{
    this->tag_table.push_back(line);
}
/// @brief same with load but for tag_table
/// @return exit code;
int rnt::textEditor::reload_tag_table()
{
    this->tag_table.clear();


    size_t line_pos = 0;
    std::string buff_line;
    // std::string word;
    //
    _section curr_sec;
    _option opt_var;
    //
    for(const auto& line : this->text)
    {   
        for(const auto& word : line){
            std::string buff_word = word;
            if(check_sec(buff_word) != _section::NOWAY || check_opt(buff_word) != _option::NOWAY){
                curr_sec = check_sec(buff_word);
                opt_var = check_opt(buff_word);  
            }
        }
        add_line_in_tag_table({line_pos, curr_sec, opt_var, line});
        line_pos++;
    }
    
    
    return 0;
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


