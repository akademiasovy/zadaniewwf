#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
@author Dominika Fric
@date 13.11.2016
@description: finds out the amount of numbers in the file, helper function.
*/
int getSize()
{
	FILE *fr;
	int n=0 ,count=0;
	fr=fopen("numbers.txt","r");
	if(fr==NULL)
	{
		printf("Error. Your file doesn't exist.");
	}
	else
	{
		while(fscanf(fr,"%d",&n)!=EOF){
			count++;
			
		}
		return count;
	}
	
	fclose(fr);
	
}

/*
@author Dominika Fric
@date 13.11.2016
@description: sorts numbers in ascending order and creates a file including them.
*/

int sortNumbers()
{
	FILE *fw, *fr;
	fr=fopen("numbers.txt","r");
	fw=fopen("sortedNumbers.txt","w");
	int fileLen=getSize();
	int i,j,t, array[fileLen];
	
	for(i=0;i<=fileLen;i++)
	{
		fscanf(fr,"%d",&t);
		array[i]=t;
	}
	
	for(i=0;i<=fileLen;i++)
	{
		for(j=0;j<=fileLen-i;j++){
			if(array[j]>array[j+1]){
				t=array[j];
				array[j]=array[j+1];
				array[j+1]=t;
			}
		}
	}
	
	for(i=0;i<=fileLen;i++){
		fprintf(fw,"%d ",array[i]);
	}
	
	fclose(fr);
	fclose(fw);
	
	return array[0];
	
}
 
/*
@author Dominika Fric
@date 13.11.2016
@description: creates a file which contains even numbers only.
*/
void findEvenNumbers()
{
	FILE *fw, *fr;
	fr=fopen("numbers.txt","r");
	fw=fopen("evenNumbers.txt","w");
	int n;
	
	if(fr==NULL)
	{
		printf("Error. Your file doesn't exist.");
	}
	else
	{
		while(fscanf(fr,"%d",&n)!=EOF){
			if(n%2==0){
				fprintf(fw,"%d ",n);
			}
			
		}
		
	}
	
	fclose(fw);
	fclose(fr);
}

/*
@author Dominika Fric
@date 13.11.2016
@description: creates a file which contains prime numbers only.
*/

void findPrimes()
{
	FILE *fr, *fw;
	fr=fopen("numbers.txt","r");
	fw=fopen("primeNumbers.txt","w");
	int i,n,check=0;
	
	if(fr==NULL)
	{
		printf("Error. Your file doesn't exist.");
	}
	else
	{
		while(fscanf(fr,"%d",&n)!=EOF){
			check=0;
			if(n>1&&n%2==1){
			for(i=2;i<n;i++)
			{
				if(n%i==0){
				check+=1;
				}
			}
			
		if(check==0){
			fprintf(fw,"%d ",n);
		}
	
		}
	}
	}
	
	fclose(fw);
	fclose(fr);
	
}

/*
@author Dominika Fric
@date 13.11.2016
@description: finds most common numbers of the file,reads from sortedNumbers to save some work.
*/
void findMostPopulousNumber()
{
	FILE *fr, *fw;
	fr=fopen("sortedNumbers.txt","r");
	fw=fopen("mostPopulousNumber.txt","w");
	int len=getSize();
	int numbers[len],count[len];
	int i,j,n;
	
	for(i=0;i<len;i++){
		count[i]=0;
	}
	
	for(i=0;i<len;i++)
	{
		fscanf(fr,"%d",&n);
		numbers[i]=n;
	}
	
	for(i=0;i<len;i++){
		for(j=0;j<len;j++){
			if(numbers[i]==numbers[j]){
				count[i]++;
			}
		}
	}
	
	for(i=0;i<len;i++){
		if(count[i]>2&&(count[i]!=count[i+1])){
			fprintf(fw,"\n%d included %d times\n",numbers[i],count[i]);
		}
	}
	
	fclose(fw);
	fclose(fr);
	
	
}

/*
@author Dominika Fric
@date 13.11.2016
@description: makes statistics about number.txt, including number of negative numbers, 4digit and 5 digit numbers
and the amount of numbers whose ciphers equal 20 when added.
*/
void createStatistics()
{
	FILE *fr, *fw;
	fr=fopen("numbers.txt","r");
	fw=fopen("statistics.txt","w");
	int countN=0, count20=0, count4=0,count5=0,n,t;
	int sum=0;
	
		while(fscanf(fr,"%d",&n)!=EOF){ //negative numbers
			if(n<0){
				countN++;
			}
			
		}
		fprintf(fw,"\nCount of negative numbers: %d\n",countN);
		
		
		rewind(fr); //four digit numbers here
		while(fscanf(fr,"%d",&n)!=EOF){
			if((n>999&&n<10000)||(n<-999&&n>-10000)){
				count4++;
			}
			
		}
		fprintf(fw,"\nCount of 4 digit numbers: %d\n",count4);
		
		rewind(fr);
		while(fscanf(fr,"%d",&n)!=EOF){ //five digit numbers
			if((n>9999&&n<100000)||(n<-9999&&n>-100000)){
				count5++;
			}
			
		}
		fprintf(fw,"\nCount of 5 digit numbers: %d\n",count5);
		
		rewind(fr); //numbers with digit sum 20
		while(fscanf(fr,"%d",&n)!=EOF){
			sum=0;
			if(n<0){
				n=n*(-1);
			}
				while(n>0){
				t=n%10;
				sum+=t;
				n/=10;
				}
			
			if(sum==20){
				count20++;
			}
		}
		fprintf(fw,"\nCount of numbers with digit sum 20: %d\n",count20);
		
		fprintf(fw, "Minimal value: %d\n",sortNumbers());
		
		
		
		
		
	
	
	
}
