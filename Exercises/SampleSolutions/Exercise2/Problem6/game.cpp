/*
 * Created: 07-10-2015
 * Modified: Wed 07 Oct 2015 15:28:45 CEST
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#include<cstdlib>
#include<ctime>
#include"hangman.hpp"

int main(int, char**)
{
  std::srand(std::time(0));
  playHangman("nouns.txt");
  
}
