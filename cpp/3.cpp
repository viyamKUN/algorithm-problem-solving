//
//  3.cpp
//  LeetCode
//
//  Created by 윤하연 on 2021/03/25.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> alphabetCounter;
        int max = 0;
        int minIndex = 0;
        
        for (int i = 0; i < s.size(); i++) {
            auto result = alphabetCounter.find(s[i]);
            
            if (result == alphabetCounter.end()) {
                alphabetCounter[s[i]] = i;
                continue;
            }

            for (int j = minIndex; j <= result->second; j++) {
                auto temp = alphabetCounter.find(s[j]);

                if (temp != alphabetCounter.end()) {
                    int currentCount = i - temp->second;
                    max = std::max(max, currentCount);
                }
            }
            minIndex = std::max(result->second, minIndex);
            result->second = i;
            alphabetCounter[s[i]] = i;
        }

        for (auto temp : alphabetCounter) {
            if(temp.second < minIndex)
                continue;

            int currentCount = (int)s.size() - temp.second;
            max = std::max(max, currentCount);
        }

        return max;
    }
};


int main(int argc, const char * argv[]) {
    Solution solution;
    std::string s[] = {"abcabcbb", "bbbbb","pwwkew", "",  "a", "au", "dvdf", "asdhsjfa", "uqinntq","ohvhjdml"};
    int answer[] = {3,1,3,0,1,2,3,6,4,6};
    for(int i = 0 ; i < sizeof(s) / sizeof(s[0]); i++) {
        int result = solution.lengthOfLongestSubstring(s[i]);
        if(result != answer[i]) {
            std::cout <<s[i] << " Answer: " << std::to_string(answer[i]) << "  My Answer: " << std::to_string(result) << std::endl;
        }
    }
    return 0;
}
