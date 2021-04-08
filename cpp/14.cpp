//
//  14.cpp
//  LeetCode
//
//  Created by 윤하연 on 2021/04/09.
//
//  14. Longest Common Prefix
//
//  Write a function to find the longest common prefix string amongst an array of strings.
//  If there is no common prefix, return an empty string "".

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if(strs.size()==0) return "";
        if(strs.size()==1) return strs[0];
        
        int result = (int) strs[0].size();
        int temp = 0;
        
        for (int i = 1; i < strs.size(); i++) {
            temp = 0;
            for (int j = 0; j < result; j++) {
                if(strs[i-1][j] == strs[i][j])
                    temp ++;
                else break;
            }
            if(result > temp)
                result = temp;
        }
        return strs[0].substr(0, result);
    }
};

int main() {
    Solution solution;
    std::vector<std::string> input[2] = {{"flower","flow","flight"},{"dog","racecar","car"}};
    std::string answer[] = {"fl",""};
    for (int i = 0; i < sizeof(input)/sizeof(input[0]); i++) {
        std::string result = solution.longestCommonPrefix(input[i]);
        if (result != answer[i]) {
            std::cout << std::to_string(i) << " Answer: " << answer[i] << "  My Answer: " << result << std::endl;
        }
    }
    return 0;
}
