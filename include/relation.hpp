//

#ifndef TAXO_RELATION_HPP
#define TAXO_RELATION_HPP

#include "tag.hpp"

namespace taxo {
/**/
template <
  typename T
, typename charT
, typename traits
    = std::char_traits<charT>
, typename allocator
    = std::allocator<charT>
>
class basic_relation
  : public basic_tag<
      charT
    , traits
    , allocator
    >
{
public:
  T degree;
};

} /* taxo */
#include "bits/realtion.tcc"
#endif
