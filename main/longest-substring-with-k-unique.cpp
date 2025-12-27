#include <string>
#include <unordered_map>

class LongestSubstringWithKUnique {
public:
    static int findLength(const std::string& str, int k) {
        int maxLength = 0;

        int start = 0;
        std::unordered_map<char, int> uniqueMap;
        for (int end = 0; end < str.length(); end++) {
            if (uniqueMap.size() < k || (uniqueMap.size() == k && uniqueMap.count(str[end]))) {
                uniqueMap[str[end]] += 1;
                maxLength = std::max(maxLength, end - start + 1);
            }
            if (uniqueMap.size() == k && !uniqueMap.count(str[end])) {
                while (uniqueMap[str[start]] > 0) {
                    uniqueMap[str[start]] -= 1;
                    if (uniqueMap[str[start]] == 0) {
                        uniqueMap.erase(str[start]);
                        uniqueMap[str[end]] += 1;
                        start++;
                        maxLength = std::max(maxLength, end - start + 1);
                        break;
                    }
                    start++;
                }
            }
        }

        if (uniqueMap.size() < k) {
            return -1;
        }

        return maxLength;
    }
};