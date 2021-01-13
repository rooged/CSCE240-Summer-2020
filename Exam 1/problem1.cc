/* Copyright 240 Timothy Gedney
 *
 * Problem1: prefix notation arithmetic calculator
 *  Arithmetic is customarily represented using infix notation, e.g. 1.0 + 2.0.
 *  In this assignment, you are creating a prefix notation calculator,
 *  e.g. + 1.0 2.0.
 *
 *  The program will read the operator and operands from the standard input
 *  stream (using cin). The operator will be first and the left-hand side and
 *  right-hand side operands will be second and third, respectively. You will
 *  then write the output of the operation to the standard output stream (using
 *  cout).
 *
 *  DO NOT emit anything other than the result. This is a calculator. Simply
 *  emit the result of the operation. Do not prompt for input. Just write the
 *  result of the operation.
 *
 *  You must provide operators:
 *    + : addition
 *    - : subtraction
 *    x : multiplication
 *    / : division
 *    < : less than
 *    > : greater than
 *
 * Notes:
 *  The two operands should be read as floating point data and the operator is a
 *  character. You need not set precision for the floating point
 *  output. The default precision for a double is all that is required.
 *
 * Points:
 *  compilation: 1
 *  style: 1
 *  correctness: 3
 */
#include <iostream>
using std::cin;
using std::cout;

int main(int argc, char* argv[]) {
  //input expression
  char operand;
  double first;
  double second;
  cin >> operand >> first >> second;

  //if/else statement to check operand & do calculation
  double answer = 0;
  double answerTF = 1;
  if (operand == '+') {
    answer = first + second;
  } else if (operand == '-') {
    answer = first - second;
  } else if (operand == 'x') {
    answer = first * second;
  } else if (operand == '/') {
    answer = first / second;
  } else if (operand == '<') {
    if (first > second) {
      answerTF = 0;
    }
  } else {
    if (first < second) {
      answerTF = 0;
    }
  }

  //output answer
  if (operand == '<' || operand == '>') {
    if (answerTF == 1) {
      cout << "true";
    } else {
      cout << "false";
    }
  } else {
    cout << answer;
  }
}