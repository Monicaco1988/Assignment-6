#pragma once
class DoublyLinkedList
{
	//instances


	//constructor

	DoublyLinkedList() { }; // (needed to create objects)ill prob need som parameter of Node* and int pos etc.


	//declaration of methods
	DoublyLinkedList add(Node* data, int pos);
	DoublyLinkedList remove(int pos);
	DoublyLinkedList remove(int pos);
	DoublyLinkedList remove(int pos);
	DoublyLinkedList remove(int pos);


	//defenitions of methods
	bool add(Node* data, int pos)
	{

		return true;
	}

	bool remove(int pos)
	{
		return true;
	}

	bool replace(Node* old, Node* new)
	{}

	int search(Node* data)
	{}

	Node* nodeAt(int pos)
	{}

	void display_forward() {}

	void display_backward() {}

	int size() {}

	~DoublyLinkedList();
	//delete
};



