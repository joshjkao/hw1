#include <cstddef>
#include <stdexcept>
// #include <iostream> 
#include <string>
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
  if (empty()) {  //case 1: empty list
    head_ = new Item;
    head_->val[0] = val;
    tail_ = head_;
    ++head_->last;
  }
  else if (tail_->last != ARRSIZE) {  //case 2: tail item has space
    tail_->val[tail_->last] = val;
    ++tail_->last;
  }
  else {
    Item* temp = new Item;  //case 3: tail item has no space; create new item and update tail
    tail_->next = temp;
    temp->prev = tail_;
    tail_ = temp;
    tail_->val[0] = val;
    ++tail_->last;
  }
  ++size_;
}

void ULListStr::pop_back() {
  if (empty()) return;  //case 1: empty list, nothing to pop
  else if (tail_->last - tail_->first != 1) { //case 2: tail item has more than 1 item
    --tail_->last;
  }
  else {  //case 3: tail item has 1 item; delete last item and update tail
    tail_ = tail_->prev;
    delete tail_->next;
    tail_->next = NULL;
  }
  --size_;
}

void ULListStr::push_front(const std::string& val) {
  if (empty()) {  //case 1: empty list
    head_ = new Item;
    head_->val[0] = val;
    tail_ = head_;
    ++head_->last;
  }
  else if (head_->first != 0) { //case 2: head item has space 
    head_->val[head_->first-1] = val;
    --head_->first;
  }
  else {  //case 3: head item has no space; create new item and update head
    Item* temp = new Item;
    head_->prev = temp;
    temp->next = head_;
    head_ = temp;
    head_->val[ARRSIZE-1] = val;
    head_->first = ARRSIZE-1;
    head_->last = ARRSIZE;
  }
  ++size_;
}

void ULListStr::pop_front() {
  if (empty()) return;  //case 1: empty list, nothing to pop
  else if (head_->last - head_->first != 1) { //case 2: head item has more than 1 item
    ++head_->first;
  }
  else {  //case 3: head item has 1 item; delete and update head
    head_ = head_->next;
    delete head_->prev;
    head_->prev = NULL;
  }
  --size_;
}

std::string const & ULListStr::back() const {
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const {
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  /*keep iterating through nodes until you find the node that contains index loc*/
  Item* curr_ = head_;
  while (loc >= curr_->last - curr_->first) {
    loc -= curr_->last - curr_->first;
    if (curr_->next == NULL) return NULL;
    curr_ = curr_->next;
  }
  return &curr_->val[curr_->first + loc];
}

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
