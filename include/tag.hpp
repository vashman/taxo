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
template <typename charT
, typename traits = std::char_traits<charT>
, typename allocator = std::allocator<charT>
>
class basic_tag {
public:
  /* ctor */
  basic_tag(
    std::basic_string<charT,traits,allocator>
  );
  
  /* ctor */
  basic_tag(
    charT const * const  
  );

  /* dtor */
  virtual
  ~basic_tag(
  );

  /* assignment operator */
  void
  operator=(
    std::basic_string<charT,traits,allocator> const &
  );
  
  /* assignment operator */
  void
  operator=(
    charT const * const
  );

private:
  std::basic_string<charT,traits,allocator> tag;
};

/**/
template <typename charT, typename traits, typename allocator>
bool
operator==(
  basic_tag<charT,traits,allocator> const &
, basic_tag<charT,traits,allocator> const &
);

/**/
template <typename charT, typename traits, typename allocator>
bool
operator!=(
  basic_tag<charT,traits,allocator> const &
, basic_tag<charT,traits,allocator> const &
);

typedef basic_tag<char> tag;
typedef basic_tag<wchar_t> wtag;
} /* taxo */
#include "bits/tag.tcc"
#endif
