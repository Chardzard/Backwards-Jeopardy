// Parke Lovett

/* record.cpp file Class Definition (Implementation of all functions from
 * record.h) */

#include "record.h"

Record::~Record() {
  if (fields != nullptr) {
    delete[] fields;
    fields = nullptr;
  }
}

Record Record::upper() {
  Record tmp = *this;
  for (int i = 0; i < tmp.length(); i++) {
    tmp[i] = std::toupper(tmp[i]);
  }
  return tmp;
}

Record Record::lower() {
  Record tmp = *this;
  for (int i = 0; i < tmp.length(); i++) {
    tmp[i] = std::tolower(tmp[i]);
  }
  return tmp;
}

int Record::compareIgnoreCase(const Record &record) {
  Record tmp = *this;
  Record tmp2 = record;
  return tmp.lower().compare(tmp2.lower());
}

std::istream &operator>>(std::istream &is, Record &r) {
  if (is.peek() == '\n')
    is.ignore(1);
  std::getline(is, r, '\n');

  return is;
}

std::ifstream &operator>>(std::ifstream &is, Record &r) {
  if (is.peek() == '\n')
    is.ignore(1);

  std::getline(is, r, '\n');
  return is;
}

Record *Record::split(char delimeter) {
  Record str = *this;
  used = 0;
  maxSize = 1;
  fields = new Record[maxSize];
  int endIndex = str.find(delimeter);
  while (endIndex != std::string::npos) {
    Record *tmp = new Record[++maxSize];
    std::copy(fields, fields + used, tmp);
    delete[] fields;
    fields = tmp;
    fields[used++] = str.substr(0, endIndex);
    str.erase(0, endIndex + 1);
    endIndex = str.find(delimeter);
  }
  fields[used++] = str;
  return fields;
}
