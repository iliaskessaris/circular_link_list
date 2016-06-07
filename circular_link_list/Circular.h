#ifndef CIRCULAR_H
#define CIRCULAR_H

class Circular {
private:
	struct node {
		int data;
		node* next;
	};
	node* Tail;

public:
	Circular();
	~Circular();

	void  InsertFirstNode(int data);
	void  AddNodeAtEnd(int data);
	void  AddAtBeginig(int data);
	void AddBetween(int data, node* Temp);
	void  AddNode(int data);
	void  PrintList();
};

#endif
