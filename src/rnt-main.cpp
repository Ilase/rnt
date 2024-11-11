#include "rnt.hpp"
#include "rnt-sys.hpp"
#include "rnt-mainapp.hpp"
/// @brief Main function zalupa polnaya
/// @param argc 
/// @param argv 
/// @return status code
int main(int argc, char const *argv[]){
    
    //std::vector<std::string> args(argv, argv + argc);
    const char **_argv_ = argv;
    rnt::MainApp app(argc, _argv_);
    //app.show_args();
    app.start();
    
    return 0;
}