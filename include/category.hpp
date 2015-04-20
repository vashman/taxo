//

//          Copyright Sundeep S. Sangha 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TAXO_CATEGORY_HPP
#define TAXO_CATEGORY_HPP

#include "tag.hpp"

namespace taxo {
/**/
template <
  typename charT
, typename traits
    = std::char_traits<charT>
, typename allocator
    = std::allocator<charT>
>
class basic_category {
public:
  /* ctor */
  basic_category() = default;

  /* ctor */
  basic_category(
    basic_tag<charT,traits,allocator>
  );
 
  /* ctor */
  basic_category(
    basic_category<
      charT
    , traits
    , allocator
    > const &
  );
  
  /* ctor */
  basic_category(
    charT const * const _tag
  );
  
  ~basic_category(
  );

private:
  /*  */
  basic_tag<
    charT
   , traits
   , allocator
   > * const tag;

  std::size_t * const count;
};

typedef basic_category<char> category;
typedef
  basic_category<wchar_t> wcategory;

} /* taxo */
#include "bits/category.tcc"
#endif
