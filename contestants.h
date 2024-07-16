/* 
Parke Lovett
contestants.h file - class declaration - Topic 3
*/

#ifndef CONTESTANTS_H
#define CONTESTANTS_H

#include "player.h"
#include <iostream>
#include <fstream>
#include <string>

class Contestants{
  public:
    Contestants();
    int getSize() const;
    int getMaxSize() const;
    bool append(const Player& item_to_append);
    bool erase(const Player& item_to_remove);
    bool erase(int index);
    void clearAll();
    int find(const Player& obj);
    Player getItembyIndex(int obj);
    bool readfile(const std::string& fileName);
    bool writefile(const std::string& fileName);
    Player operator[](int index);
    static const int MAX_SIZE = 3;

  private:
    Player data[MAX_SIZE];
    int size;
};

#endif