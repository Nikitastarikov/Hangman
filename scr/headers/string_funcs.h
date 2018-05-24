#include <ncurses.h>
#ifndef STRING_FUNCS_H
#define STRING_FUNCS_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define IDX_END 1000000
#define STD_SPC 29
//#define CLRS "CLS" //for Windows
#define CLRS "clear" //for Linux


int strschk(char word[], int k_index[],char ch,int* num);
void space_print(int n);
int space_suff(char string[]);
int used_simbol_check(char used_simbols[], char ch);
int Topic_output (int topic, FILE ** in);
int Difficult_output (int difficult, int *tryed);
#endif
