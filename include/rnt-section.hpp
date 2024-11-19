#ifndef _RNT_SECTION_HPP
#define _RNT_SECTION_HPP
#include "rnt.hpp"
#include "rnt-enum.hpp"

using OptionField = std::pair<rnt::_option, std::vector<std::variant<int, float, std::string, bool>>>;

namespace rnt
{
    class Section
    {
        std::vector<OptionField> fields;
        std::vector<OptionField> subsection_fields;

    public:
        // OptionField get_field(_option) const;
        int show();
        int show(_option);
        // Returns rnt::OptionField by search
        OptionField &search_field(_option, std::string = "");
        int add_field(OptionField);
    };
}

#endif // !_RNT_SECTION_HPP