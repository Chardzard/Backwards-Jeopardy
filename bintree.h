#ifndef BINTREE_H
#define BINTREE_H

#include "binnode.h"

template <class Type>
class BinTree{
  BinNode<Type>* root = nullptr;
  void free(BinNode<Type>* cursor);
  void writeFile(std::ofstream& ofs, BinNode<Type>* obj) const;
  void printElement(BinNode<Type>* cursor);
  void inOrder(BinNode<Type>* cursor, int , int& , void process(Type , int , int& ));
  void copyTree(BinNode<Type>* cursor);

  public:
    BinTree() {} // Empty tree
    ~BinTree() { free(root); }
    bool isEmpty() const { return root == nullptr; }
    void add(Type dataIn);
    bool writeFile(std::string fileName) const;
    void clearAll() { free(root); }
    bool readFile(std::string fileName);
    void printAll() const { printElement(root); }
    void inOrderTraversal(int , void process(Type , int , int& ));
    BinTree(const BinTree<Type>& source);
    BinTree<Type>& operator=(const BinTree<Type>& source);
};

#include "bintree.template"

#endif
