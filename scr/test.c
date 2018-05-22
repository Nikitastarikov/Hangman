#include <string_funcs.h>
#include <ctest.h>
#include <stdio.h>

//cat 10
//elephant 7
//tiger 9
//ocelot 8
//puma 9
//GIRAFFE 8
//ZEBRA 9
//BOBCAT 8
//MOUSE 9
//rat 10

CTEST(move_suite, move_pawn) // Ход пешки 
{
	int i,expected[10],check[10];
	char word[10][10];
	FILE* file = fopen ("topics/Animals.txt","r");
	for (i = 0; i < 10; ++i){
		printf ("%d\n",i);
		fscanf (file,"%s",word[i]);
		printf ("%s",word[i]);	
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
