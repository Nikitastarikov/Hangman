#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "headers/interface.h"
#include "headers/string_funcs.h"
#define IDX_END 1000000
#define STD_SPC 29
//#define CLRS "CLS" //for Windows
#define CLRS "clear" //for Linux

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
//		fprintf(scr,"%d",0);
		best_score = 0;
		fclose(scr);
	} else {
		fscanf (scr,"%d",&best_score);
		fclose(scr);
	}
/*	scr = fopen("score.txt","w");
	if (scr == NULL){
		return 0;
	} */
	int tryed = 0,i = 0,j = 0,k = 0,z = 0,y = 0; // Popitki, schetchiki
	unsigned int score = 0; // Ochki
	char words[10][50] = {{0}};
	int difficult = 3, num = 0;
//	char readed_word[50] = {0};
	char used_simbols[26] = {0};
	int game_start = 0,game_lose = 0;
	int k_index[100] = {0}; // Massive dlya indexov naidenih bukov
	char input[3] = {0}, *ch = 0; // Vvodimaja bukva
	char menu_ch[3] = {0};
	char man[6] = {' ',' ',' ',' ',' ',' '}; // Massive dlya chelovechka
	char eng_ch[27]; // Massive dlya Angliskih bukov
	char word[23] = "COFFE"; //ugadivaemoe slovo
	char campf[strlen(word) + 1]; // slovo dlya otkritih bukov
	ch = input;
	while(1){
		k = 0;
		z = 0;
		y = 0;
		tryed = 0;
		score = 0;
		difficult = 0;
		num = 0;
		game_start = 0;
//		game_exit = 0;
//		game_topic = 0;
		game_lose = 0;
		for (i = 0; i < 10; ++i){
			for (j = 0; j < 50; ++j){
				words[i][j] = '\0';
			}
		}
		for (i = 0;i < 6; ++i){
			man[i] = ' ';
		}
		while(1){
			while(1){
				menu_ch[0] = menu();
				if (menu_ch[0] >= '1' && menu_ch[0] <= '3'){
					break;
				}
			}
			if (menu_ch[0] == '1'){
				while(1){
					menu_ch[1] = topic_select();
					if (menu_ch[1] >= '1' && menu_ch[1] <= '4'){
						switch(menu_ch[1]){
							case '1':
								in = fopen("topics/Animals.txt","r");
								if (in == NULL){
									printf ("\nErr: NO data files\n");
									return 1;
								}
								break;
							case '2':
								in = fopen("topics/Sports.txt","r");
								if (in == NULL){
									printf ("\nErr: NO data files\n");
									return 1;
								}
								break;
							case '3':
								in = fopen("topics/Professions.txt","r");
								if (in == NULL){
									printf ("\nErr: NO data files\n");
									return 1;
								}
								break;
							case '4':
								in = fopen("topics/Fruits.txt","r");
								if (in == NULL){
									printf ("\nErr: NO data files\n");
									return 1;
								}
								break;		
						}
						while (1){
							menu_ch[2] = difficult_select();
							if (menu_ch[2] >= '1' && menu_ch[2] <= '3'){
								switch(menu_ch[2]){
									case '1':
										difficult = 1;
										break;
									case '2':
										difficult = 2;
										break;
									case '3':
										difficult = 3;
										break;
								}
								game_start = 1;
								break;
							}
							if (menu_ch[2] == '4'){
								break;
							}
						}
					}
					if (menu_ch[1] == '6'){
						break;
					}
					if (game_start == 1){
						break;
					}
				}
			}
			if (menu_ch[0] == '2'){
				while(1){
					menu_ch[0] = stats(best_score);
					if (menu_ch[0] >= '1' && menu_ch[0] <= '1'){
						break;
					}
				}
			}
			if (menu_ch[0] == '3'){
				return 0;
			}
			if (game_start == 1){
				break;
			}
		}
		switch(difficult){
		case 1:
			tryed = 6;
			break;
		case 2:
			tryed = 3;
			break;
		case 3:
			tryed = 2;
			break;
		default:
			break;
		}
		for (i = 0; i < 10; ++i){
			fscanf (in,"%s",words[i]);
		}
		while(1){
			/*Vnosim Angliskie bukvovi*/
			for (i = 0;i < 26; ++i){
				eng_ch[i] = 'A' + i;
			}
			eng_ch[26] = '\0';
			//----//
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
			//	fgets (input,2,stdin);
				scanf("%s",input);
				system(CLRS);
				strschk(word,k_index,*ch,&num);
				if (used_simbol_check(used_simbols,*ch)){
					if ((*ch >= 'a' && *ch <= 'z') || (*ch >= 'A' && *ch <= 'Z') ){
						score += num*10;
						used_simbols[y] = *ch;
						++y;
					}
				}
		//		printf ("\t%d",num);
		//		sleep(2);
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
		//		printf ("\n%c\n\n",*ch);
				/*Udalaem bukvu iz angliskih bukov*/
				for (i = 0; i < 26; ++i){
					if (eng_ch[i] == *ch){
						eng_ch[i] = ' ';
					}
				}
				//-----//
			//	system("clear");
				system(CLRS);
			}
		}
	}
	fclose(in);
	return 0;
}
