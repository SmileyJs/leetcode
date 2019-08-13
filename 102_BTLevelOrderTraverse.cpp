#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int arg) : val(arg), left(NULL), right(NULL) {}
};

void helper(TreeNode *node, int level, vector<vector<int>> &ret) {
    if (NULL == node)
        return;

    if (ret.size() < level + 1) {
        ret.push_back({});
    }
        
    ret[level].push_back(node->val);

    helper(node->left, level+1, ret);
    helper(node->right, level+1, ret);
}

vector<vector<int>> BTLevelOrderTraverse(TreeNode *node) {
    if (NULL == node) {
        return {};
    }

    vector<vector<int>> ret;

    // bfs
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(node);
    nodeQueue.push(NULL);
    vector<int> levelElement;

    while (!nodeQueue.empty()) {
        TreeNode *tmp = nodeQueue.front();
        nodeQueue.pop();

        if (NULL == tmp) {
            ret.push_back(levelElement);
            levelElement.resize(0);
            if (!nodeQueue.empty()) {
                nodeQueue.push(NULL);
            }
        }
        else {
            levelElement.push_back(tmp->val);

            if (tmp->left) {
                nodeQueue.push(tmp->left);
            }
            if (tmp->right) {
                nodeQueue.push(tmp->right);
            }
        }        
    }
 
    // dfs recursive
    // helper(node, 0, ret);

    return ret;
}


int main(int argc, char const *argv[])
{
    TreeNode a(0);
    a.left = new TreeNode(1);
    a.right = new TreeNode(2);
    a.left->left = new TreeNode(3);
    a.left->right = new TreeNode(4);
    a.left->left->left = new TreeNode(7);
    a.left->left->right = new TreeNode(8);
    a.right->left = new TreeNode(5);
    a.right->right = new TreeNode(6);

    vector<vector<int>> ret = BTLevelOrderTraverse(&a);

    for (auto i : ret) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
