//

#ifndef TAXO_TAG_HPP
#define TAXO_TAG_HPP

#include <string>

namespace taxo {
/* basic_tag */
template <typename charT, typename traits = std::char_traits<charT>, typename allocator = std::allocator<charT> >
class basic_tag {
private:
  std::basic_string<charT,traits,allocator> tag;
};

} /* taxo */
#endif
