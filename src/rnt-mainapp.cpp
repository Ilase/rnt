#include "rnt-mainapp.hpp"

rnt::MainApp::MainApp(int _argc , const char ** _argv/*std::vector<std::string> &_args*/){
    this->argc = _argc;
    //this->args = _args;
    this->argv = const_cast<char**>(_argv);
}

// int rnt::MainApp::show_args(){
//     for(const auto & argument : this->){
//         std::cout << argument << " ";
//     }
//     std::cout << std::endl;
//     return 0;
// }

int rnt::MainApp::start(){
    PciData data;
    data.parce_pci_table();
    int c;
    std::string gen_path; 
    bool automatic;
    while((c = getopt(this->argc, argv, "g:v:Al")) != -1){
        if(argc != 1){
            switch(c){
                case 'g': // generate
                    std::cout << RNT_PR << "Generating config in file: " << optarg << "\n";
                    
                    gen_path = optarg;
                    break;
                case 'v': // vendor
                    std::cout << "<empty>\n";
                    break;
                case 'A': // automatic
                    break;
                case 'l': //pci list
                    
                    data.show_table();
                    break;
                default:
                    //std::cout << RNT_PR << "Unknown parameter!\n";
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