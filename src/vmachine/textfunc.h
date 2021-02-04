#ifndef TEXTFUNC_H
#define TESTFUNC_H

#include <stdio.h>
#include <string.h>

enum colorCodes{
    tBlack = 30,
    tRed = 31,
    tGreen = 32,
    tYellow = 33,
    tBlue = 34,
    tMagenta = 35,
    tCyan = 36,
    tWhite = 37,
    tReset = 0
};

void textColor(int colorID);
void resetText(void);


#endif