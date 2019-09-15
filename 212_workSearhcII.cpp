#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Trie {
public:
    static const int TABLE_SIZE = 26;

    Trie() : isEndOfWord(false), children({TABLE_SIZE, NULL}) {
    }

    ~Trie() {
        for (auto i : children) {
            delete i;
        }
    }

    void insert(std::string word) {
        Trie *node = this;

        for (auto c : word) {
            if (node) {
                if (!node->children[c - 'a']) {
                    node->children[c - 'a'] = new Trie();
                }
                node = node->children[c - 'a'];
            }
        }

        node->isEndOfWord = true;
    }
public:
    bool isEndOfWord;
    std::vector<Trie*> children;
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void DFSHelper(vector<string> &result, vector<vector<char>> &board, int row, int col, Trie *trie, string &crtStr)
{
    if ( row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) {
        return;
    }

    if ('.' == board[row][col]) {
        return;
    }

    int index = board[row][col] - 'a';

    if (NULL == trie->children[index]) {
        return;
    }

    char c = board[row][col];
    board[row][col] = '.';

    crtStr.push_back(c);

    if (trie->children[index]->isEndOfWord) {
        if (result.end() == find(result.begin(), result.end(), crtStr)) {
            result.push_back(crtStr);
        }
    }

    for (int k = 0; k != 4; ++k) {
        DFSHelper(result, board, row + dy[k], col + dx[k], trie->children[index], crtStr);
    }

    crtStr.pop_back();

    board[row][col] = c;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
{
    if (board.empty() || words.empty()) {
        return {};
    }

    if (board[0].empty()) {
        return {};
    }

    int row = board.size();
    int col = board[0].size();

    vector<string> result;
    Trie *root = new Trie();

    for (auto word : words) {
        root->insert(word);
    }

    string str;

    for (int i = 0; i != row; ++i) {
        for (int j = 0; j != col; ++j) {
            DFSHelper(result, board, i, j, root, str);
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };

    vector<string> words = {"oath", "pea", "eat", "rain"};
    
    auto ret = findWords(board, words);

    for (auto s : ret) {
        cout << s << endl;
    }
}
