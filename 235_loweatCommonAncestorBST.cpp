#include <iostream>

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    int val;

    TreeNode(int arg) : left(NULL), right(NULL), val(arg) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (NULL == root || root == p || root == q) return root;

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left && right) return root;
    if (NULL == left && NULL == right) return NULL;
    return NULL == left ? right : left;
}

void showTree(TreeNode *root) {
    if (root) {
        showTree(root->left);
        std::cout << root->val;
        showTree(root->right);
    }
}

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    showTree(root);
    std::cout << std::endl;

    TreeNode *ret = lowestCommonAncestor(root, root->left, root->right);

    if (ret) {
        std::cout << ret->val << std::endl;
    }
    else {
        std::cout << "ret is null" << std::endl;
    }

    return 0;
}