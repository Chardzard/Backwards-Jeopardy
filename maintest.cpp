/*
Your Name: Parke Lovett
CSC 1061- section
Date: 04/27/2023
Summary: This program plays a backwards game of Jeopardy :)

Topic 8 Main Program - Get all the questions for the random categories and
generate the game board and play the game using HTML
*/

#include <cstdlib> // srand
#include <ctime>   // time
#include <iomanip> // setw
#include <iostream>
#include <string>

#include "bintree.h"
#include "htmlfunc.h"
#include "linklist.h"
#include "question.h"
#include "record.h"

void playGame();

int main() {
  srand(time(nullptr));
  playGame();

  std::cout << "\n\n";
  return 0;
}

void playGame() {
  LinkList<Record> allCategories;

  // Read all possible category data
  allCategories.readFile("assets/gameInfo.csv");

  std::cout << "\nAll Categories\n\n";
  allCategories.printAll();

  LinkList<Record> gameCategories;

  // Generate 6 random categories
  int categoryCount = 0;
  while (categoryCount < 6) {
    Record category = allCategories.getRandomData();
    if (gameCategories.findByData(category) == nullptr) {
      gameCategories.prepend(category);
      categoryCount++;
    }
  }

  LinkList<Record> catTitles;
  std::cout << "\nGame Categories\n\n";
  for (int i = 1; i <= gameCategories.getSize(); i++) {
    Record info = gameCategories.at(i);
    info = info.upper();
    Record *fields = info.split(',');
    Record *file = fields[2].split('.');
    catTitles.append(file[0]);
    std::cout << i << ". " << std::setw(20) << std::left << file[0] << " By: ";
    std::cout << fields[1] << " " << fields[0] << "\n";
  }
  BinTree<Question> catQuestions[6]; // array of Binary Tree objects - each
                                     // index is a separate tree
  printHTMLindex(catTitles);         // generate the index.htm - main board page
  for (int i = 1; i <= catTitles.getSize(); i++) {
    catQuestions[i - 1].readFile(
        "categories/" + catTitles.at(i).lower() + ".csv"); // read all questions and store in the binary tree
    printHTMLpages(catQuestions[i - 1], i); // generate each cat#_#00.htm - a separate html page for
                       // each question
  }
}
