//
// 645. Set Mismatch
// You have a set of integers s, which originally contains all the numbers from 1 to n.
// Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set,
// which results in repetition of one number and loss of another number.

// You are given an integer array nums representing the data status of this set after the error.
// Find the number that occurs twice and the number that is missing and return them in the form of an array.

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        vector<bool> seats(nums.size(), false);
        int sum = 0;
        int twiceNum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (seats[nums[i] - 1])
            {
                twiceNum = nums[i];
            }
            else
            {
                seats[nums[i] - 1] = true;
                sum += nums[i];
            }
        }
        int expectedSum = (nums.size() + 1) * nums.size() / 2;
        return {twiceNum, expectedSum - sum};
    }
};

// int main()
// {
//     Solution solution;
//     vector<vector<int>> input = {{1, 2, 2, 4}, {1, 1}, {2, 2}, {3, 2, 3, 4, 6, 5}};
//     vector<vector<int>> answer = {{2, 3}, {1, 2}, {2, 1}, {3, 1}};
//     for (int i = 0; i < input.size(); i++)
//     {
//         vector<int> result = solution.findErrorNums(input[i]);
//         if (result != answer[i])
//         {
//             cout << to_string(i) << "  Answer: {";
//             for (int j = 0; j < answer[i].size(); j++)
//             {
//                 cout << to_string(answer[i][j]);
//                 if (j < answer[i].size() - 1)
//                 {
//                     cout << ", ";
//                 }
//             }
//             cout << "}  My Answer: {";

//             for (int j = 0; j < result.size(); j++)
//             {
//                 cout << to_string(result[j]);
//                 if (j < result.size() - 1)
//                 {
//                     cout << ", ";
//                 }
//             }
//             cout << "}" << endl;
//         }
//     }
// }
