#include "textfunc.h"

void textColor(int color){
    printf("\033[%dm", color);
    return;
}

void resetText(void){
    printf("\033[0m");
    return;
}