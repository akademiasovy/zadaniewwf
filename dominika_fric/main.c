#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"
/*
@author Dominika Fric
@date 13.11.2016
@description: an app working with a text file full of numbers.
*/

int main(int argc, char *argv[]) {
	getSize();
	sortNumbers();
	findEvenNumbers();
	findPrimes();
	findMostPopulousNumber();
	createStatistics();
	return 0;
}
