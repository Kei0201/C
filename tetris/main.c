#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define BLOCK_HEIGHT 4
#define BLOCK_WIDTH  4

#define BOARD_HEIGHT 23
#define BOARD_WIDTH  18

#define BOARD_WALL 9
#define BOARD_BLOCK 1

void initVar(int stage[BOARD_HEIGHT][BOARD_WIDTH], int *p_block_pos_x, int *p_block_pos_y);
void makeBlock(int block[BLOCK_HEIGHT][BLOCK_WIDTH], int blocks[BLOCK_HEIGHT][BLOCK_WIDTH]);
void makeBoard(int board[BOARD_HEIGHT][BOARD_WIDTH], int block[BLOCK_HEIGHT][BLOCK_WIDTH], int stage[BOARD_HEIGHT][BOARD_WIDTH], int block_pos_x, int block_pos_y);

int main() {
    int block[BLOCK_HEIGHT][BLOCK_WIDTH];
    int stage[BOARD_HEIGHT][BOARD_WIDTH];
    int board[BOARD_HEIGHT][BOARD_WIDTH];

    // 四角いブロック
    int blocks[BLOCK_HEIGHT][BLOCK_WIDTH] = {
        {0,0,0,0},
        {0,1,1,0},
        {0,1,1,0},
        {0,0,0,0},
    };

    int block_pos_x, block_pos_y;
    int *p_block_pos_x, *p_block_pos_y;

    p_block_pos_x = &block_pos_x;
    p_block_pos_y = &block_pos_y;

    initVar(stage, p_block_pos_x, p_block_pos_y);
    makeBlock(block, blocks);
    makeBoard(board, block, stage, block_pos_x, block_pos_y);
    drawBoard(board);

    return 0;
}

void initVar(int stage[BOARD_HEIGHT][BOARD_WIDTH], int *p_block_pos_x, int *p_block_pos_y) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            // ボード上の壁作成
            stage[i][0] =  BOARD_WALL;
            stage[i][1] =  BOARD_WALL;
            stage[i][2] =  BOARD_WALL;
            stage[20][j] = BOARD_WALL;
            stage[21][j] = BOARD_WALL;
            stage[22][j] = BOARD_WALL;
            stage[i][15] = BOARD_WALL;
            stage[i][16] = BOARD_WALL;
            stage[i][17] = BOARD_WALL;
        }
    }
    *p_block_pos_x = 7;
    *p_block_pos_y = 0;
}

void makeBlock(int block[BLOCK_HEIGHT][BLOCK_WIDTH], int blocks[BLOCK_HEIGHT][BLOCK_WIDTH]) {
        for (int i = 0; i < BLOCK_HEIGHT; i++) {
            for (int j = 0; j < BLOCK_WIDTH; j++) {
                block[i][j] = blocks[i][j];
            }
        }
}

void makeBoard(int board[BOARD_HEIGHT][BOARD_WIDTH], int block[BLOCK_HEIGHT][BLOCK_WIDTH], int stage[BOARD_HEIGHT][BOARD_WIDTH], int block_pos_x, int block_pos_y) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = stage[i][j];
        }
    }
    for (int y = 0; y < BLOCK_HEIGHT; y++) {
        for (int x = 0; x < BLOCK_WIDTH; x++) {
            board[block_pos_y + y][block_pos_x + x] += block[y][x];
        }
    }
}

void drawBoard(int board[BOARD_HEIGHT][BOARD_WIDTH]) {
    system("cls");

    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (board[i][j] == BOARD_WALL) printf("■");
            else if (board[i][j] == BOARD_BLOCK) printf("□");
            else printf(" ");
        }
        printf("\n");
    }
}