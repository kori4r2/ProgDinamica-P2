// Ítalo Tobler Silva - nUSP 8551910
#ifndef _MY_STRINGS_H_
#define _MY_STRINGS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *myStrdup(char*);
char *getWord(FILE*);
char *readLimitedString(FILE*, int);
char *myGetLine(FILE*);

#endif
