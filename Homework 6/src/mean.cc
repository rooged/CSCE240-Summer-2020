/*  Copyright 240 Timothy Gedney
 *
 *  Expanded upon the provided methods in the .h file
 */

#include <inc/mean.h>
#include <cstddef>
//  using size_t
#include <vector>
using std::vector;

namespace csce240 {
Statistic::~Statistic() {
//  empty
}

//  stores data (datum) such that any average may be calculated
void Mean::Collect(double datum) {
  array.push_back(datum);
}

//  returns the mean of the data from the collect method
double Mean::Calculate() const {
  if (array.size() == 0) {
    return 0;
  }

  double mean = 0;
  size_t count = 0;
  for (size_t i = 0; i < array.size(); i++) {
    mean += array[i];
    count++;
  }

  double answer = mean / count;

  return answer;
}
}  //  namespace csce240