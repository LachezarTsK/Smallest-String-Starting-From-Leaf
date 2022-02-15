
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    
public:
    
    static const string ASCII_GREATER_THAN_SMALL_CASE_Z = "~";

    string smallestFromLeaf(TreeNode* root) {
        return findPath("", root);
    }

    string findPath(string path, TreeNode* node) {
        if (node == nullptr) {
            return ASCII_GREATER_THAN_SMALL_CASE_Z;
        }

        path = string(1, ('a' + node->val)).append(path);
        if (node->left == nullptr && node->right == nullptr) {
            return path;
        }
        string left = findPath(path, node->left);
        string right = findPath(path, node->right);

        return left.compare(right) < 0 ? left : right;
    }
};
