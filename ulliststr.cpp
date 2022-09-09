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

void ULListStr::push_front(const std::string& val){
  if (empty()){ //if empty
    Item *item = new Item();
    head_ = item;
    tail_ = item;
    item->first = 0;
    item->last = 1;
    size_ = 1;
    item->val[item->first] = val;
  }
  else{ 
    Item *temp = head_;
    if (temp->first != 0){//space at the front
      temp->val[temp->first-1] = val;
      temp->first--;
      size_++;
    } 
    else if(temp->first == 0){ //no space at the front
      Item *headItem = new Item();
      headItem->first = 9;
      headItem->last = 10;
      temp->prev = headItem;
      headItem->next = temp;
      size_++;
      head_ = headItem;
      headItem->val[9] = val;
    }
  }
}

void ULListStr::push_back(const std::string& val){
  if (empty()){ //if empty
    Item *item = new Item();
    head_ = item;
    tail_ = item;
    item->first = 0;
    item->last = 1;
    size_ = 1;
    item->val[item->first] = val;
  } 
  else {
    Item *temp = tail_;
    if (temp->last != 10){  //space at the end
      temp->val[temp->last] = val;
      temp->last++;
      size_++;
    }
    else if(temp->last == 10){ //no space at the end
      Item *tailItem = new Item();
      tailItem->first = 0;
      tailItem->last = 1;
      temp->next = tailItem;
      tailItem->prev = temp;
      size_++;
      tail_ = tailItem;
      tailItem->val[0] = val;
    }
  }
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  if (empty()){
    return nullptr;
  } 
  else {
  
    Item *temp = head_;
    while (loc >= (temp->last - temp->first)){
      loc -= (temp->last - temp->first);
      temp = temp->next;
    } 
    return &temp->val[temp->first+loc];
  }
    
  
}

std::string const & ULListStr::front() const{
  
  Item *temp = head_;
  return temp->val[temp->first];

}

std::string const & ULListStr::back() const{
  
  Item *temp = tail_;
  return temp->val[temp->last-1];
  
}

void ULListStr::pop_back(){
  if (empty()){
    return;
  }
  else {
    Item *temp = tail_;
    if (temp->last-temp->first > 1){ //more than 1 element left
      temp->last--;
      size_--;
    } else if (temp->last-temp->first == 1){ //only 1 element left
      Item *prevItem = temp->prev;
      delete tail_;
      tail_ = prevItem;
      prevItem->next = NULL;
      size_--;
    }
  }
}

void ULListStr::pop_front(){
  if (empty()){
    return;
  }
  else {
    Item *temp = head_;
    if (temp->last-temp->first > 1){ //more than 1 element left
      temp->first++;
      size_--;
    } else if (temp->last-temp->first == 1){ //only 1 element left
      Item *nextItem = temp->next;
      delete head_;
      head_ = nextItem;
      nextItem->prev = NULL;
      size_--;
    }
  }
}