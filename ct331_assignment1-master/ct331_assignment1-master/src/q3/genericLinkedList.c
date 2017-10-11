//Marc Assignment 1 ProPara
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

int length(genericListElement *list) {
	genericListElement *curr = list;
	int length = 0;

	while (curr != NULL) {
		length++;
		curr = curr->next;
	}

	return printf("Number of elements in linked list: %d \n", length);
}

void push(genericListElement **list, void *data, size_t size, printSomething printFunc) {
	genericListElement *newEl = createEl(data, size, printFunc);
	newEl->next = *list;
	*list = newEl;
}

genericListElement *pop(genericListElement **list) {
	genericListElement *head = *list;

	if (head) {
		*list = head->next;
	}
	return head;
}

void enqueue(genericListElement **list, void *data, size_t size, printSomething printFunc) {
	genericListElement *newEl = createEl(data, size, printFunc);
	newEl->next = *list;
	*list = newEl;
}

genericListElement *dequeue(genericListElement *list) {
	genericListElement *temp = list;

	while ((temp->next)->next != NULL) {
		temp = temp->next;
	}
	genericListElement *tail = temp->next;
	temp->next = NULL;
	return tail;
}

genericListElement *createEl(void *data, size_t size, printSomething printFunc) {
	genericListElement* e = malloc(sizeof(genericListElement));
	if (e == NULL) {
		return NULL; 
	}
	void *dataPointer = malloc(size);
	if (dataPointer == NULL) {
		
		free(e); 
		return NULL;
	}
	memmove(dataPointer, data, size);
	e->data = dataPointer;
	e->size = size;
	e->print = printFunc;
	e->next = NULL;
	return e;
}


void traverse(genericListElement *start) {
	genericListElement *current = start;

	while (current != NULL) {
		current->print(current->data);
		current = current->next;
	}
}

genericListElement* insertAfter(genericListElement* el, void *data, size_t size, printSomething printFunc) {
	genericListElement* newEl = createEl(data, size, printFunc);
	genericListElement* next = el->next;
	newEl->next = next;
	el->next = newEl;
	return newEl;
}


//Delete the element after the given el
void deleteAfter(genericListElement* after) {
	genericListElement* delete = after->next;
	genericListElement* newNext = delete->next;
	after->next = newNext;
	free(delete->data);
	free(delete);
}