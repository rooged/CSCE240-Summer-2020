/* Copyright 240 Timothy Gedney
* Create LargestIntegers method to fit problem specifications
*/
#include <iostream>
#include <string>
using std::string;
#include <fstream> //using ifstream
using std::ifstream;
#include <stdlib.h> //using atoi

int LargestInteger(const std::string& file_name) {
  //uses fstream to read file
  ifstream input(file_name);

  //while the file is read, if statement compares number read to max value
  int max = -9999999;
  int number = 0;
  while (input >> number) {
    if (number > max) {
      max = number;
    }
  }

  //returns max
  return max;
}