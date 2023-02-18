/*
 * Created: 28-09-2015
 * Modified: Wed 30 Sep 2015 19:54:20 CEST
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#include"array_manip.hpp"
#include<utility>
#include<functional>

namespace {

// Upper bound algorithm implemented by checking the midpoint
// and then working with an effective array half the size of
// the original one
//
// Use a lot of fun pointer arithmetic ^^
int* upper_bound(int *begin, int *end, int value)
{
  if (begin == end)
    return begin;

  auto half_pos = static_cast<unsigned>(end - begin)/2;

  if ( *(begin + half_pos) < value ) {
    return upper_bound(begin+1+half_pos, end, value);
  } else {
    return upper_bound(begin, begin+half_pos, value);
  }
}

}

namespace Array {
 
// Reverses the the input array
// Reverse done by swapping two and two elements
void reverse(int input[], unsigned size)
{
  for (auto i = 0; i < size/2; ++i)
    std::swap(input[i],input[size-1-i]);
}

// Pivot the list around the pivot point
void pivot(int input[], unsigned size, unsigned pivot)
{
  int buffer[size];

  // Copy the elements from the beginning to the pivot to a buffer
  for (auto i = 0; i < pivot; ++i)
    buffer[i] = input[i];

  // Move the elements from behind the pivot to the front of the array
  for (auto i = pivot; i < size; ++i)
    input[i-pivot] = input[i];

  // Copy the buffer to the end of the array
  for (auto i = 0; i < pivot; ++i)
    input[size-pivot+i] = buffer[i];
}

// Sort an array using the bubblesort algorithm
void sort(int input[], unsigned size)
{
  bool no_swaps = true;

  do {
    no_swaps = true;

    // Iterate through the list, and swap every pair that is not
    // sorted
    for (auto i = 0; i < size - 1; ++i) {
      if (input[i] > input[i+1]) {
        std::swap(input[i],input[i+1]);
        no_swaps = false;
      }
    }
    
    // Continue doing this until no more pairs remain unsorted
  } while (!no_swaps);
}

// Sort for en element in an array
// Return the index of the first occurance
// if the value isn't in the array, return the size of the array
unsigned search(int input[], unsigned size, int value)
{
  for (auto i = 0; i < size; ++i) {
    if (input[i] == value)
      return i;
  }

  return size;
}

// Search for the element assuming that the array is sorted
// First check if the middle element is bigger or smaller than the value
// you are looking for. If the mid point is bigger, the value need to be
// located in the lower half of the array. If it is larger it needs to be
// located in the upper half
unsigned sorted_search(int input[], unsigned size, int value)
{
  // First find an upper bound for the location of the element
  auto search_ptr = upper_bound(input, input + size, value);

  // Check if the element at the upper bound it the same as the one we
  // are looking for
  if ( *search_ptr == value )
    return static_cast<unsigned>(search_ptr - input);
  else
    return size;
}

// Copy the elements of input that give true when
// given to the unary function, the return value is the
// effective size of the output array
unsigned filter(int input[], int output[], unsigned size, bool (*unary)(int))
{
  auto pos = 0;

  for (auto i = 0; i < size; ++i) {
    if ( (*unary)(input[i]) ) {
      output[pos] = input[i];
      ++pos;
    }
  }

  return pos;
}


} // namespace Array 

