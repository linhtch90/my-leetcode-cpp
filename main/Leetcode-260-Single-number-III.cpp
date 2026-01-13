using namespace std;

#include <vector>

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        long xorResult = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            xorResult ^= nums[i];
        }
        int rightMostBit = xorResult & (-xorResult);
        int num1 = 0;
        int num2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] & rightMostBit)
            {
                num1 ^= nums[i];
            }
            else
            {
                num2 ^= nums[i];
            }
        }
        return {num1, num2};
    }
};