/* Copyright 240 Timothy Gedney
*
* Expanded upon the provided methods in the .h file
*/

#include <inc/functional_array.h>
#include <cstddef>
//using size_t

//creates new array of arrays for nested for loop to fill the each array of the sizes[i]
size_t** Allocate(const size_t* sizes, size_t length) {
  size_t** answer = new size_t*[length];
  size_t rowNumber;
  for (size_t i = 0; i < length; i++) {
    rowNumber = sizes[i];
    answer[i] = new size_t[rowNumber];
    for (size_t j = 0; j < rowNumber; j++) {
      answer[i][j] = rowNumber;
    }
  }
  return answer;
}

//nested for loop to sum the entire array then deletes the array
size_t Deallocate(const size_t** arrays, const size_t* sizes, size_t length) {
  size_t sum = 0;
  for (size_t i = 0; i < length; i++) {
    for (size_t j = 0; j < arrays[i][0]; j++) {
      sum += arrays[i][0];
    }
  }

  for (size_t i = 0; i < length; i++) {
    delete [] arrays[i];
  }
  delete [] arrays;

  return sum;
}