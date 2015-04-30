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
  typename allocator
    = std::allocator<char>
>
class category {
public:
  typedef tag<allocator>::value_type
    value_type;

  /* ctor */
  category(
  ) = default;

  /* ctor */
  category(
    tag<allocator>
  );
 
  /* ctor copy */
  category(
    category<allocator> const &
  );
  
  /* ctor */
  template <typename charT>
  category(
    charT const * const _tag
  );
  
  /* dtor */
  ~basic_category(
  );

  /* merge */
  bool
  merge(
    basic_category<allocator> &
  );

  /* split */
  basic_category
  split(
  ) const ;

  /* assignment tag */
  bool
  operator=(
    basic_tag<allocator> const &
  ) const;

private:
  /* tag */
  tag<allocator> * const tag;

  /* instance counter */
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

} /* taxo */
#include "bits/category.tcc"
#endif
