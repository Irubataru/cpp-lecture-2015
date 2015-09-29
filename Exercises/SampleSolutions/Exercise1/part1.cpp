#include<iostream>

int main()
{
  auto i1 = 121124125;
  auto i2 = 214241241;

  std::cout << i1 << " * " << i2 << " = " << i1*i2 << std::endl;

  auto f1 = static_cast<float>(1e24);
  auto f2 = static_cast<float>(5e15);

  std::cout << f1 << " * " << f2 << " = " << f1*f2 << std::endl;
  std::cout << f1 << " / 0 = " << f1/0. << std::endl;
}
