#ifndef BINNODE_H
#define BINNODE_H
#include <iostream>
#include <fstream>
#include "bintree.h"

template <class Type>
class BinNode{
    BinNode<Type>* left = nullptr;
    BinNode<Type>* right = nullptr;
    Type data;

  public:
    template <class Type2> friend class BinTree;
    BinNode() {}
    BinNode(Type dataIn) : data(dataIn) {}
};

#endif
