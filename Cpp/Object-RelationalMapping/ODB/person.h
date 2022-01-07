// person.hxx
//

#include <string>

#include <odb/core.hxx>

#pragma db object
class Person
{
public:

  Person (const std::string& first,
          const std::string& last,
          unsigned short age);

  const std::string& first () const;
  const std::string& last () const;

  unsigned short age () const;
  void age (unsigned short);

private:
  Person () {};
  friend class odb::access;

  #pragma db id auto
  unsigned long id_;

  std::string first_;
  std::string last_;
  unsigned short age_;
};
  
