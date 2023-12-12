#include <iostream>

using namespace std;

// single nexted list


class Node
{
public:
	int data;
	Node* next; // 
	Node* prev;
};

//typedef Node* nodePtr;

void insert(Node*& head, int data)
{
	Node* tempPtr;
	tempPtr = new Node;
	tempPtr->data = data;
	tempPtr->next = head;
	head = tempPtr;
}



int main()
{
	Node* head;
	head = new Node;
	head->data = 20; // using arrow to populate data in the "headNode" 
	head->next = NULL;
	//cout << head->data << endl;

	insert(head, 30);

	insert(head, 40);

	Node* tmp;
	tmp = head;

	while (tmp != NULL)
	{
		cout << tmp->data << endl;
		tmp = tmp->next;

	}

}