//
//  28.cpp
//  LeetCode
//
//  Created by 윤하연 on 2021/10/16.
//
//  28. Implement strStr()
//
//  Implement strStr().
//  Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>


class Solution {
public:
    int strStr(std::string haystack, std::string needle)
    {
        if ((int)needle.size() == 0) return 0;
        
        bool isSame;
        
        for (int i = 0; i <= (int)haystack.size() - (int)needle.size(); i++)
        {
            if (haystack[i] != needle[0]) continue;
            
            isSame = true;
            
            for (int j = 1; j < (int)needle.size(); j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    isSame = false;
                    break;
                }
            }
            if(isSame) return i;
        }
        return -1;
    }
};

int main (int argc, char * argv [])
{
    Solution solution;
    std::vector<std::string> haystack = {"hello", "aaaaa","a"};
    std::vector<std::string> needle = {"ll", "bba","a"};
    std::vector<int> results = {2, -1,0};
    
    for (int i = 0; i < (int)haystack.size(); i++)
    {
        int answer = solution.strStr(haystack[i], needle[i]);
        if (answer != results[i])
        {
            std::cout << haystack[i] << ": " << answer << std::endl;
        }
    }
}
