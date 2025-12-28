//
// Created by boris on 12/28/25.
//

#include <vector>
#include <unordered_map>

class MaxFruitCountOf2Types {
public:
    static int findLength(const std::vector<char>& arr) {
        int maxLength = 0;
        const int type = 2;

        std::unordered_map<char, int> fruitMap;
        int start = 0;
        for (int end = 0; end < arr.size(); end++) {
            fruitMap[arr[end]] += 1;
            if (fruitMap.size() <= type) {
                maxLength = std::max(maxLength, end - start + 1);
            }
            while (fruitMap.size() > type) {
                fruitMap[arr[start]] -= 1;
                if (fruitMap[arr[start]] == 0) {
                    fruitMap.erase(arr[start]);
                }
                start++;
            }
        }

        return maxLength;
    }
};

