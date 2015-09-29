#include<iostream>

constexpr auto unsigned_num_bits = sizeof(unsigned)*8;

int main()
{
  unsigned number = 542;
  int bitrep[unsigned_num_bits];

  unsigned bit = 1;
  for (auto i = 0; i < unsigned_num_bits; ++i) {
    bitrep[unsigned_num_bits - 1 - i] = static_cast<bool>(number&bit);
    bit <<= 1;
  }

  std::cout << "Bit representation of " << number << " is ";
  for (auto b : bitrep)
    std::cout << b;

  std::cout << std::endl;
}
