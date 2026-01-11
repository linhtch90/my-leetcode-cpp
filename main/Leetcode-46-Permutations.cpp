using namespace std;

#include <vector>
#include <queue>

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        queue<vector<int>> current;
        current.push(vector<int>());
        for (int i = 0; i < nums.size(); i++)
        {
            int currentSize = current.size();
            for (int j = 0; j < currentSize; j++)
            {
                vector<int> currentPermu = current.front();
                current.pop();
                for (int k = 0; k <= currentPermu.size(); k++)
                {
                    vector<int> processing(currentPermu);
                    processing.insert(processing.begin() + k, nums[i]);
                    if (processing.size() == nums.size())
                    {
                        result.push_back(processing);
                    }
                    else
                    {
                        current.push(processing);
                    }
                }
            }
        }
        return result;
    }
};