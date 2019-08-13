#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(TreeNode *root, int &max, int level)
{
    if (NULL == root) {
        if (max < level) max = level - 1;
        return;
    }

    helper(root->left, max, level + 1);
    helper(root->right, max, level + 1);
}

int maxDepth(TreeNode* root)
{
    using namespace std;

    if (root == NULL) return 0;
    
    // recursion
    // return 1 + std::max(maxDepth(root->left), maxDepth(root->right));

    // dfs
    // int max = 0;
    // helper(root, max, 1);
    // return max;

    // bfs
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    int count = 1;
    int levelSize = 1;

    while (0 != levelSize) {
        TreeNode *tmp = nodeQueue.front();
        nodeQueue.pop();
        levelSize--;

        if (tmp->left) {
            nodeQueue.push(tmp->left);
        }

        if (tmp->right) {
            nodeQueue.push(tmp->right);
        }

        if (0 == levelSize) {
            if (!nodeQueue.empty()) {
                levelSize = nodeQueue.size();
                count++;
            }
            else {
                break;
            }
        }
    }

    return count;
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

    std::cout << "depth: " << maxDepth(&a) << std::endl;

    return 0;
}