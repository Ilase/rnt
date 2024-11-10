#ifndef _RNT_MAINAPP_HPP
#define _RNT_MAINAPP_HPP
#include "rnt.hpp"
#include "rnt-sys.hpp"
namespace rnt{

    // const std::map<
    //     std::string,
    //     std::variant<
    //         std::function<void()>
    //     >
    // > arguments;

    /// @brief Arguments catcher and deployer;
    class MainApp{
            int argc;
            char **argv;
            //std::vector<std::string> args;
        public:
            MainApp(int, const char ** /*std::vector<std::string>&*/);
            int start();
            int show_args();
    };

}

#endif