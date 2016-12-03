/**
*@description: File with functions
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "header.h"


/**
*@description: Function SizeofFile counts all numbers
*/
int SizeofFile() { // kolko je tam cisel
	
	int count=0,num;
	
	rewind(fr);
	while(fscanf(fr,"%d",&num)!=EOF) {
		count++;
	}
	return(count);
}

/**
*@description: Function SortedNums sorts numbers from the highest to the lowest one
*/
void SortedNums() { // zoradenie
	
	int count=SizeofFile(fr);
	int numbers[count];
	int i=0,j,num;
	
	FILE *fsorted;
	fsorted=fopen("sorted.txt", "w");
	
	rewind(fr);
	while(fscanf(fr,"%d",&num)!=EOF) {
		numbers[i]=num;
		i++;
	}
	
	for(i=0;i<count-1;i++){
		for(j=i+1;j<count;j++){
			if(numbers[i] > numbers[j]){
				numbers[i] = numbers[i] + numbers[j];
				numbers[j] = numbers[i] - numbers[j];
				numbers[i] = numbers[i] - numbers[j];
			}	
		}
	}
	for(i=0;i<count;i++) {
		fprintf(fsorted,"%d ",numbers[i]);
	}
	fclose(fsorted);
}

/**
*@description: Function EvenNums looks up even numbers
*/
void EvenNums() { // parne
	
	int num;
	FILE *feven;
	feven=fopen("even.txt", "w");
	
	rewind(fr);
	while(fscanf(fr,"%d",&num)!=EOF) {
		
		if(num%2==0) {
			fprintf(feven,"%d ",num);
		}
	}
	fclose(feven);
}

/**
*@description: Function PrimeNums looks up prime numbers
*/
void PrimeNums() { // prvocisla
	
	int num, i, count;
	FILE *fprime;
	fprime=fopen("primeNumbers.txt", "w");
	
	rewind(fr);
	while ( fscanf(fr,"%d",&num)!=EOF ) { // prvocisla
    	
    		if (num>2) {
        		if(num%2==0) {
            		continue;
        		}
				else {
        			for (i=1;i<=num;i++) {
        				if (num%i==0) {
        					count++;
        				if (count>2) {
        					continue;
						}
					}
				}
				if (count<=2) {
					fprintf (fprime,"%d ",num);
				}
			count=0;
		}
	}
	else
		continue;
	}
	fclose(fprime);
}


/**
*@description: Function MostlyRepeatedNum looks up mostly repeated number
*/void MostlyRepeatedNum() { // najcastejsie sa vyskytujuce
	int count=SizeofFile(fr);
	int numbers[count];
	int numbers2[1250];
	int NumCount[1250];
	
	int num, i=0, j=0, size=1, max;
	FILE *frepeated;
	frepeated=fopen("mostly.txt", "w");
	
	rewind(fr);
	while(fscanf(fr,"%d",&num)!=EOF) {
		numbers[i]=num;
		i++;
	}
	
	for(i=0;i<count-1;i++){
		for(j=i+1;j<count;j++){
			if(numbers[i] > numbers[j]){
				numbers[i] = numbers[i] + numbers[j];
				numbers[j] = numbers[i] - numbers[j];
				numbers[i] = numbers[i] - numbers[j];
			}
		}
	}
	
	j=0;
	i=0;
	
	for(i=0;i<count;i++){
		if(numbers[i]==numbers[i+1]){
			size++;
		}
		else {
			NumCount[j] = size;
			numbers2[j] = numbers[i];
			size=1;
			j++;
		}
	}
	NumCount[j]='\0';
	max=NumCount[0];
	i=1;
	int max2;
	while(NumCount[i]!='\0'){
		if(NumCount[i]>max){
			max=NumCount[i];
			max2=i;
		}
		i++;
	}
	
	i=0;
	j=0;
	size=0;
	
	int AM[1250];
	while(NumCount[i]!='\0') {
		if(NumCount[i]==max) {
			size++;
			AM[j]=i;
			j++;
		}
		i++;
	}
	i=0;
	while(AM[i] != '\0') {
		fprintf(frepeated,"%d ",numbers2[AM[i]]);
		i++;
	}
	fclose(frepeated);
}


/**
*@description: Function Statistics makes statistics
*/
void Statistics() { // statistika

	int neg=0, d4=0, d5=0, count20=0, min=999999, countofdigs=0, sumofdigs=0, num;
	
	FILE *fstatistic;
	fstatistic=fopen("statistics.txt", "w");
	
	rewind(fr);
	while(fscanf(fr,"%d",&num)!=EOF) {
		
		if(min>num) {
			min=num;
		}
		
		if(num<0) {
			neg++;
		}
		
		num=abs(num);
		while(num!=0) {
			sumofdigs+=num%10;
			num/=10;
			countofdigs++;
		}
		
		if(countofdigits==4) {
			d4++;
		}
		
		if(countofdigs==5) {
			d5++;
		}
		
		if(sumofdigs==20) {
			count20++;
		}
		
		sumofdigs=0;
		countofdigs=0;
	}
	
	fprintf(fstatistic,"%d ",Neg);
	fprintf(fstatistic,"%d ",Digs4);
	fprintf(fstatistic,"%d ",Digs5);
	fprintf(fstatistic,"%d ",Sum20);
	fprintf(fstatistic,"%d ",min);
	fclose(fstatistic);
}

