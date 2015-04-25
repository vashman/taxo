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
  basic_category(
  ) = default;

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

  /* merge */
  bool
  merge(
    basic_category<
      charT
    , traits
    , allocator> &
  );

  /* split */
  basic_category
  split(
  ) const ;

  /* compare tag */
  bool
  operator=(
    basic_tag<charT,traits,allocator>
      const &
  ) const;

private:
  /* tag */
  basic_tag<
    charT
   , traits
   , allocator
   > * const tag;

  std::size_t * const count;
};

/* create_category
Create a category, copying if it is
all ready in a range.
*/
template <typename Iter>
basic_category<>
create_category(
  Iter _first
, Iter _last
, basic_category<>
){
  if (
     std::find(
       _first
     , _last
     , (_tag)
   !=
     _last
  ){
  return basic_category<>(_tag);
  }
return basic_catagory(_tag);
}

typedef basic_category<char> category;
typedef
  basic_category<wchar_t> wcategory;

} /* taxo */
#include "bits/category.tcc"
#endif
