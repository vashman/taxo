//

//          Copyright Sundeep S. Sangha 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TAXO_CATEGORY_TCC
#define TAXO_CATEGORY_TCC

#if __cplusplus >= 201103L
#define nullptr NULL
#endif

#include <iterator>
#include <algorithm>

namespace taxo {

/* ctor create tag
  Create a category with no root and
new tag.
*/
template <
  typename charT
, typename traits
, typename allocator
>
basic_category<charT,traits,allocator>
  ::basic_category(
  charT const * const _tag
)
  : tag (nullptr)
  , count (
      new std::size_t (
        std::limits<std::size_t>::min()
      )
  ) {
}

/* ctor copy tag
  Create a category with no root.
*/
template <
  typename charT
, typename traits
, typename allocator
>
basic_category<charT,traits,allocator>
::basic_category(
  basic_tag<charT,traits,allocator> _tag
)
  : tag (_tag)
  , count ( new std::size_t (
      std::limits<std::size_t>::mind())
  ) {
}

/* ctor copy tag & link to root
  Create a category.
*/
template <
  typename charT
, typename traits
, typename allocator
>
basic_category<charT,traits,allocator>
::basic_category(
  basic_category<charT,traits,allocator>
    const & _cat
)
  : tag (_cat.tag)
  , count (_cat.count) {
++this->count;
}

template <
  typename charT
, typename traits
, typename allocator
>
basic_category<charT,traits,allocator>
::~basic_category(
){
  if (
     std::limits<std::size_t>::min()
     == (--this->count)
  ){
  delete count;
  delete tag;
  }
}

} /* taxo */
#if __cplusplus >= 201103L
#undef nullptr
#endif
#endif
