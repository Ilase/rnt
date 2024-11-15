#include "rnt-section.hpp"

// OptionField rnt::Section::get_field(_option opt, std::string opt_s) const {

//     for(const auto& it : this->fields){
//         if(it.first == opt && opt != _option::Option){
//             return it;
//         }
//     }
//     throw std::out_of_range("Option not found!");
// }

int rnt::Section::show()
{
    for (const auto &line : this->fields)
    {
        std::cout << option(line.first) << " : ";
        for (const auto &arg : line.second)
        {
            std::visit([](const auto &val)
                       { std::cout << val << " "; }, arg);
        }
        std::cout << "\n";
    }
    return 0;
}

int rnt::Section::show(_option opt)
{
    std::cout << search_field(opt) << "\n";
    return 0;
}

OptionField &rnt::Section::search_field(_option opt, std::string opt_s = "")
{
    OptionField emp = {_option::NOWAY, {"ERROR"}};
    for (auto &line : this->fields)
    {
        if (line.first == opt && opt != _option::Option)
        {
            return line;
        }
        if (opt_s != "" && opt == _option::Option && line.first == _option::Option)
        {
            std::string check = std::visit([](const auto &val) -> std::string
            {
                if constexpr (std::is_same_v<decltype(val), std::string>){
                    return val;
                } else {
                    return std::to_string(val);
                } 
            }, line.second[0]);
            if (opt_s == check)
            {
                return line;
            }
        }
        else
        {
            return emp;
        }
    }
}
