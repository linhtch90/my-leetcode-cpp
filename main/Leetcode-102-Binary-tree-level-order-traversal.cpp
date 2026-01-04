using namespace std;

#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;

        if (root == nullptr)
        {
            return result;
        }

        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty())
        {
            int queueSize = nodeQueue.size();
            vector<int> currentLevel;
            for (int i = 0; i < queueSize; i++)
            {
                TreeNode *currentNode = nodeQueue.front();
                nodeQueue.pop();
                currentLevel.push_back(currentNode->val);
                if (currentNode->left != nullptr)
                {
                    nodeQueue.push(currentNode->left);
                }
                if (currentNode->right != nullptr)
                {
                    nodeQueue.push(currentNode->right);
                }
            }
            result.push_back(currentLevel);
        }

        return result;
    }
};