#include <iostream>
#include <vector>

using namespace std;

bool isValidBlock(char item, int row, int col, vector<vector<char>>& board)
{
    int size = board.size();

    cout << "item = " << item << " row = " << row << " col = " << col << endl;

    // is valid row
    for (int i = 0; i != size; ++i) {
        if (i == col) {
            continue;
        }
        if (item == board[row][i]) {
            cout << "row invalid" << endl;
            return false;
        }
    }

    // is valid col
    for (int i = 0; i != size; ++i) {
        if (i == row) {
            continue;
        }
        if (item == board[i][col]) {
            cout << "col invalid" << endl; 
            return false;
        }
    }

    // is valid block
    for (int i = 0; i != size; ++i) {
        if (i == (row % 3 * 3 + col % 3)) {
            continue;
        }
        if (item == board[row/3*3 + i/3][col/3*3 + i%3]) {
            cout << "invalid block" << endl;
            return false;
        }
    }

    return true;
}

bool helper(int row, int col, vector<vector<char>>& board)
{
    if (col > 8) {
        col = 0;
        ++row;
    }

    if (row > 8) {
        return true;
    }

    cout << "row = " << row <<  " col " << col << endl;

    if (board[row][col] == '.') {
        for (char i = '1'; i <= '9'; ++i) {
            if (isValidBlock(i, row, col, board)) {
                board[row][col] = i;
                if (helper(row, col + 1, board)) {
                    return true;
                }
            }
        }
        board[row][col] = '.';
        return false;
    }
    else {
        return helper(row, col + 1, board);
    }
}

void solveSudoku(vector<vector<char>>& board)
{
    // TODO:
    // optimise:
    // 1) 预处理, 每个格子的可选数
    // 2) 从选项少的开始算
    // 3) 可选数循环

    helper(0, 0, board);
}

int main(int argc, char const *argv[])
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    solveSudoku(board);

    for (vector<char> vec : board) {
        for (char c : vec) {
            cout << c <<  " ";
        }
        cout << endl;
    }

    return 0;
}
