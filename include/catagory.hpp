//

#ifndef TAXO_CATAGORY_HPP
#define TAXO_CATAGORY_HPP

namespace taxo {
/**/
template <typename charT, typename traits = std::char_traits<charT>, typename allocator = std::allocator<charT> >
class basic_catagory : public basic_tag<charT,traits,allocator> {
private:
  basic_catagory<charT,traits,allocator> * const root;
};

} /* taxo */
#endif
