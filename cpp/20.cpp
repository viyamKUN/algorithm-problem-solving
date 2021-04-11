//
//  20.cpp
//  LeetCode
//
//  Created by 윤하연 on 2021/04/12.
//
//  20. Valid Parentheses
//
//  Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//  An input string is valid if:
//
//  Open brackets must be closed by the same type of brackets.
//  Open brackets must be closed in the correct order.


#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s) {
        if (s.size() == 1) return false;
        
        std::string waitLine;
        std::unordered_map<char, char> pair = {{'(',')'},{'{','}'},{'[',']'}};
        
        if (pair.find(s[s.length()-1]) != pair.end()) return false;
        
        for (int i = 0; i < s.size(); i++) {
            auto temp = pair.find(s[i]);
            if (temp != pair.end()) {
                waitLine += temp->second;
                continue;
            }
            if (waitLine.size() == 0) return false;
            if (waitLine.back() != s[i]) return false;
            
            waitLine.pop_back();
        }
        return waitLine.size() == 0;
    }
};

//int main(int argc, const char * argv[]) {
//    Solution solution;
//    std::string input[] = {"()","()[]{}","(]","([)]","{[]}","["};
//    bool answer[] = {true,true,false,false,true,false};
//    for (int i = 0 ; i < sizeof(input) / sizeof(input[0]); i++) {
//        bool result = solution.isValid(input[i]);
//        if (result != answer[i]) {
//            std::cout << std::to_string(i) << " Answer: " << answer[i] << "  My Answer: " << result << std::endl;
//        }
//    }
//    return 0;
//}
