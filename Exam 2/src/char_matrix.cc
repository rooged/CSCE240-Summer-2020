/* Copyright 240 Timothy Gedney
*
* Expanded upon the provided methods in the .h file
*/

#include <inc/char_matrix.h>
#include <cstddef>
//using size_t

CharMatrix::CharMatrix() {
  //empty
}

//constructor
CharMatrix::CharMatrix(const char** chars, size_t rows, size_t cols) {
  rows_ = rows;
  cols_ = cols;
  matrix_ = new char*[rows];
  for (size_t i = 0; i < rows; i++) {
    matrix_[i] = new char[cols];
    for (size_t j = 0; j < cols; j++) {
      matrix_[i][j] = chars[i][j];
    }
  }
}

//copy constructor
CharMatrix::CharMatrix(const CharMatrix& that) {
  rows_ = that.rows_;
  cols_ = that.cols_;

  if (rows_ > 0 && cols_ > 0) {
    matrix_ = new char*[rows_];
  }

  for (size_t i = 0; i < rows_; i++) {
    matrix_[i] = new char[cols_];
    for (size_t j = 0; j < cols_; j++) {
      matrix_[i][j] = that.matrix_[i][j];
    }
  }
}

//destructor
CharMatrix::~CharMatrix() {
  if (matrix_) {
    for (size_t i = 0; i < rows_; i++) {
      delete [] matrix_[i];
    }
    delete [] matrix_;
  }
}

//assignment operator
const CharMatrix& CharMatrix::operator=(const CharMatrix& rhs) {
  rows_ = rhs.rows_;
  cols_ = rhs.cols_;

  if (rows_ > 0 && cols_ > 0) {
    matrix_ = new char*[rows_];
  }

  for (size_t i = 0; i < rows_; i++) {
    matrix_[i] = new char[cols_];
    for (size_t j = 0; j < cols_; j++) {
      matrix_[i][j] = rhs.matrix_[i][j];
    }
  }

  return *this;
}