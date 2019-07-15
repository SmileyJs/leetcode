#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;

    TreeNode(int arg) : left(NULL), right(NULL), val(arg) {}
};

TreeNode *pre = NULL;

bool helper(TreeNode *root, TreeNode *min, TreeNode *max)
{
    if (NULL == root) return true;

    if (min && min->val >= root->val) return false;
    if (max && max->val <= root->val) return false;

    return helper(root->left, min, root) && helper(root->right, root, max);
}

bool isValidBST(TreeNode *root)
{
    // ordered array
    // stack<int> *container = new stack<int>();

    // insertElement(root, container);

    // if (2 > container->size()) return true;

    // int tmp = container->top();
    // container->pop();

    // while (0 != container->size()) {
    //     if (tmp > container->top()) {
    //         return false;
    //     }
    //     tmp = container->top();
    //     container->pop();
    // }

    // recursive
    if (NULL == root) return true;

    if (!isValidBST(root->left)) return false;

    if (pre && pre->val >= root->val) return false;

    pre = root;

    if (!isValidBST(root->right)) return false;

    // return true;

    // return helper(root, NULL, NULL);

    return true;
}

void showTree(TreeNode *root) {
    if (root) {
        showTree(root->left);
        std::cout << root->val;
        showTree(root->right);
    }
}

int
main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    showTree(root);

    std::cout << std::endl;

    cout << isValidBST(root) << endl;
    
    return 0;
}
  