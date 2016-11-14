#include <stdio.h>
#include <string.h>

/**
* @input: pointer on file
* @description: function is counting numbers from file
*/
int getSize(FILE *fread){
	int size=0, num;
	rewind(fread);
	while(fscanf(fread, "%d", &num)!=EOF){
		size++;
	}
	return size;
}

/**
* @input: pointer on file
* @description: function printf sorted numbers into output file
*/
void sortNumbers(FILE *fread){
	int size=getSize(fread);
	int numbers[size];
	int i=0, j, num;
	
	FILE *fwSort;
	fwSort=fopen("sortNumbers.txt", "w");
	rewind(fread);
	while(fscanf(fread, "%d", &num)!=EOF){
		numbers[i]=num;
		i++;
	}
	for(i=0; i<size-1; i++){
		for(j=i+1; j<size; j++){
			if(numbers[i] > numbers[j]){
				numbers[i]=numbers[i]+numbers[j];
				numbers[j]=numbers[i]-numbers[j];
				numbers[i]=numbers[i]-numbers[j];
			}	
		}
	}
	for(i=0; i<size; i++){
		fprintf(fwSort, "%d ", numbers[i]);
	}
	fclose(fwSort);
}

/**
* @input: pointer on file
* @description: function printf all even numbers into output file
*/
void evenNumbers(FILE *fread){
	int num;
	FILE *fwEven;
	fwEven=fopen("evenNumbers.txt", "w");
	rewind(fread);
	while(fscanf(fread, "%d", &num) != EOF){
		if(num%2 == 0){
			fprintf(fwEven, "%d ", num);
		}
	}
	fclose(fwEven);
}

/**
* @input: pointer on file
* @description: function printf all prime numbers into output file
*/
void primeNumbers(FILE *fread){
	int num, x, count;
	FILE *fwPrime;
	fwPrime=fopen("primeNumbers.txt", "w");
	rewind(fread);
	while(fscanf(fread, "%d", &num)!=EOF){
		x=2;
		while(x < num){
			if(num%x == 0){
				count++;
				break;
			}
			x++;
		}
		if(count==0 && num > 0)
			fprintf(fwPrime, "%d ", num);
		count=0;
	}
	fclose(fwPrime);
}

/**
* @input: pointer on file
* @description: function printf one or more numbers which occurs most often in the input file, into output file
*/
void mostPopulousNumber(FILE *fread){
	int size=getSize(fread);
	int numbers[size];
	int numbers2[1500];
	int countOfNums[1500];
	
	int num, i=0, j=0, count=1, max;
	FILE *fwOften;
	fwOften=fopen("mostPopulousNumber.txt", "w");
	rewind(fread);
	while(fscanf(fread, "%d", &num)!=EOF){
		numbers[i]=num;
		i++;
	}
	
	for(i=0; i<size-1; i++){
		for(j=i+1; j<size; j++){
			if(numbers[i] > numbers[j]){
				numbers[i]=numbers[i]+numbers[j];
				numbers[j]=numbers[i]-numbers[j];
				numbers[i]=numbers[i]-numbers[j];
			}
		}
	}
	j=0;
	i=0;
	for(i=0; i<size; i++){
		if(numbers[i]==numbers[i+1]){
			count++;
		}
		else {
			countOfNums[j]=count;
			numbers2[j]=numbers[i];
			count=1;
			j++;
		}
	}
	countOfNums[j]='\0';
	max=countOfNums[0];
	i=1;
	int maxx;
	while(countOfNums[i]!='\0'){
		if(countOfNums[i] > max){
			max=countOfNums[i];
			maxx=i;
		}
		i++;
	}
	i=0;
	j=0;
	count=0;
	int allmodus[1500];
	while(countOfNums[i]!='\0'){
		if(countOfNums[i] == max){
			count++;
			allmodus[j]=i;
			j++;
		}
		i++;
	}
	i=0;
	while(allmodus[i] != '\0'){
		fprintf(fwOften, "%d ", numbers2[allmodus[i]]);
		i++;
	}
	fclose(fwOften);
}

/**
* @input: pointer on file
* @description: function printf statistics into output file
*/
void statistics(FILE *fread){
	int negCount=0;
	int digs4Count=0;
	int digs5Count=0;
	int sum20Count=0;	
	int minNum=999999;
	int digitsCount=0;
	int digitsSum=0;
	int num;
	
	FILE *fwStat;
	fwStat=fopen("statistics.txt", "w");
	rewind(fread);
	while(fscanf(fread, "%d", &num) != EOF){
		if(minNum > num){
			minNum=num;
		}
		if(num < 0){
			negCount++;
		}
		num=abs(num);
		while(num != 0){
			digitsSum+=num%10;
			num/=10;
			digitsCount++;
		}
		if(digitsCount == 4){
			digs4Count++;
		}
		if(digitsCount == 5){
			digs5Count++;
		}
		if(digitsSum == 20){
			sum20Count++;
		}
		digitsSum=0;
		digitsCount=0;
	}
	fprintf(fwStat, "%d ", negCount);
	fprintf(fwStat, "%d ", digs4Count);
	fprintf(fwStat, "%d ", digs5Count);
	fprintf(fwStat, "%d ", sum20Count);
	fprintf(fwStat, "%d ", minNum);
	fclose(fwStat);
}

