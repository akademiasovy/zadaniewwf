/**
* @author Matus Haluska
* @description program that works with numbers from file
*/
#include <stdio.h>
#include <math.h>
#include <ctype.h>
void sortedN();
void evenN();
void primeN();
void mostPopulousN();
void statistics();

int main(){
	sortedN();
	evenN();
	primeN();
	mostPopulousN();
	statistics();
	

}

/**
* @input numbers from file
* @output file with all numbers sorted ascending
*/
void sortedN(){
	int x, count=0,comp, i, j;
	FILE *fr, *fw;
	fr=fopen("numbers.txt", "r");

	if(fr==NULL){
		printf("error");
	}
	else{ 
		while(fscanf(fr,"%d", &x )!=EOF){
			count++;	
		}
	}
	fclose(fr);

	
	int holder[count];
	count=0;
	
	fr=fopen("numbers.txt", "r");
	if(fr==NULL){
		printf("error");
	}
	else{ 
		while(fscanf(fr,"%d", &x )!=EOF){
			holder[count]=x;
			count++;
		}
	}
	
	for(i=0; i<=count-2; i++){
		for (j=i+1; j<=count-1; j++){
			if(holder[i]>holder[j]){
				comp=holder[i];
				holder[i]=holder[j];
				holder[j]=comp; 
			}
		}
	}
	
	fclose(fr);
	
	fw=fopen("sortedNumbers.txt", "w");
	if(fw==NULL){
		printf("error");
	}
	else{
		for(i=0; i<count; i++){
			fprintf(fw,"%d ", holder[i]);
		}
	fclose(fw);
	}
}

/**
* @input numbers from file
* @output file with  all even numbers
*/
void evenN(){
	int x;
	FILE *fr, *fw;
	fr=fopen("numbers.txt", "r");
	fw=fopen("evenNumbers.txt", "w");
	if(fw==NULL){
		printf("error");
	}
	else{
		if(fr==NULL){
			printf("error");
		}
		else{ 
			while(fscanf(fr,"%d", &x )!=EOF){
				if(x>0 && x%2==0){
				fprintf(fw,"%d ",x);	
				}
			}
		}
	}
		
	fclose(fr);
	fclose(fw);
	
}

/**
* @input numbers from file
* @output file with  all prime numbers
*/
void primeN(){
	int x, count=0,comp, i, j;
	FILE *fr, *fw;
	fr=fopen("numbers.txt", "r");
	fw=fopen("primeNumbers.txt", "w");
	if(fw==NULL){
		printf("error");
	}
	else{
		if(fr==NULL){
			printf("error");
		}
		else{ 
			while(fscanf(fr,"%d", &x )!=EOF){
				if(x>1){
					if(x>2 && x%2==0){
						continue;
					}
					else{
						for(i=1; i<=x; i++){
							if(x%i==0){
								count++;
								if(count>2){
									continue;
								}
							}
						}
						if(count<=2){
							fprintf(fw,"%d ",x);
						}
					}
					count=0;
				}
				else{
					continue;
				}
			}
		}
	}
		
	fclose(fr);
	fclose(fw);

}

/**
* @input numbers from file
* @output most popular number
*/
void mostPopulousN(){
	int x, count=0,comp, i, j;
	FILE *fr, *fw;
	fr=fopen("numbers.txt", "r");

	if(fr==NULL){
		printf("error");
	}
	else{ 
		while(fscanf(fr,"%d", &x )!=EOF){
			count++;	
		}
	}
	fclose(fr);
	
	int holder[count];
	count=0;
	
	fr=fopen("numbers.txt", "r");
	if(fr==NULL){
		printf("error");
	}
	else{ 
		while(fscanf(fr,"%d", &x )!=EOF){
			holder[count]=x;
			count++;
		}
	}
	
	for(i=0; i<=count-2; i++){
		for (j=i+1; j<=count-1; j++){
			if(holder[i]>holder[j]){
				comp=holder[i];
				holder[i]=holder[j];
				holder[j]=comp; 
			}
		}
	}
	
	int min=holder[0];
	int max=holder[count-1];
	int size, m=0, pos;
	
	if(min<0){
		min*=(-1);
	}
	
	if(max<0){
		max*=(-1);
	}
	
	size=max+min;
	int index[size+1];
	for(i=0; i<size+1; i++){
		index[i]=0;
	}
	
	for(i=0; i<size+1; i++){
		for(j=0; j<count; j++){
			if((i+holder[0])==holder[j]){
				index[i]++;
			}
		}	
	}
	
	for(i=0; i<size+1; i++){
		if(index[i]>m){
			m=index[i];
			pos=i;
		}
	}
	
	int result=pos+holder[0];
	
	fw=fopen("mostPopulousNumber.txt", "w");
	if(fw==NULL){
		printf("error");
	}
	else{
		fprintf(fw,"%d - Most populous number\n%d - The number of occurrences", result, m);
	}
	

	fclose(fr);
	fclose(fw);
}

/**
* @input numbers from file
* @output statistics (quantity of negative nubers, 4-digit numbers, 5-digit numbers, min volue, sum of digits)
*/
void statistics(){
	int x;
	int neg=0, fordigit=0, fivedigit=0,sum=0, digitSum=0, minV=2147483647, modulo, a;
	FILE *fr, *fw;
	fr=fopen("numbers.txt", "r");
	fw=fopen("statistics.txt", "w");
	if(fw==NULL){
		printf("error");
	}
	else{
		if(fr==NULL){
			printf("error");
		}
		else{ 
			while(fscanf(fr,"%d", &x )!=EOF){
				if(x<0){
					neg++;
				}
				if((x>999 && x<=9999) || (x>=-9999 && x<-999)){
					fordigit++;
				}
				if((x>9999 && x<=99999) || (x>=-99999 && x<-9999)){
					fivedigit++;
				}
				if(x>298 || x<-298){
					if(x<-298){
						a=x*(-1);
					}
					else{
						a=x;
					}
				
					while(a!=0){
						modulo=a%10;
						sum+=modulo;
						a=a/10;
					}
					if(sum==20){
						digitSum++;
						sum=0;
					}
					else{
						sum=0;
					}
				}
				if(x<minV){
					minV=x;
				}
				
			}
		}
	}
	fprintf(fw,"negative numbers - %d\n4-digit numbers - %d\n5-digit numbers - %d\nnumber of numbers where digit sum is 20 - %d\nmin volue - %d",neg, fordigit, fivedigit,digitSum,minV);	
	
	fclose(fr);
	fclose(fw);
	
}
