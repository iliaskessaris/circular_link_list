#include <iostream>
#include <fstream>
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
	 cout << "The circular list is empty\n";
	}
}

//Delete a node from the ascending ordered circular link list.
void  Circular::DeleteNode(int data) {
	node* Curr;
	node* Prev;

	if (Tail != NULL) {
		if (Tail->next == Tail && Tail->data == data) {
			delete(Tail);
			Tail = NULL;
			cout << "The item successfully deleted\n";
		}
		else {
			Curr = Tail->next;
			Prev = Tail;
			while (Curr != Tail && Curr->data !=data) {
				Prev = Curr;
				Curr = Curr->next;
			}
			if (Curr->data == data) {
				Prev->next = Curr->next;
				if (Curr == Tail) {
					Tail = Prev;
				}
				delete(Curr);
				cout << "The item successfully deleted\n";
			}
		}
	}
	else {
		cout << "The circular list is empty\n";
	}
}

//Add node in an ascending ordered circular list.
void  Circular::AddNode(int data) {
	node* newnode = new node();
	node* Curr;
	node* Prev;

	newnode->data = data;
	if (Tail == NULL) { //Insert the first node in the circular list.
		newnode->next = newnode;
		Tail = newnode;
		cout << "The item successfully inserted\n";
	}
	else {
		Curr = Tail->next;
		Prev = Tail;
		while (Curr != Tail && data > Curr->data) { //Search for the proper location in the circular list to add the node.
			Prev = Curr;
			Curr = Curr->next;
		}
		if (Curr->data != data) { //Check for the existance of the new node in the circular link list.
			if (Curr == Tail && data > Curr->data) { //Insert the node at the end of the circular list.
				newnode->next = Tail->next;
				Tail->next = newnode;
				Tail = newnode;
			}
			else {
				newnode->next = Curr; //Insert the node anywhere else in the circular list.
				Prev->next = newnode;
			}
			cout << "The item successfully inserted\n";
		}
		else { //Do not insert the new node if it already exists in the circular list.
			cout << "The item exists\n";
			delete(newnode);
		}
	}
}

//Store the circular list to a file.
void Circular::StoreListToFIle() {
	ofstream newfile("Circular.txt");
	node* Temp=Tail;

	if (Temp !=NULL) {
		Temp = Tail->next;
		while (Temp != Tail) {
			newfile << Temp->data << endl;
			Temp = Temp->next;
		}
		newfile << Temp->data;
	}
	newfile.close();
}

//Retrieve list from file.
void Circular::RetrieveListFromFile() {
	ifstream newfile("Circular.txt");
	int data;

	if (newfile.is_open()) {
		while (!newfile.eof()) {
			newfile >> data;
			AddNode(data);
		}
	}
	newfile.close();
}