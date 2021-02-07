#include "textfunc.h"

void textColor(int color){
    printf("\033[%d;1m", color);
    return;
}

void resetText(void){
    printf("\033[0m");
    return;
}
