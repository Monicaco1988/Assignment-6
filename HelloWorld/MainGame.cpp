#include <iostream>
#include <vector>
#include "Node.cpp"

using namespace std;

int main()
{
	Node* n0 = new Node(0);
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	Node* n5 = new Node(5);


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

	cout << list.Search(n1) << endl;

	cout << list.Search(n2) << endl;

	list.Replace(n3, nullptr);
	
	list.Replace(n2, n4);

	list.Replace(n1, n4);

	list.Display_forward();

	list.Display_backward();
	
	list.size();

	list.NodeAt(5); // invalid position gives result nullptr working

	list.NodeAt(2); // gives the Node-position of the index-position of the node. not working
	
}