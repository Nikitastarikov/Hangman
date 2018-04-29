#ifndef INTERFACE_H
#define INTERFACE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define IDX_END 1000000
#define STD_SPC 29
//#define CLRS "CLS" //for Windows
#define CLRS "clear" //for Linux

void pole_print(char man[],char eng_ch[],char word[],unsigned int score,int tryed);
char menu();
char topic_select();
char stats();
char difficult_select();
#endif
