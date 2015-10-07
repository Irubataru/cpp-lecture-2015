/*
 * Created: 07-10-2015
 * Modified: Wed 07 Oct 2015 14:45:03 CEST
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#include"hangman_print.hpp"
#include<iostream>

void printHangman(unsigned state)
{
  switch (state) {
    case 1:
      std::cout << " --------------   \n";
      std::cout << "  |               \n";
      std::cout << "  |               \n";
      std::cout << "  |               \n";
      std::cout << "  |               \n";
      std::cout << "  |               \n";
      std::cout << "  |               \n";
      std::cout << "  |               \n";
      break;
    case 2:
      std::cout << " --------------   \n";
      std::cout << "  |          |    \n";
      std::cout << "  |          @    \n";
      std::cout << "  |               \n";
      std::cout << "  |               \n";
      std::cout << "  |               \n";
      std::cout << "  |               \n";
      std::cout << "  |               \n";
      break;
    case 3:
      std::cout << " --------------   \n";
      std::cout << "  |          |    \n";
      std::cout << "  |          @    \n";
      std::cout << "  |          |    \n";
      std::cout << "  |          |    \n";
      std::cout << "  |               \n";
      std::cout << "  |               \n";
      std::cout << "  |               \n";
      break;
    case 4:
      std::cout << " --------------   \n";
      std::cout << "  |          |    \n";
      std::cout << "  |          @    \n";
      std::cout << "  |         /|    \n";
      std::cout << "  |          |    \n";
      std::cout << "  |               \n";
      std::cout << "  |               \n";
      std::cout << "  |               \n";
      break;
    case 5:
      std::cout << " --------------   \n";
      std::cout << "  |          |    \n";
      std::cout << "  |          @    \n";
      std::cout << "  |         /|\\   \n";
      std::cout << "  |          |    \n";
      std::cout << "  |               \n";
      std::cout << "  |               \n";
      std::cout << "  |               \n";
      break;
    case 6:
      std::cout << " --------------   \n";
      std::cout << "  |          |    \n";
      std::cout << "  |          @    \n";
      std::cout << "  |         /|\\   \n";
      std::cout << "  |          |    \n";
      std::cout << "  |         /     \n";
      std::cout << "  |               \n";
      std::cout << "  |               \n";
      break;
    case 7:
      std::cout << " --------------   \n";
      std::cout << "  |          |    \n";
      std::cout << "  |          @    \n";
      std::cout << "  |         /|\\   \n";
      std::cout << "  |          |    \n";
      std::cout << "  |         / \\   \n";
      std::cout << "  |               \n";
      std::cout << "  |   Game Over   \n";
      break;
    default:
      std::cout << std::endl;
  }
}

