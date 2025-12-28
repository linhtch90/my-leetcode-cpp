//
// Created by boris on 12/28/25.
//

#include <vector>
#include <algorithm>

class TripletSumToZero {
public:
    static std::vector<std::vector<int>> searchTriplet(std::vector<int>& arr) {
        const int finalValue = 0;
        std::vector<std::vector<int>> result;
        std::sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size() - 2; i++) {
            if (i > 0 && arr[i] == arr[i - 1]) {
                continue;
            }

            int subResult = finalValue - arr[i];
            int startIndex = i + 1;
            int endIndex = arr.size() - 1;

            while (startIndex < endIndex) {
                if (arr[startIndex] + arr[endIndex] == subResult) {
                    result.push_back({arr[i], arr[startIndex], arr[endIndex]});
                    startIndex++;
                    endIndex--;
                    while (startIndex < endIndex && arr[startIndex] == arr[startIndex - 1]) {
                        startIndex++;
                    }
                    while (startIndex < endIndex && arr[endIndex] == arr[endIndex + 1]) {
                        endIndex--;
                    }
                }
                if (arr[startIndex] + arr[endIndex] > subResult) {
                    endIndex--;
                }
                if (arr[startIndex] + arr[endIndex] < subResult) {
                    startIndex++;
                }
            }
        }

        return result;
    }
};
