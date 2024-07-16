// Parke Lovett

/* contestants.cpp file Class Definition (Implementation of all functions from contestants.h) */

#include "contestants.h"

Contestants::Contestants(){
  size = 0;
}

int Contestants::getSize() const{
  return size;
}

int Contestants::getMaxSize() const{
  return MAX_SIZE;
}

bool Contestants::append(const Player& item_to_append){
  if (size < MAX_SIZE){
    data[size++] = item_to_append;
    return true;
  }
  else{
    return false;
  }
}

bool Contestants::erase(const Player& item_to_remove){
  int item_Found = find(item_to_remove);
  if (item_Found != -1){
    erase(item_Found);
    return true;
  }
  else{
    std::cout << "Item to remove not found, or index out of range\n";
    return false;
  }
  // call find function then once found, call erase function
}

bool Contestants::erase(int index){
  if (index > size || index < 0){
    return false;
  }
  else{
    data[index] = data[--size];
    return true;
  }
}

void Contestants::clearAll(){
  size = 0;
}

int Contestants::find(const Player& obj){
  int index = -1;
  for (int i = 0; i < size; i++){
    if (data[i] == obj){
      index = i;
      break;
    }
  }
    return index;
}

Player Contestants::getItembyIndex(int index){
  Player tmpPlayerObj;
  if (index >= 0 && index < size){
    return data[index];
  }
  return tmpPlayerObj;
}

bool Contestants::readfile(const std::string& fileName){
  std::ifstream inFile_object;
  Player tmpPlayerObj;
  inFile_object.open(fileName);
  if (!inFile_object){
    std::cout << "Error opening file\n";
    return false;
  }
  do {
    inFile_object >> tmpPlayerObj;
    append(tmpPlayerObj);
  } while (!inFile_object.eof());
  
  inFile_object.close();
  return true;
  }

bool Contestants::writefile(const std::string& fileName){
  std::ofstream outFile_object;
  outFile_object.open(fileName);
  if (!outFile_object){
    std::cout << "Error opening file\n";
    return false;
  }
  for (int i = 0; i < size; i ++){
    outFile_object << data[i];
  }
  outFile_object.close();
  return true;
}

Player Contestants::operator[](int index){
  Player default_obj;
  if (index < size && index >= 0){
    return data[index];
}
  else{
    return default_obj;
  }
}
