#include "headers/interface.h"
#include "headers/string_funcs.h"

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

char menu(){
	char ch = 0;
	system(CLRS);
	printf("\n\t\t\tMENU\n\n\n"
		"1.Start game\n"
		"2.Stats\n\n"
		"3.Quit\n\n\n"
		"Enter the num: ");
	scanf("%c",&ch);
	return ch;
}

char topic_select(){
	char ch = 0;
	system(CLRS);
	printf("\n\t\t\tSELECT THE TOPIC\n\n\n"
		"1.Animals\n"
		"2.Sports\n"
		"3.Professions\n"
		"4.Fruits\n\n"
//	printf ("5.\n\n");
		"6.Back \n\n\n"
		"Enter the num: ");
	scanf("%c",&ch);
	return ch;
}

char stats(int best_score){
	char ch = 0;
	system(CLRS);
	printf("\n\t\t\tSTATS\n\n\n"
		"Best score: %d\n\n"
		"1.Back\n\n\n"
		"Enter the num: ",best_score);
	scanf("%c",&ch);
	return ch;
}

char difficult_select(){
	char ch = 0;
	system(CLRS);
	printf("\n\t\t\tSELECT THE DIFFICULT\n\n\n"
		"1.Easy\n"
		"2.Midle\n"
		"3.Hard\n\n"
		"4.Back\n\n\n"
		"Enter the num: ");
	scanf("%c",&ch);
	return ch;
}
