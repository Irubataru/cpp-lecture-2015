/*
 * Created: 02-10-2015
 * Modified: Fri 02 Oct 2015 15:46:12 CEST
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#ifndef TEXT_OBJECT_HPP
#define TEXT_OBJECT_HPP

#include<ostream>

class TextObject
{
public:
  virtual std::ostream& print(std::ostream &) = 0;
  virtual ~TextObject() {}
};

std::ostream & operator<<(std::ostream & os, TextObject & t)
{
  return t.print(os);
}



#endif /* TEXT_OBJECT_HPP */
