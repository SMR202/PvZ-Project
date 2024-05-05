#pragma once
#include "Scoreboard.h"
#include "Levels.h"
#include "Grid.h"
#include "State.h"

class Game {
protected:
    Scoreboard scoreboard;
    Levels levels;
    Grid grid;
    State* state;

public:
    Game();

    void startGame();
    Levels& getLevel();
    void setLevel(Levels& level);
    void setScoreboard(Scoreboard& scoreboard);
    Scoreboard getScoreboard();
    Grid& getGrid();
};

