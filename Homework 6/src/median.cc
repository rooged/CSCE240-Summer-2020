/*  Copyright 240 Timothy Gedney
 *
 *  Expanded upon the provided methods in the .h file
 */

#include <inc/median.h>
#include <cstddef>
//  using size_t
#include <vector>
using std::vector;
#include <cmath>

namespace csce240 {
Statistic::~Statistic() {
//  empty
}

//  sorts the array, smallest to largest
void Median::Sort() {
  double swap;
  for (size_t i = 0; i < array.size(); i++) {
    for (size_t j = i + 1; j < array.size(); j++) {
      if (array[i] > array[j]) {
        swap = array[i];
        array[i] = array[j];
        array[j] = swap;
      }
    }
  }
}

//  collects datum into some collection
void Median::Collect(double datum) {
  array.push_back(datum);
  Sort();
}

//  calculates and returns the median of the data from the collect method
double Median::Calculate() const {
  if (array.size() == 0) {
    return 0;
  }

  bool even = true;
  if (array.size() % 2 != 0) {
    even = false;
  }

  double answer;
  int index = ceil(array.size() / 2);
  if (even == false) {
    answer = array[index];
  } else {
    answer = (array[index] + array[index - 1]) / 2;
  }

  return answer;
}
}  //  namespace csce240
