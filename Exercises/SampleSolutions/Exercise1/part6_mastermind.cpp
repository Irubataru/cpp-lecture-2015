#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>

constexpr unsigned alternatives = 6;
constexpr unsigned size = 4;
constexpr unsigned guesses = 12;

int main()
{
  std::srand(std::time(0));

  unsigned master_combination[size];
  unsigned master_colour_count[alternatives];
  unsigned current_guess[size];

  for (auto c = 0; c < alternatives; ++c)
    master_colour_count[c] = 0;

  for (auto i = 0; i < size; ++i) {
    master_combination[i] = rand() % alternatives;
    ++master_colour_count[master_combination[i]];
  }


  std::cout << "Guess the combination of " << size << " numbers in [0,"
    << alternatives-1 << "] in " << guesses << " turns or less" << std::endl;

  unsigned guess_nr = 0;
  bool won_game = false;
  while (guess_nr < guesses) {
    std::cout << "Guess[" << guess_nr + 1 << "]: ";

    for (auto i = 0; i < size; ++i)
      std::cin >> current_guess[i];

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    if (!std::cin) {
      std::cout << "Nun-numeric character" << std::endl;

      std::cin.clear();
      std::string rubbish;
      std::getline(std::cin,rubbish);
      continue;
    }

    bool invalid_guess = false;
    for (auto i = 0; i < size; ++i) {
      if (current_guess[i] >= alternatives) {
        std::cout << "Invalid guess" << std::endl;
        invalid_guess = true;
        break;
      }
    }

    if (invalid_guess)
      continue;

    unsigned colour_count[alternatives];

    for (auto c = 0; c < alternatives; ++c) {
      colour_count[c] = 0;
    }

    unsigned fully_correct {0};
    unsigned partially_correct {0};

    for (auto i = 0; i < size; ++i) {
      if (current_guess[i] == master_combination[i])
        ++fully_correct;

      ++colour_count[current_guess[i]];
    }

    for (auto c = 0; c < alternatives; ++c) {
      if (colour_count[c] > master_colour_count[c])
        partially_correct += master_colour_count[c];
      else
        partially_correct += colour_count[c];
    }

    partially_correct -= fully_correct;

    std::cout << "Fully correct: " << fully_correct << ", partial: " << partially_correct << std::endl;

    if (fully_correct == size) {
      std::cout << "You won!" << std::endl;
      won_game = true;
      break;
    }

    ++guess_nr;
  }

  if (!won_game) {
    std::cout << "You lost, better luck next time!" << std::endl;
    std::cout << "The master combination was: [" << master_combination[0];

    for (auto i = 1; i < size; ++i)
      std::cout << ", " << master_combination[i];

    std::cout << "]" << std::endl;
  }
} 
