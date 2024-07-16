/* 
Parke Lovett

player.h file - class declaration - Topic 2
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>
#include <string>

class Player{

  public:
    Player();
    void setName(const std::string& nameToSet);
    void setScore(int scoreToSet);
    std::string toString() const;
    std::string toFileString() const;
    std::string getName() const;
    int getScore() const;
    friend bool operator==(const Player& lhs, const Player& rhs);
    friend bool operator !=(const Player& lhs, const Player& rhs);
    friend bool operator >(const Player& lhs, const Player& rhs);
    friend bool operator <=(const Player& lhs, const Player& rhs);
    friend bool operator >=(const Player& lhs, const Player& rhs);
    friend bool operator <(const Player& lhs, const Player& rhs);
    friend std::istream& operator >>(std::istream& input, Player& rhs);
    friend std::ifstream& operator >>(std::ifstream& input_file, Player& rhs);
    friend std::ostream& operator <<(std::ostream& output, const Player& rhs);
    friend std::ofstream& operator <<(std::ofstream& output_file, const Player& rhs);

  private:
    std::string name;
    int score;
};

#endif
