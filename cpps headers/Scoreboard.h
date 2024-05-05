#pragma once
#include <string>

class Scoreboard {
protected:
    int score;
    std::string name;

public:
    Scoreboard(int score = 0, std::string name = "player 1");
};

