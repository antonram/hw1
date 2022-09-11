#ifndef SPLIT_H
#define SPLIT_H


struct Node 
{
  int value;
  Node* next;

  /**
   * Initializing constructor
   */
  Node(int v, Node* n)
  {
    value = v;
    next = n;
  }
};

void split(Node*& in, Node*& odds, Node*& evens);

// WRITE YOUR CODE HERE}
void addToEvens(Node*& evens, Node*& in);
void addToOdds(Node*& odds, Node*& in);

void split(Node*& in, Node*& odds, Node*& evens) {
	if(in == NULL) {
		return;
	}

	// if the current value is even, we add it to the evens linked list
	if(in->value%2 == 0) {
		addToEvens(evens, in);
	}

// else, we add it to the odds linked list
	else {
		addToOdds(odds, in);
	}

	split(in, odds, evens);

}
#endif
