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
	void AddNode(int data);

};

#endif
