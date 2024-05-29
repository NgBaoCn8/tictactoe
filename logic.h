#ifndef _LOGIC__H
#define _LOGIC__H

#define BOARD_SIZE 3
#define EMPTY_CELL ' '
#define O_CELL 'o'
#define X_CELL 'x'

struct Tictactoe {
    char board[BOARD_SIZE][BOARD_SIZE];
    char nextMove = O_CELL;

    void init() {
        for (int i = 0; i < BOARD_SIZE; i++)
            for (int j = 0; j < BOARD_SIZE; j++) board[i][j] = EMPTY_CELL;
    }
    void move(int row, int column) {
        if (row >= 0 && row < BOARD_SIZE && column >= 0 && column < BOARD_SIZE)
        {
            if(board[row][column]==EMPTY_CELL) {board[row][column] = nextMove;
            nextMove = (nextMove == O_CELL) ? X_CELL : O_CELL;}
        }
    }
    bool gameover(Tictactoe&game)
    {
        for(int i=0;i<3;i++)
        {
            if(board[i][0]!=EMPTY_CELL&&board[i][0]==board[i][1]&&board[i][1]==board[i][2]) return 0;
        }
         for(int i=0;i<3;i++)
        {
            if(board[0][i]!=EMPTY_CELL&&board[0][i]==board[1][i]&&board[1][i]==board[2][i]) return 0;
        }

        if(board[0][0]!=EMPTY_CELL&&board[0][0]==board[1][1]&&board[1][1]==board[2][2]) return 0;
        if(board[2][0]!=EMPTY_CELL&&board[0][2]==board[1][1]&&board[2][0]==board[1][1]) return 0;
        return 1;
    }
};

#endif
