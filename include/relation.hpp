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
template <typename T>
class relation {
public:
  /* ctor */
  template <typename... Ts>
  relation(
    Ts...
  );

  /* ctor overload
    Overload is selected over template
    mapping when the first argument is
    a tag.
  */
  template <typename... Ts>
  relation(
    tag const &
  , Ts...
  );

  /* ctor copy */
  relation(
    relation<T> const &
  ) = default;

  /* assignment operator */
  relation<T> &
  operator=(
    relation<T> const &
  ) = default;

  /* ctor move */
  relation(
    relation<T> &&
  ) = default;

  /* assignment operator move */
  relation<T> &
  operator=(
    relation<T> &&
  ) = default;

  ~relation() = default;

  tag value;
  T degree;
};

} /* taxo */
#include "bits/relation.tcc"
#endif
