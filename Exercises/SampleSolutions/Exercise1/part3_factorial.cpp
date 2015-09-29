#include<iostream>

int main()
{
  unsigned factorial = 1;
  unsigned counter = 10;

  while (true) {
    if (counter < 2)
      break;

    factorial *= counter;
    --counter;
  }

  std::cout << "10! = " << factorial << std::endl;


}
