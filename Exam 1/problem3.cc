/* Copyright 240 Timothy Gedney
* Create SumDigits method to fit problem specifications
*/
#include <iostream>
#include <cmath> //using pow

int SumDigits(int value) {
  //checks if the entered value is negative
  int positive = 1;
  if (value < 0) {
    positive = 0;
    value *= -1;
  }

  //find length of number
  int width = 0;
  for (int i = value; i > 0; width++) {
    i /= 10;
  }

  //for loop to add up the numbers till it reaches the total length
  int answer = 0;
  for (int number = 0; width > -1; width--) {
    number = value / pow(10, width);
    int power = number * pow(10, width);
    value -= power;
    answer += number;
  }

  //if negative, makes answer negative
  if (positive == 0) {
    answer *= -1;
  }

  //returns answer
  return answer;
}