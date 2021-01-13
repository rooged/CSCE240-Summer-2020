/* Copyright 240 Timothy Gedney
*
* Expand the provided calculation library from comp_geo.h to be implemented and calculated here.
* The methods should stick to the specifications provided
*/
#include <inc/sum_finder.h>
#include <iostream>
using std::cin;
using std::cout;
#include <cstddef>
//using size_t

size_t** FindSum(int sum, const int** matrix, const size_t matrix_size[], size_t* sums_found) {
  int width = matrix_size[0];
  int height = matrix_size[1];
  int srow = 0;
  int scol = 0;
  int erow = 0;
  int ecol = 0;
  int count = 0;
  size_t** finalMatrix = &sums_found;

  //check horizontonally left to right
  int add = 0;
  for (int j = 0; j < height; j++) {
    for (int i = 0; i < width; i++) {
      if (add == 0) {
        srow = i;
        scol = j;
      }
      add += *(*(matrix + i) + j);
      erow = i;
      ecol = j;
      if (add == sum) {
        *sums_found += 1;
        count++;
        add = 0;
      }
    }
    add = 0;
  }

  //check horizontally right to left
  add = 0;
  for (int j = height - 1; j >= 0; j--) {
    for (int i = width - 1; i >= 0; i--) {
      if (add == 0) {
        erow = i;
        ecol = j;
      }
      add += *(*(matrix + i) + j);
      srow = i;
      scol = j;
      if (add == sum) {
        *sums_found += 1;
        count++;
        add = 0;
      }
    }
 }

  //check vertically top down
  add = 0;
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      if (add == 0) {
        srow = i;
        scol = j;
      }
      add += *(*(matrix + i) + j);
      erow = i;
      ecol = j;
      if (add == sum) {
        *sums_found += 1;
        count++;
        add = 0;
      }
    }
    add = 0;
  }

  //check vertically down up
  add = 0;
  for (int i = width - 1; i >= 0; i--) {
    for (int j = height - 1; j >= 0; j--) {
      if (add == 0) {
        erow = i;
        ecol = j;
      }
      add += *(*(matrix + i) + j);
      srow = i;
      scol = j;
      if (add == sum) {
        *sums_found += 1;
        count++;
        add = 0;
      }
    }
    add = 0;
  }

  //checks count to see if any summations were found, sets *sums_found to 0 if not
  if (count == 0) {
    *sums_found = 0;
  }

  return finalMatrix;
}

//grows 2-D array in only one dimension. Increases the arrays length by 1.
size_t** GrowArray(const size_t** array, size_t size) {
  size_t** new_array = nullptr;
  size_t new_size = size + 1;

  new_array = new size_t*[new_size];

  for (size_t i = 0; i < size; i++) {
    new_array[i] = new size_t[4];
    for (size_t j = 0; j < 4; j++) {
      new_array[i][j] = array[i][j];
    }
  }

  return new_array;
}
