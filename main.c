/*! \mainpage Programová dokumentace
 *
 * \section intro Úvod
 *
 * Vítejte na hlavní stránce programové dokumentace jednoduchého programu na analýzu četnosti znaků v textu.
 *
 * \section motiv K čemu mi to může být?
 *
 *	Tento program zvládne zanalyzovat velké množství textu jak ze souboru tak i z přímého vstupu. 
 *	Četnost znaků může být potřeba například při psaní bakalářských a diplomových prací, v
 *	některém případě i u prací seminárních. 
 * 
 */

/**
 * \file main.c
 * \brief soubor main obsluhující výpis na konzoli a cyklus obsluhující chod programu
 * \author Jozef Kováč, Romana Stopková, Daniel Vaškovič, Luboš Perna
 * \date Duben 2018
 * \details Konzolová aplikace s následujícími vlastnostmi
 *   - Uživatel může zadat text ze vstupu nebo ze souboru
 *   - Uživatel má k dispozici tyto funkce
 *   	+ Informace o nejčastějším znaku
 *   	+ Informace o nejméně používaném znaku
 *		+ Výpis celkového počtu znaků
 *		+ Výpis průměrné četnosti znaků
 *		+ Výpis četnosti každého abecedního znaku
 *   - Zadávání nových dat z konzole (Klávesa Space)
 *   - Ukončení programu (Klávesa Enter)
 * 
 * Zdrojové kódy jsou zapsány ve znakové sadě UTF-8
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>

#include "array.h"

typedef enum{MOSTFREQUENT, LEASTFREQUENT, SUM, AVERAGE, PRINTALL, NEWINPUT, ENDPROGRAM}Function_t;


/*!
 * \brief Funkcia slúži k overeniu, či bol zadaný správny formát vstupného súboru
 * \param string[], názov cesty k súboru zadanej ako parameter príkazovej riadky
 * \return Vracia true alebo false podľa toho, či je zadaný vstup textovým súborom, alebo nie
 */
bool textfile(char string[]){

    char suffix[3] = {0};
    char cmp[3] = "txt";

    int j = 0;
    if(strlen(string) < 5){
        return false;
    }
    for(unsigned int i = strlen(string)-3; i < strlen(string); i++){
        suffix[j] = string[i];
        j++;
    }

    for(unsigned int k =0; k < 3; k++){
        if(suffix[k] != cmp[k]){
            return false;
        }
    }
    return true;
}

/*!
 * \brief Vypíše menu popisujúce funkcionalitu programu
 */
void printMenu(){
    printf("**************************************************\n");
    printf("Pokracuj stisknutim klavesy:\n");
    printf("Stlac 1) pre informacie o najcastejsom abecednom znaku\n");
    printf("Stlac 2) pre informacie o najmenej castych abecednych znakoch\n");
    printf("Stlac 3) pre vypis, kolko je celkovo abecednych znakov\n");
    printf("Stlac 4) pre informaciu o priemernej pocetnosti abecednych znakov\n");
    printf("Stlac 5) pre vypis pocetnosti kazdeho abecedneho znaku\n");
    printf("Stlac SPACEBAR) pre zadanie novych dat z konzole\n");
    printf("Stlac ENTER) pre ukoncenie programu\n");
    printf("**************************************************\n");
}

/*!
 * \brief Vypíše menu a realizuje voľbu funkcie pomocou uživateľského vstupu z terminálu
 * \return Vracia zvolenú funkciu (realizované uživateľom definovaným výčtovým typom Function_t, viď. vyššie)
 */
Function_t functionChoice(){
    printMenu();
    char znak;

    while(1){
        printf("Vasa volba: ");
        znak = getche();
        printf("\n");
        if (znak == '1'){
            return MOSTFREQUENT;
        }
        else if(znak == '2'){
            return LEASTFREQUENT;
        }
        else if(znak == '3'){
            return SUM;
        }
        else if(znak == '4'){
            return AVERAGE;
        }
        else if(znak == '5'){
            return PRINTALL;
        }
        else if(znak == 32){
            return NEWINPUT;
        }
        else if(znak == 13){
            return ENDPROGRAM;
        }
        else{
            printf("Nevalidny vstup, zadaj 1, 2, 3, 4, 5, Mezernik alebo Enter \n");
        }
    }
}


int main(int argc, char** argv)
{
    // zadeklarovanie, prípadne inicializácia potrebných premenných
    Function_t function;
    unsigned long array[256];
    const int length = 256;
    unsigned long sum;
    float average;


    // zvolenie input streamu - buď súbor poskytnutý ako parameter alebo štandardný vstup
    FILE *input = stdin;
    if(argc == 2){
        input = fopen(argv[1], "r");
        if(!textfile(argv[1])){
            printf("Nespravny format suboru, program bude ukonceny\n");
            return -1;
        }
    }
    if(input == NULL){
        printf( "Chyba pri otvarani suboru, program bude ukonceny\n" );
        return -1;
        }


    // rozparsovanie vstupu do pripraveného poľa
    parseInput(array, length, input);
    // výpočet celkového počtu znakov (potrebné pre ďalšie funkcie)
    sum = charTotal(array, length);

    // nekonečný cyklus - zadávanie vstupu uživateľom
    while(1){
        function = functionChoice();
        // na ich základe určíme, ktorá funkcia sa má vykonať
        switch(function){
            case MOSTFREQUENT:
            mostFrequent(array, length);
            printf("\n");
            break;

            case LEASTFREQUENT:
            leastFrequent(array, length);
            printf("\n");
            break;

            case SUM:
            printf("Celkovy pocet znakov je: %lu\n", sum);
            break;

            case AVERAGE:
            average = averageCount(array, length);
            printf("Priemerny pocet vyskytov znaku je %.3f\n", average);
            break;

            case NEWINPUT:
            if(input != stdin){
                input = stdin;
            }
            parseInput(array, length, input);
            sum = charTotal(array, length);
            break;

            case PRINTALL:
            printArray(array, length);
            break;

            case ENDPROGRAM:
            break;

        }
        // ak užívateľ zvolil koniec, ukončíme program
        if(function == ENDPROGRAM){
            break;
        }
    }
    // zatvorenie vstupného streamu
    fclose(input);
    return 0;
}

