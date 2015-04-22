//

#ifndef TAXO_RELATION_HPP
#define TAXO_RELATION_HPP

#include "tag.hpp"

namespace taxo {
/* basic_relation */
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
  /* ctor */
  template <typename... Ts>
  basic_relation(
    Ts...
  );

  /* ctor copy */
  basic_relation(
    basic_relation<
      charT
    , traits
    , allocator
    > const &
  );

  ~basic_relation(
  ) = default;

  T degree;
};

} /* taxo */
#include "bits/realtion.tcc"
#endif
