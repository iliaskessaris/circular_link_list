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
	void PrintList();
	void DeleteNode(int data);
	void AddNode(int data);
	void StoreListToFIle();
	void RetrieveListFromFile();
};

#endif
