/*
 * Created: 30-09-2015
 * Modified: Wed 07 Oct 2015 15:40:19 CEST
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#include<list>
#include<fstream>
#include<iostream>
#include<limits>
#include"hangman.hpp"
#include"hangman_print.hpp"

namespace {

std::list<std::string> readNouns(std::string filename)
{
  std::ifstream ifs {filename};

  if (!ifs) {
    std::cerr << "Error opening noun list" << std::endl;
    std::exit(1);
  }

  std::string noun;
  std::list<std::string> list_of_nouns;

  while (std::getline(ifs,noun)) {
    list_of_nouns.push_back(noun);
  }

  return list_of_nouns;
}

std::string getRandomNoun(std::list<std::string> noun_list)
{
  auto random_position = std::rand() % noun_list.size();

  auto it = noun_list.begin();
  std::advance(it,random_position);

  return *it;
}

std::string makeHidden(const std::string & master_word)
{
  return std::string (master_word.size(),'_');
}

void printCharArray(const char * arr, unsigned size)
{
  if (size == 0)
    return;

  std::cout << arr[0];

  for (auto i = 1; i < size; ++i)
    std::cout << ", " << arr[i];
}

bool inCharArray(const char * arr, unsigned size, char check_char)
{
  for (auto i = 0; i < size; ++i) {
    if (arr[i] == check_char)
      return true;
  }

  return false;
}

void addChar(char arr[], unsigned & size, char new_char)
{
  arr[size] = new_char;
  ++size;
}

void printState(std::string word, char rg[], unsigned num_rg, char wg[], unsigned num_wg)
{
  printHangman(num_wg);
  std::cout << std::endl;
  std::cout << "Guess word:      " << word << std::endl;

  std::cout << "Correct guesses: ";
  printCharArray(rg,num_rg);
  std::cout << std::endl;

  std::cout << "Wrong guesses:   ";
  printCharArray(wg,num_wg);
  std::cout << std::endl;
}

char promptGuess(char rg[], unsigned num_rg, char wg[], unsigned num_wg)
{
  char guess = ' ';
  bool good_guess = false;

  while (!good_guess) {
    std::cout << "Next character guess: " << std::flush;
    std::cin >> guess;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    if (!std::isalpha(guess)) {
      std::cout << "Only alphabetic characters allowed" << std::endl;
      continue;
    }

    guess = std::tolower(guess);

    if (inCharArray(rg,num_rg,guess) or inCharArray(wg, num_wg, guess)) {
      std::cout << "Character already guesses" << std::endl;
      continue;
    }

    good_guess = true;
  }

  return guess;
}

void revealChar(const std::string & master_word, std::string & display_word, char guess)
{
  for (auto i = 0; i < master_word.size(); ++i) {
    if (master_word[i] == guess)
      display_word[i] = guess;
  }
}

}

void playHangman(std::string noun_filename)
{
  auto noun_list = readNouns(noun_filename);
  auto master_word = getRandomNoun(noun_list);
  auto display_word = makeHidden(master_word);

  bool game_over = false;

  unsigned number_of_wrong_guesses = 0;
  unsigned number_of_right_guesses = 0;

  char wrong_guesses [26];
  char right_guesses [26];

  while (!game_over) {
    printState(display_word, right_guesses, number_of_right_guesses, wrong_guesses, number_of_wrong_guesses);
    auto guess = promptGuess(right_guesses, number_of_right_guesses, wrong_guesses, number_of_wrong_guesses);

    if (inCharArray(master_word.c_str(), master_word.size(), guess)) {
      addChar(right_guesses, number_of_right_guesses, guess);
      revealChar(master_word, display_word, guess);
    } else {
      addChar(wrong_guesses, number_of_wrong_guesses, guess);
    }

    if (master_word == display_word or number_of_wrong_guesses > 6)
      game_over = true;
  }

  if (master_word == display_word) {
    std::cout << "You won!" << std::endl;
    std::cout << "The word was: " << master_word << std::endl;
  } else {
    printHangman(7);
  }

}
