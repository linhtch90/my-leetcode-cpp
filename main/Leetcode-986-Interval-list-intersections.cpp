using namespace std;

#include <vector>

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;

        if (firstList.size() == 0 || secondList.size() == 0) {
            return {};
        }
        
        int i = 0;
        int j = 0;
        
        while (i < firstList.size() && j < secondList.size()) {
            vector<int> firstItem = firstList[i];
            vector<int> secondItem = secondList[j];

            if ((firstItem[0] >= secondItem[0] && firstItem[0] <= secondItem[1]) 
            || (secondItem[0] >= firstItem[0] && secondItem[0] <= firstItem[1])) {
                int tempBegin = max(firstItem[0], secondItem[0]);
                int tempEnd = min(firstItem[1], secondItem[1]);
                result.push_back({tempBegin, tempEnd});                
            }

            if (firstItem[1] < secondItem[1]) {
                i++;
            } else {
                j++;
            }
        }

        return result;
    }
};