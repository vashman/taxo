//

//          Copyright Sundeep S. Sangha 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TAXO_CATEGORY_HPP
#define TAXO_CATEGORY_HPP

#include "tag.hpp"

namespace taxo {
/* category */
class category {
public:
  /* ctor */
  category();

  /* ctor */
  category(char const * const);

  /* ctor */
  explicit
  category(
    tag const &
  );
 
  /* ctor copy */
  category(
    category const &
  );

  /* assignment operator copy */
  category &
  operator=(
    category const &
  );

  /* ctor move */
  category(
    category &&
  );

  /* assignment operator move */
  category &
  operator=(
    category &&
  );
  
  /* dtor */
  ~category();

  /* merge */
  bool
  merge(
    category &
  );

  /* split */
  category
  split() const ;

  /* assignment tag */
  bool
  operator=(
    tag const &
  ) const;

  /* operator == */
  bool
  operator==(
    category const & _rhs
  );

  /* operator != */
  bool
  operator!=(
    category const & _rhs
  );

private:
  /* tag */
  tag * value;

  /* instance counter */
  std::size_t * count;
};

/* create_category
  Create a category, copying if it is
  all ready in a range.
*/
template <typename Iter>
category
create_category(
  Iter _first
, Iter _last
, tag & _tag
);

} /* taxo */
#include "bits/category.tcc"
#endif
