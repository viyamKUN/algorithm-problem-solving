//
//  329.cpp
//  LeetCode
//
//  Created by 윤하연 on 2021/03/26.
//  329. Longest Increasing Path in a Matrix
//
//  Given an m x n integers matrix, return the length of the longest increasing path in matrix.
//
//  From each cell, you can either move in four directions: left, right, up, or down.
//  You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

#include <algorithm>
#include <iostream>
#include <vector>


class Solution {
public:
    int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
        int max = 1;
        std::cout << "Start" << std::endl;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (isMinimumAround(matrix, {i, j}))
                    max = std::max(countPath(matrix, {i,j}, -1), max);
            }
        }
        return max;
    }
    
    bool isMinimumAround(std::vector<std::vector<int>>& matrix, std::vector<int> target)
    {
        int row = target[0];
        int col = target[1];
        
        int currentNumber = matrix[row][col];
        
        if (col > 0)
            if (matrix[row][col-1] < currentNumber) return false;
        if (col < (int)matrix[0].size()-1)
            if (matrix[row][col+1] < currentNumber) return false;
        if (row > 0)
            if (matrix[row-1][col] < currentNumber) return false;
        if(row < (int)matrix.size()-1)
            if (matrix[row+1][col] < currentNumber) return false;
        return true;
    }
    
    int countPath(std::vector<std::vector<int>>& matrix, std::vector<int> target, int lastNumber)
    {
        int row = target[0];
        int col = target[1];
        
        int currentNumber = matrix[row][col];
        
        if (lastNumber >= currentNumber) return 0;
        
        int left = 0, right = 0, up = 0, down = 0;
        
        if (col > 0)
            left = countPath(matrix, {row, col-1}, currentNumber);
        if (col < (int)matrix[0].size()-1)
            right = countPath(matrix, {row, col+1}, currentNumber);
        if (row > 0)
            up = countPath(matrix, {row-1, col}, currentNumber);
        if(row < (int)matrix.size()-1)
            down = countPath(matrix, {row+1, col}, currentNumber);
        
        return std::max(std::max(left, right), std::max(up, down))+ 1;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    std::vector<std::vector<int>> input [6] = {{{9,9,4},{6,6,8},{2,1,1}}, {{3,4,5},{3,2,6},{2,2,1}}, {{1}}, {{1,2}}, {{7,7,5},{2,4,6},{8,2,0}}, {{0,1,2,3,4,5,6,7,8,9},{19,18,17,16,15,14,13,12,11,10},{20,21,22,23,24,25,26,27,28,29},{39,38,37,36,35,34,33,32,31,30},{40,41,42,43,44,45,46,47,48,49},{59,58,57,56,55,54,53,52,51,50},{60,61,62,63,64,65,66,67,68,69},{79,78,77,76,75,74,73,72,71,70},{80,81,82,83,84,85,86,87,88,89},{99,98,97,96,95,94,93,92,91,90},{100,101,102,103,104,105,106,107,108,109},{119,118,117,116,115,114,113,112,111,110},{120,121,122,123,124,125,126,127,128,129},{139,138,137,136,135,134,133,132,131,130},{0,0,0,0,0,0,0,0,0,0}}};
    int answer[] = {4, 4, 1, 2, 4, 140};
    for (int i = 0 ; i < sizeof(input) / sizeof(input[0]); i++) {
        int result = solution.longestIncreasingPath(input[i]);
        if (result != answer[i]) {
            std::cout << std::to_string(i) << " Answer: " << std::to_string(answer[i]) << "  My Answer: " << std::to_string(result) << std::endl;
        }
    }
    return 0;
}
