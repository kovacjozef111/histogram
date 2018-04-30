
#include "array.h"


void parseInput(unsigned long array[], const int length, FILE* inputfile){

    for(int i = 0; i < length; i++){
        array[i] = 0;
    }

    char read;

    if(inputfile == stdin){
        printf("Zadaj Sekvenciu znakov: \n");
    }

    do{
        read = fgetc(inputfile);
        if(isalpha(read)){
            array[(int)read] += 1;
        }
    }while(read != EOF && read != '#');
}



void printArray(unsigned long array[], const int length){
    for(int i = 0; i < length; i++){
        if(isalpha(i)){
            printf("Znak '%c' ... Pocet vyskytov = %lu\n", (char)i, array[i]);
        }
    }
}


float averageCount(unsigned long array[], const int length){
    float sum = 0;
    unsigned long countalpha = 0;

    for(int i = 0; i < length; i++){
        if(isalpha(i)){
            sum += array[i];
            countalpha++;
        }
    }
    return sum / countalpha;
}


void mostFrequent(unsigned long array[], const int length){
    unsigned long maxnum = 0;

    for(int i = 0; i < length; i++){
        if(isalpha(i)){
            if(array[i] > maxnum){
                maxnum = array[i];
            }
        }
    }
    printf("Najvyssi pocet vyskytov nejakeho znaku: %lu\n", maxnum);
    printf("Tento pocet vyskytov maju znaky:\n");

    for(int j = 0; j < length; j++){
        if(isalpha(j)){
            if(array[j] == maxnum){
                printf("%c ", (char)j);
            }
        }
    }
}


void leastFrequent(unsigned long array[], const int length){
    unsigned long minnum = ULONG_MAX;

    for(int i = 0; i < length; i++){
        if(isalpha(i)){
            if(array[i] < minnum){
                minnum = array[i];
            }
        }
    }
    printf("Najnizsi pocet vyskytov nejakeho znaku: %lu\n", minnum);
    printf("Tento pocet vyskytov maju znaky:\n");

    for(int j = 0; j < length; j++){
        if(isalpha(j)){
            if(array[j] == minnum){
                printf("%c ", (char)j);
            }
        }
    }
}

unsigned long charTotal(unsigned long array[], const int length){
    unsigned long sum = 0;
    for(int i = 0; i < length; i++){
        if(isalpha(i)){
            sum += array[i];
        }
    }
    return sum;
}
