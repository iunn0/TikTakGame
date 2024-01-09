#pragma once
#include <vector>
#include <iostream>

class Board
{
public:
    int count = 0;
    bool rightPos = false;
    
    std::vector<std::string> board = { " ", "|", " ", "|", " ", "\n-----\n", " ", "|", " ", "|", " ",
        "\n-----\n", " ", "|", " ", "|", " " };
    void displayBoard();
    std::vector<int> alreadyPicked;

    bool pickChecker(int pick, std::vector<int>& picked);
    bool winChecker();

    void xses(int p, std::vector<std::string>* map);
    void circles(int p, std::vector<std::string>* map);

};

