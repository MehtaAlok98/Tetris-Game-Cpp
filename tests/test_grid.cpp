#include <gtest/gtest.h>
#include "grid.h"
#include "block.h"
#include "blocks.h"

// Test the Grid class
TEST(GridTest, InitializationTest) {
    Grid grid;
    for (int row = 0; row < grid.getRows(); row++) {
        for (int col = 0; col < grid.getCols(); col++) {
            EXPECT_EQ(grid.grid[row][col], 0);
        }
    }
}

TEST(GridTest, LockBlockTest) {
    Grid grid;
    Blocks::OBlock block(grid);
    block.ResetBlock();
    grid.LockBlock(block, block.x_block_pos, block.y_block_pos);
    for (int row = 0; row < (int)block.shape.size(); row++) {
        for (int col = 0; col < (int)block.shape[row].size(); col++) {
            if (block.shape[row][col] == 1) {
                EXPECT_EQ(grid.grid[block.y_block_pos + row][block.x_block_pos + col], block.blockColor);
            }
        }
    }
}

TEST(GridTest, CheckComboRowsTest) {
    Grid grid;
    // Fill a row
    for (int col = 0; col < grid.getCols(); col++) {
        grid.grid[grid.getRows() - 1][col] = 1;
    }
    grid.CheckComboRows();
    // After clearing, the bottom row should be zeros
    for (int col = 0; col < grid.getCols(); col++) {
        EXPECT_EQ(grid.grid[grid.getRows() - 1][col], 0);
    }
}
