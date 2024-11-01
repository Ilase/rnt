#include "rnt.hpp"

void rnt::rnt_handler(std::exception& e, std::string add_info){
    std::cerr << RNT_ERR << "Error:"<< e.what() << "\n" <<
                 RNT_ERR << "Additional info:" << add_info << "\n";
    exit(1);
}



//------------------------------------------------------------


