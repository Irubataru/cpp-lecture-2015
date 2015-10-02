/*
 * Created: 02-10-2015
 * Modified: Fri 02 Oct 2015 16:16:02 CEST
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#ifndef STRING_OBJECT_HPP
#define STRING_OBJECT_HPP

#include"text_object.hpp"
#include<string>

class StringObject : public TextObject
{
public:
  StringObject(std::string text)
    : text {text} {}

  virtual ~StringObject() {}

  virtual std::ostream& print(std::ostream & os) override
  {
    os << text;
    return os;
  }


private:
  std::string text;

};


#endif /* STRING_OBJECT_HPP */
