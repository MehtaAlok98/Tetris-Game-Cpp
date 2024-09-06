#include <gtest/gtest.h>
#include "block.h"
#include "blocks.h"
#include "grid.h"

// Test the Block class
TEST(BlockTest, CanSpawnTest) {
    Grid grid;
    Blocks::IBlock block(grid);
    block.ResetBlock();
    EXPECT_TRUE(block.CanSpawn());
}

TEST(BlockTest, CanRotateTest) {
    Grid grid;
    Blocks::IBlock block(grid);
    block.ResetBlock();
    EXPECT_TRUE(block.CanRotate());
}

TEST(BlockTest, MoveBlockTest) {
    Grid grid;
    Blocks::IBlock block(grid);
    block.ResetBlock();
    int initialX = block.x_block_pos;
    int initialY = block.y_block_pos;
    block.MoveBlock(1, 0);
    EXPECT_EQ(block.x_block_pos, initialX + 1);
    EXPECT_EQ(block.y_block_pos, initialY);
}
