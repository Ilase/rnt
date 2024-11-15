#include "rnt.hpp"

void rnt::rnt_handler(std::exception& e, std::string add_info){
    std::cerr << RNT_ERR << "Error:"<< e.what() << "\n" <<
                 RNT_ERR << "Additional info:" << add_info << "\n";
    exit(1);
}

std::vector<std::vector<std::string>> rnt::sys_call(const char *cmd)
{   
    std::vector<std::vector<std::string>> result;
    char buffer[256];
    FILE* pipe = popen(cmd, "r");
    if(!pipe){
        std::cerr << RNT_ERR << "popen() failed in sys_call(" << cmd << ")" << "\n";
    }
    try{
        while(fgets(buffer, sizeof(buffer), pipe) != NULL){
            std::istringstream iss(buffer);
            std::vector<std::string> line;
            std::string word;
            while(iss >> word){
                line.push_back(word);
            }
            result.push_back(line);
        }
    } catch(...){
        pclose(pipe);
        std::cerr << RNT_ERR << "Error occured while parcing data from: [ " << cmd << " ]'" << std::endl;
        exit(1);
    }
    pclose(pipe);
    return result;
}

std::string rnt::add_dc(std::string input){
    return "\"" + input + "\"";
}
std::ostream& rnt::operator<<(std::ostream& os, const OptionField& field) {
    os << option(field.first) << " ";
    for(const auto& arg : field.second){
        std::visit([&os](const auto& val){
            os << val << " ";
        }, arg);
    }
    return os;
};

//------------------------------------------------------------


