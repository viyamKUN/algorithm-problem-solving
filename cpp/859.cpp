//
//  859.cpp
//  LeetCode 
//
//  Created by 윤하연 on 2021/04/11.
//
//  859. Buddy Strings
//
//  Given two strings a and b, return true if you can swap two letters in a so the result is equal to b, otherwise, return false.
//  Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at a[i] and b[j].
//  For example, swapping at indices 0 and 2 in "abcd" results in "cbad".


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    bool buddyStrings(std::string a, std::string b) {
        if (a.size() != b.size()) return false;
        if (a.size() == 1) return false;
        
        if (a == b) {
            for (int i = 0; i < a.size()-1; i++)
                for (int j = i + 1; j < a.size(); j++)
                    if (a[i] == a[j]) return true;
        }
        
        int differCharNum = -1;
        bool isSwap = false;
        
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[i]) continue;

            if (differCharNum == -1)
                differCharNum = i;
            else {
                if (isSwap) return false;
                if (a[differCharNum] != b[i] || a[i] != b[differCharNum]) return false;
                
                isSwap = true;
                differCharNum = -1;
            }
        }
        return isSwap;
    }
};

//int main() {
//    Solution solution;
//    std::vector<std::string> input[] = {{"ab","ba"},{"ab","ab"},{"aa","aa"},{"aaaaaaabc","aaaaaaacb"},{"abcd","badc"},{"ab","ca"}};
//    bool answer[] = {true, false, true, true, false, false};
//    for (int i = 0; i < sizeof(input)/sizeof(input[0]); i++) {
//        bool result = solution.buddyStrings(input[i][0], input[i][1]);
//        if (result != answer[i]) {
//            std::cout << std::to_string(i) << " Answer: " << answer[i] << "  My Answer: " << result << std::endl;
//        }
//    }
//    return 0;
//}
