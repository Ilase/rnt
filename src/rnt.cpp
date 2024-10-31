#include "rnt.hpp"

void rnt::rnt_handler(std::exception& e, std::string add_info){
    std::cerr << RNT_ERR << "Error:"<< e.what() << "\n" <<
                 RNT_ERR << "Additional info:" << add_info << "\n";
    exit(1);
}



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


//------------------------------------------------------------


rnt::textEditor::textEditor(fs::path path)
{
    this->path = path;
}

int rnt::textEditor::create()
{
    std::ofstream buff_file(this->path);
    if(buff_file.is_open()){
        buff_file.close();
        std::cout << RNT_PR << "File " << this->path.filename() << " created succsessfuly";
        return 0;
    } else {
        std::cerr << RNT_PR << "Can't create file!\n";
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
        std::cout << RNT_PR << line.n << " \t " << section(section_inline) << " \t " << option(option_inline) << "\t::";
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
        std::cerr << RNT_PR << "Unable open file for reading.\n"; 
        return 1;
    }

    size_t line_pos = 0;
    std::string buff_line_fw;
    //
    _section curr_sec;
    _option curr_opt;
    //
    while (std::getline(input, buff_line_fw))
    {
        std::istringstream iss(buff_line_fw);
        std::vector<std::string> word_line;
        std::string word;
        //check this out nigga

        while(iss >> word){
            word_line.push_back(word);
        }
        if(!word_line.empty()){
            this->text.push_back(word_line);
            //add_line_in_tag_table({line_pos, check_sec(word), check_opt(word), word_line});
        }
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
    return 0;
}
/// @brief same with load but for tag_table. autotagging in double cycle 
/// @return exit code;
int rnt::textEditor::reload_tag_table()
{
    try{
        this->tag_table.clear();
        size_t line_pos = 0;
        std::string buff_line_fw;
        _section curr_sec = _section::NOWAY;
        _option curr_opt = _option::NOWAY;
        //
        for(const auto& line : this->text){   
            auto buff_line_fw = line;
            if (buff_line_fw[0] == tag(_tag::Section)){
                //std::cerr << buff_line_fw[0].c_str();
                curr_sec = check_sec(buff_line_fw[1]);
            }

            if (check_opt(buff_line_fw[0]) != _option::NOWAY){
                curr_opt = check_opt(buff_line_fw[0]);
            }
            add_line_in_tag_table({line_pos, curr_sec, curr_opt, line});
            line_pos++;
            curr_opt = _option::NOWAY;
        }
    }catch(std::exception& e){
        rnt_handler(e, "reload_tag_table()");
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

rnt::_tag rnt::check_tag(std::string& word){
    for(size_t i = 0; i < static_cast<int>(_tag::NOWAY); ++i){
        std::string _buff = tag(static_cast<_tag>(i));
        if(word == _buff){
            return static_cast<_tag>(i);
        }
    }
    return _tag::NOWAY;
}

