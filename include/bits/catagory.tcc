//

#ifdef __cplusplus < 2011
#define nullptr NULL
#endif

namespace taxo {


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
}

} /* taxo */
#ifdef __cplusplus < 2011
#undef nullptr
#endif
#endif
