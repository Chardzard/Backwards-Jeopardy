#ifndef LINKLIST_H
#define LINKLIST_H
#include "node.h"

template <class T>
class LinkList{
  public:
    LinkList() {}
    int getSize() const;
    bool isEmpty() const;
    T at(int counter) const;
    T getRandomData() const;
    bool writeFile(std::string fileName) const;
    Node<T>* findByData(T data) const;
    void prepend(T data);
    void append(T data);
    void removeFirst();
    void removeByData(T data);
    void clearAll();
    bool readFile(std::string fileName);
    ~LinkList();
    LinkList(const LinkList<T>& source);
    LinkList<T>& operator=(const LinkList<T>& source);
    void printAll();

  private:
    Node<T>* first = nullptr; // link to first Node in the LinkList
    Node<T>* last = nullptr;  // link to last Node in the LinkList
};

#include "linklist.template"

#endif

/*
Parke Lovett

### LinkList<T> Template Class Declaration (linklist.h) Topic 6 & 7

1. The LinkList class **MUST** be declared in linklist.h and defined in linklist.template
    - Include macro guard defined as LINKLIST_H
2. Create the LinkList class as a template class that has access to Node's private data members `data and next` through being a friend class of Node.
    - LinkList is a dynamic, linear, one-directional data structure that is a collection of Nodes.
3. Add private data member for LinkList:
  ```
  Node<T>* first; // link to first Node in the LinkList
  Node<T>* last; // link to last Node in the LinkList
  ```
4. Create a default constructor for a LinkList data structure that will setup as an empty LinkList.
5. Add getSize() public accessor member function to traverse through the LinkList and counts the number of Nodes within to obtain the size of the LinkList.
     - Note a LinkList size is **ALWAYS** exactly equivaluent to the amount of elements in the collection.  It grows and shrinks with each add/erase.
```
int getSize() const;
@param: none
@return: the counter of number of elements - BigO(n) - linear
```
6. Add isEmpty() public accessor member function to return true or false if the LinkList is empty or not.  An empty list is **NOT** determined based upon the size, but checking the first and last pointers.
```
bool isEmpty() const;
@param: none
@return: true or false if the LinkList has any elements or not 
```
7. Add at(int) public accessor member function to return the Node's data at the location counter passed in.  
```
T at(int) const;
@param: counter is **NOT** zero-based nor an index, but a counter of the number of items in the LinkList starting at 1
@return: the data portion of the Node element.
```
8. Add getRandomData() public accessor member function to return the Node's data at a randomly generated location
```
T getRandomData() const;
@param: none
@return: the data portion of the Node element that is found at a random counter that is **NOT** zero-based nor an index, but a counter of the number of items in the LinkList starting at 1
```
9. Add writeFile(std::string) public accessor member function to write all data being stored in LinkList to the file.
```
bool writeFile(std::string fileName) const;
@param: the string representing the file name of the file to write to
@return: true - all data written to file, or false - there was an error as the file didn't open correctly.
```
10. Add findByData(T) **private** accessor member function to search through the Linklist mathcing the data to each Node's data and returning a pointer to the Node when matched.
```
Node<T>* findByData(T data) const;
@param: the data to use to check against each Node's data in the LinkList
@return: a pointer to the Node that matches or nullptr if not found
```
11. Add prepend(T) public modifier member function to allocate the memory for the new Node with the data element of the Node passed in and add at the beginning before first.
```
void prepend(T data);
@param: the data to use to create a Node and then add into the LinkList
@return: none
```
12. Add append(T) public modifier member function to allocate the memory for the new Node with the data element of the Node passed in and add the item at the end after last.
```
void append(T data);
@param: the data to use to create a Node and then add into the LinkList
@return: none
```
13. Add removeFirst() public modifier member function to remove the first Node from the LinkList and deallocate the memory for the Node that is removed.
```
void removeFirst();
@param: none
@return: none
```
14. Add removeByData(T) public modifier member function to find and remove the data that matches a Node's data in the LinkList and deallocate the memory for the Node that is removed.
```
void removeByData(T data);
@param: the data to use to match to a Node in the LinkList and then remove and deallcoate the Node from the LinkList
@return: none
```
15. Add clearAll() public modifier member function to traverse through and deallocate the memory for each Node in the LinkList until all Nodes are deallocated.  This funciton frees all memory in the LinkList to reset the LinkList as an empty data structure.
```
void clearAll();
@param: none
@return: none
```
16. Add readFile(std::string) public modifier member function to read all data from a file by appending the data into the LinkList.
```
bool readFile(std::string fileName);
@param: the string representing the file name of the file to read from
@return: true - all data read from the file, or false - there was an error as the file didn't open correctly.
```
17. Complete the value semantics - meaning of the memory for the LinkList class since it uses dynamic memory.

Destructor
18. Add Destructor public modifier member function to destroy all memory of the LinkList.  **NOTE** a programmer cannot call the destructor themselves, this function gets called by the compiler when the LinkList object goes out of scope.
```
~LinkList();
@param: none
@return: none
```
19. Add Copy Constructor public modifier member function to make a deep copy of the LinkList object `source` being passed in. **NOTE** copy constructors get called for the following 3 reasons:
    1. When an object is created and initialized to an existing object
    2. When an object is passed by value to a function
    3. When an object is returned out of a function (not as a reference)
```
LinkList(const LinkList<T>& source);
@param: source is the existing LinkList object being passed in to make a copy of
@return: none
```
20. Add Assignment Operator public modifier member function to make a deep copy of the LinkList object `source` being passed in and reassigned to an already existing LinkList object.  **NOTE** assignment operator's make a copy just like the copy constructor, but they **MUST**
    1. Check for self-assignment and if so stop and not do anything and return *this
    2. Destroy all memory from the existing LinkList before making the copy for the reassignment to ensure NO memory leak.
```
LinkList<T>& operator=(const LinkList<T>& source);
@param: source is the existing LinkList object being passed in to make a copy of
@return: The newly updated *this
```

#### Bonus (OPTIONAL) Public Member Functions in LinkList

1. Add removeAllDups() public modifier member function remove all duplicate data from the LinkList, leaving only the first occurrence of all data, making the LinkList store only unique data.
```
void removeAllDups();
@param: none
@return: none
```
2. Add insertAscending(T) public modifier member function to allocate the memory for the new Node with the data element of the Node passed in and insert the Node into the correct position keeping the LinkList in ascending order
```
void insertAscending(T data);
@param: the data to use to create a Node and then add into the LinkList
@return: none
```
3. Add insertDescending(T) public modifier member function to allocate the memory for the new Node with the data element of the Node passed in and insert the Node into the correct position keeping the LinkList in descending order
```
void insertDescending(T data);
@param: the data to use to create a Node and then add into the LinkList
@return: none
```
*/