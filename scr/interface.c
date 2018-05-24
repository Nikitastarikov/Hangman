#include "headers/interface.h"
#include "headers/string_funcs.h"

const char items2[5][7] = {
	"Easy",
	"Midle",
	"Hard",
	"Back",
};

const char items1[6][15] = {
	"Animals",
	"Sports",
	"Professions",
	"Fruits",
	"Back",
};

const char items3[3][5] = {
	"Back",
	"Exit",
};

int Menu_stats (game* menu,int best_score) {
	bool sch3 = false;
	int choice = 0, x;
	while (!sch3) {
		clear();
		printw ("\n\t\t\tSTATS\n\n\n"
		"Best score: %d\n\n",best_score);
		//menu_ch[0] = stats(best_score);
		//printw ("\tSELECT THE DIFFICULT\n");
		for (x = 0; x < 2; x++) {
			if ( x == choice ) {		
				addch('>'); //Выводим указатель
				printw("%s", items3[x]);
				addch('<');
				printw ("\n");
			}
			else {         
				addch(' '); 
				printw("%s", items3[x]);
				addch(' ');
				printw("\n");
			}
		}
		switch ( getch() ) {
			case KEY_UP:
				if ( choice )
					choice--; 
				break;
			case KEY_DOWN:
				if ( choice != 1 )
       					choice++;
				break;
			case 10	:{
				if (choice == 0) {
					sch3 = true;			
				}
				else if (choice == 1) {
					menu->exit = 1;
					return 1;
				}
			}
		}
	}
	return 0;
}
int Menu_topic (game* menu, bool* sch) {
	int x, choice = 0;	
	bool sch1 = false;
	while (!sch1) {
		clear();
		//printw ("%d\n",best_score);
		printw ("\tSELECT THE TOPIC\n");
		for (x = 0; x < 5; x++) {
			if ( x == choice ) {//Если текущий элемент совпадает с выбором пользователя
					addch('>'); //Выводим указатель
					printw("%s", items1[x]);
					addch('<');
					printw ("\n");
			}
			else {         
					addch(' '); //Иначе выводим " ", для равновесия
					printw("%s", items1[x]);
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
				if ( choice != 4 ) //Если возможно, переводим указатель вниз
					choice++;
					break;
			case 10: {
				clear();
				if (choice != 4) {
					if (choice == 0) {
						menu->topic = 1;
					}
					else if (choice == 1) {
						menu->topic = 2;
					}	
					else if (choice == 2) {
						menu->topic = 3;
					}
					else if (choice == 3) {
						menu->topic = 4;
					}							
					choice = Menu_difficult (menu, &sch1);
					if (choice == -1) {
						menu->exit = 1;
						return 0;	
					}
					*sch = true;
				}
				else if (choice == 4) {
					sch1 = true;
				}
			}		
		}
	}
	return 0;
}

int Menu_difficult (game* menu, bool* sch1) {
	int choice = 0; //Выбор пользователя	
	int x;	
	bool sch2 = false;
	while (!sch2) {
		clear();
		//printw ("topic = %d\n",menu->topic);
		printw ("\tSELECT THE DIFFICULT\n");
		for (x = 0; x < 4; x++) {
			if ( x == choice ) {			
				addch('>'); //Выводим указатель
				printw("%s", items2[x]);
				addch('<');
				printw ("\n");
			}
			else {         
				addch(' '); 
				printw("%s", items2[x]);
				addch(' ');
				printw("\n");
			}
		}
		switch ( getch() ) {
			case KEY_UP:
				if ( choice )
					choice--; 
				break;
			case KEY_DOWN:
				if ( choice != 3 )
					choice++;
				break;
			case 10	:{
				if (choice == 3) {
					sch2 = true;
					return 0;
				}
				else if (choice != 3) {
					if (choice == 0) {
						menu->difficult = 1;		
					}
					else if (choice == 1) {
						menu->difficult = 2;		
					}
					else if (choice == 2) {
						menu->difficult = 3;		
					}	
					menu->start_game = 1;
					*sch1 = true;
					sch2 = true;	
				}
			}
		}
	}
	return 0;
}


void pole_print(char man[],char eng_ch[],char word[],unsigned int score,int tryed){
	int i = 0;
//	system("clear");
	system(CLRS);
	printf("\nscore: %-6d",score); // 13 chars
	space_print(STD_SPC);
	printf("trying: %-2d\n\n\n",tryed); // 10 chars
	space_print(STD_SPC-3);
	printf("_____\n"); // 5 chars
	space_print(STD_SPC-3);
	printf("|   |\n");
	space_print(STD_SPC-3);
	printf("|   %c\n",man[0]);
	space_print(STD_SPC-3);
	printf("|  %c%c%c\n",man[2],man[1],man[3]);
//	space_print(20);
//	printf("|   |\n");
	space_print(STD_SPC-3);
	printf("|  %c %c\n",man[4],man[5]);
	space_print(STD_SPC - 4);
	printf("_|_  \n\n");
	space_print(STD_SPC - 12 + space_suff(word));
	printf ("%-23s\n",word);
	printf ("-----------------------------------------------------\n");
	for (i = 0; i < 26; ++i){
		printf ("|%c",eng_ch[i]);
	}
	printf("|\n\n\n");
	printf("Enter the char(ENG): ");
}

