//Marc assignment1 ProPar1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"


int length(listElement *list) {
	listElement *curr = list;
	int length = 0;

	//while curr != null pointer increment length
	while (curr != NULL) {
		length++;
		curr = curr->next;
	}
	// prints number of elements in linked list
	return printf("Number of elements in linked list: %d \n", length);
}

//Pushes new element onto head
//Updates list
void push(listElement **list, char *data, size_t size) {
	//creates new element
	listElement *newEl = createEl(data, size);
	newEl->next = *list;
	*list = newEl;
}

//Pops element from head
//Updates list
listElement *pop(listElement **list) {
	listElement *head = *list;
	//if head of the pointer list, list = the member  
	//next from struct that head points to 
	if (head) {
		*list = head->next;
	}
	return head;
}

//Enqueues new elemenet
//Updates list
void enqueue(listElement **list, char *data, size_t   size) {
	//samae as above
	listElement *newEl = createEl(data, size);
	newEl->next = *list;
	*list = newEl;
}

//Dequeues element
listElement *dequeue(listElement *list) {
	listElement *temp = list;

	while ((temp->next)->next != NULL) {
		temp = temp->next;
	}
	listElement *tail = temp->next;
	temp->next = NULL;
	return tail;
}

//Creates linked list element
//Returns pointer
listElement* createEl(char* data, size_t size) {
	listElement* e = malloc(sizeof(listElement));
	if (e == NULL) {
		return NULL; 
	}
	char* dataPointer = malloc(sizeof(char)*size);
	if (dataPointer == NULL) {
		free(e); //release the previously allocated memory
		return NULL; //return NULL to indicate an error.
	}
	strcpy(dataPointer, data);
	e->data = dataPointer;
	e->size = size;
	e->next = NULL;
	return e;
}

//Prints out all elements
void traverse(listElement* start) {
	listElement* current = start;
	while (current != NULL) {
		printf("%s\n", current->data);
		current = current->next;
	}
}

//Inserts new element
//Returns pointer
listElement* insertAfter(listElement* el, char* data, size_t size) {
	listElement* newEl = createEl(data, size);
	listElement* next = el->next;
	newEl->next = next;
	el->next = newEl;
	return newEl;
}


//Delete the element
void deleteAfter(listElement* after) {
	listElement* delete = after->next;
	listElement* newNext = delete->next;
	after->next = newNext;
	//malloc means need to create memory
	free(delete->data);
	free(delete);
}