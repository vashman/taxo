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
namespace bits {
/**/
template <typename charT, typename traits, typename allocator>
void
detach(
  basic_category<charT,traits,allocator> const * const _leaf
){
_leaf->notify_detach();
}

} /* bits */

/* attach
*/
template <typename charT, typename traits, typename allocator>
void
basic_category<charT,traits,allocator>::attach(
  basic_category<charT,traits,allocator> const & _root
){
this->leafs.insert(&_root);
}

/*
*/
template <typename charT, typename traits, typename allocator>
void
basic_category<charT,traits,allocator>::detach(
){
this->root->notify_detach(this);
}

/* notify_detach leaf from root
*/
template <typename charT, typename traits, typename allocator>
void
basic_category<charT,traits,allocator>::notify_detach(
){
this->root = nullptr;
}

/* notify_detach root from leaf
  This will assume the leaf is a unique element.
*/
template <typename charT, typename traits, typename allocator>
void
basic_category<charT,traits,allocator>::notify_detach(
  basic_category<charT,traits,allocator> const * const _leaf
){
this->leaf.erase(_leaf);
}

/* ctor create tag
  Create a category with no root and new tag.
*/
template <typename charT, typename traits, typename allocator>
basic_category<charT,traits,allocator>::basic_category(
  charT const * const _tag
)
  : basic_tag<charT,traits,allocator> (_tag)
  , root (nullptr)
  , leafs () {
}

/* ctor copy tag
  Create a category with no root.
*/
template <typename charT, typename traits, typename allocator>
basic_category<charT,traits,allocator>::basic_category(
  basic_tag<charT,traits,allocator> _tag
)
  : basic_tag<charT,traits,allocator> (_tag)
  , root (nullptr)
  , leafs () {
}

/* ctor create tag & link to root
  Create a category.
*/
template <typename charT, typename traits, typename allocator>
basic_category<charT,traits,allocator>::basic_category(
  charT const * const _tag
, basic_category<charT,traits,allocator> const & _cat
)
  : basic_tag<charT,traits,allocator> (_tag)
  , root (&_cat)
  , leafs () {
_cat.attach(this);
}

/* ctor copy tag & link to root
  Create a category.
*/
template <typename charT, typename traits, typename allocator>
basic_category<charT,traits,allocator>::basic_category(
  basic_tag<charT,traits,allocator> _tag
, basic_category<charT,traits,allocator> const & _cat
)
  : basic_tag<charT,traits,allocator> (_tag)
  , root (&_cat)
  , leafs () {
_cat.attach(this);
}

template <typename charT, typename traits, typename allocator>
basic_category<charT,traits,allocator>::~basic_category(
){
std::for_each
  (std::begin(this->leafs), std::end(this->leafs), bits::detach);
}

} /* taxo */
#if __cplusplus >= 201103L
#undef nullptr
#endif
#endif
