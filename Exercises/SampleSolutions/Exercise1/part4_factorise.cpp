#include<iostream>
#include<cmath>

int main()
{
  std::cout << "Please enter an integer to check:" << std::endl;

  unsigned number {0};
  std::cin >> number;

  unsigned * factors = new unsigned[256];
  unsigned pos = 0;

  unsigned working_copy = number;
  unsigned factor = 2;

  while (factor <= sqrt(working_copy)) {
    if (working_copy % factor == 0) {
      factors[pos] = factor;
      working_copy /= factor;
      ++pos;
    } else {
      ++factor;
    }
  }

  factors[pos] = working_copy;
  ++pos;

  std::cout << number << " factorised is: [";

  for (auto i = 0; i < pos; ++i)
    std::cout << factors[i] << ", ";

  std::cout << "]" << std::endl;
}
