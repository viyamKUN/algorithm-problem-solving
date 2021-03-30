//
//  5.cpp
//  LeetCode
//  5. Longest Palindromic Substring
//  Given a string s, return the longest palindromic substring in s.
//  Created by 윤하연 on 2021/03/29.
//

#include <algorithm>
#include <iostream>
#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        std::string temp = s.substr(0,1), result = temp;
        int postPoint = 0, lastPoint = 0;
        
        std::cout << s << std::endl;
        for (int i = 0; i < s.size(); i++) {
            postPoint = i;
            lastPoint = i+1;
            
            int j = 0;
            while (true) {
                if (postPoint-j < 0 || lastPoint+j >= s.size()) {
                    temp = s.substr(postPoint-j+1, lastPoint-postPoint+j*2-1);
                    break;
                }
                if (s[postPoint-j] != s[lastPoint+j]) {
                    if (s[postPoint-j] != s[lastPoint+j-1]) {
                        temp = s.substr(postPoint-j+1, lastPoint-postPoint+j*2-1);
                        break;
                    }
                    lastPoint -= 1;
                }
                j++;
            }
            std::cout << i << ": " << temp << std::endl;
            if (temp.size() > result.size())
                result = temp;
        }
        return result;
    }
};

//int main(int argc, const char * argv[]) {
//    Solution solution;
//    std::string input[] = {"babad","cbbd","a","ac","aaaa","ccc","bb","aacabdkacaa"};
//    std::string answer[] = {"bab", "bb", "a", "a","aaaa","ccc","bb","aca"};
//    for (int i = 0 ; i < sizeof(input) / sizeof(input[0]); i++) {
//        std::string result = solution.longestPalindrome(input[i]);
//        if (result != answer[i]) {
//            std::cout << std::to_string(i) << " Answer: " << answer[i] << "  My Answer: " << result << std::endl;
//        }
//    }
//    return 0;
//}
