#include <iostream>
#include "Circular.h"

using namespace std;

Circular::Circular() {
	Tail = NULL;
}

Circular::~Circular() {

}

void Circular::AddNode(int data) {
	node* newnode;
	newnode->data = data;

	if (Tail == NULL) {
		newnode->next = newnode; //Add the first node in an empty List.
		Tail = newnode;
	} else if (Temp == Tail->next ) {
		newnode->next = Tail->next; //Add a node at the begining of a non empty List.
		Tail->next = newnode;
		} else if ()
		{
		
		}

