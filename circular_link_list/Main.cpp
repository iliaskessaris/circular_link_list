#include <iostream>
#include "Circular.h"

using namespace std;

void main() {
	Circular* CircularList=new Circular();
	CircularList->AddNode(2);
	CircularList->AddNode(5);
	CircularList->AddNode(3);
	CircularList->AddNode(1);
	CircularList->AddNode(6);
	CircularList->AddNode(3);
	CircularList->PrintList();
	system("Pause");
}