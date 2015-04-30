//

//          Copyright Sundeep S. Sangha 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TAXO_RELATION_HPP
#define TAXO_RELATION_HPP

#include "tag.hpp"

namespace taxo {
/* basic_relation */
template <
  typename T
, typename allocator
    = std::allocator<char>
>
class relation
  : public tag<allocator>
{
public:
  /* ctor */
  template <typename... Ts>
  relation(
    Ts...
  );

  /* ctor copy */
  relation(
    relation<allocator> const &
  ) = default;

  ~relation(
  ) = default;

  T degree;
};

} /* taxo */
#include "bits/realtion.tcc"
#endif
