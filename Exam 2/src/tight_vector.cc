/* Copyright 240 Timothy Gedney
*
* Expanded upon the provided methods in the .h file
*/

#include <inc/tight_vector.h>
#include <cstddef>
//using size_t

//constructor
TightVector::TightVector() {
  count_ = 0;
  array_ = 0;
}

//destructor
TightVector::~TightVector() {
  delete [] array_;
}

//adds new element to end
//increases the array size by one every iteration
void TightVector::Append(int element) {
  int *new_array;
  size_t new_count = count_ + 1;

  new_array = new int[new_count];

  for (size_t i = 0; i < count_; i++) {
    new_array[i] = array_[i];
  }
  new_array[count_] = element;

  delete [] array_;
  count_ = new_count;
  array_ = new_array;
}

//adds new element to beginning
//increases the array size by one every iteration
void TightVector::Prepend(int element) {
  int *new_array;
  size_t new_count = count_ + 1;

  new_array = new int[new_count];

  for (size_t i = 1; i < new_count; i++) {
    new_array[i] = array_[i - 1];
  }

  new_array[0] = element;

  delete [] array_;
  count_ = new_count;
  array_ = new_array;
}
