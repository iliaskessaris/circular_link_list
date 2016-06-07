#include <iostream>

#include "Circular.h"

using namespace std;

//The constructor of the class Circular.
Circular::Circular() {
	Tail = NULL;
}

//The destructor of the class Circular.
Circular::~Circular() {
	node* Temp;
	node* Curr;

	if (Tail != NULL) {
		Curr = Tail->next;
		while (Curr != Tail) {
			Temp = Curr;
			Curr = Curr->next;
			delete(Temp);
			}
		delete(Tail);
	}
}

//Insert first node into an empty circular list.
void  Circular::InsertFirstNode(int data) {
	node* newnode = new node();
	newnode->data = data;

	newnode->next = newnode; 
	Tail = newnode;
}

//Add a node at the end of a non empty in ascending order circular list.
void  Circular::AddNodeAtEnd(int data) {
	node* newnode = new node();
	newnode->data = data;

	newnode->next = Tail->next;
	Tail->next = newnode;
	Tail = newnode;
}

//Add a node at the begining of a non empty in ascending order circular list.
void  Circular::AddAtBeginig(int data) {
	node* newnode = new node();
	newnode->data = data;

	newnode->next = Tail->next; 
	Tail->next = newnode;
}

//Add a node between two nodes in a non empty in ascending order circular list.
void  Circular::AddBetween(int data, node* Temp) {
	node* newnode=new node();
	newnode->data = data;

	newnode->next = Temp->next; 
	Temp->next = newnode;
}

//Add node in an ascending ordered circular list.
void  Circular::AddNode(int data) {
	node* Curr=Tail;
	node* Prev=Tail;
	bool Added = false;

	if (Tail != NULL) {
		if (data > Tail->data) {
			Added = true;
			AddNodeAtEnd(data);
		}
		else if (data < Tail->next->data) {
			Added = true;
			AddAtBeginig(data);
		}
		else {
			Curr = Tail->next;
			while (Curr != Tail && data > Curr->data) {
				Prev = Curr;
				Curr = Curr->next;
			}
			if (data != Curr->data) {
				AddBetween(data, Prev);
				Added = true;
			}
		}
	}
	else {
		Added = true;
		InsertFirstNode(data); //Insert first node into an empty circular list.
	}

	if (Added == false) {
		cout << "The item exists\n";
	}
	else {
		cout << "The item successfully inserted\n";
	}
}

//Prints the ascending ordered circular link list.
void  Circular::PrintList() {
	node* Temp;

	if(Tail != NULL) {
		Temp = Tail->next;
		if (Tail != Temp) {
			while (Temp != Tail) {
				cout << Temp->data << endl;
				Temp = Temp->next;
			}
			cout << Tail->data << endl;
		}
		else {
			cout << Tail->data << endl;
		}
	}
 else {
	 cout << "The list is empty\n";
	}

}