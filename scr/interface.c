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
	//printf ("space = %d", space_suff(word));
	//sleep (2);
	printf ("%-23s\n",word);
	printf ("-----------------------------------------------------\n");
	for (i = 0; i < 26; ++i){
		printf ("|%c",eng_ch[i]);
	}
	printf("|\n\n\n");
	printf("Enter the char(ENG): ");
}

