#include <stdio.h>
#include <string.h>
#include <locale.h>
#define IDX_END 1000000

int strschk(char word[], int k_index[],char ch);

int main()
{
	char string[] = "Chocolate";
	int k_index[100] = {0}, i = 0,j = 0;
	char ch = 0;
	scanf ("%c", &ch);
	strschk(string,k_index,ch);
	printf ("\n%s\t",string);
	for (i = 1; k_index[i] != IDX_END ; ++i){
		printf ("%i ",k_index[i]);
	}
	printf ("\n");
	char campf[strlen(string) + 1];
	for (i = 0; i <strlen(string); ++i){
		campf[i] = '_';
	}
	campf[i] = '\0';
	for (i = 0,j = 1; i < strlen(string) && k_index[j] != IDX_END; ++i){
		if (i == k_index[j]){
			campf[i] = ch;
			++j;
		}
	}
	printf ("%s\n",campf);
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
