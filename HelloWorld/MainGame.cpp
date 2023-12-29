#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> existingNodes; // keeps track of how many nodes and which nodes are in the linked list

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

	int getPos()
	{
		return pos;
	}

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
		if (data != nullptr && pos <= existingNodes.size())
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
				existingNodes.push_back(pos);
				return true;
			}
		}
		else
		{
			cout << "false" << endl;
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
			//cout << "-1" << endl;
			return -1;
		}

		//cout << position << endl;
		return position;
	}

	bool Remove(int pos) // works with nodes in the middle not in the end or start
	{
		Node* temp = head;

		if (temp == nullptr || find(existingNodes.begin(), existingNodes.end(),pos) == existingNodes.end()) //evaluates if temp node exists
		{
			cout << "false" << endl;
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

	bool Replace(Node* oldNode, Node* newNode) // Needs a little more work!!!!!!!!!!!!!!!!!!!!!!!!!!!
	{

		if (oldNode != nullptr && newNode != nullptr && Search(oldNode) != -1) // checks if oldNode exists and that new/oldNode are not nullptr
		{

			newNode->setPrev(oldNode->getPrev());

			newNode->setNext(oldNode->getNext());

			int pos = oldNode->getPos();

			auto nodeToDelete = find(existingNodes.begin(), existingNodes.end(), pos); // removes the element from the vector
			if (nodeToDelete != existingNodes.end())
				existingNodes.erase(nodeToDelete);

			Node* previ = oldNode->getPrev();

			previ->setNext(newNode);


		//Remove(oldNode->getPos());

		delete oldNode;

		return true;
		}
		else
		{
			cout << "false" << endl;
			return false;
		}
	}

	void Display_forward() // working correctly, displays all the nodes values from head to tail
	{
		Node* newNode = head;
		while (newNode != nullptr)
		{
			cout << newNode->getData() << " ";
			newNode = newNode->getNext();
		}
		cout << endl;
	}

	Node* NodeAt(int pos) // not working as intended
	{
		if (find(existingNodes.begin(), existingNodes.end(), pos) <= existingNodes.end())
		{
			Node* temp = head;
			int position = 0;

			while (temp != nullptr)
			{
				if (position == pos)
				{
					cout << temp->getPos();
					return temp;
				}
				temp = temp->getNext();
				position++;
			}
		}
		cout << "nullptr" << endl;
		return nullptr;
	}

	void Display_backward() // working correctly, displays all the nodes values from tail to head
	{
		Node* current = tail;
		while (current != nullptr)
		{
			cout << current->getData() << " ";
			current = current->getPrev();
		}
		cout << endl;
	}

	
	int size() // working
	{
		cout << existingNodes.size() << endl;
		return existingNodes.size();
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

	list.Add(n1, 10);

	list.Add(nullptr, 1);

	list.Add(n1, 1);

	list.Remove(3);

	list.Add(n2, 2);

	list.Display_forward();

	list.Add(n3, 1);

	list.Display_forward();

	list.Remove(2);

	list.Display_forward();

	list.Display_backward();

	cout << list.Search(n4) << endl;

	cout << list.Search(n3) << endl;

	list.Replace(n3, nullptr);
	
	list.Replace(n2, n4); // n5 could not be used as n5 node has never been initialized, n2 is chosen because it has been removed and
	// thus no longer exists

	list.Replace(n3, n4);

	list.Display_forward();
	
	list.size();

	list.NodeAt(5); // invalid position gives result nullptr

	list.NodeAt(2); // gives the Node-position of the index-position of the node.
	


}