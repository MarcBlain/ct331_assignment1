//Marc assignment1 ProPar1
#ifndef CT331_ASSIGNMENT_LINKED_LIST
#define CT331_ASSIGNMENT_LINKED_LIST

//moved from linkedList.c
typedef struct listElementStruct {
	char *data;
	size_t size;
	struct listElementStruct *next;
} listElement;

//Returns elemenets in LinkedList
int length(listElement *list);

//Pushes to head of the list
//Updates list
void push(listElement **list, char *data, size_t size);

//Pops element from head
//Updates list
listElement *pop(listElement **list);

//Enqueues to head of the list
//Updates list
void enqueue(listElement **list, char *data, size_t   size);

//Dequeues element
listElement *dequeue(listElement *list);

//Creates new linked list
//Returns pointer
listElement* createEl(char* data, size_t size);

//Prints out each element in list
void traverse(listElement* start);

//Inserts new element
//Returns pointer
listElement* insertAfter(listElement* after, char* data, size_t size);

//Delete the element after the given el
void deleteAfter(listElement* after);


#endif