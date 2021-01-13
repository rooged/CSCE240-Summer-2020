/* Copyright 240 Timothy Gedney
 *
 * Problem2: prefix notation arithmetic calculator
 *  Arithmetic is customarily represented using infix notation, e.g. 1 + 2. In
 *  this assignment, you are creating a prefix notation calculator, e.g. + 1 2.
 *
 *  Read the three arguments passed into the file. They will be at indices 1,
 *  2, and 3. The operator will be at index 1, the left and right operands at
 *  indices 2 and 3, respectively. You will then write the output of the
 *  operation. DO NOT emit anything else. This is a calculator. Simply write the
 *  result of the operation to the standard output stream (using cout).
 *
 *  You must provide operators:
 *    + : addition
 *    - : subtraction
 *    x : multiplication
 *    / : division
 *    % : modulo
 *    ^ : exponentiation
 *
 * Notes:
 *  The two operands should be converted to integral data and the operator is a
 *  character. The arguments are passed in as character arrays (char* argv[])
 *  and so the operator cannot be directly compared to string literals such as
 *  "+". I would recommend using the string class, which accepts a character
 *  array in its constructor and provides the == (equivalency) operator to
 *  determine which operator was provided.
 *
 *  The operands can be converted from character arrays (char* argv[]) to
 *  signed ints by the atoi function.
 *
 * References:
 *  atoi: cplusplus.com/reference/cstdlib/atoi/
 *  string: http://www.cplusplus.com/reference/string/
 *
 * Points:
 *  compilation: 1
 *  style: 1
 *  correctness: 3
 */
#include <iostream>
using std::cin;
using std::cout;
#include <cmath> //using pow
#include <stdlib.h> //using atoi

int main(int argc, char* argv[]) {
  //take in the character arrays
  char operand = argv[1][0];
  int first = atoi(argv[2]);
  int second = atoi(argv[3]);

  //if/else statements to determind the correct operand and calculate answer
  int answer = 0;
  if (operand == '+') {
    answer = first + second;
  } else if (operand == '-') {
    answer = first - second;
  } else if (operand == 'x') {
    answer = first * second;
  } else if (operand == '/') {
    answer = first / second;
  } else if (operand == '%') {
    answer = first % second;
  } else {
    answer = pow(first, second);
  }

  //output answer
  cout << answer;
}