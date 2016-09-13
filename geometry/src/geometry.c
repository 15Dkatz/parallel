/*
 ============================================================================
 Name        : geometry.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//Your program should present a menu for the human to choose which shape to calculate, then ask them for the appropriate values (length, width, radius, etc.). Then it should pass those values to the appropriate function and display the resulting area.

//Notice that you must not input the values inside the functions, and you must not display the values inside the functions. All input and output must be in the main(), and values must be passed to the functions and returned from them.

int main(void) {
	printf("Hello! What shape would you like to calculate the area for?\n");

	printf("\t 1) square?\n");
	printf("\t 2) rectangle?\n");
	printf("\t 3) triangle?\n");
	printf("\t 4) circle?\n");

	printf("Enter your the number of your choice: ");
	int choice;
	scanf("%d", &choice);

	if (choice == 1) {
		printf("\nWhat is the side length of your square?");
	}

	if (choice == 2) {
		printf("\nWhat is the length of your rectangle?");
		// scanf
		printf("\nWhat is the width of your rectangle?");
	}

//	choice 3
//	choice 4

	return EXIT_SUCCESS;
}
