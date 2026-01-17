using namespace std;

#include <vector>

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int once = 0;
        int twice = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            once = (once ^ nums[i]) & (~twice);
            twice = (twice ^ nums[i]) & (~once);
        }
        return once;
    }
};