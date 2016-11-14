/**
    @author: Jozef Bálint
    @date: 13.11.2016
    @description: Program operates with file "numbers.txt", manages different tasks and creates output to .txt files
    and finds statistical data, storing them in .txt file.
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int sizeOfNumbers();
void sorted();
void evenNum();
void primeNum();
void mostPopulous();
void statistics();

/**
    @author: Jozef Bálint
    @date: 13.11.2016
    @description: Start function
*/
int main(){

    if(sizeOfNumbers() == -1){
        printf("READ File issue!");
    }

    sorted();
    evenNum();
    primeNum();
    mostPopulous();
    statistics();

    return 0;
}

/**
    @author: Jozef Bálint
    @date: 13.11.2016
    @description: Function to find how many numbers are in numbers.txt
    @input: numbers.txt
    @output: integer
*/
int sizeOfNumbers(){
    FILE *fr;
    int num;
    int count = 0;

    fr = fopen("numbers.txt","r");

    if(fr == NULL){
        return -1;
    }else{
        while((fscanf(fr,"%d",&num)) != EOF){
            count++;
        }
        return count;
    }

    fclose(fr);
}

/**
    @author: Jozef Bálint
    @date: 13.11.2016
    @description: Function to sort numbers with bubblesort
    @input: numbers.txt
    @output: sortedNumbers.txt
*/
void sorted(){
    FILE *fr, *fw;
    int arrSize = sizeOfNumbers();
    int array[arrSize];

    int i = 0;
    int j,temp;

    fr = fopen("numbers.txt","r");
    fw = fopen("sortedNumbers.txt","w");

    if(fr == NULL){
        printf("Error! Read file issue.");
    }else if(fw == NULL){
        printf("Error! Write file issue.");
    }else{
        while((fscanf(fr,"%d",&temp)) != EOF){
            array[i] = temp;
            i++;
        }
    }

    //bubble sort
    for (i = 0 ; i < ( arrSize - 1 ); i++){
        for (j = 0 ; j < arrSize - i - 1; j++){
            if (array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    for(i = 0; i < arrSize; i++){
        fprintf(fw,"%d\n",array[i]);
    }

    fclose(fr);
    fclose(fw);
}

/**
    @author: Jozef Bálint
    @date: 13.11.2016
    @description: Function to find all even numbers
    @input: numbers.txt
    @output: evenNumbers.txt
*/
void evenNum(){
    FILE *fr, *fw;
    int num;

    fr = fopen("numbers.txt","r");
    fw = fopen("evenNumbers.txt","w");

    if(fr == NULL){
        printf("Error! Read file issue.");

    }else if(fw == NULL){
        printf("Error! Write file issue.");
    }

    while((fscanf(fr,"%d",&num)) != EOF){
        if((num % 2) == 0){
            fprintf(fw,"%d\n",num);
        }
    }
    fclose(fr);
    fclose(fw);
}

/**
    @author: Jozef Bálint
    @date: 13.11.2016
    @description: Function to find all prime numbers
    @input: numbers.txt
    @output: primeNumbers.txt
*/
void primeNum(){
    FILE *fr, *fw;
    int num;
    int divisor;
    bool isPrime;

    fr = fopen("numbers.txt","r");
    fw = fopen("primeNumbers.txt","w");

    if(fr == NULL){
        printf("Error! Read file issue.");
    }else if(fw == NULL){
        printf("Error! Write file issue.");
    }

    while((fscanf(fr,"%d",&num)) != EOF){
        isPrime = false;
        divisor = 2;

        do{
            if(((num % divisor) == 0) || (num <= 2)){
                isPrime = true;
                break;
            }else{
                isPrime = false;
            }
            divisor++;
        }while(divisor <= (num/2));

        if(isPrime == false){
            fprintf(fw,"%d\n",num);
        }
    }

    fclose(fr);
    fclose(fw);
}
/**
    @author: Jozef Bálint
    @date: 13.11.2016
    @description: Function runs through all numbers, find the most recurring one
    @input: numbers.txt
    @output: mostPopulousNumber.txt
*/
void mostPopulous(){
    FILE *fr, *fw;
    int num;
    int arrSize = sizeOfNumbers();
    int array[arrSize];
    int i = 0;
    int j;
    int count;
    int arrayCount[arrSize][2];

    fr = fopen("numbers.txt","r");
    fw = fopen("mostPopulousNumber.txt","w");

    if(fr == NULL){
        printf("Error! Read file issue.");
    }else if(fw == NULL){
        printf("Error! Write file issue.");
    }else{
        while((fscanf(fr,"%d",&num)) != EOF){
            array[i] = num;
            i++;
        }
    }

    //filling arrayCount with numbers and their occurrence
    for(i = 0; i< arrSize; i++){
            count = 0;
        for(j = 0; j<arrSize; j++){
            if(array[i] == array[j]){
                count++;
            }
        }
        arrayCount[i][0] = array[i];
        arrayCount[i][1] = count;
    }

    //finding the most reoccurring number
    count = arrayCount[0][1];
    for(i = 0; i< arrSize; i++){
        if(arrayCount[i][1] > count){
            num = arrayCount[i][0];
            count = arrayCount[i][1];
        }
    }
    fprintf(fw,"Number %d is the most frequent number with %d occurrences.",num,count);

    fclose(fr);
    fclose(fw);
}
/**
    @author: Jozef Bálint
    @date: 13.11.2016
    @description: Function counts negative, 4-digit, 5-digit and digit sum of 20 numbers and minimal value number
    @input: numbers.txt
    @output: statistics.txt
*/
void statistics(){
    FILE *fr, *fw;
    int num;
    int countNegative = 0;
    int count4 = 0;
    int count5 = 0;
    int count20 = 0;
    int min;
    int temp;

    fr = fopen("numbers.txt","r");
    fw = fopen("statistics.txt","w");

    if(fr == NULL){
        printf("Error! Read file issue.");
    }else if(fw == NULL){
        printf("Error! Write file issue.");
    }

    min = fscanf(fr,"%d",&num);

    while((fscanf(fr,"%d",&num)) != EOF){
        temp = 0;
        if(min > num){
            min = num;
        }
        if(num < 0){
            countNegative++;
        }
        if((num > 999 && num < 10000) || (num < -999 && num > -10000)){
            count4++;
        }
        if((num > 9999 && num < 100000) || (num < -9999 && num > -100000)){
            count5++;
        }
        num = abs(num);
        while(num != 0){
            temp += num % 10;
            num /= 10;
        }
        if(temp == 20){
            count20++;
        }
    }

    fprintf(fw,"Number of negative numbers: %d\nNumber of 4 digit numbers: %d\nNumber of 5 digit numbers: %d\nNumber of digit summary of 20: %d\nMin value number: %d",countNegative,count4,count5,count20,min);

    fclose(fr);
    fclose(fw);
}
