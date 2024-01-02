#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> existingNodes;

class Node
{
private:
	Node* next;
	Node* prev;

public:
	int data;

	Node(int datas) { data = datas; };

	//Getters and Setters!

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