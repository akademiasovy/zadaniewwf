/**
* @author Martin Pach
* @date 13.11.2016
* @description application that is reading data from file modify them and write to another file
*/

#include <stdio.h>
#include <stdbool.h>

/**
* @input reading file pointer
* @output number of numbers in reading text file
*/
int getSize(FILE *pFr){
    int count = 0, num;
    rewind(pFr); //set pointer to beginning of file
    while((fscanf(pFr, "%d", &num)) != EOF){
        count++;
    }
    return count;
}

/**
* @input reading file pointer
* @output sorted numbers written in sortedNumbers.txt file
*/
void sortNumbers(FILE *pFr){
    int size = getSize(pFr);
    int array[size];
    FILE *fw;
    int i = 0, j, temp;

    fw = fopen("sortedNumbers.txt", "w");
    if(fw == NULL){
        fclose(fw);
        fclose(pFr);
        return 1;
    }
    rewind(pFr);

    while((fscanf(pFr, "%d", &array[i])) != EOF){
        i++;
    }
    for(i=1; i<size; i++){
        for(j=0; j<size-i; j++){
            if(array[j]>array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    for(i=0; i<size; i++){
        fprintf(fw, "%d ", array[i]);
    }
    fclose(fw);

}

/**
* @input reading file pointer
* @output even numbers written in evenNumbers.txt file
*/
void getEvenNumbers(FILE *pFr){
    FILE *fw;
    int num;

    fw = fopen("evenNumbers.txt", "w");
    if(fw == NULL){
        fclose(fw);
        fclose(pFr);
        return 1;
    }
    rewind(pFr);

    while((fscanf(pFr, "%d", &num)) != EOF){
        if((num % 2) == 0){
            fprintf(fw, "%d ", num);
        }
    }
    fclose(fw);
}

/**
* @input reading file pointer
* @output prime numbers written in primeNumbers.txt file
*/
void getPrimeNumbers(FILE *pFr){
    int num;
    bool isPrime;
    FILE *fw;
    int i;

    fw = fopen("primeNumbers.txt", "w");
    if(fw == NULL){
        fclose(fw);
        fclose(pFr);
        return 0;
    }
    rewind(pFr);
    while((fscanf(pFr, "%d", &num)) != EOF){
        if((num == 2 || num == 3) && num>=2){
            isPrime = true;
        }
        else if((num % 2) != 0 && num>=2){
            for(i=3; i<num; i+=2){
                if(num % i != 0){
                    isPrime = true;
                }
                else{
                    isPrime = false;
                    break;
                }
            }
        }
        else{
            isPrime = false;
        }
        if(isPrime == true){
            fprintf(fw, "%d ", num);
        }
    }
}

/**
* @input reading file pointer
* @output modus(es) written in mostPopulosNumber.txt file
*/
void getModus(FILE *pFr){
    int size = getSize(pFr);
    int array[size], max[size];
    int i, temp, j;
    int count = 0;
    FILE *fw;

    fw = fopen("mostPopulousNumber.txt", "w");
    if(fw == NULL){
        fclose(fw);
        fclose(pFr);
        return 1;
    }
    rewind(pFr);

    for(i=0; i<size; i++){
        fscanf(pFr, "%d", &array[i]);   //filling the array with numbers
    }
    for(i=1; i<size; i++){  //sorting numbers ascending because we want same numbers to stand next to each other
        for(j=0; j<size-i; j++){
            if(array[j]>array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    for(i=0; i<size; i++){  //set 0 to all indexes in array max
        max[i] = 0;
    }

    j = 0;
    while(j<size){
        i = j;
        j = i + 1;
        while(array[i] == array[j]){    //finding which number is the most populos
            max[i] = count++;
            j++;
        }
        count = 0;
    }

    for(i=1; i<size; i++){  //sort 'max' array descending but we are sorting 'array' array too because we want to know to which 'array' index is related to max value
        for(j=0; j<size-i; j++){
            if(max[j]<max[j+1]){
                temp = max[j];
                max[j] = max[j+1];
                max[j+1] = temp;
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    i = 0;
    j = 0;
    while(max[i] == max[j]){
        fprintf(fw, "%d ", array[j]);
        j++;
    }
}

/**
* @input reading file pointer
* @output statistics written in statistics.txt file
*/
void getStatistics(FILE *pFr){
    int num, min = 2147483647, sum = 0;
    int countNegative = 0, countDigits = 0, count4Digits = 0, count5Digits = 0, countSum20 = 0;
    FILE *fw;

    fw = fopen("statistics.txt", "w");
    if(fw == NULL){
        fclose(fw);
        fclose(pFr);
        return 1;
    }
    rewind(pFr);

    while((fscanf(pFr, "%d", &num)) != EOF){
        if(num < 0){
            countNegative++;
        }
        if(num < min){
            min = num;
        }

        num = abs(num);
        while(num != 0){
            sum += num % 10;
            num /= 10;
            countDigits++;
        }
        if(countDigits == 4){
            count4Digits++;
        }
        if(countDigits == 5){
            count5Digits++;
        }
        if(sum == 20){
            countSum20++;
        }
        countDigits = 0;
        sum = 0;
    }
    fprintf(fw, "number of negative numbers:%d\nnumber of 4-digit numbers:%d\nnumber of 5-digit numbers:%d\nnumber of numbers where digit sum is 20:%d\nmin value:%d", countNegative, count4Digits, count5Digits, countSum20, min);
}


int main(){
    FILE *fr;
    char action;

    fr = fopen("numbers.txt", "r");
    if(fr == NULL){
        printf("error");
        return 1;
    }
    printf("what do you want to do: sort(s) | get even numbers(e) | get prime numbers(p) | get modus(m) | get statistics(S):\n");
    scanf("%c", &action);
    switch(action){
        case 's' :
            sortNumbers(fr);
            break;
        case 'e' :
            getEvenNumbers(fr);
            break;
        case 'p' :
            getPrimeNumbers(fr);
            break;
        case 'm' :
            getModus(fr);
            break;
        case 'S' :
            getStatistics(fr);
            break;
        default :
            printf("bad input!");
    }
    fclose(fr);
    return 0;
}
