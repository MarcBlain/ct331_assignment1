//Marc Assignment 1 ProPara
#ifndef CT331_ASSIGNMENT_GENERIC_LINKED_LIST
#define CT331_ASSIGNMENT_GENERIC_LINKED_LIST

typedef void(*printSomething) (void *data);

typedef struct genericListElementStruct {
	void *data;
	size_t size;
	printSomething print;
	struct genericListElementStruct *next;
} genericListElement;

int length(genericListElement *list);

void push(genericListElement **list, void *data, size_t size, printSomething);

genericListElement *pop(genericListElement **list);

void enqueue(genericListElement **list, void *data, size_t size, printSomething);

genericListElement *dequeue(genericListElement *list);

genericListElement *createEl(void *data, size_t size, printSomething);

void traverse(genericListElement *start);

genericListElement* insertAfter(genericListElement* after, void *data, size_t size, printSomething);

void deleteAfter(genericListElement* after);


#endif