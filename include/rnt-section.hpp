#ifndef _RNT_SECTION_HPP
#define _RNT_SECTION_HPP
#include "rnt.hpp"
#include "rnt-enum.hpp"

namespace rnt
{
    class Section
    {
        std::vector<OptionField> fields;

    public:
        // OptionField get_field(_option) const;
        int show();
        int show(_option);
        OptionField &search_field(_option, std::string);
        int add_field(OptionField);
    };
}

#endif // !_RNT_SECTION_HPP