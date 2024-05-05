#include "Game.h"

Game::Game() : scoreboard(), levels(), state(nullptr), grid() {}

void Game::startGame() {
    // Implement logic
}

Levels& Game::getLevel() {
    return levels;
}

void Game::setLevel(Levels& level) {
    levels = level;
}

void Game::setScoreboard(Scoreboard& scoreboard) {
    this->scoreboard = scoreboard;
}

Scoreboard Game::getScoreboard() {
    return scoreboard;
}

Grid& Game::getGrid() {
    return grid;
}
