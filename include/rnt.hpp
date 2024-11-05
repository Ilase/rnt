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

#define RNT_PR "[RNT] "
#define RNT_ERR "[RNT-ERR] "



namespace fs = std::filesystem;

namespace rnt{
    /// @brief Handler for my poops
    /// @param  exception from catch !
    /// @param  additional information;
    void rnt_handler(std::exception&, std::string);

    
    //================================================
    //defifnitions
    class Data;
    class Configurator;
    class MainApp;
    class textEditor;
    //================================================
    
    /// @brief Shell parser for ldpci or something else
    /// @param cmd const char* 
    /// @return table of words
    std::vector<std::vector<std::string>> sys_call(const char* cmd);
    //

   


}
#endif