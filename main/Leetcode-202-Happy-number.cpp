//
// Created by boris on 12/29/25.
//

class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = squareSum(slow);
            fast = squareSum(squareSum(fast));
        } while (slow != fast);
        return slow == 1;
    }
private:
    int squareSum(int n) {
        int sum = 0;
        while (n != 0) {
            int temp = n % 10;
            sum = sum + temp * temp;
            n = n / 10;
        }
        return sum;
    }
};