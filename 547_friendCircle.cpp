#include <iostream>
#include <vector>

using namespace std;

void dfs(int person, vector<bool>& visited, vector<vector<int>>& M)
{
    for (int j = 0; j != M.size(); ++j) {
        if (M[person][j] == 1 && !visited[j]) {
            visited[j] = true;
            dfs(j, visited, M);
        }
    }
}

int findRoot(int x, vector<int>& vec)
{
    return x == vec[x] ? x : findRoot(vec[x], vec);
}

int findCircleNum(vector<vector<int>>& M) {
    int m = M.size();
    if (m < 1) return 0;

    // dfs
    // vector<bool> visited(m, false);

    // int count = 0;

    // for (int i = 0; i != m; ++i) {
    //     if (!visited[i]) {
    //         dfs(i, visited, M);
    //         count++;
    //     }
    // }

    // Union & Find uf;
    vector<int> vec(m, 0);
    for (int i = 0; i != m; ++i) {
        vec[i] = i;
    }

    int count = m;

    for (int i = 0; i != m; ++i) {
        for (int j = i + 1; j != m; ++j) {
            if (M[i][j] == 1) {
                int rootA = findRoot(i, vec);
                int rootB = findRoot(j, vec);
                if (rootA != rootB) {
                    count--;
                    vec[rootB] = rootA;
                }
            }
        }
    }

    return count;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> M = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    cout << "result = " << findCircleNum(M) << endl;

    return 0;
}
