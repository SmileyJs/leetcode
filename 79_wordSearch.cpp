#include <iostream>
#include <vector>

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool searchHelper(string &word, int index, vector<vector<char>> &board, int row, int col)
{
    if (index == word.size()) {
        return true;
    }

    if ( row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) {
        return false;
    }

    if (word[index] != board[row][col]) {
        return false;
    }

    board[row][col] = '.';

    for (int k = 0; k != 4; ++k) {
        if (searchHelper(word, index+1, board, row + dy[k], col + dx[k])) {
            board[row][col] = word[index];
            return true;
        }
    }

    board[row][col] = word[index];

    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    if (board.empty()) {
        return false;
    }

    int row = board.size();

    if (board[0].empty()) {
        return false;
    }

    int col = board[0].size();

    for (int i = 0; i != row; ++i) {
        for (int j = 0; j != col; ++j) {
            if (word[0] == board[i][j] && searchHelper(word, 0, board, i, j)) {
                return true;
            }
        }
    }
    
    return false;
}

int main(int argc, char const *argv[])
{
    vector<vector<char>> board = {
        {'C', 'A', 'A'},
        {'A', 'A', 'A'},
        {'B', 'C', 'D'}
    };

    cout << exist(board, "AAB") << endl;

    return 0;
}
