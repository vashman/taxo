//

#ifndef TAXO_RELATION_HPP
#define TAXO_RELATION_HPP

namespace taxo {
/**/
template <typename charT, typename traits = std::char_traits<charT>, typename allocator = std::allocator<charT> >
class basic_relation : public basic_catagory<charT,traits,allocator> {
public:
  typedef int realtionship_type;
  static int const composition = 
  static int const assocation = 

private:
  int differnece, likeness;
  int relationship;
};

} /* taxo */
#endif
