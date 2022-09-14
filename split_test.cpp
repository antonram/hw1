#include "split.h"
#include <iostream>

int main(){
	Node* node5 = new Node(5, nullptr);
	Node* node4 = new Node(4, node5);
	Node* node3 = new Node(3, node4);
	Node* node2 = new Node(2, node3);
	Node* node1 = new Node(1, node2);

	Node* in = node1;

	Node* evens = nullptr;
	Node* odds = nullptr;

	split(in, odds, evens);
	//expected: both addresses to be the same
	std::cout << odds << " " << node1 << std::endl;

	// expected: 1 3 5
	while(odds != nullptr) {
		std::cout << odds->value << " ";
		odds = odds->next;
	}

	std::cout << std::endl;
	
	//expected: 2 4
	while(evens != nullptr) {
		std::cout << evens->value << " ";
		evens = evens->next;
	}

	delete node1;
	delete node2;
	delete node3;
	delete node4;
	delete node5;

	return 0;			
}