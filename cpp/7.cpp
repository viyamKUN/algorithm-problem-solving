//
//  7.cpp
//  LeetCode
//
//  Created by 윤하연 on 2021/03/30.
//

#include <algorithm>
#include <iostream>

class Solution {
public:
    int reverse(int x) {
        int imax = std::numeric_limits<int>::max(); // 2147483647
        
        if (std::numeric_limits<int>::min() >= x) return 0;
        
        int result = 0, sign = 1;
        
        if (x < 0) sign = -1;
        x *= sign;
        
        int checkNumber = imax, firstNumber = x % 10;
        
        while (x > 0) {
            if(checkNumber == 2) {
                if (firstNumber > checkNumber)
                    return 0;
                else if (firstNumber == checkNumber) {
                    if((result - imax / 10) * 10 + 1 - imax % 10 > 0)
                        return 0;
                }
            }
            result = result * 10 + x % 10;
            x /= 10;
            checkNumber /= 10;
        }
        return result * sign;
    }
};

//int main(int argc, const char * argv[]) {
//    Solution solution;
//    int input[] = {123,-123,120,0,1534236469,-2147483412, 2147483647, -2147483648, 563847412,-1563847412};
//    int answer[] = {321,-321,21,0,0,-2143847412,0,0, 214748365,0};
//    for (int i = 0 ; i < sizeof(input) / sizeof(input[0]); i++) {
//        int result = solution.reverse(input[i]);
//        if (result != answer[i]) {
//            std::cout << std::to_string(i) << " Answer: " << answer[i] << "  My Answer: " << result << std::endl;
//        }
//    }
//    return 0;
//}
