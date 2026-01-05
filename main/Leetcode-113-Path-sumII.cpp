using namespace std;

#include <vector>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> result;
        vector<int> path;

        findPathRecursive(root, targetSum, path, result);

        return result;
    }

private:
    static void findPathRecursive(TreeNode *node, int target, vector<int> &path, vector<vector<int>> &result)
    {
        if (node == nullptr)
        {
            return;
        }
        path.push_back(node->val);
        if (node->val == target && node->right == nullptr && node->left == nullptr)
        {
            result.push_back(path);
        }
        else
        {
            findPathRecursive(node->left, target - node->val, path, result);
            findPathRecursive(node->right, target - node->val, path, result);
        }
        path.pop_back();
    }
};