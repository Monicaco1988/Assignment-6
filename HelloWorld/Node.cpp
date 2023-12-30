#include "Node.h"

int Node::getPos()
{
	return pos;
};

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
	if (data != nullptr && pos <= existingNodes.size())
	{
		if (pos == 0)
		{
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
			data->setData(pos);
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
};

int DoublyLinkedList::Search(Node* data) // working just fine now... altering the nodes starting from the "head"
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

bool DoublyLinkedList::Replace(Node* oldNode, Node* newNode) // replaces the "oldNode" with "newNode" and removes the old one from memory
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

		delete oldNode;

		return true;
	}
	else
	{
		cout << "false" << endl;
		return false;
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
	if (find(existingNodes.begin(), existingNodes.end(), pos) <= existingNodes.end())
	{
		Node* temp = head;
		int position = 0;

		while (temp != nullptr)
		{
			if (position == pos)
			{
				cout << temp->getPos() << endl;
				return temp;
			}
			temp = temp->getNext();
			position++;
		}
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