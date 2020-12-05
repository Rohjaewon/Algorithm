#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* mergeTree(TreeNode* t1, TreeNode* t2) {
    TreeNode* temp = new TreeNode();
    if (t1 == nullptr) {
        temp = t2;
    } else if (t2 == nullptr) {
        temp = t1;
    } else {
        temp->val = t1->val + t2->val;
        temp->left = mergeTree(t1->left, t2->left);
        temp->right = mergeTree(t1->right, t2->right);
    }
    return temp;
}

