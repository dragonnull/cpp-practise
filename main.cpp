#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>

using std::min;
using std::set;
using std::stack;
using std::string;
using std::stringstream;
using std::vector;
using std::unordered_map;
using std::to_string;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        if (root == nullptr) return nullptr;
        if (root->val <= p->val) return inorderSuccessor(root->right, p);
        TreeNode *ans = inorderSuccessor(root->left, p);
        return ans == nullptr ? root : ans;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left && right)
            return root;
        return left ? left : right;
    }

};


int main() {

}