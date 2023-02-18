/*
 * Created: 02-10-2015
 * Modified: Fri 02 Oct 2015 15:29:49 CEST
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#include<iostream>
#include"cout_lock.hpp"

void foo();

int main(int, char**)
{
  {
    try {
      CoutLock lock {"subfolder/log.txt"};
      foo();
    } catch (std::logic_error & err) {
      std::cout << "Caught a runtime error, error message: \"" << err.what() << "\"" << std::endl;
    } catch (std::exception & e) {
      std::cout << "Caught an exception, error message: \"" << e.what() << "\"" << std::endl;
    }
  }

  std::cout << "Hello!" << std::endl;
}

void foo()
{
  for (auto i = 0; i < 1000; ++i)
    std::cout << i << std::endl;
}
