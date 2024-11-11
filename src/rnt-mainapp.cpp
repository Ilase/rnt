#include "rnt-mainapp.hpp"

rnt::MainApp::MainApp(int _argc , const char ** _argv/*std::vector<std::string> &_args*/){
    this->argc = _argc;
    //this->args = _args;
    this->argv = const_cast<char**>(_argv);
}

int rnt::MainApp::start(){
    //PciData data;
    //data.parce_pci_table();
    Configurator configurator;
    int c;
    std::string gen_path; 
    bool automatic;
    while((c = getopt(this->argc, argv, "g:v:Al")) != -1){
        if(argc != 1){
            switch(c){
                case 'g': // generate
                    std::cout << RNT_PR << "Generating config in file: " << optarg << "\n";
                    gen_path = optarg;
                    gen_path = fs::path(gen_path, fs::path::format::auto_format);
                    configurator.write(gen_path, configurator.generate_section_device("Card10", _vendor::Intel, "i915", "00:02.0"));
                    break;
                case 'v': // vendor
                    std::cout << "<empty>\n";
                    break;
                case 'A': // automatic
                    break;
                case 'l': //pci list
                    std::cout << "List?\n";
                    //data.show_table();
                    break;
                default:
                    std::cout << RNT_PR << "Nothing to break!\n";
                    break;
            }
        }// } else {
        //     std::cout << RNT_PR << "Nothing to break!\n";
        //     break;   
        // }
        //std::cout << "Nothing to break!\n";
        break;
    }

    return 0;
}