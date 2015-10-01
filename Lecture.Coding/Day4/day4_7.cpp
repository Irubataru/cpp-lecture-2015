/*
 * Created: 01-10-2015
 * Modified: Thu 01 Oct 2015 12:05:34 CEST
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#include<iostream>

template <typename Type>
class Vector
{
public:
  Type & operator[](unsigned);
  unsigned size() const;

  typedef Type value_type;
};

template <typename Type>
struct type_traits
{
  typedef typename Type::value_type value_type;
};

template <typename Type>
struct type_traits<Type*>
{
  typedef Type value_type;
};

template <typename Container>
void swap(Container & cont, unsigned index_1, unsigned index_2)
{
  typename type_traits<Container>::value_type tmp = cont[index_1];
  cont[index_1] = cont[index_2];
  cont[index_2] = tmp;
}

int main(int, char**)
{
  
}
