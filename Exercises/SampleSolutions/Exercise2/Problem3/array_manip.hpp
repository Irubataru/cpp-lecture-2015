/*
 * Created: 28-09-2015
 * Modified: Wed 30 Sep 2015 08:24:00 CEST
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#ifndef ARRAY_MANIP_HPP
#define ARRAY_MANIP_HPP

namespace Array {

void reverse(int input[], unsigned size);
void pivot(int input[], unsigned size, unsigned pivot);
void sort(int input[], unsigned size);
unsigned search(int input[], unsigned size, int value);
unsigned sorted_search(int input[], unsigned size, int value);
unsigned filter(int input[], int output[], unsigned size, bool (*unary)(int));

} // namespace Array 


#endif /* ARRAY_MANIP_HPP */
