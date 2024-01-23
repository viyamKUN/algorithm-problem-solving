//
// 907. Sum of Subarray Minimums
// Given an array of integers arr, find the sum of min(b),
// where b ranges over every (contiguous) subarray of arr.
// Since the answer may be large, return the answer modulo 10^9 + 7.

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int sum = 0;
        for (int cnt = 1; cnt < arr.size(); cnt++)
        {
            // TODO...
        }
        return sum;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> input = {{3, 1, 2, 4}, {11, 81, 94, 43, 3}};
    vector<int> answer = {17, 444};
    for (int i = 0; i < input.size(); i++)
    {
        int result = solution.sumSubarrayMins(input[i]);
        if (result != answer[i])
        {
            cout << to_string(i) << "  Answer: " << answer[i] << "  My Answer: " << result << endl;
        }
    }
}
