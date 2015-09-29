#include<iostream>
#include<cmath>

int main()
{
  std::cout << "Please enter an integer to check:" << std::endl;

  unsigned number {0};
  std::cin >> number;

  bool is_prime {true};
  for(auto i = 2; i < std::sqrt(number); ++i) {
    if (number % i == 0) {
      is_prime = false;
      break;
    }
  }

  std::cout << "The number is ";
  if (!is_prime)
    std::cout << "not ";
  std::cout << "a prime" << std::endl;

}
