//

#ifdef __cplusplus < 2011
#define nullptr NULL
#endif

#include <iterator>
#include <algorithm>

namespace taxo {
namespace bits {
/**/
template <typename charT, typename traits, typename allocator>
void
dettatch(
  basic_catagory<charT,traits,allocator> const * const _leaf
){
_leaf->notify_detach();
}

} /* bits */

/* attatch
*/
void
template <typename charT, typename traits, typename allocator>
basic_catagory<charT,traits,allocator>::attach(
  basic_catagory<charT,traits,allocator> const & _root
){
this.leaf.push_back(&_root);
}

/*
*/
void
template <typename charT, typename traits, typename allocator>
basic_catagory<charT,traits,allocator>::detach(
){
this->root->notify_detach(this);
}

/* notify_dettach leaf fromn root
*/
void
template <typename charT, typename traits, typename allocator>
basic_catagory<charT,traits,allocator>::notify_detach(
){
this->root = nullptr;
}

/* notify_dettach root from leaf
  This will assume the leaf is a unique element.
*/
void
template <typename charT, typename traits, typename allocator>
basic_catagory<charT,traits,allocator>::notify_detach(
  basic_catagory<charT,traits,allocator> const * const _leaf
){
this->leaf.erase(_leaf);
}

/* ctor create tag
  Create a catagory with no root and new tag.
*/
template <typename charT, typename traits, typename allocator>
basic_catagory<charT,traits,allocator>::basic_catagory(
  charT const * const _tag
)
  : basic_tag (_tag)
  , root (nullptr) {
}

/* ctor copy tag
  Create a catagory with no root.
*/
template <typename charT, typename traits, typename allocator>
basic_catagory<charT,traits,allocator>::basic_catagory(
  basic_tag<charT,traits,allocator> _tag
)
  : basic_tag (_tag)
  , root (nullptr) {
}

/* ctor create tag & link to root
  Create a catagory.
*/
template <typename charT, typename traits, typename allocator>
basic_catagory<charT,traits,allocator>::basic_catagory(
  charT const * const _tag
, basic_catagory<charT,traits,allocator> const & _cat
)
  : basic_tag (_tag)
  , root (&_cat) {
_cat.attach(this);
}

/* ctor copy tag & link to root
  Create a catagory.
*/
template <typename charT, typename traits, typename allocator>
basic_catagory<charT,traits,allocator>::basic_catagory(
  basic_tag<charT,traits,allocator> _tag
, basic_catagory<charT,traits,allocator> const & _cat
)
  : basic_tag (_tag)
  , root (&_cat) {
_cat.attach(this);
}

template <typename charT, typename traits, typename allocator>
basic_catagory<charT,traits,allocator>::~basic_catagory(
){
std::for_each(std::begin(), std::end(), bits::detach);
}

} /* taxo */
#ifdef __cplusplus < 2011
#undef nullptr
#endif
#endif
