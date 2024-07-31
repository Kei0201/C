#include <stdio.h>
#include <conio.h>

// ブロックの縦幅・横幅
#define BLOCK_HEIGHT 4
#define BLOCK_WIDTH  4

// ゲームボードの縦幅・横幅
#define BOARD_HEIGHT 23
#define BOARD_WIDTH  18

void initVar(int *stage[], int *p_block_pos_x, int *p_block_pos_y);
void makeBlock(int *block[], int *blocks[]);
void makeBoard(int *block, int *stage[], int *block_pos_x, int *block_pos_y);

int main() {
    // int stop;
    int *block[BLOCK_HEIGHT][BLOCK_WIDTH];
    int stage[BOARD_HEIGHT][BOARD_WIDTH];
    int *board[BOARD_HEIGHT][BOARD_WIDTH];

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

    // int
    initVar(stage, p_block_pos_x, p_block_pos_y);
    printf("%d\n", block_pos_x);
}

void initVar(int *stage[], int *p_block_pos_x, int *p_block_pos_y) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            stage[i][0] =  9;
            stage[i][1] =  9;
            stage[i][2] =  9;
            stage[20][j] = 9;
            stage[21][j] = 9;
            stage[22][j] = 9;
            stage[i][15] = 9;
            stage[i][16] = 9;
            stage[i][17] = 9;
        }
    }
    *p_block_pos_x = 7;
    *p_block_pos_y = 0;
}

// void makeBlock(int *block[], int *blocks[]) {
//         for (int i = 0; i < BLOCK_HEIGHT; i++) {
//             for (int j = 0; j < BLOCK_WIDTH; j++) {
//                 block[j][i] = blocks[j][i];
//             }
//         }
// }

// void makeBoard(int *board[], int *stage[]) {
//     for (int i = 0; i < BOARD_HEIGHT; i++) {
//         for (int j = 0; j < BLOCK_WIDTH; j++) {
//             board[i][j] = stage[i][j];
//         }
//     }

//     for (int i = 0; i < BLOCK_HEIGHT; i++) {
//         for (int j = 0; j < BLOCK_WIDTH; j++) {
//             board[block_pos_y + i][block_pos_x_ + j] += block[i][j];
//         }
//     }
// }