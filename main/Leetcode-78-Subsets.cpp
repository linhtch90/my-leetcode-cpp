using namespace std;

#include <vector>

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> subsets;

        subsets.push_back(vector<int>());

        for (int i = 0; i < nums.size(); i++)
        {
            vector<vector<int>> copiedSubsets(subsets);
            for (int j = 0; j < copiedSubsets.size(); j++)
            {
                copiedSubsets[j].push_back(nums[i]);
            }
            subsets.insert(subsets.end(), make_move_iterator(copiedSubsets.begin()), make_move_iterator(copiedSubsets.end()));
        }

        return subsets;
    }
};