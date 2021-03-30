//
//  6.cpp
//  LeetCode
//  ZigZag Conversion
//  Created by 윤하연 on 2021/03/31.
//

#include <algorithm>
#include <iostream>
#include <string>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1) return s;
        
        std::string result = "";
        result.reserve(s.size());
        
        int patternNum = 0;
        int interval[2] = {0,0};
        
        for (int i = 0; i < numRows; i++) {
            interval[0] = (numRows - 1) * 2 - 2 * i;
            interval[1] = 2 * i;
            
            if (interval[1] == 0) interval[1] = interval[0];
            if (interval[0] == 0) interval[0] = interval[1];
            
            int j = 0;
            patternNum = i;
            while (patternNum < s.size()) {
                result += s[patternNum];
                patternNum += interval[j % 2];
                j++;
            }
        }
        return result;
    }
};

//int main(int argc, const char * argv[]) {
//    Solution solution;
//    std::string inputString[] = {"PAYPALISHIRING","PAYPALISHIRING","A", "A"};
//    int inputInt[] = {3,4,1,2};
//    std::string answer[] = {"PAHNAPLSIIGYIR","PINALSIGYAHRPI","A","A"};
//    for (int i = 0 ; i < sizeof(inputString) / sizeof(inputString[0]); i++) {
//        std::string result = solution.convert(inputString[i], inputInt[i]);
//        if (result != answer[i]) {
//            std::cout << std::to_string(i) << " Answer: " << answer[i] << "  My Answer: " << result << std::endl;
//        }
//    }
//    return 0;
//}
