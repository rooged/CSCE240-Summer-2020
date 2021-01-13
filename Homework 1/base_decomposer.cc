/* Copyright 202 Timothy Gedney
*
* Take in a base-10 number and output the number in the power series positional counting system
* i.e.
* Input: 123,456
* Output: 100000 + 20000 + 3000 + 400 + 50 + 6
*/
#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

int main(int argc, char* argv[]) {
	// input the base-10 number
	int input = 10;
	cin >> input;

	// check if the number is negative
	int positive = 1;
	if (input < 0) {
		positive = 0;
		cout << "-(";
		input *= -1;
	}
	
	// find the width of the number
	int width = -1;
	for (int i = input; i > 0; width++) {
		i /= 10;
	}
	
	// for loop to divide the number by 10 to get each leading number
	// and prints out the power series
	for (int number = 0; width > -1; width--) {
		number = input / pow(10, width);
		int power = number * pow(10, width);
		input = input - power;
		if (power == 0) {
			for (int i = width; i > 0; i--) {
				cout << "0";
			}
		}
		cout << power;
		if (width > 0) {
			cout << " + ";
		}
	}
	if (positive == 0) {
		cout << ")";
	}
}