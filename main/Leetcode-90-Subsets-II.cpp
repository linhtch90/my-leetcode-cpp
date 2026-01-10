using namespace std;

#include <vector>
#include <algorithm>

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> subsetsWithDuplicated;
        subsetsWithDuplicated.push_back(vector<int>());
        vector<vector<int>> previous;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            vector<vector<int>> copy(calculateCopy(i, nums, subsetsWithDuplicated, previous));
            previous.clear();

            for (int j = 0; j < copy.size(); j++)
            {
                copy[j].push_back(nums[i]);
                previous.push_back(copy[j]);
            }
            subsetsWithDuplicated.insert(subsetsWithDuplicated.end(), make_move_iterator(copy.begin()), make_move_iterator(copy.end()));
        }

        return subsetsWithDuplicated;
    }

private:
    vector<vector<int>> calculateCopy(int index, vector<int> &nums, vector<vector<int>> &subsetsWithDuplicated, vector<vector<int>> &previous)
    {
        if (index == 0 || (index > 0 && nums[index] != nums[index - 1]))
        {
            return subsetsWithDuplicated;
        }
        return previous;
    }
};