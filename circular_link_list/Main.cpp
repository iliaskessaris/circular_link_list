#include <iostream>
#include "Circular.h"

using namespace std;

//Displays the contents of the main menu.
void menu() {
	cout << "Press 1 to insert a number\n";
	cout << "Press 2 to delete a number\n";
	cout << "Press 3 to display the list numbers\n";
	cout << "Press any other character to quit\n";
}

//Main menu for managing a circular link list.
void main() {
	Circular* CircularList = new Circular();
	char choice;
	int data;

	CircularList->RetrieveListFromFile();
	menu();
	cin >> choice;
	while (choice == '1' || choice == '2' || choice == '3') {
		switch (choice) {
		case '1':
			cout << "Type number to insert\n";
			cin >> data;
			CircularList->AddNode(data);
			break;
		case '2':
			cout << "Type the number to delete\n";
			cin >> data;
			CircularList->DeleteNode(data);
			break;
		case '3':
			cout << "The list numbers are\n";
			CircularList->PrintList();
			break;
		}
		menu();
		cin >> choice;
	}
	CircularList->StoreListToFIle();
	system("Pause");
}