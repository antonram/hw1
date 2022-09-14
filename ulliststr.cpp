#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE


void ULListStr::push_back(const std::string& val) {
  // if no nodes yet, we create a new one
  if(tail_ == NULL) {
    tail_ = new Item();
    // in this case, head == tail
    head_ = tail_;
  }
  //else if last node is full, we create new
  else if(tail_->last == ARRSIZE) {
    tail_->next = new Item();
    tail_->next->prev = tail_;
    tail_ = tail_->next;
  }
// we add new val at last available index of tail
  tail_->val[tail_->last] = val;
  // update index of last
  tail_->last++;
	//update size of list
	size_++;
}


void ULListStr::pop_back() {
  // if tail doesn't exist, we just return
  if(tail_ == NULL) {
    return;
  }
  // if only one val, we deallocate tail
  if(tail_->last == tail_->first + 1) {
    // if tail only node, we wipe everything
    if(tail_->prev == NULL) {
      delete tail_;
      tail_ = NULL;
      head_ = NULL;
			size_ = 0;
      return;
    }
    //if there was node, we update tail
    tail_ = tail_->prev;
    delete tail_->next;
    tail_->next = NULL;
		size_--;
    return;
  }
  // we eliminate string in place to pop
  tail_->val[tail_->last-1] = "";
  // we update last
  tail_->last--;
	//update size
	size_--;
}


void ULListStr::push_front(const std::string& val) {
  // if no nodes yet, we create new
  if(head_ == NULL) {
    head_ = new Item();
		tail_ = head_;
		//append new value to the end of item
    head_->val[ARRSIZE-1] = val;
		head_->first = ARRSIZE - 1;
		head_->last = ARRSIZE;
		size_++;
    return;
  }
// if list full from front, create new
  if(head_->first == 0) {
    head_->prev = new Item();
    head_->prev->next = head_;
    head_ = head_->prev;
		//append new value to the end of item
    head_->val[ARRSIZE-1] = val;
		head_->first = ARRSIZE - 1;
		head_->last = ARRSIZE;
		size_++;
    return;
  }
  //update value
  head_->val[head_->first-1] = val;
  head_->first--;
	size_++;
}

void ULListStr::pop_front() {
  //if no nodes yet, nothing to do
  if(head_ == NULL) {
    return;
  }
  //if only one item, deallocate
  if(head_->first == head_->last - 1) {
    //if only one node exists, wipe everything
    if(head_->prev == NULL) {
      delete head_;
      head_ = NULL;
      tail_ = NULL;
      return;
    }
  // delete node, make new head front
    head_ = head_->prev;
    delete head_->next;
    head_->next = NULL;
    return;
  }
  // else, we remove front
  head_->val[head_->first] = "";
  head_->first++;
	size_--;
}

std::string const & ULListStr::back() const {
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const {
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
	// if list empty, return NULL
	if(head_ == NULL) {
		return NULL;
	}
	// calculate how many items at node 1
	size_t node1 = head_->last - head_->first;
	// if loc is less than number of items at node 1, our job is done.
	if(node1 > loc) {
		return &head_->val[head_->first + loc];
	}
	//else, calculate how many nodes to traverse
	size_t target = (loc - node1)/ARRSIZE + 1;
	//also calculate index at target node
	size_t index = (loc-node1)%ARRSIZE;
	//traverse linked list
	Item* ptr = head_;
	while(target > 0) {
		ptr = ptr->next;
		target--;
		if(ptr == NULL) {
			return NULL;
		}
	}
	//now that we are at target node
	size_t numItems = ptr->last - ptr->first;
	// check if node has enough items
	if(index > numItems-1) {
		return NULL;
	}
	return &ptr->val[ptr->first+index];
}


// END OF MY CODE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
