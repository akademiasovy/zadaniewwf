/**
* @author: Rastislav Ruscak
* @date: 13.11.2016 
* @description: Main file.
*/
#include <stdio.h>
#include "header.h"

int main() {
	FILE *fr;
	fr=fopen("numbers.txt","r");
	if(fr==NULL){
		printf("ERROR, file issue!");
		return 1;
	}
	sortNumbers(fr);
	evenNumbers(fr);
	primeNumbers(fr);
	mostPopulousNumber(fr);
	statistics(fr);
	fclose(fr);
}






