/*
 * Created: 02-10-2015
 * Modified: Fri 02 Oct 2015 16:11:03 CEST
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#include<iostream>
#include<memory>
#include"text_object.hpp"
#include"string_object.hpp"
#include"bullet_list.hpp"
#include"make_unique.hpp"

using TOPtr = std::unique_ptr<TextObject>;

unsigned BulletList::indent = 0;

int main(int, char**)
{
  BulletList bullets {};
  bullets.add(make_unique<StringObject>("Hello"));
  bullets.add(make_unique<StringObject>("How"));


  auto sub_bullets2 = make_unique<BulletList>();
  sub_bullets2->add(make_unique<StringObject>("Even"));
  sub_bullets2->add(make_unique<StringObject>("More"));

  auto sub_bullets = make_unique<BulletList>();
  sub_bullets->add(make_unique<StringObject>("Sub"));
  sub_bullets->add(make_unique<StringObject>("Bullet"));

  sub_bullets2->add(std::move(sub_bullets));

  sub_bullets2->add(make_unique<StringObject>("Bullets"));

  bullets.add(std::move(sub_bullets2));

  bullets.add(make_unique<StringObject>("Are"));
  bullets.add(make_unique<StringObject>("You?"));

  bullets.print(std::cout);

  
}
