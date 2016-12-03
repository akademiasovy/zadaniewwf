/**
*@author: Stanislav Roba
*@date: 20/11/16
*@description: Main file
*@input: Numbers from Numbers.txt
*@output: 	1. Numbers are sorted from the highest to the lowest one in sorted.txt
			2. There are only even numbers written in even.txt
			3. There are only prime numbers written in prime.txt
			4. The mostly repeated number in mostly.txt
			5. Statistics in statisctics.txt
*/
#include <stdio.h>
#include <math.h>
#include "header.h"

int main() {
	
	FILE *fr;
	
	fr=fopen("Numbers.txt","r");
			if (fr==NULL) {
				printf ("ERROR! File issue!");
				return(1);
		}
	
	SortedNums(fr);
	EvenNums(fr);
	PrimeNums(fr);
	MostlyRepeatedNum(fr);
	Statistics(fr);
	fclose(fr);
}
