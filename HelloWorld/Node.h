#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> existingNodes;

class Node
{
private:
	int pos; // use this variable to set a position for each each node. like a name for that position, I use it in AtNode() function
	int data;
	Node* next;
	Node* prev;

public:

	Node(int position) { pos = position; };

	//Getters and Setters!

	int getPos();

	int getData();

	void setData(int selectData);

	Node* getNext();

	void setNext(Node* selectNext);

	Node* getPrev();

	void setPrev(Node* selectPrev);

	~Node()
	{
	}
};

class DoublyLinkedList
{
private:
	Node* head = nullptr;
	Node* tail = nullptr;
	//Node* temp = nullptr;
public:

	bool Add(Node* data, int pos);

	int Search(Node* data);

	bool Remove(int pos); 

	bool Replace(Node* oldNode, Node* newNode);

	void Display_forward(); 

	Node* NodeAt(int pos); 

	void Display_backward(); 

	int size(); 
};