#include "rnt-section.hpp"

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
    std::cout << search_field(opt, "") << "\n";
    return 0;
}

OptionField &rnt::Section::search_field(_option opt, std::string opt_s)
{

    if (opt_s == "")
    {
        for (auto &line : this->fields)
        {
            if (line.first == opt)
            {
                return line;
            }
        }
    }
    else
    {
        for (auto &line : this->fields)
        {
            if (line.first == opt)
            {
                for (const auto &arg : line.second)
                {
                    bool _isMatch = false;
                    std::visit([&_isMatch, &opt_s](const auto &val)
                               {
                                   using T = std::decay_t<decltype(val)>;
                                   if constexpr (std::is_same_v<T, std::string>)
                                   {
                                       if (val == opt_s)
                                       {
                                           _isMatch = true;
                                       }
                                   }
                                   else if constexpr (std::is_same_v<T, int> || std::is_same_v<T, float> || std::is_same_v<T, bool>)
                                   {
                                    try{
                                        if(val == std::stod(opt_s)){
                                            _isMatch = true;
                                        }
                                    }catch(const std::invalid_argument &e){
                                        std::cerr << e.what() << "\n"; 
                                    }
                                   } },
                               arg);
                               if(_isMatch){
                                return line;
                               }
                }
            }
        }
    }
    static OptionField dummy = {_option::NOWAY, {"ERROR"}};
    return dummy;
}
