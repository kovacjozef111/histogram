/**
 * \file array.h
 * \brief Hlavičkový soubor k souboru array.c
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

#include <stdio.h>
#include <ctype.h>
#include <limits.h>

#ifndef ARRAY_H
#define ARRAY_H

/*!
 * \brief Načíta vstup zo zvoleného input streamu a rozparsuje ho do pripraveného poľa
 * \param array[] Pole kam má byť vstup po spracovaní uložený
 * \param length dĺžka poľa, konštantná hodnota (256)
 * \param inputfile input stream (závisí na parametroch príkazovej riadky, s ktorými bol program spustený)
 */
void parseInput(unsigned long array[], const int length, FILE* inputfile);

/*!
 * \brief Vypíše obsah poľa : jednotlivé znaky a ich príslušné počty
 * \param array[] Pole, z ktorého je výpis realizovaný
 * \param length dĺžka poľa, konštantná hodnota (256)
 */
void printArray(unsigned long array[], const int length);

/*!
 * \brief Vypočíta priemerný počet znakov z textu
 * \param array[] Pole, z ktorého je priemer počítaný
 * \param length dĺžka poľa, konštantná hodnota (256)
 * \return float average - priemerný počet výskytov abecedného znaku
 */
float averageCount(unsigned long array[], const int length);

/*!
 * \brief Vyhľadá znak s najvačším počtom výskytov
 * \param array[] Pole, nad ktorým hľadanie realizujeme
 * \param length dĺžka poľa, konštantná hodnota (256)
 */
void mostFrequent(unsigned long array[], const int length);

/*!
 * \brief Vyhľadá znak s najmenším počtom výskytov
 * \param array[] Pole, nad ktorým hľadanie realizujeme
 * \param length dĺžka poľa, konštantná hodnota (256)
 */
void leastFrequent(unsigned long array[], const int length);

/*!
 * \brief Spočíta celkový počet abecedných znakov vo vstupnom súbore
 * \param array[] Pole obsahujúce spracovaný vstup, nad ktorým výpočet vykonávame
 * \param length dĺžka poľa, konštantná hodnota (256)
 * \return sum - celkový počet abecedných znakov vyskytujúcich sa v textovom súbore
 */
unsigned long charTotal(unsigned long array[], const int length);

#endif // ARRAY_H
