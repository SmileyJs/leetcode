#include <iostream>
#include <vector>
#include <queue>
#include <limits>

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(TreeNode *root, int& min, int level)
{
    if (NULL == root->left && NULL == root->right) {
        if (min > level) {
            min = level;
            std::cout << root->val << " " << level << std::endl;
        }
    }
    
    if (root->left) {
        helper(root->left, min, level + 1);
    }
    if (root->right) {
        helper(root->right, min, level + 1);
    }
}

int minDepth(TreeNode *root)
{
    if (NULL == root) return 0;
    // dfs
    int min = std::numeric_limits<int>::max();
    helper(root, min, 1);
    return min;

    // bfs
    // using namespace std;

    // queue<TreeNode *> nodeQueue;
    // nodeQueue.push(root);
    // int count = 1;
    // int levelSize = 1;

    // while (0 != levelSize) {
    //     TreeNode *tmp = nodeQueue.front();
    //     nodeQueue.pop();
    //     levelSize--;

    //     if (NULL == tmp->left && NULL == tmp->right) {
    //         return count;
    //     }

    //     if (tmp->left) {
    //         nodeQueue.push(tmp->left);
    //     }

    //     if (tmp->right) {
    //         nodeQueue.push(tmp->right);
    //     }

    //     if (0 == levelSize) {
    //         if (!nodeQueue.empty()) {
    //             levelSize = nodeQueue.size();
    //             count++;
    //         }
    //         else {
    //             break;
    //         }
    //     }
    // }

    // return count;
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

    std::cout << "depth: " << minDepth(&a) << std::endl;

    return 0;
}