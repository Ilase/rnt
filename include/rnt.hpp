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
#include <type_traits>
#include <regex>
#include <functional>
#include <variant>
#include <getopt.h>
//
#include "rnt-enum.hpp"
//
#define RNT_PR "[RNT] "
#define RNT_ERR "[RNT-ERR] "
// #define DEBUG "[RNT-DEBUG] "

namespace rnt{
    enum class _option;
}
using TextMatrix = std::vector<std::vector<std::string>>;
using OptionField = std::pair<rnt::_option, std::vector<std::variant<int, float, std::string, bool>>>;

namespace fs = std::filesystem;

namespace rnt {
    /// @brief Handler for my poops
    /// @param exception from catch !
    /// @param additional information;
    void rnt_handler(std::exception &, std::string);
    static const std::regex bus_id_pattern("[0-9]+:\\d.*\\.[0-9]+$");
    //===============================================================//

    class PciData;
    class Configurator;
    class MainApp;
    class textEditor;
    class MainApp;
    class Section;
    //===============================================================//

    /// @brief Shell parser for ldpci or something else
    /// @param cmd const char*
    /// @return table of words
    TextMatrix sys_call(const char *cmd);
    //

    /// @brief Adding double comma to string
    /// @param input string
    /// @return output string
    std::string add_dc(std::string);


    std::ostream& operator<<(std::ostream&, const OptionField&);
}
#endif