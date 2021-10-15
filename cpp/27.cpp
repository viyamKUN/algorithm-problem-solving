//
//  27.cpp
//  LeetCode
//
//  Created by 윤하연 on 2021/10/16.
//
//  27. Remove Element
//
//  Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The relative order of the elements may be changed.
//
//  Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.
//
//  Return k after placing the final result in the first k slots of nums.
//
//  Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int count = 0;
        
        for (int i = 0; i < (int)nums.size(); i++)
        {
            if (nums[i] == val)
                count++;
            else
                nums[i - count] = nums[i];
        }
        
        return  (int)nums.size() - count;
    }
};

int main (int argc, char * argv[])
{
    Solution solution;
    std::vector<std::vector<int>> inputVector = {{0,1,2,2,3,0,4,2},{3,2,2,3}};
    std::vector<int> inputVal = {2,3};
    std::vector<int> result = {5,2};

    for (int i = 0; i < (int)result.size(); i++)
    {
        int answer = solution.removeElement(inputVector[i], inputVal[i]);
        if (answer != result[i])
        {
            for(auto num : inputVector[i]) std::cout << num << ", ";
            std::cout << "Count: " << answer << std::endl;
        }
    }
}
