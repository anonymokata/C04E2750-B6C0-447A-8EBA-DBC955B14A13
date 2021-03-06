#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common-utils.h"

static const int SUBTRACTIVE_PREFIX_ARRAY_SIZE = 6;
static const int ADDITIVE_PREFIX_ARRAY_SIZE = 6;
static const int INTERNAL_SUM_ARRAY_SIZE = 6;
static char *subtractivePrefixes[] = {"IV","IX","XL","XC","CD","CM"};
static char *additivePrefixes[] = {"IIII","VIIII","XXXX","LXXXX","CCCC","DCCCC"};
static char *internalSumPrefix[] = {"IIIII","VV","XXXXX","LL","CCCCC","DD"};
static char *internalSumValue[] = {"V","X","L","C","D","M"};

char *convertSubtractiveToAdditivePrefix(const char *romanNumerals, char result[]){
  char partialResult[100] = {};
  char romanNumeralsCopy[100] = {};
  strcpy(romanNumeralsCopy, romanNumerals);

  for (int i = 0; i < SUBTRACTIVE_PREFIX_ARRAY_SIZE; i++) {
      partialResult[0] = '\0';
      replaceSubstring(romanNumeralsCopy, subtractivePrefixes[i], additivePrefixes[i], partialResult);
      strcpy(romanNumeralsCopy, partialResult);
  }

  strcat(result, partialResult);
  return result;
}

char *convertAdditiveToSubtractivePrefix(const char *romanNumerals, char result[]){
  char partialResult[100] = {};
  char romanNumeralsCopy[100] = {};
  strcpy(romanNumeralsCopy, romanNumerals);

  for (int i = ADDITIVE_PREFIX_ARRAY_SIZE - 1; i >= 0; i--) {
      partialResult[0] = '\0';
      replaceSubstring(romanNumeralsCopy, additivePrefixes[i], subtractivePrefixes[i],partialResult);
      strcpy(romanNumeralsCopy, partialResult);
  }

  strcat(result, partialResult);
  return result;
}

char *convertInternalSums(const char *romanNumerals, char result[]){
  char partialResult[100] = {};
  char romanNumeralsCopy[100] = {};
  strcpy(romanNumeralsCopy, romanNumerals);

  for (int i = 0; i < INTERNAL_SUM_ARRAY_SIZE; i++) {
      partialResult[0] = '\0';
      replaceSubstring(romanNumeralsCopy, internalSumPrefix[i], internalSumValue[i],partialResult);
      strcpy(romanNumeralsCopy, partialResult);
  }

  strcat(result, partialResult);
  return result;
}
