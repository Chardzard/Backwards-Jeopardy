/*
Parke Lovett

node.h file - class declaration & definition - Topic 6&7

Node<T> Template Class

1. Node is a template class that is a helper class to LinkList.
    - Node is very short and thus why only Node.h is required
3. A Node has private data member:
    i. Node<T>* next (link to next Node)
    ii. T data (data item or element being stored)
4. Declare and define a Node default constructor as an inline function within
Node.h
5. Declare and define another Node constructor that takes the dataIn as the
parameter as an inline function within Node.h
6. Give LinkList friend class access inside of Node

*/

#ifndef NODE_H
#define NODE_H
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include "linklist.h"

template <class T>
class Node {
public:
  template <class T2> friend class LinkList;
  Node() {
    data = T();
    next = nullptr;
  }
  Node(T dataIn) {
    data = dataIn;
    next = nullptr;
  }

private:
  Node<T> *next; // link to next
  T data = T();  // element or item
  //friend class LinkList;
};

#endif