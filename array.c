
/**
 * \file array.c
 * \brief soubor array obsahující parsovaní textu a obsluhu pole
 * \author Jozef Kováč, Romana Stopková, Daniel Vaškovič, Luboš Perna
 * \date Duben 2018
 * \details soubor array.c s následujícími vlastnostmi
 *   - parseInput pro zpracování textu
 *   - printArray pro výpis pole
 *   - averageCount pro průměrnou četnost znaku
 *   - mostFrequent pro nejčastější znak
 *   - leastFrequent pro nejméně častý znak
 *   - charTotal pro celkový počet znaků
 * 
 * Zdrojové kódy jsou zapsány ve znakové sadě UTF-8
*/

#include "array.h"

/*!
 * \brief Načíta vstup zo zvoleného input streamu a rozparsuje ho do pripraveného poľa
 * \param array[] Pole kam má byť vstup po spracovaní uložený
 * \param length dĺžka poľa, konštantná hodnota (256)
 * \param inputfile input stream (závisí na parametroch príkazovej riadky, s ktorými bol program spustený)
 */
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

/*!
 * \brief Vypíše obsah poľa : jednotlivé znaky a ich príslušné počty
 * \param array[] Pole, z ktorého je výpis realizovaný
 * \param length dĺžka poľa, konštantná hodnota (256)
 */
void printArray(unsigned long array[], const int length){
    for(int i = 0; i < length; i++){
        if(isalpha(i)){
            printf("Znak '%c' ... Pocet vyskytov = %lu\n", (char)i, array[i]);
        }
    }
}

/*!
 * \brief Vypočíta priemerný počet znakov z textu
 * \param array[] Pole, z ktorého je priemer počítaný
 * \param length dĺžka poľa, konštantná hodnota (256)
 * \return float average - priemerný počet výskytov abecedného znaku
 */
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

/*!
 * \brief Vyhľadá znak s najvačším počtom výskytov
 * \param array[] Pole, nad ktorým hľadanie realizujeme
 * \param length dĺžka poľa, konštantná hodnota (256)
 */
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

/*!
 * \brief Vyhľadá znak s najmenším počtom výskytov
 * \param array[] Pole, nad ktorým hľadanie realizujeme
 * \param length dĺžka poľa, konštantná hodnota (256)
 */
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

/*!
 * \brief Spočíta celkový počet abecedných znakov vo vstupnom súbore
 * \param array[] Pole obsahujúce spracovaný vstup, nad ktorým výpočet vykonávame
 * \param length dĺžka poľa, konštantná hodnota (256)
 * \return sum - celkový počet abecedných znakov vyskytujúcich sa v textovom súbore
 */
unsigned long charTotal(unsigned long array[], const int length){
    unsigned long sum = 0;
    for(int i = 0; i < length; i++){
        if(isalpha(i)){
            sum += array[i];
        }
    }
    return sum;
}
