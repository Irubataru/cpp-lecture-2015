#include<iostream>

constexpr std::size_t size = 20;

int main()
{
  unsigned multiplication_table[size][size];

  for (auto i = 0; i < size; ++i) {
    for (auto j = 0; j < size; ++j) {
      multiplication_table[i][j] = (i+1) * (j+1);
    }
  }

  for (auto i = 0; i < size; ++i) {
    for (auto j = 0; j < size; ++j) {
      if (multiplication_table[i][j] < 100)
        std::cout << " ";

      if (multiplication_table[i][j] < 10)
        std::cout << " ";

      std::cout << multiplication_table[i][j] << " ";
    } 
    std::cout << std::endl;
  }
}
