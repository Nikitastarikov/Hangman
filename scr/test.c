#include <string_funcs.h>
#include <ctest.h>
#include <stdio.h>


CTEST(expected,check) // probel
{
	int i,expected[10],check[10];
	char word[10][10];
	FILE* file = fopen ("topics/Animals.txt","r");
	for (i = 0; i < 10; ++i){
		//printf ("%d\n",i);
		fscanf (file,"%s",word[i]);
		//printf ("%s",word[i]);	
	}
	fclose (file);
	for (i = 0; i < 10; ++i) {
		check[i] = space_suff(word[i]);
	}
	expected[0] = 10;
	expected[1] = 7;
	expected[2] = 9;
	expected[3] = 8;
	expected[4] = 9;
	expected[5] = 8;
	expected[6] = 9;
	expected[7] = 8;
	expected[8] = 9;
	expected[9] = 10;
	ASSERT_EQUAL(expected[0], check[0]);
	ASSERT_EQUAL(expected[1], check[1]);
	ASSERT_EQUAL(expected[2], check[2]);
	ASSERT_EQUAL(expected[3], check[3]);
	ASSERT_EQUAL(expected[4], check[4]);
	ASSERT_EQUAL(expected[5], check[5]);
	ASSERT_EQUAL(expected[6], check[6]);
	ASSERT_EQUAL(expected[7], check[7]);
	ASSERT_EQUAL(expected[8], check[8]);
	ASSERT_EQUAL(expected[9], check[9]);
}

// simbol
CTEST(input, output) // check_simbol
{
	int i = 0;
	int expected[11];
	int check[11];
	char input = 'a';
	char simbol[11] = {0};
	
	for (i = 0; i < 11; ++i){
		simbol[i] = 0;	
	}
	printf ("\n");
	for (i = 0; i < 10; ++i) {
		check[i] = used_simbol_check(simbol, input);
		++input;
		//printf ("check[%d] = %d\n",i,check[i]);
	}
	expected [0] = 1;
	expected [1] = 1;
	expected [2] = 1;
	expected [3] = 1;
	expected [4] = 1;
	expected [5] = 1;
	expected [6] = 1;
	expected [7] = 1;
	expected [8] = 1;
	expected [9] = 1;
	ASSERT_EQUAL(expected[0], check[0]);
	ASSERT_EQUAL(expected[1], check[1]);
	ASSERT_EQUAL(expected[2], check[2]);
	ASSERT_EQUAL(expected[3], check[3]);
	ASSERT_EQUAL(expected[4], check[4]);
	ASSERT_EQUAL(expected[5], check[5]);
	ASSERT_EQUAL(expected[6], check[6]);
	ASSERT_EQUAL(expected[7], check[7]);
	ASSERT_EQUAL(expected[8], check[8]);
	ASSERT_EQUAL(expected[9], check[9]);

}
