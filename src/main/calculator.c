#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roman-numerals-sorter.h"
#include "roman-numerals-converter.h"
#include "roman-numerals-reducer.h"
#include "common-utils.h"

static int hasInvalidBuffer(const char buffer[], const int size);

void add(const char *romanNumeral1, const char *romanNumeral2, char result[], const int size)
{
    if(hasInvalidBuffer(result,size)){
      return;
    }

    char additiveNumerals1[100] = {};
    char additiveNumerals2[100] = {};
    char combinedNumerals[100] = {};
    char sortedNumerals[100] = {};
    char internalSumsNumerals[100] = {};

    convertSubtractiveToAdditivePrefix(romanNumeral1, additiveNumerals1);
    convertSubtractiveToAdditivePrefix(romanNumeral2, additiveNumerals2);
    concatenate(additiveNumerals1, additiveNumerals2, combinedNumerals);
    sortRomanNumerals(combinedNumerals, sortedNumerals);
    convertInternalSums(sortedNumerals, internalSumsNumerals);
    convertAdditiveToSubtractivePrefix(internalSumsNumerals,result);
}

void subtract(const char *romanNumeral1, const char *romanNumeral2, char result[], const int size){
  if(hasInvalidBuffer(result,size)){
    return;
  }

  char additiveNumerals1[100] = {};
  char additiveNumerals2[100] = {};
  char reducedNumerals[100] = {};

  convertSubtractiveToAdditivePrefix(romanNumeral1, additiveNumerals1);
  convertSubtractiveToAdditivePrefix(romanNumeral2, additiveNumerals2);
  reduceMatchingNumerals(additiveNumerals1, additiveNumerals2, reducedNumerals);
  convertAdditiveToSubtractivePrefix(reducedNumerals,result);
}

int hasInvalidBuffer(const char buffer[], const int size){
  return size < 100 || !buffer;
}
