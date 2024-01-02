#include "Node.h"

int Node::getData()
{
	return data;
};

void Node::setData(int selectData)
{
	data = selectData;
};

Node* Node::getNext()
{
	return next;
};

void Node::setNext(Node* selectNext)
{
	next = selectNext;
};

Node* Node::getPrev()
{
	return prev;
};

void Node::setPrev(Node* selectPrev)
{
	prev = selectPrev;
};


bool DoublyLinkedList::Add(Node* data, int pos) // working fine adds a new Node to the list
{

	if (data == nullptr || pos < 0 || pos > existingNodes.size()) // checks if data exists or if data is in the existing nodes
	{
		cout << "false" << endl;
		return false;
	}

	Node* newNode = new Node(pos);
	newNode->setData(data->getData());
	newNode->setPrev(nullptr); //good practice to set uninitialized pointers to nullptr.
	newNode->setNext(nullptr);

	if (pos == 0) // if position is 0 then this is the first index which means it will be placed at the beginning of the node-list
	{
		if (head == nullptr) // updates head and tail - Empty list
		{
			head = newNode;
			tail = newNode;
		}
		else // it the list is not empty the head will be updated
		{
			newNode->setNext(head);
			head->setPrev(newNode);
			head = newNode;
		}
	}
	else if (pos == existingNodes.size()) // if the new node is inserted at the end of the list
	{
		tail->setNext(newNode);
		newNode->setPrev(tail);
		tail = newNode;
	}
	else // inserts at the position that pos is referring to that is in the middle of the list somewhere
	{
		Node* current = head;
		for (int i = 0; i < pos; i++)
		{
			current = current->getNext();
		}
		newNode->setPrev(current->getPrev());
		newNode->setNext(current);
		current->getPrev()->setNext(newNode);
		current->setPrev(newNode);
		}


	existingNodes.push_back(data->getData()); // adds the Data of the node to the vector, the Data doesn't matter to much
	return true;

};

int DoublyLinkedList::Search(Node* data) // working just fine now... altering the nodes starting from the "head"
{
	Node* temp = head;
	int position = 0;

	while (temp != nullptr)
	{
		if (temp->getData() == data->getData())
		{
			return position; // returns the position of the node in the index
		}
		temp = temp->getNext();
		position++;
	}

	if (temp != data)
	{
		//cout << "-1" << endl;
		return -1;
	}

};

bool DoublyLinkedList::Remove(int pos) // Removes the node at a given position
{
	Node* temp = head;

	if (temp == nullptr || find(existingNodes.begin(), existingNodes.end(), pos) == existingNodes.end()) //evaluates if temp node exists
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

	else if (temp->getPrev() == nullptr) //evaluates if temp node is first in the list head
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
};

bool DoublyLinkedList::Replace(Node* oldNode, Node* newNode) // replaces the "oldNode" with "newNode" and removes the old one from memory - fixed
{

	if (oldNode == nullptr || newNode == nullptr || Search(oldNode) == -1) // checks if oldNode exists and that new/oldNode are not nullptr
	{
		cout << "false" << endl;
		return false;
	}
		

	Node* current = head;
	while (current != nullptr) // sets the node "current" = oldnode, loops throug the list from head -> tail
	{
		if (current->getData() == oldNode->getData()) // sets the node "current" = oldnode
		{
			if (current->getPrev() != nullptr) // checks if current (oldnode) is head
			{
				current->getPrev()->setNext(newNode); // changes the node that comes previous to "oldnode". the previous nodes next is the newnode.
			}
			else
			{
				head = newNode;
			}

			if (current->getNext() != nullptr)// checks if current (oldnode) is tail
			{
				current->getNext()->setPrev(newNode); // changes the node that comes next to "oldnode". the next nodes previous is the newnode.
			}
			else
			{
				tail = newNode;
			}

			newNode->setPrev(current->getPrev());

			newNode->setNext(current->getNext());

			delete oldNode;


			return true;
		}
		current = current->getNext();
	}
	
};

void DoublyLinkedList::Display_forward() // working correctly, displays all the nodes values from head to tail
{
	Node* newNode = head;
	while (newNode != nullptr)
	{
		cout << newNode->getData() << " ";
		newNode = newNode->getNext();
	}
	cout << endl;
};

Node* DoublyLinkedList::NodeAt(int pos) // working as intended, shpws the node-position at given index
{

	Node* temp = head;

	while (temp != nullptr)
	{
		if (Search(temp) == pos)
		{
			cout << temp->getData() << endl;
			return temp;
		}
		temp = temp->getNext();
	}

	cout << "nullptr" << endl;
	return nullptr;
};

void DoublyLinkedList::Display_backward() // working correctly, displays all the nodes values from tail to head
{
	Node* current = tail;
	while (current != nullptr)
	{
		cout << current->getData() << " ";
		current = current->getPrev();
	}
	cout << endl;
};


int DoublyLinkedList::size() // working, shows the size of the linked list
{
	cout << existingNodes.size() << endl;
	return existingNodes.size();
};