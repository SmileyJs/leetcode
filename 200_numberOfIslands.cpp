#include <iostream>
#include <vector>

using namespace std;

class UnionFind
{
public:
    void initialise(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        count = 0;
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                if ('1' == grid[i][j]) {
                    count++;
                    roots.push_back(i * n + j);
                }
                else {
                    roots.push_back(0);
                }
            }
        }
    }

    int findRoot(int i) {
        int root = i;
        while (root != roots[root]) {
            root = roots[root];
        }

        // Optimise: path compress
        while (root != roots[i]) {
            int tmp = roots[i];
            roots[i] = root;
            i = tmp;
        }

        return root;
    }

    bool isConnected(int p, int q) {
        return findRoot(p) == findRoot(q);
    }

    void unionRoot(int p, int q) {
        int rootP = findRoot(p);
        int rootQ = findRoot(q);
        if (rootP == rootQ)
            return;
        roots[rootP] = rootQ;
        count--;
    }

    int getCount() {
        return count;
    }

private:
    vector<int> roots;
    int count;
};

vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

bool isValid(vector<vector<char>>& grid, int row, int col)
{
    return (row >=0 && row < grid.size() && col >= 0 && col < grid[0].size() && '1' == grid[row][col]);
}

int infect(vector<vector<char>>& grid, int row, int col)
{
    if (isValid(grid, row, col)) {
        grid[row][col] = '0';

        for (int i = 0; i != 4; ++i) {
            infect(grid, row + dx[i], col + dy[i]);
        }

        return 1;
    }

    return 0;
}

int numIslands(vector<vector<char>>& grid) {
    // floodFill
    // int count = 0;
    // for (int i = 0; i != grid.size(); ++i) {
    //     for(int j = 0; j != grid[i].size(); ++j) {
    //         count += infect(grid, i, j);
    //     }
    // }

    int m = grid.size();
    if (m < 1) return 0;
    int n = grid[0].size();
    if (n < 1) return 0;

    UnionFind uf;
    uf.initialise(grid);

    for (int i = 0; i != m; ++i) {
        for (int j = 0; j != n; ++j) {
            if (grid[i][j] == '0') {
                continue;
            }
            for (int k = 0; k !=4; ++k) {
                int newX = i + dx[k];
                int newY = j + dy[k];
                if (newX >=0 && newY >= 0 && newX < m && newY < n && grid[newX][newY] == '1') {
                    uf.unionRoot(i * n + j, newX * n + newY);
                }
            }
        }
    }

    return uf.getCount();
}

int main(int argc, char const *argv[])
{
    vector<vector<char>> grid = {
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '1', '0'}
    };

    int ret = numIslands(grid);

    cout << "result = " << ret << endl;

    return 0;
}
