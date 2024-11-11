#include "rnt-texteditor.hpp"


rnt::textEditor::textEditor()
{
    this->path = "/etc/X11/xorg.conf";
    if(!fs::exists(this->path)){
        system("sudo Xorg :2 -configure");
        system("sudo cp /root/xorg.conf.new /etc/X11/xorg.conf");
    }
}

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
        std::cout << RNT_PR;
        int t_modes = 0;
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
        }
        line_pos++;
    }
    return 0;
}

int rnt::textEditor::write()
{
 
    std::ofstream output(this->path);
    if(!output.is_open()){
        const std::string e = std::string("Unable open file [ " + this->path.string() + " ] for write");
        std::cerr << RNT_ERR << e << "\n";
    }else {
        for(const auto& line : this->text){
            for(const auto& word : line){
                output << word << " ";           
            }
            output << "\n";
        }
    }
    output.close();
    return 0;
}

int rnt::textEditor::write(TextMatrix& input_text){
    std::ofstream output(this->path);
    if(!output.is_open()){
        const std::string e = std::string("Unable open file [ " + this->path.string() + " ] for write");
        std::cerr << RNT_ERR << e << "\n";
    }else {
        for(const auto& line : input_text){
            for(const auto& word : line){
                output << word << " ";           
            }
            output << "\n";
        }
    }
    output.close();
    return 0;
}

int rnt::textEditor::write(fs::path custom_path, TextMatrix input_text){
    std::ofstream output(custom_path);
    if(!output.is_open()){
        const std::string e = std::string("Unable open file [ " + custom_path.string() + " ] for write");
        std::cerr << RNT_ERR << e << "\n";
    }else {
        for(const auto& line : input_text){
            for(const auto& word : line){
                output << word << " ";           
            }
            output << "\n";
        }
    }
    output.close();    
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
        // be careful hero.... check out positions carefuly 
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


int rnt::textEditor::set_path(fs::path _path)
{
    this->path = _path;
    return 0;
}

fs::path rnt::textEditor::get_path()
{
    return this->path;
}
