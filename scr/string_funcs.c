#include "headers/string_funcs.h" 



int Difficult_output (int difficult, int *tryed) {
	if (difficult >= 1 || difficult <= 3) {
		if (difficult == 1) { 
			*tryed = 6;
		}
		else if (difficult == 2) {
			*tryed = 3;
		}
		else if (difficult == 3) {
			*tryed = 2;
		}
	}
	else {
		return -1;
	}
	return 0;
}

int Topic_output (int topic, FILE ** in) {
		if (topic == 1) {
			*in = fopen("topics/Animals.txt","r");
			if (*in == NULL){
				printf ("\nErr: NO data files\n");
				return -1;
			}	
		}
		else if (topic == 2) {
			*in = fopen("topics/Sports.txt","r");
			if (*in == NULL){
				printf ("\nErr: NO data files\n");
				return -1;
			}	
		}
		else if (topic == 3) {
			*in = fopen("topics/Professions.txt","r");
			if (*in == NULL){
				printf ("\nErr: NO data files\n");
				return -1;
			}	
		}
		else if (topic == 4) {
			*in = fopen("topics/Fruits.txt","r");
			if (*in == NULL){
				printf ("\nErr: NO data files\n");
				return -1;
			}	
		}
	return 0;
}

int strschk(char word[], int k_index[],char ch,int* num){
	char chupper = '\0';
	if (ch >= 'a' && ch <= 'z'){
		chupper = ch - ('a' - 'A');
	} else if (ch >= 'A' && ch <= 'Z'){
		chupper = ch + ('a' - 'A');
	}
	int i = 0,j = 0;
	for (j = 1,i = 0; word[i] != '\0'; ++i){
		if (word[i] == ch || word[i] == chupper){
			k_index[j] = i;
			++j;
		}
	}
	*num = j - 1;
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
