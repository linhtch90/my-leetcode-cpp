using namespace std;

#include <vector>

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int i = 0;

        while (i < nums.size())
        {
            int correctIndex = nums[i] - 1;

            if (nums[i] != nums[correctIndex])
            {
                int temp = nums[i];
                nums[i] = nums[correctIndex];
                nums[correctIndex] = temp;
            }
            else
            {
                i++;
            }
        }

        vector<int> result;

        for (i = 0; i < nums.size(); i++)
        {
            if (i != nums[i] - 1)
            {
                result.push_back(i + 1);
            }
        }

        return result;
    }
};