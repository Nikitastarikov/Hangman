#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#define IDX_END 1000000
#define STD_SPC 29
#define CLRS "CLS" //for Windows
//#define CLRS "clear" //for Linux

int strschk(char word[], int k_index[],char ch);
void space_print(int n);
int space_suff(char string[]);
void pole_print(char man[],char eng_ch[],char word[],unsigned int score,int tryed);

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
