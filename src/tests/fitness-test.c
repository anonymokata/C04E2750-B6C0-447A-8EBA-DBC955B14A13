#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../main/calculator.h"

static const char *getfield(char* line, int num);
static void assertAdd(char *firstNumeral, char *secondNumeral, char *expected);
static FILE *openFileStream();

START_TEST(testAddFitness)
{
  char line[100] = {'\0'};
  char lineCopy[100] = {'\0'};
  char firstNumeral[100] = {'\0'};
  char secondNumeral[100] = {'\0'};
  char expectedNumeral[100] = {'\0'};

  FILE *stream = openFileStream();

  while (fgets(line, 1024, stream))
  {
      firstNumeral[0] = '\0';
      secondNumeral[0] = '\0';
      expectedNumeral[0] = '\0';
      lineCopy[0] = '\0';
      
      strcat(lineCopy,line);
      strcat(firstNumeral, getfield(lineCopy, 1));

      strcat(lineCopy,line);
      strcat(secondNumeral, getfield(lineCopy, 2));

      strcat(lineCopy,line);
      strcat(expectedNumeral, getfield(lineCopy, 3));

      assertAdd(firstNumeral, secondNumeral, expectedNumeral);
  }
   fclose(stream);
}
END_TEST

static void assertAdd(char *firstNumeral, char *secondNumeral, char *expectedNumeral){
  char result[100] = {'\0'};

  add(firstNumeral, secondNumeral, result);
  strcat(result, "\n");

  ck_assert_str_eq(result, expectedNumeral);
}

static FILE *openFileStream(){
  return fopen("src/tests/fitness-test-data", "r");
}

static const char *getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
            tok != NULL;
            tok = strtok(NULL, ","))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

Suite * makeFitnessSuite(void)
{
    Suite *s;
    TCase *tcCore;

    s = suite_create("Fitness Suite");
    tcCore = tcase_create("Core");

    tcase_add_test(tcCore, testAddFitness);
    suite_add_tcase(s, tcCore);

    return s;
}