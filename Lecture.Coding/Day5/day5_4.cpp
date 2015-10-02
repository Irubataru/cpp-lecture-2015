/*
 * Created: 02-10-2015
 * Modified: Fri 02 Oct 2015 12:10:30 CEST
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#include<iostream>
#include<algorithm>
#include<vector>

struct Greater
{
  bool operator() (int a, int b)
  {
    return a > b;
  }
};

int main(int, char**)
{
  std::vector<int> v1 = {4, 1, 6, 2, 7, 4, 6};

  for (auto elem : v1)
    std::cout << elem << " ";
  std::cout << std::endl;

  std::sort(v1.begin(), v1.end(), [](int a, int b){return a > b;});

  for (auto elem : v1)
    std::cout << elem << " ";
  std::cout << std::endl;
  
}
