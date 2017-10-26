#include <stdio.h>

int a; //int
int* p; //int*
long b; //long
double* d; //double*
char** c; //char**

//prints out size of the variables
int main(int arg, char* argc[]) {
	printf("Assignment 1.\n");
	printf("%d\n", sizeof(a));
	printf("%d\n", sizeof(p));
	printf("%d\n", sizeof(b));
	printf("%d\n", sizeof(d));
	printf("%d", sizeof(c));
	return 0;
}