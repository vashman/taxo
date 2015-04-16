//

//          Copyright Sundeep S. Sangha 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TAXO_TAG_TCC
#define TAXO_TAG_TCC

namespace taxo {
/* ctor */
template <typename charT, typename traits, typename allocator>
template <typename Iter>
basic_tag<charT,traits,allocator>::basic_tag(
  Iter _begin
, Iter _end
)
  : tag (_begin, _end) {
}

/* ctor */
template <typename charT, typename traits, typename allocator>
basic_tag<charT,traits,allocator>::basic_tag(
  charT const * const _str
)
  : tag (_str) {
}

/* dtor */
template <typename charT, typename traits, typename allocator>
basic_tag<charT,traits,allocator>::~basic_tag(
){
}

/* operator compare equal */
template <typename charT, typename traits, typename allocator>
bool
operator==(
  basic_tag<charT,traits,allocator> const & _tag
, basic_tag<charT,traits,allocator> const & _other
){
return (_tag.tag == _other.tag);
}

/* operator compare not equal */
template <typename charT, typename traits, typename allocator>
bool
operator!=(
  basic_tag<charT,traits,allocator> const & _tag
, basic_tag<charT,traits,allocator> const & _other
){
return (_tag.tag != _other.tag);
}

/* assignment operator */
template <typename charT, typename traits, typename allocator>
void
basic_tag<charT,traits,allocator>::operator=(
  charT const * const _str
){
this->tag = _str;
}

} /* taxo */
#endif