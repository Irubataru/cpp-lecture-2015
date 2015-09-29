#include<iostream>

constexpr auto unsigned_num_bits = sizeof(int)*8;


int main()
{
  int number = -1025;
  int bitrep[unsigned_num_bits];

  if (number < 0) {
    number *= -1;
    bitrep[0] = 1;
  } else {
    bitrep[0] = 0;
  }

  unsigned bit = 1;
  for (auto i = 0; i < unsigned_num_bits-1; ++i) {
    bitrep[unsigned_num_bits - 1 - i] = static_cast<bool>(number&bit);
    bit <<= 1;
  }

  std::cout << "Bit representation of " << number << " is ";
  for (auto b : bitrep)
    std::cout << b;

  std::cout << std::endl;
}
