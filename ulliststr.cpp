#include <cstddef>
#include <stdexcept>
#include <iostream> //comment out
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
  if (empty()) {
    head_ = new Item;
    head_->val[0] = val;
    tail_ = head_;
    ++head_->last;
  }
  else if (tail_->last != ARRSIZE) {
    tail_->val[tail_->last] = val;
    ++tail_->last;
  }
  else {
    Item* temp = new Item;
    tail_->next = temp;
    temp->prev = tail_;
    tail_ = temp;
    tail_->val[0] = val;
    ++tail_->last;
  }
  ++size_;
}

void ULListStr::pop_back() {
  if (empty()) return;
  else if (tail_->last - tail_->first != 1) {
    --tail_->last;
  }
  else {
    tail_ = tail_->prev;
    delete tail_->next;
    tail_->next = NULL;
  }
  --size_;
}

void ULListStr::push_front(const std::string& val) {
  if (empty()) {
    head_ = new Item;
    head_->val[0] = val;
    tail_ = head_;
    ++head_->last;
  }
  else if (head_->first != 0) {
    head_->val[head_->first-1] = val;
    --head_->first;
  }
  else {
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
  if (empty()) return;
  else if (head_->last - head_->first != 1) {
    ++head_->first;
  }
  else {
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
