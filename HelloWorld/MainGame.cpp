#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

unsigned int nodeIndexCounter = 0; // keeps track of the overall additions of the nodes

vector <int> existingNodes; // keeps track of how many nodes and which nodes are in the linked list

class Node
{
private:
	int data;
	Node* next;
	Node* prev;

public:

	Node(int pos) {};

	//Getters and Setters!

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
	//Node* temp = nullptr;
public:

	bool Add(Node* data, int pos) // working correctly
	{
		if (data != nullptr && pos <= nodeIndexCounter)
		{
			if (pos == 0)
			{
				//Node* data;
				//data = new Node(pos);
				data->setData(pos);
				data->setNext(head);//had to change head so that it is first in line
				data->setPrev(nullptr);
				head = data;
				tail = data;
				//temp = data;
				nodeIndexCounter++;
				existingNodes.push_back(pos);
				return true;
			}
			else
			{
				//newNode -> setPrev(nullptr); works the same way with or without
				//newNode -> setNext(nullptr);
				data->setData(pos);
				//data->setNext(head);//had to change head so that it is first in line
				data->setPrev(tail);
				tail->setNext(data);
				tail = data;
				//temp = data;
				nodeIndexCounter++;
				existingNodes.push_back(pos);
				return true;
			}
		}
		else
		{
			return false;
		}
	}

	int Search(Node* data) // working just fine now... altering the nodes starting from the "head"
	{
		Node* temp = head;
		int position = temp->getData();


		while (temp != data && temp->getNext() != nullptr)
		{
			temp = temp->getNext();
			position++;
		}

		if (temp != data)
		{
			return -1;
		}

		return (position);
	}

	bool Remove(int pos) // works with nodes in the middle not in the end or start
	{
		Node* temp = head;

		if (temp == nullptr || find(existingNodes.begin(), existingNodes.end(),pos) == existingNodes.end()) //evaluates if temp node exists
		{
			return false;
		}

		auto nodeToDelete = find(existingNodes.begin(), existingNodes.end(), pos); // removes the element from the vector
		if (nodeToDelete != existingNodes.end())
			existingNodes.erase(nodeToDelete);

		while (pos > 0) // finds the node for the given position 
		{
			temp = temp->getNext();
			pos--;
		}

		if (temp->getNext() == nullptr) //evaluates if temp node is last in the lists tail
		{

			tail = temp->getPrev();

			tail->setNext(nullptr);

			delete temp;



			return true;
		}

		else if (temp ->getPrev() == nullptr) //evaluates if temp node is first in the list head
		{
			head = temp->getNext();
			
			head->setPrev(nullptr);

			delete temp;

			return true;
		}
		
		else // evaluates if the temp node is in the middle of the list
		{
			Node* previ = temp->getPrev();

			Node* next = temp->getNext();

			next->setPrev(previ);

			previ->setNext(next);

			delete temp; // deallocating memory that temp is using

			return true;
		}
	}

	bool Replace(Node * oldNode, Node *newNode) // works
	{

		Node* temp = oldNode;

		temp->setData(newNode->getData());
		temp -> setNext(oldNode->getNext());
		temp -> setPrev(oldNode->getPrev());

		oldNode = temp;

		return true;

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

	Node* NodeAt(int pos) // works as intended, modifies pos though after the while loop keep in mind
	{
		Node* temp = head;

		if (temp == nullptr || find(existingNodes.begin(), existingNodes.end(), pos) == existingNodes.end())
		{
			return nullptr;
		};

		while (pos > 0)
		{
			temp = temp->getNext();
			pos--;
		}

		return temp;
	}

	void Display_backward() // working correctly
	{
		Node* current = tail;
		while (current != nullptr)
		{
			cout << current->getData() << " ";
			current = current->getPrev();

		}
	}

	int size() // working
	{
		return sizeof(existingNodes);
	}
};

int main()
{
	Node* n0 = new Node(0);
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

	list.Display_backward();

	//list.Display_forward();

	//cout << list.Search(n4);

	//cout << list.size();

	//list.NodeAt(3);

	list.Remove(3);

	//list.Replace(n3, n4);

	list.Display_forward();

}