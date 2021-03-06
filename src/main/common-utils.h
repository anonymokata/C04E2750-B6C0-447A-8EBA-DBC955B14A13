#ifndef COMMON_UTILS_H_
#define COMMON_UTILS_H_

void replaceSubstring(const char *inputString, const char *substring, const char *replaceWith, char result[]);
void concatenate(const char *romanNumeral1, const char *romanNumeral2, char result[]);
int isGreaterThanOrEqual(const int romanNumeral, const int compareTo);

#endif
