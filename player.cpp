// Parke Lovett

/* player.cpp file Class Definition (Implementation of all functions from player.h) */

#include "player.h"

Player::Player(){
  name = "NoName";
  score = -1;
}

void Player::setName(const std::string& nameToSet){
  if (nameToSet.length() < 1){
    std::cout << "Error, input cannot be empty";
  }
  else{
    name = nameToSet;
  }
}

void Player::setScore(int scoreToSet) {
  if (scoreToSet < 1){
    std::cout << "Error, input cannot be 0 or less";
  }
  else{
  score = scoreToSet;
}
}

std::string Player::toString() const {
  std::string format_data = name + " " + std::to_string(score) + "\n";
  return format_data;
}

std::string Player::toFileString() const{
  std::string file_format_data = name + ',' + std::to_string(score) + "\n";
  return file_format_data;
}

std::string Player::getName() const {return name;}
int Player::getScore() const {return score;}

bool operator==(const Player& lhs, const Player& rhs){
  return lhs.getScore() == rhs.getScore();
}

bool operator !=(const Player& lhs, const Player& rhs){
  return (lhs.getScore() != rhs.getScore());
}

bool operator >(const Player& lhs, const Player& rhs){
  return (rhs.getScore() < lhs.getScore());
}

bool operator <=(const Player& lhs, const Player& rhs){
  return !(lhs.getScore() > rhs.getScore());
}

bool operator >=(const Player& lhs, const Player& rhs){
  return !(lhs.getScore() < rhs.getScore());
}

bool operator <(const Player& lhs, const Player& rhs){
  return !(lhs.getScore() >= rhs.getScore());
}

std::istream& operator >>(std::istream& input, Player& rhs){
  std::cout << "Enter contestants name: ";
  std::getline(input, rhs.name, '\n');
  std::cout << "Enter contestants score: ";
  input >> rhs.score;
  return input;
}

std::ifstream& operator >>(std::ifstream& input_file, Player& rhs){
   if (input_file.peek() == '\n')
    input_file.ignore(1);
  std::getline(input_file, rhs.name, ',');
  input_file >> rhs.score;
  return input_file;
}

std::ostream& operator <<(std::ostream& output, const Player& rhs){
  output << rhs.toString();
  return output;
}

std::ofstream& operator <<(std::ofstream& output_file, const Player& rhs){
  output_file << rhs.toFileString();
  return output_file;
}
