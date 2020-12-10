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
    TreeNode* t3 = new TreeNode();
    if (t1 == nullptr) return t2;
    if (t2 == nullptr) return t1;
    t3->val = t1->val + t2->val;
    t3->left = mergeTree(t1->left, t2->left);
    t3->right = mergeTree(t1->right, t2->right);
    return t3;
}


/*
- 풀이과정
새로운 tree 포인터를 하나 더 만들어서
현재 노드의 값을 더한 후 새로운 포인터에 값을 넣어준 후,
왼쪽 -> 오른쪽 순으로 tree를 병합한다. 이때, 두 트리 중에서
한쪽이 null이면 null이 아닌 트리를 통째로 가리키도록 한다.
*/
