using namespace std;

#include <vector>

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] < nums.size() && nums[i] != nums[nums[i]])
            {
                int index = nums[i];
                int temp = nums[i];
                nums[i] = nums[index];
                nums[index] = temp;
            }
            else
            {
                i++;
            }
        }

        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] != j)
            {
                return j;
            }
        }
        return nums.size();
    }
};