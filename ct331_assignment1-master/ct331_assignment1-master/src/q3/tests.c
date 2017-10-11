//Marc Assignment 1 ProPara
#include <stdio.h>
#include "tests.h"
#include "genericLinkedList.h"

void printChar(void *data) {
	printf("%c\n", *(char*)data);
}

void printStr(void *data) {
	printf("%s\n", data);
}

void printInt(void *data) {
	printf("%d\n", *(int*)data);
}

void printFloat(void *data) {
	printf("%f\n", *(float*)data);
}

void runTests() {
	printf("Test is running\n");

	//testing char print function and traverse
	char x = 'X';
	genericListElement *l = createEl(&x, sizeof(char), &printChar);

	traverse(l);
	length(l);

	//testing string print function and traverse
	char str[] = "Hello";
	genericListElement *l2 = insertAfter(l, &str, sizeof(str), &printStr);

	traverse(l);
	length(l);

	//testing int print function and traverse
	int y = 23;
	insertAfter(l2, &y, sizeof(y), &printInt);

	traverse(l);
	length(l);

	//testing float print function and traverse
	float z = 50.00;
	insertAfter(l2, &z, sizeof(z), &printFloat);

	traverse(l);
	length(l);


	printf("\n");

	printf("\nTests complete.\n");
}