/*
 * Created: 02-10-2015
 * Modified: Fri 02 Oct 2015 16:14:41 CEST
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#ifndef BULLET_LIST_HPP
#define BULLET_LIST_HPP

#include<memory>
#include<list>
#include"text_object.hpp"

class BulletList : public TextObject
{
public:
  using TOPtr = std::unique_ptr<TextObject>;

  void add(TOPtr new_bullet)
  {
    bullet_points.push_back(std::move(new_bullet));
  }

  virtual std::ostream & print(std::ostream & os) override
  {
    bool first = true;

    for (auto & bullet : bullet_points) {

      if (!first) {
        for (auto i = 0; i < indent; ++i)
          os << " ";
      } else {
        first = false;
      }

      os << " * ";
      indent += 3;
      bullet->print(os);
      indent -= 3;
      os << std::endl;
    }
    
    return os;
  }

private:
  std::list<TOPtr> bullet_points;

  static unsigned indent;

};


#endif /* BULLET_LIST_HPP */
