//

//          Copyright Sundeep S. Sangha 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TAXO_TAG_HPP
#define TAXO_TAG_HPP

#include <string>

namespace taxo {
/* tag */
class tag {
public:
  /* ctor */
  template <typename Iter>
  tag(
    Iter
  , Iter
  );

  /* ctor */
  explicit
  tag(char const * const);

  /* ctor */
  explicit
  tag() = default;
  
  /* ctor copy */
  tag(tag const &) = default;

  /* assignment operator copy */
  tag &
  operator=(tag const &) = default;

  /* ctor move */
  tag(tag &&) = default;

  /* assignment operator move */
  tag &
  operator=(tag &&) = default;

  /* dtor */
  ~tag();
  
private:
  /* internal tag storage */
  std::string value;

  friend bool
  operator==(tag const &, tag const &);

  friend bool
  operator!=(tag const &, tag const &);
};

/**/
bool
operator==(
  tag const &
, tag const &
);

/**/
bool
operator!=(
  tag const &
, tag const &
);

} /* taxo */
#include "bits/tag.tcc"
#endif
