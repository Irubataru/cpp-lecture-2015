#include<iostream>

constexpr auto unsigned_num_bits = sizeof(double)*8;

union unsigned_double {
  double d;
  unsigned long long l;
};

int main()
{
  unsigned_double number;
  number.d = 2.52e-23;
  int bitrep[unsigned_num_bits];

  unsigned long long bit = 1;
  for (auto i = 0; i < unsigned_num_bits; ++i) {
    bitrep[unsigned_num_bits - 1 - i] = static_cast<bool>(number.l&bit);
    bit <<= 1;
  }

  std::cout << "Bit representation of " << number.d << " is ";
  for (auto b : bitrep)
    std::cout << b;

  std::cout << std::endl;
}
