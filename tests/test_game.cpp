#include <gtest/gtest.h>
#include "game.h"

// Test the Game class
TEST(GameTest, PointsInitializationTest) {
    Game game;
    EXPECT_EQ(Game::points, 0);
}

TEST(GameTest, PointsIncrementTest) {
    Game game;
    Game::points += 100;
    EXPECT_EQ(Game::points, 100);
}

TEST(GameTest, GameOverTest) {
    Game game;
    game.status = game.GAME_OVER;
    EXPECT_EQ(game.status, game.GAME_OVER);
}
