#include <ncurses.h>
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


typedef struct {
	int difficult;
	int start_game;
	int topic;
	int exit;
}game;  

int Menu_stats (game* menu, int best_score);
int Menu_topic (game* menu, bool* sch);
int Menu_difficult (game* menu, bool* sch1);
void pole_print(char man[],char eng_ch[],char word[],unsigned int score,int tryed);
#endif
