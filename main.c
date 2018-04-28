#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#define IDX_END 1000000
#define STD_SPC 29
//#define CLRS "CLS" //for Windows
#define CLRS "clear" //for Linux

int strschk(char word[], int k_index[],char ch);
void space_print(int n);
int space_suff(char string[]);
void pole_print(char man[],char eng_ch[],char word[],unsigned int score,int tryed);
char menu();
char topic_select();
char stats();
char difficult_select();
int used_simbol_check(char used_simbols[], char ch);

int main()
{
	int i = 0;
	char man[6] = {' ',' ',' ',' ',' ',' '};
	char eng_ch[26] = {0};
	for (i = 0; i < 26; ++i){
		eng_ch[i] = 'A' + i;
	}
	char word[50] = "COFFE";
	unsigned int score = 0;
	int tryed = 0;
	pole_print(man,eng_ch,word,score,tryed);
	getchar();
	menu();
	sleep(2);
	topic_select();
	stats();
	sleep(2);
	difficult_select();
	return 0;
}

int strschk(char word[], int k_index[],char ch){
	char chupper = '\0';
	if (ch >= 'a' && ch <= 'z'){
		chupper = ch - ('a' - 'A');
	} else if (ch >= 'A' && ch <= 'Z'){
		chupper = ch + ('a' - 'A');
	}
	int i = 0,j = 0;
	k_index[0] = strlen(word);
	for (j = 1,i = 0; word[i] != '\0'; ++i){
		if (word[i] == ch || word[i] == chupper){
			k_index[j] = i;
			++j;
		}
	}
	k_index[j] = IDX_END;
	return 0;
}

void space_print(int n){
	int i = 0;
	for (i = 0; i < n; ++i){
		printf (" ");
	}
}

int space_suff(char string[]){
	return (23 - strlen(string))/2;
}

void pole_print(char man[],char eng_ch[],char word[],unsigned int score,int tryed){
	int i = 0;
//	system("clear");
	system(CLRS);
	printf("score: %-6d",score); // 13 chars
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
	printf("|||Enter the char(ENG): ");
}

char menu(){
	char ch = 0;
	system(CLRS);
	printf("\n\t\t\tMENU\n\n\n");
	printf ("1.Start game\n");
	printf ("2.Stats\n\n");
	printf ("3.Quit\n\n\n");
	printf ("|||Enter the num: ");
	scanf("%c",&ch);
	return ch;
}

char topic_select(){
	char ch = 0;
	system(CLRS);
	printf("\n\t\t\tSELECT THE TOPIC\n\n\n");
	printf ("1.Animals\n");
	printf ("2.Sports\n");
	printf ("3.Professions\n");
	printf ("4.Fruits\n\n");
//	printf ("5.\n\n");
	printf ("6.Back \n\n\n");
	printf ("|||Enter the num: ");
	scanf("%c",&ch);
	return ch;
}

char stats(int best_score){
	char ch = 0;
	system(CLRS);
	printf("\n\t\t\tSTATS\n\n\n");
	printf("Best score: %d\n\n",best_score);
	printf ("1.Back\n\n\n");
	printf ("|||Enter the num: ");
	scanf("%c",&ch);
	return ch;
}

char difficult_select(){
	char ch = 0;
	system(CLRS);
	printf("\n\t\t\tSELECT THE DIFFICULT\n\n\n");
	printf ("1.Easy\n");
	printf ("2.Midle\n");
	printf ("3.Hard\n\n");
	printf ("4.Back\n\n\n");
	printf ("|||Enter the num: ");
	scanf("%c",&ch);
	return ch;
}

int used_simbol_check(char used_simbols[], char ch){
	int i = 0;
	char chupper = 0;
	if (ch >= 'a' && ch <= 'z'){
		chupper -= 'a' - 'A';
	}
	if (ch >= 'A' && ch <= 'Z'){
		chupper += 'a' - 'A';
	}
	for (i = 0; i < 26; ++i){
		if (used_simbols[i] == ch){
			return 0;
		}
	}
	return 1;
}
