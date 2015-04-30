//

//          Copyright Sundeep S. Sangha 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TAXO_TAG_HPP
#define TAXO_TAG_HPP

#include <string>

namespace taxo {
/* basic_tag */
template <
, typename allocator
  = std::allocator<char>
>
class tag {
public:
  typedef char value_type;

  /* ctor */
  template <typename Iter>
  tag(
    Iter
  , Iter
  );
  
  /* ctor */
  template <typename charT>
  tag(
    charT const * const  
  );

  /* dtor */
  virtual
  ~tag(
  );
  
  /* assignment operator */
  template <typename charT>
  void
  operator=(
    charT const * const
  );

private:
  /**/
  std::basic_string<
    char
  , std::char_traits<value_type>
  , allocator
  > tag;
};

/**/
template <typename allocator>
bool
operator==(
  tag<allocator> const &
, tag<allocator> const &
);

/**/
template <typename allocator>
bool
operator!=(
  tag<allocator> const &
, tag<allocator> const &
);

} /* taxo */
#include "bits/tag.tcc"
#endif
