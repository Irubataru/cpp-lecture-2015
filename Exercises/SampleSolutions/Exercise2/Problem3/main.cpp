/*
 * Created: 28-09-2015
 * Modified: Wed 30 Sep 2015 19:54:34 CEST
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#include<iostream>
#include"array_manip.hpp"

bool largerThanThree(int check_val)
{
  return check_val > 3;
}

int main(int, char**)
{
  int original[] = {4, 1, 6, 1, 8, 3, 5};
  int filtered[7];

  auto new_size = Array::filter(original,filtered,7,largerThanThree);

  for (auto i = 0; i < new_size; ++i)
    std::cout << filtered[i] << " ";

  std::cout << std::endl;

  int data[] = {4, 1, 6, 2, 7, 10, 13, 8};
  Array::sort(data,8);

  for (auto i : data)
    std::cout << i << " ";

  std::cout << std::endl;

  std::cout << Array::sorted_search(data, 8, 4) << std::endl;

}
