/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void splitHelper(Node*& in, Node*& odds, Node*& evens) {
  
// if in is now empty, no nodes will be assigned to the other lists
	if(in == nullptr) {
		return;
	}

	// if the current value is even, we add it to the evens linked list
	if(in->value%2 == 0) {
		addToList(evens, in);
		splitHelper(in, odds, evens);
	}

// else, we add it to the odds linked list
	else {
		addToList(odds, in);
		splitHelper(in, odds, evens);
	}

}

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  splitHelper(in, odds, evens);
  in = nullptr;
}



/* If you needed a helper function, write it here */

void addToList(Node*& target, Node*& in) {
	// if nothing in the block we are looking at for target linked list
	if(target == nullptr) {
		// we update target linked list, move input along to the next, and remove connection from target to the rest of the items in input linked list
		target = in;
		in = in->next;
		target->next = nullptr;
	}
	else {
		// traverse target linked list until we find open spot
		addToList(target->next, in);
	}
}

// WRITE YOUR CODE HERE