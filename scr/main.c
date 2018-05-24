#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "headers/interface.h"
#include "headers/string_funcs.h"
#define IDX_END 1000000
#define STD_SPC 29
#define CLRS "clear" //for Linux
const char items[4][6] = {
	"Start", 
	"Stats",
	"Exit", 
};


game* Menu (game* menu,int best_score){
	initscr();
	int choice = 0; //Выбор пользователя
	curs_set(0); //"Убиваем" курсор
        //Включаем режим удобной работы с функциональными клавишами, другими словами KEY_UP и KEY_DOWN без этого не работали бы
	keypad(stdscr, true); 
	int x;
	bool sch = false;
	
	menu->start_game = 0;
	menu->exit = 0;
	menu->topic = 0;
	menu->difficult = 0;
	while ( !sch ) {
        	clear();
		printw("\tMENU\n");
        	for ( x = 0; x < 3; x++ ) {//Проходим по всем элементам меню
			                	
			if ( x == choice ) {//Если текущий элемент совпадает с выбором пользователя
                		addch('>'); //Выводим указатель
				printw("%s", items[x]);
				addch('<');
				printw ("\n");
			}
                	else {         
                		addch(' '); //Иначе выводим " ", для равновесия
				printw("%s", items[x]);
				addch(' ');
				printw("\n");
           		}
        	}
        	//Получаем нажатие пользователя
			
		switch ( getch() ) {
        		case KEY_UP:
                	if ( choice ) //Если возможно, переводим указатель вверх
                        	choice--; 
                		break;
                	case KEY_DOWN:
                		if ( choice != 2 ) //Если возможно, переводим указатель вниз
                    		choice++;
                		break;
	    		case 10: {	
				clear();
				
				if (choice == 0) {
					choice = Menu_topic (menu, &sch);
					if (choice == -1) {
						menu->exit = 1;
						endwin ();
						return 0;
					}
				}
				else if (choice == 2) {
					menu->exit = 1;
					endwin();
					return menu;
				}				
				else if (choice == 1){
					choice = Menu_stats (menu, best_score);
					if (choice == 1) {
						endwin ();
						return menu;
					}
				}
			}
		}		
	}
	endwin();
	return menu;
}

int main()
{
	FILE* in = NULL;
	int best_score = 0;
	FILE* scr = fopen("score.txt","r");
	if (scr == NULL){
		scr = fopen("score.txt","w");
		if (scr == NULL){
			return 1;
		}
		best_score = 0;
		fclose(scr);
	} else {
		fscanf (scr,"%d",&best_score);
		fclose(scr);
	}
	int tryed = 0,i = 0,j = 0,k = 0,z = 0,y = 0; // Popitki, schetchiki
	unsigned int score = 0; // Ochki
	char words[10][50] = {{0}};
	int difficult = 3, num = 0;
	char used_simbols[26] = {0};
	int game_lose = 0;
	int k_index[100] = {0}; // Massive dlya indexov naidenih bukov
	char input[100] = {0}, *ch = 0; // Vvodimaja bukva
	char man[6] = {' ',' ',' ',' ',' ',' '}; // Massive dlya chelovechka
	char eng_ch[27]; // Massive dlya Angliskih bukov
	char word[23] = "COFFE"; //ugadivaemoe slovo
	char campf[strlen(word) + 1]; // slovo dlya otkritih bukovw
	ch = input;
	game* menu;
	menu = (game*) malloc (sizeof (game));
	menu->exit = 0;
	while(menu->exit != 1){
		menu->start_game = 0;
		k = 0;
		z = 0;
		y = 0;
		tryed = 0;
		score = 0;
		difficult = 0;
		num = 0;
		game_lose = 0;
		for (i = 0; i < 10; ++i){
			for (j = 0; j < 50; ++j){
				words[i][j] = '\0';
			}
		}
		for (i = 0;i < 6; ++i){
			man[i] = ' ';
		}
		menu = Menu (menu, best_score);
		if (menu->exit == 1) {
			free (menu);
			return 0;
		} 	
		difficult = menu->difficult;
		if (Topic_output (menu->topic,&in) == -1) {
			return 1;
		}
		if (Difficult_output (menu->difficult,&tryed) == -1) {
			return 1;
		}
		for (i = 0; i < 10; ++i){
			printf ("%d\n",i);
			fscanf (in,"%s",words[i]);		
		}
		while(1){
			for (i = 0;i < 26; ++i){
				eng_ch[i] = 'A' + i;
			}
			eng_ch[26] = '\0';
		    if (z == 10 || game_lose == 1){
		    	system(CLRS);
			printf ("\n\n\n\n\n");
			space_print(STD_SPC - 4);
			printf ("GAME OVER\n");
			space_print(STD_SPC - 6);
			printf ("Score: %-6d\n\n\n\n",score);
			if (best_score < score){
				scr = fopen ("score.txt","w");
				if (scr == NULL){
					printf ("\nERR: SCORE");
					return 1;
				}
				fprintf (scr,"%d",score);
				best_score = score;	
			}
			sleep(3);
			break;
		   }
		   strcpy(word,words[z]);
		   /* Delaem slovo nerazgadannim*/
	           for (i = 0; i <strlen(word); ++i){
		   campf[i] = '^';
		   }
		   campf[i] = '\0';
		   campf[0] = word[0];
		   //----//
		   for (i = 0; i < 26; ++i){
		   	used_simbols[i] = 0;
		   }
		   ++z;
		   while(1){
		   	if (tryed == 0){
		 		game_lose = 1;
				break;
			}
			if (strcmp(word,campf) == 0){
				system(CLRS);
				pole_print(man,eng_ch,campf,score,tryed);
				sleep(2);
				break;
			}
			pole_print(man,eng_ch,campf,score,tryed); //Resuem pole
			/*Schitivaem simvol, ishem ego v slove i zapisivaem v campf
			pribavlaem ochki esli bukva nashlas'*/
			scanf("%98s",input);
			system(CLRS);
			strschk(word,k_index,*ch,&num);
			if (used_simbol_check(used_simbols,*ch)){
				if ((*ch >= 'a' && *ch <= 'z') || (*ch >= 'A' && *ch <= 'Z') ){
					score += num*10;
					used_simbols[y] = *ch;
					++y;
				}
			}
			if (num == 0){
				--tryed;
				for (i = 0;i < difficult; ++i){
					switch(i+k){
						case 0:
							man[0] = 'O';
							break;
						case 1:
							man[1] = '|';
							break;
						case 2:
							man[2] = '/';
							break;
						case 3:
							man[3] = '\\';
							break;
						case 4:
							man[4] = '/';
							break;
						case 5:
							man[5] = '\\';
							break;
					}
				}
				k += difficult;
			}
			if (*ch >= 'a' && *ch <= 'z'){
				*ch -= 'a' - 'A';
			}
			for (i = 0,j = 1; i < strlen(word) && k_index[j] != IDX_END; ++i){
				if (i == k_index[j]){
					campf[i] = *ch;
					++j;
				}
			}
			//-----//
			/*Udalaem bukvu iz angliskih bukov*/
			for (i = 0; i < 26; ++i){
				if (eng_ch[i] == *ch){
					eng_ch[i] = ' ';
				}
			}
			//-----//
			//system("clear");
			system(CLRS);
		}
	}
	fclose(in);
	}
	return 0;
}
