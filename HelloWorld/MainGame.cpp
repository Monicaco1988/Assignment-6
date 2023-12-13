#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int nodeIndexCounter = 0;



class Node
{
private:
	int data;
	Node* next;
	Node* prev;

public:
	
	//Getters and Setters!

	Node(int pos) {};

	int getData()
	{
		return data;
	}

	void setData(int selectData)
	{
		data = selectData;
	}

	Node* getNext()
	{
		return next;
	}

	void setNext(Node *selectNext)
	{
		next = selectNext;
	}

	Node* getPrev()
	{
		return prev;
	}

	void setPrev(Node* selectPrev)
	{
		prev = selectPrev;
	}

	~Node()
	{
		
	}
};



class DoublyLinkedList
{
private:
	Node* head = nullptr;
	Node* tail = nullptr;
public:

	bool Add(Node* data, int pos)
	{
		if (data != nullptr && pos <= nodeIndexCounter)
		{
			if (pos == 0)
			{
				//Node* data;
				//data = new Node(pos);
				data->setData(pos);
				data->setNext(head);//had to change head so that it is first in line
				data->setPrev(data);
				head = data;
				tail = data;
				nodeIndexCounter++;
				return true;
			}
			else
			{
				//Node* data;
				//data = new Node(pos);
				//newNode -> setPrev(nullptr); works the same way with or without
				//newNode -> setNext(nullptr);
				data->setData(pos);
				data->setNext(head);//had to change head so that it is first in line
				data->setPrev(data);
				head = data;
				nodeIndexCounter++;
				return true;
			}
		}
		else
		{
			return false;
		}
	}

	//bool Remove(int pos) // wont work untill search workds
	//{
	// 
	//	Node* temp = this->search(pos);

	//		if (temp == NULL)
	//		{
	//			return false;
	//		};
	// 
	//	Node* previ = temp->getPrev();

	//	Node *next = temp -> getNext();
	//	
	//	next->setPrev(previ);
	//	
	//	previ -> setNext(next);
	// 
	//	delete temp; // deallocating memory that temp is using
	//	
	//	
	// return true;
	//}

	bool Replace(Node * oldNode, Node *newNode)
	{


	}

	int Search(Node* data) // not working either
	{
		Node* temp = head;
		int position = temp->getData();

		
		while (temp != data && temp->getNext() != nullptr)
		{
			temp = temp->getNext();
			position--;
		}

		if (temp != data)
		{
			return -1;
		}

		return (position);
	}

	void Display_forward() // working correctly
	{
		Node* newNode = head;
		while (newNode != nullptr)
		{
			cout << newNode->getData() << " ";
			newNode = newNode->getNext();

		}
	}

	Node* NodeAt(int pos)
	{


	}

	void Display_backward() // not working correctly this is because the first add implementation is not working correctly
	{
		Node* current = tail;
		while (current != nullptr)
		{
			cout << current->getData() << " ";
			current = current->getPrev();

		}
	}

	int size()
	{
		return nodeIndexCounter;
	}
};





int main()
{
	Node* n0 = new Node(0); // i want these to change as well!
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);


	DoublyLinkedList list;

	list.Add(n0, 0);
	list.Add(n1, 1);
	list.Add(n2, 2);
	list.Add(n3, 3);
	list.Add(n4, 4);

	list.Display_forward();

	cout << list.Search(n2);
	//list.display_backward(); not working right

}