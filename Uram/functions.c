#include "functions.h"
#include <stdio.h>
#include <math.h>

FILE *fr,*fw;

/**
*@author: Vladimir Uram
*@date: 13.11.2016
*@description: create file 'statistics.txt' which consists counts of numbers from file 'numbers.txt' which are negative, 4-digits, 5-digits, which digit sum is 20 and smallest number
*@input: count of numbers in 'numbers.txt' and file 'numbers.txt'
*@output: 'statistics.txt' where are writted numbers
*/
void statistics(int size){
	FILE *fm;
	int n[size],i,count=0;
	fr = fopen("numbers.txt","r");
	fw=fopen("statistics.txt","w");
		for(i=0; i<size; i++)fscanf(fr,"%d",&n[i]);
		for(i=0; i<size; i++)if(n[i]<0)count++;
		fprintf(fw,"Number of negative numbers: %d",count);
		count=0;
		for(i=0;i<size;i++)if(n[i]>999&&n[i]<10000||n[i]>-10000&&n[i]<-999)count++;
		fprintf(fw,"\nNumber of 4-digit numbers: %d",count);
		count=0;
		for(i=0;i<size;i++)if(n[i]>9999&&n[i]<100000||n[i]>-100000&&n[i]<-9999)count++;
		fprintf(fw,"\nNumber of 5-digit numbers: %d",count);
		fm=fopen("storedNumbers.txt", "r");
		count=0;
		int j;
		for(i=0;i<size;i++){
			if(n[i]<0)n[i]*=-1;
			if(n[i]>299){
			int dig=floor (log10 (abs (n[i]))) + 1;
			int sum = 0;
			for(j=0;j<dig;j++){
				sum = sum + (n[i]%10);
				n[i]/=10;
			}
			if(sum==20)count++;
			}
		}
		fprintf(fw,"\nNumber of numbers where digit sum is 20: %d",count);
		fm=fopen("storedNumbers.txt", "r");	
			
		
	fscanf(fm,"%d",&i);
		fprintf(fw,"\nThe smallest number: %d",i);
		fclose(fm);
	}
	
/**
*@author: Vladimir Uram
*@date: 13.11.2016
*@description:create file 'mostPopulousNumber.txt' which consists of all numbers from file 'numbers.txt' that are most populous
*@input: count of numbers in 'numbers.txt' and file 'numbers.txt'
*@output: 'mostPopulousNumber.txt' where are writted numbers
*/
void mostPopulousNumber(int size){
	int i,j;
	int n[size];
	int m[size];
	for (i=0;i<size;i++)m[i]=0;
	fr = fopen("numbers.txt","r");
	fw=fopen("mostPopulousNumber.txt","w");
		for(i=0; i<size; i++)fscanf(fr,"%d",&n[i]);
	for(i=0; i<size;i++){
			for(j=0; j<size;j++){
		if(n[i]==n[j])m[i]+=1;
		}
	}
	int max=0;
	int s[size];
		for (i=0;i<size;i++)s[i]=0;
	int c=1;
		for(i=0; i<size;i++){
				if(max<m[i])max=m[i];
	}
		for(i=0; i<size;i++){
				if(m[i]==max){	s[i]=n[i];
			}}	
				for(i=0; i<size;i++){
					for(j=0; j<size;j++){
					if(s[i]!=0&&i!=j)if(s[i]==s[j])s[j]=0;
			}}
		for(i=0;i<size;i++){
			if(s[i]!=0){fprintf(fw,"%d. %d\n",c,n[i]); c++;
			}}
	fclose(fr);
    fclose(fw);
	}
/**
*@author: Vladimir Uram
*@date: 13.11.2016
*@description: create file 'primeNumbers.txt' which consists of all numbers from file 'numbers.txt' that are prime
*@input: count of numbers in 'numbers.txt' and file 'numbers.txt'
*@output: 'primeNumbers.txt' where are writted numbers
*/
void primeNumbers(int size){
	fr = fopen("numbers.txt","r");
	fw=fopen("primeNumbers.txt","w");
	int n[size],a,c=1;
	for(a=0;a<size;a++){
		if(n[a]>11||n[a]<-11){
	
		if(n[a]%2!=0&&n[a]!=0&&n[a]%3!=0&&n[a]%5!=0&&n[a]%7!=0&&n[a]%11!=0){
	    	fprintf(fw,"%d. %d\n",c,n[a]);	c++;
		}}
		else{	if(n[a]==2||n[a]==3||n[a]==5||n[a]==7||n[a]==11){
	
			fprintf(fw,"%d. %d\n",c,n[a]);	c++;
		} }
		
	}
		 fclose(fr);
    fclose(fw);
}

/**
*@author: Vladimir Uram
*@date: 13.11.2016
*@description: create file 'storeNumbers.txt' which consists of all numbers from file 'numbers.txt' that are even
*@input: count of numbers in 'numbers.txt' and file 'numbers.txt'
*@output: 'evenNumbers.txt' where are writted numbers
*/
void evenNumbers(int size){
	fr = fopen("numbers.txt","r");
	fw=fopen("evenNumbers.txt","w");
	int n[size],a,c=1;
	for(a=0;a<size;a++){
		if(n[a]%2==0&&n[a]!=0){
	   	fprintf(fw,"%d. %d\n",c,n[a]);	c++;
		}
	}
	 fclose(fr);
    fclose(fw);
}
/**
*@author: Vladimir Uram
*@date: 13.11.2016
*@description: create file 'storeNumbers.txt' which consists of all numbers from file 'numbers.txt' that are stored in ascending order
*@input: count of numbers in 'numbers.txt' and file 'numbers.txt'
*@output: 'storedNumbers.txt' where are writted numbers
*/
void numberAscending(int size){
 	int n[size],d,a;
	 fr = fopen("numbers.txt","r");
	for(a=0; a<size; a++)fscanf(fr,"%d",&n[a]);
	for (a = 0 ; a < ( size - 1 ); a++){
    for (d = 0 ; d < size - a - 1; d++){
      if (n[d] > n[d+1]){
        int swap = n[d];
        n[d] = n[d+1];
       n[d+1] = swap;
      }}}
    fw=fopen("storedNumbers.txt","w");
    for(a=0;a<size;a++){
    	fprintf(fw,"%d\n",n[a]);
	}
    fclose(fr);
    fclose(fw);
}

/**
*@author: Vladimir Uram
*@date: 13.11.2016
*@description: this function calculate count of numbers in file 'numbers.txt'
*@input: file 'numbers.txt'
*@output: 'statistics.txt' where are writted numbers
*/
int numberOfDigits(){
	int c,count=0;
    fr = fopen("numbers.txt","r");
    while ((fscanf(fr,"%d",&c))!=EOF){
        count++;
    }
     fclose(fr);
      return count;
}

/**
*@author: Vladimir Uram
*@date: 13.11.2016
*@description:
*@input: chceck if exists file 'numbers.txt' and call functions
*@output: text output which informs if program ending correctly or not
*/
void mainFunction(){
    fr = fopen("numbers.txt","r");
    if(fr!=NULL){
	
   int size =numberOfDigits();
   numberAscending(size);
   evenNumbers(size);
   primeNumbers(size);
   mostPopulousNumber(size);
   statistics(size);
   printf("The process was done correctly!");
    }
    else printf("Error! file 'numbers.txt' not exist or not have premission to open file");
		
}

