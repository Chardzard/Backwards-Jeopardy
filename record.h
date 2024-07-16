/*
Parke Lovett

record.h - class declaration file - Topic 4
*/

#ifndef RECORD_H
#define RECORD_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

class Record : public std::string {

public:
  int getNumFieldsInRecord() const { return used; }
  int getMax() const { return maxSize; }
  Record() : std::string() {}
  Record(const std::string &str) : std::string(str) {}
  Record(const std::string &str, size_t pos, size_t len = npos)
      : std::string(str, pos, len) {}
  Record(const char *s) : std::string(s) {}
  Record(const char *s, size_t n) : std::string(s, n) {}
  Record(size_t n, char c) : std::string(n, c) {}
  ~Record();
  Record upper();
  Record lower();
  int compareIgnoreCase(const Record &record);
  friend std::istream &operator>>(std::istream &is, Record &r);
  friend std::ifstream &operator>>(std::ifstream &is, Record &r);
  Record *split(char delimeter);

private:
  Record *fields = nullptr; // Internal vector for split function
  int used = 0;             // Returns actual capacity used by elements
  int maxSize = 0;          // Returns amount of allocated storage space
};

#endif
