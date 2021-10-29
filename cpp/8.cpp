//
//  8.cpp
//  LeetCode
//
//  Created by 윤하연 on 2021/10/17.
//
//  8. String to Integer (atoi)
// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).
//  The algorithm for myAtoi(string s) is as follows:
//
//    Read in and ignore any leading whitespace.
//    Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
//    Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
//    Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
//    If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
//    Return the integer as the final result.

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int myAtoi(std::string s) {
        int signNumber = 0;
        int result = 0;
        int length = 0;
        for (char c: s)
        {
            if (c < '0' || c > '9')
            {
                if (signNumber != 0) break;
                if (c == ' ') continue;
                
                if (c == '+')
                {
                    signNumber = 1;
                    continue;
                }
                if (c == '-')
                {
                    signNumber = -1;
                    continue;
                }
                break;
            }
                
            if (signNumber == 0) signNumber = 1;
            if (++length >= 10)
            {
                if (result > 214748364)
                    return signNumber > 0? 2147483647:-2147483648;
                else if (result == 214748364 && c >= (signNumber > 0? '7':'8'))
                    return signNumber > 0? 2147483647:-2147483648;
            }
            result = result * 10 + (c - '0');
            if(length == 1 && c == '0') length--;
        }
        return result * signNumber;
    }
};

int main (int argc, char * argv[])
{
    Solution solution;
    std::vector<std::string> inputs = {"42","   -42", "4193 with words", "words and 987", "-91283472332", "+-12", "  0000000000012345678", "   +0 123"};
    std::vector<int> results = {42, -42, 4193, 0, -2147483648, 0, 12345678, 0};
    int answer;
    
    for (int i = 0; i < inputs.size(); i++)
    {
        answer = solution.myAtoi(inputs[i]);
        if(answer != results[i])
        {
            std::cout << "Q. " << inputs[i] << " -> 예상: " << results[i] << "  결과: " << answer << std::endl;
        }
    }
}
