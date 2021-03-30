//
//  9.cpp
//  LeetCode
//
//  Created by 윤하연 on 2021/03/31.
//

#include <iostream>
#include <algorithm>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        if (x % 10 == 0) return false;
        int n = x;
        int count = 0;
        while (n > 0) {
            n /= 10;
            count++;
        }
        int temp = 0;
        for (int i = 0; i < count/2; i++) {
            temp = temp * 10 + x % 10;
            x /= 10;
        }
        if (count % 2 == 1)
            x /= 10;
        return x == temp;
    }
};

int main() {
    Solution solution;
    int input[] = {121, -121, 10, -101, 1, 313,1122};
    bool answer[] = {true, false, false, false, true, true,false};
    for (int i = 0; i < sizeof(input)/sizeof(input[0]); i++) {
        bool result = solution.isPalindrome(input[i]);
        if (result != answer[i]) {
            std::cout << std::to_string(i) << " Answer: " << answer[i] << "  My Answer: " << result << std::endl;
        }
    }
    return 0;
}
