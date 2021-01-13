/* Copyright 240 Timothy Gedney
* Create SumDigits method to fit problem specifications
*/
#include <iostream>
#include <string>
using std::string;
#include <cmath> //using floor

std::string DecimalToBinary(unsigned int decimal_value) {
  //initialize answer string
  string answer = "";

  //while loop to convert decimal_value until its zero
  //uses .insert to add a 0/1 to beginning of string
  int remainder = 0;
  while (decimal_value > 0) {
    remainder = decimal_value % 2;
    if (remainder == 0) {
      answer.insert(0, "0");
    } else {
      answer.insert(0, "1");
    }
    decimal_value = floor(decimal_value / 2);
  }

  //returns answer
  return answer;
}