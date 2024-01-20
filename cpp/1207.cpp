//
// 1207. Unique Number of Occurrences
// LeetCode
//
// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
    bool uniqueOccurrences(std::vector<int> &arr)
    {
        std::sort(arr.begin(), arr.end());
        std::vector<bool> countArr(1000, false);
        int current = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (i == arr.size() - 1 ||
                arr[i] != arr[i + 1])
            {
                int count = i - current + 1;
                if (countArr[count])
                {
                    return false;
                }
                countArr[count] = true;
                current = i + 1;
            }
        }
        return true;
    }
};

// int main()
// {
//     Solution solution;
//     std::vector<std::vector<int>> input = {{1, 2, 2, 1, 1, 3}, {1, 2}, {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0}};
//     bool answer[] = {true, false, true};
//     for (int i = 0; i < input.size(); i++)
//     {
//         bool result = solution.uniqueOccurrences(input[i]);
//         if (result != answer[i])
//         {
//             std::cout << std::to_string(i) << " Answer: " << answer[i] << "  My Answer: " << result << std::endl;
//         }
//     }
//     return 0;
// }
